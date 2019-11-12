/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 11:01:26 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*new_alloc(size_t size, int type)
{
	t_metablock		*block;
	size_t			size_type[2];
	void			*ptr;

	size_type[TINY] = TINY_BLOCK_SIZE;
	size_type[SMALL] = SMALL_BLOCK_SIZE;
	block = do_mmap(size_type[type], type);
	ptr = find_block(block, size, type);
	return (ptr);
}

static void	*malloc_large(size_t size)
{
	t_metadata	*data;
	t_metadata	*cpy;
	size_t		final_size;
	void		*ptr;

	if ((ptr = find_space(g_data[LARGE], size, LARGE)))
		return (ptr);
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
	size_t	new_size;
	void	*ptr;
	int		type;

	new_size = round_up(size, 16);
	type = get_type(new_size);
	if (type == LARGE)
		return (malloc_large(new_size));
	ptr = find_block(g_data[type], new_size, type);
	return (ptr ? ptr : new_alloc(new_size, type));
}
