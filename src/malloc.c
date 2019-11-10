/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 18:13:56 by amatthys    ###    #+. /#+    ###.fr     */
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
	block = do_mmap(size_type[type], size, type);
	ptr = find_block(block, size, type);
	ft_printf("Before ret : %lu\n", block->size);
	return (type == 2 ? block + 1 : ptr);
}

static void	*malloc_large(size_t size)
{
	(void)size;
	return (NULL);
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
//	ft_printf("type : %d\tsize : %lu\tnew_size : %lu\n", type, size, new_size);
	ptr = find_block(g_data[type], new_size, type);
//	ft_printf("ptr : %p\n", ptr);
	return (ptr ? ptr : new_alloc(new_size, type));
}
