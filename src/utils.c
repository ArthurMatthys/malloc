/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:17 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 11:57:41 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

/*
** Create a new metadata after allocation and update the new one
*/

void		update_data(t_metadata *data, size_t size, int type)
{
	static int	size_tab[] = {1, TINY_SIZE, SMALL_SIZE};
	size_t		min_size;
	size_t		old_size;
	t_metadata	*new;

	min_size = size_tab[type];
	if (data->size < size + min_size)
		;
	else
	{
		old_size = data->size;
		data->size = size;
		data->freed = 0;
		new = (t_metadata*)((char *)(data + data->size + sizeof(t_metadata)));
		new->size = old_size - (data->size + sizeof(t_metadata));
		new->freed = 1;
		new->next = data->next;
		new->previous = data;
		data->next = new;
	}
}

/*
** round a size_t up to to_round
*/

size_t		round_up(size_t start, size_t to_round)
{
	return ((start & (to_round - 1)) | to_round);
}

/*
** Return the type of allocation needed
*/

int			get_type(size_t size)
{
	if (size < TINY_SIZE)
		return (TINY);
	else if (size < TINY_SIZE)
		return (SMALL);
	else
		return (LARGE);
}
