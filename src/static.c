/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   static.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 16:15:53 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 15:09:29 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*g_data[] = {NULL, NULL, NULL};

static void	init_area(t_metablock *ptr, size_t size, int type)
{
	t_metadata	*start;

	ptr->type = type;
	ptr->size = size + sizeof(t_metablock);
	ptr->previous = NULL;
	ptr->next = NULL;
	start = (t_metadata*)(ptr + 1);
	start->size = size - sizeof(t_metadata);
	start->freed = 1;
	start->previous = NULL;
	start->next = NULL;
}

void		calledfirst(void)
{
	g_data[TINY] = mmap(0, TINY_BLOCK_SIZE + sizeof(t_metablock),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	init_area(g_data[TINY], TINY_BLOCK_SIZE, TINY);
	g_data[SMALL] = mmap(0, SMALL_BLOCK_SIZE + sizeof(t_metablock),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	init_area(g_data[SMALL], SMALL_BLOCK_SIZE, SMALL);
}

static void	free_all(t_metablock *ptr)
{
	if (!ptr)
		return ;
	free_all(ptr->next);
	munmap(ptr, ptr->size);
	ptr = NULL;
}

void		calledlast(void)
{
	free_all(g_data[TINY]);
	g_data[TINY] = NULL;
	free_all(g_data[SMALL]);
	g_data[SMALL] = NULL;
	free_all(g_data[LARGE]);
	g_data[LARGE] = NULL;
}
