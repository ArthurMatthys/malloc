/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:17 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 16:54:38 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

/*
** Create a new metadata after allocation and update the new one
*/

void		update_data(t_metadata *data, size_t size, int type)
{
	static int	size_tab[] = {0, TINY_SIZE, SMALL_SIZE};
	size_t		size_left;
	size_t		size_needed;
	t_metadata	*new;

	size_needed = size_tab[type] + sizeof(t_metadata);
	size_left = data->size - size;
	data->size = (type == LARGE ? data->size : size);
	data->freed = 0;
	if (type != LARGE && size_left > size_needed)
	{
		new = (t_metadata*)(((char *)data + data->size + sizeof(t_metadata)));
		new->size = size_left - sizeof(t_metadata);
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
