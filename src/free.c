/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:35:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 14:56:10 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	do_munmap(t_metablock *ptr, int type)
{
	t_metadata	*data;

	if (!ptr->previous && !ptr->next)
		return ;
	if (g_data[type] == ptr)
		g_data[type] = ptr->next;
	if (ptr->next)
		ptr->next->previous = ptr->previous;
	if (ptr->previous)
		ptr->previous->next = ptr->next;
	data = (t_metadata*)(ptr + 1);
//	ft_printf("data : %d\t%lu\n", data->freed, data->size);
//	ft_printf("prev : %p\tnext : %p\n", data->previous, data->next);
	munmap(ptr, ptr->size + sizeof(t_metablock));
}

static void	check_free_space(t_metablock *ptr, t_metadata *data, int type)
{
	if (data->size + sizeof(t_metadata) == ptr->size)
		do_munmap(ptr, type);
}
static void check_munmap(t_metablock *ptr, t_metadata *data, int type)
{
	while (ptr)
	{
		if ((void*)data > (void*)ptr && (void*)data < (void*)(ptr + ptr->size))
		{
			check_free_space(ptr, (t_metadata*)(ptr + 1), type);
			break ;
		}
		ptr = ptr->next;
	}
}

static void	merge_metadata(t_metadata *data)
{
	if (data->next && data->next->freed)
	{
		data->size += (sizeof(t_metadata) + data->next->size);
		data->next = data->next->next;
		if (data->next)
			data->next->previous = data;
	}
	if (data->previous && data->previous->freed)
	{
		data->previous->size += (sizeof(t_metadata) + data->size);
		data->previous->next = data->next;
		if (data->next)
			data->next->previous = data->previous;
	}
}

void		free(void *ptr)
{
	t_metadata	*data;
	int			type;

//	ft_printf("\tfree((void*)%p);\n", ptr);
	if (!ptr)
		return ;
	data = find_alloc(ptr);
	if (!data)
		return ;
	data->freed = 1;
	type = get_type(data->size);
	if (0 && type != LARGE)
		merge_metadata(data);
	if (type == LARGE)
		do_munmap((t_metablock*)data, type);
	else
		check_munmap(g_data[type], data, type);
}
