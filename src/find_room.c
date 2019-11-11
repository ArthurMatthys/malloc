/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_room.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 10:21:04 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 14:39:31 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*find_space(t_metadata *data, size_t size, int type)
{
	void	*ptr;

	ptr = NULL;
	while (data)
	{
		if (data->freed && data->size >= size)
		{
			ptr = (void*)(data + 1);
			update_data(data, size, type);
			return (ptr);
		}
		data = data->next;
	}
	return (NULL);
}

/*
** Look if there is enough room in some already
** mmaped block to put the new pointer
*/

void		*find_block(t_metablock *block, size_t size, int type)
{
	void		*ptr;
	t_metablock	*cpy;

	cpy = block;
	ptr = NULL;
	while (cpy)
	{
		ptr = find_space((t_metadata*)(cpy + 1), size, type);
		if (ptr)
			break ;
		cpy = cpy->next;
	}
	return (ptr);
}
