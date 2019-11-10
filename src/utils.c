/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:17 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 17:28:53 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static int	find_metadata(t_metablock *block, void *ptr)
{
	t_metadata	*actual;

	actual = (t_metadata*)(block + 1);
	while (actual)
	{
		if (ptr == actual + 1)
			return (1);
		actual = actual->next;
	}
	return (0);
}

int		find_area(t_metablock *block, void *ptr)
{
	t_metablock	*cpy;

	cpy = block;
	while (cpy)
	{
		if (ptr > (void*)cpy && ptr < ((void*)cpy + cpy->size))
			return (find_metadata(cpy, ptr));
		cpy = cpy->next;
	}
	return (0);
}

/*
** Create a new metadata after allocation and update the new one
*/

void		update_data(t_metadata *data, size_t size, int type)
{
	static int	size_tab[] = {0, TINY_SIZE, SMALL_SIZE};
	size_t		min_size;
	size_t		size_left;
	t_metadata	*new;

	min_size = size_tab[type] + sizeof(t_metadata);
	size_left = data->size - size;
	data->size = size;
	data->freed = 0;
	if (size_left < min_size)
		;
	else
	{
		new = (t_metadata*)(((char *)data + data->size + sizeof(t_metadata)));
		new->size = size_left - (data->size + sizeof(t_metadata));
		new->freed = 1;
		new->next = data->next;
		new->previous = data;
		data->next = new;
	}
}

/*
** round a size_t up to to_round
*/

size_t		round_up(size_t size, size_t to_round)
{
	return (((size + to_round - 1) & (0xFFFFFFFFFFFFFFFF - (to_round - 1))));
}

/*
** Return the type of allocation needed
*/

int			get_type(size_t size)
{
	if (size < TINY_SIZE)
		return (TINY);
	else if (size < SMALL_SIZE)
		return (SMALL);
	else
		return (LARGE);
}
