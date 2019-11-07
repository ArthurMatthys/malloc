/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show_alloc_mem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 16:26:16 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 17:02:01 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static size_t	show_allocated_memory(t_metadata *data)
{
	if (!data)
		return (0);
	return (data->size + show_allocated_memory(data->next));
}

static size_t	show_data(t_metablock *block, const char *str)
{
	t_metablock	*cpy;
	size_t		size_block;

	cpy = block;
	size_block = 0;
	while (cpy)
	{
		ft_printf("%s : %p", str, cpy);
		size_block = show_allocated_memory((t_metadata*)(cpy + 1));
		cpy = cpy->next;
	}
	return (size_block);
}

void		show_alloc_mem(void)
{
	size_t	tot;

	tot = show_data(g_data[TINY], "TINY");
	tot += show_data(g_data[SMALL], "SMALL");
	tot += show_data(g_data[LARGE], "LARGE");
	ft_printf("Total : %lu octets\n", tot);
}
