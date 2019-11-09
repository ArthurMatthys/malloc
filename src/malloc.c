/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:25:10 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*new_alloc(size_t size, int type)
{
	t_metablock		*block;
	void			*ptr;

	ptr = NULL;
	block = do_mmap(size, type);
	return (type == 2 ? block + 1 : ptr);
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
//	ft_printf("type : %d\tsize : %lu\tnew_size : %lu\n", type, size, new_size);
	ptr = type == 2 ? NULL : find_block(g_data[type], new_size, type);
//	ft_printf("ptr : %p\n", ptr);
	return (ptr ? ptr : new_alloc(new_size, type));
}
