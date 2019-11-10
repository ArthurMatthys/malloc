/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_mmap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 09:07:15 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 17:24:52 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	write_metadata(t_metablock *block, size_t size)
{
	t_metadata	*new;

	new = (t_metadata*)(block + 1);
	new->size = (size - (sizeof(t_metablock) + sizeof(t_metadata)));
	new->previous = NULL;
	new->next = NULL;
	new->freed = 1;
}

void		*do_mmap(size_t size_alloc, size_t size, int type)
{
	t_metablock		*new_area;
	t_metablock		*cpy;

	ft_printf("size mmap : %lu\n", size_alloc);
	new_area = mmap(0, size_alloc,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new_area->type = type;
	new_area->size = size_alloc - sizeof(t_metablock);
	new_area->previous = NULL;
	new_area->next = NULL;
	cpy = g_data[type];
	if (!cpy)
		g_data[type] = new_area;
	else
	{
		while (cpy->next)
		{
			cpy = cpy->next;
		}
		new_area->previous = cpy;
	}
	write_metadata(new_area, size - sizeof(t_metadata));
	return (new_area);
}
