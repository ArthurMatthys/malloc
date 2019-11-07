/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_mmap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 09:07:15 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 14:34:27 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	write_metadata(t_metablock *block, size_t size)
{
	t_metadata	*new;

	new = (t_metadata*)(block + 1);
	new->size = (size - (sizeof(block) + sizeof(t_metadata)));
	new->previous = NULL;
	new->next = NULL;
	new->freed = 1;
}

void		*do_mmap(size_t size, int type)
{
	t_metablock		*new;
	t_metablock		*cpy;

	new = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	new->size = size;
	new->previous = NULL;
	new->next = NULL;
	cpy = g_data[type];
	if (!cpy)
		g_data[type] = new;
	else
	{
		while (cpy->next)
		{
			cpy = cpy->next;
		}
		new->previous = cpy;
	}
	write_metadata(new, size);
	return (new);
}
