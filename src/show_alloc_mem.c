/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show_alloc_mem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 16:26:16 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 16:54:30 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void		show_range(void *ptr, size_t size_ptr, size_t size)
{
	ft_printf("%#X - %#X : %lu octets\n", ptr + size_ptr,
			((char*)ptr + size_ptr) + size, size);
}

static size_t	show_allocated_memory(t_metadata *data, int type)
{
	size_t	size;

	if (!data)
		return (0);
	size = data->freed ? 0 : data->size;
	if (!data->freed)
	{
		if (type == LARGE)
			ft_printf("LARGE : %#X\n", data);
		show_range(data, sizeof(t_metadata), data->size);
	}
	if (!data->next)
		return (size);
	return (size + show_allocated_memory(data->next, type));
}

static size_t	show_data(t_metablock *block, const char *str, int type)
{
	t_metablock	*cpy;
	size_t		size_block;

	cpy = block;
	size_block = 0;
	while (cpy)
	{
		ft_printf("%s : %X\n", str, cpy);
		size_block += show_allocated_memory((t_metadata*)(cpy + 1), type);
		cpy = cpy->next;
	}
	return (size_block);
}

void			show_alloc_mem(void)
{
	size_t	tot;

	tot = show_data(g_data[TINY], "TINY", TINY);
	tot += show_data(g_data[SMALL], "SMALL", SMALL);
	tot += show_allocated_memory(g_data[LARGE], LARGE);
	ft_printf("Total : %lu octets\n", tot);
}
