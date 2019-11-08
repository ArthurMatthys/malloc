/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 16:59:01 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*new_alloc(size_t size_block, size_t size, int type)
{
	t_metablock		*block;
	void			*ptr;

	ptr = NULL;
//	ft_printf("Trying to mmap....\n");
	block = do_mmap(size_block, type);
//	ft_printf("New mmap done ! \n");
//	ft_printf("Searching for block...\n");
	ptr = find_block(block, size, type);
//	ft_printf("Block found!\n");
	return (type == 2 ? block + 1 : ptr);
}

void		*malloc(size_t size)
{
	size_t	size_type[3];
	size_t	new_size;
	void	*ptr;
	int		type;

//	ft_printf("Malloc call\n");
	size_type[0] = TINY_BLOCK_SIZE;
	size_type[1] = SMALL_BLOCK_SIZE;
	size_type[2] = size;
	new_size = round_up(size, 16);
	type = get_type(new_size);
//	ft_printf("type : %d\tsize : %lu\tnew_size : %lu\n", type, size, new_size);
	ptr = type == 2 ? NULL : find_block(g_data[type], new_size, type);
//	ft_printf("ptr : %p\n", ptr);
	return (ptr ? ptr : new_alloc(size_type[type], new_size, type));
}
