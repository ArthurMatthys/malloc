/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:35:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 17:03:32 by amatthys    ###    #+. /#+    ###.fr     */
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

void		free(void *ptr)
{
	t_metadata	*data;

//	ft_printf("Free call\n");
	if (!ptr)
		return ;
	data = NULL;
	if (find_area(g_data[0], ptr) >= 0)
		data = (t_metadata *)ptr - 1;
	else if (find_area(g_data[1], ptr) >= 0)
		data = (t_metadata *)ptr - 1;
	else if (find_alloc(g_data[2], ptr))
		data = (t_metadata *)ptr - 1;
	if (data)
		merge_metadata(data);
}
