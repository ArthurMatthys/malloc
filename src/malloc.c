/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 16:55:07 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*new_alloc(size_t size, int type)
{
	t_metablock	*block;
	t_metadata	*data;
	size_t		size_type[2];

	size_type[TINY] = TINY_BLOCK_SIZE;
	size_type[SMALL] = SMALL_BLOCK_SIZE;
	block = do_mmap(size_type[type], type);
	data = find_block(g_data[type], NULL, FIND_ROOM, size);
	update_data(data, size, type);
	return (data + 1);
}

static void	*malloc_large(size_t size)
{
	t_metadata	*data;
	t_metadata	*cpy;
	size_t		final_size;

	final_size = round_up(size + sizeof(t_metadata), getpagesize());
	data = mmap(0, final_size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	data->freed = 0;
	data->size = size - sizeof(t_metadata);
	data->next = NULL;
	data->previous = NULL;
	cpy = g_data[LARGE];
	if (!cpy)
		g_data[LARGE] = data;
	else
	{
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = data;
		data->previous = cpy;
	}
	return (data + 1);
}

void		*malloc(size_t size)
{
	t_metadata	*data;
	size_t		new_size;
	int			type;

	new_size = round_up(size, 16);
	type = get_type(new_size);
	if (type == LARGE)
		data = find_metadata(g_data[type], NULL, FIND_ROOM, new_size);
	else
		data = find_block(g_data[type], NULL, FIND_ROOM, new_size);
	if (data)
	{
		update_data(data, new_size, type);
		return (data + 1);
	}
	if (type == LARGE)
		return (malloc_large(new_size));
	return (new_alloc(new_size, type));
}
