/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 11:51:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*new_alloc(size_t size_block, size_t size, int type)
{
	t_metablock		*block;
	void			*ptr;

	ptr = NULL;
	block = do_mmap(size_block, type);
	ptr = find_block(block, size, type);
	return (ptr);
}

void		*malloc(size_t size)
{
	size_t	size_type[3];
	size_t	new_size;
	void	*ptr;
	int		type;

	size_type[0] = TINY_BLOCK_SIZE;
	size_type[1] = SMALL_BLOCK_SIZE;
	size_type[2] = size;
	new_size = round_up(size, 16);
	type = get_type(new_size);
	ptr = find_block(g_data[type], new_size, type);
	return (ptr ? ptr : new_alloc(size_type[type], new_size, type));
}
