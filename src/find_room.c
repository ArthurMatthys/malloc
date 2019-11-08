/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_room.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 10:21:04 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 11:44:33 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*find_space(t_metadata *data, size_t size, int type)
{
	void	*ptr;

	ptr = NULL;
	while (data)
	{
		if (data->freed && data->size >= size)
		{
//			ft_printf("cocoon : %p\t%lu\n", data, data->size);
			ptr = (void*)(data + 1);
			update_data(data, size, type);
			break ;
		}
		data = data->next;
	}
	return (ptr);
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
