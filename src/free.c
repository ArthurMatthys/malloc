/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:35:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 10:46:46 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	do_big_munmap(t_metadata *ptr)
{
	if (g_data[LARGE] == ptr)
		g_data[LARGE] = ptr->next;
	if (ptr->next)
		ptr->next->previous = ptr->previous;
	if (ptr->previous)
		ptr->previous->next = ptr->next;
	if (munmap(ptr, ptr->size + sizeof(t_metadata)) < 0)
		ft_putstr_fd("Munmap failed\n", 2);
	ptr = NULL;
}

static void	do_munmap(t_metablock *ptr, int type)
{
	(void)type;
	if (!ptr->previous && !ptr->next)
		return ;
	if (ptr->next)
		ptr->next->previous = ptr->previous;
	if (ptr->previous)
		ptr->previous->next = ptr->next;
	if (munmap(ptr, ptr->size + sizeof(t_metablock)) < 0)
		ft_putstr_fd("Munmap failed\n", 2);
	ptr = NULL;
}

static void	check_munmap(t_metablock *ptr, t_metadata *data, int type)
{
	while (ptr)
	{
		if ((void*)data > (void*)ptr && (void*)data < (void*)(ptr + ptr->size))
		{
			if (data->size + sizeof(t_metadata) +
					sizeof(t_metablock) == ptr->size)
				do_munmap(ptr, type);
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

	if (!ptr)
		return ;
	data = find_alloc(ptr);
	if (!data)
		return ;
	data->freed = 1;
	type = get_type(data->size);
	if (type != LARGE)
		merge_metadata(data);
	if (type != LARGE)
		check_munmap(g_data[type], data, type);
	else
		do_big_munmap(data);
}
