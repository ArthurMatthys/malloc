/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:35:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 13:20:26 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	merge_metadata(t_metadata *data)
{
	t_metadata	*prev;
	t_metadata	*next;

	prev = data->previous;
	next = data->next;
	data->freed = 1;
	if (prev && prev->freed)
	{
		prev->size += (sizeof(t_metadata) + data->size);
		prev->next = next;
		data = prev;
	}
	if (next && next->freed)
	{
		data->size += (sizeof(t_metadata) + data->size);
		data->next = next->next;
	}
}

static int	find_area(t_metablock *block, void *ptr)
{
	t_metablock	*cpy;

	cpy = block;
	while (cpy)
	{
		if (ptr > (void*)cpy && ptr < ((void*)cpy + cpy->size))
			return (1);
		cpy = cpy->next;
	}
	return (0);
}

void		free(void *ptr)
{
	t_metadata	*data;

//	ft_printf("Free call\n");
	data = NULL;
	if (find_area(g_data[0], ptr))
		data = (t_metadata *)ptr - 1;
	else if (find_area(g_data[1], ptr))
		data = (t_metadata *)ptr - 1;
	else if (find_area(g_data[2], ptr))
		data = (t_metadata *)ptr - 1;
	if (data)
		merge_metadata(data);
}
