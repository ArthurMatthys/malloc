/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:35:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 16:53:22 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

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

	if (!ptr)
		return ;
	data = find_alloc(ptr);
	if (!data)
		return ;
	data->freed = 1;
	if (0 && get_type(data->size) != LARGE)
		merge_metadata(data);
}
