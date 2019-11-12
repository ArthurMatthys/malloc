/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_room.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 10:21:04 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 16:55:24 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_metadata
	*find_metadata(t_metadata *data, void *ptr, int fun, size_t size)
{
	while (data)
	{
		if ((ptr && data + 1 == ptr) ||
				(fun && data->freed && data->size >= size))
			return (data);
		data = data->next;
	}
	return (NULL);
}

/*
** Look if there is enough room in some already
** mmaped block to put the new pointer
*/

t_metadata
	*find_block(t_metablock *block, void *ptr, int fun, size_t size)
{
	t_metablock	*cpy;
	t_metadata	*ret;

	ret = NULL;
	cpy = block;
	while (cpy)
	{
		ret = find_metadata((t_metadata*)(cpy + 1), ptr, fun, size);
		if (ret)
			break ;
		cpy = cpy->next;
	}
	return (ret);
}

t_metadata
	*find_alloc(void *ptr)
{
	t_metadata	*ret;

	ret = NULL;
	if (!ret)
		ret = find_block(g_data[TINY], ptr, FIND_ALLOC, 0);
	if (!ret)
		ret = find_block(g_data[SMALL], ptr, FIND_ALLOC, 0);
	if (!ret)
		ret = find_metadata(g_data[LARGE], ptr, FIND_ALLOC, 0);
	return (ret);
}
