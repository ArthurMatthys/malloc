/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:36:09 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 16:55:16 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void		*find_room(t_metadata *data, void *ptr, size_t size)
{
	void	*cpy;

	if (!data)
	{
		cpy = malloc(size);
		ft_printf("yo1\n");
		ft_memmove(cpy, ptr, size);
		ft_printf("yo2\n");
		free(ptr);
		return (cpy);
	}
	if (data->size >= size)
		return (data);
	else
		return (find_room(data->next, ptr, size));
}

size_t	find_alloc(t_metadata *data, void *ptr)
{
	if (!data)
		return (0);
	if (ptr == (void*)(data + 1))
		return (data->size);
	else
		return (find_alloc(data->next, ptr));
}

static void	*realloc_large(void *ptr, size_t size)
{
	t_metadata	*cpy;
	size_t		size_actual;

	cpy = g_data[LARGE];
	size_actual = find_alloc(cpy, ptr);
	if (!size_actual)
		return (NULL);
	else if (size <= size_actual)
		return (ptr);
	else
		return (find_room(cpy, ptr, size));
}

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	new_size;
	int		room;
	int		type;

	room = 0;
	new_size = round_up(size, 16);
	type = get_type(new_size);
	if (type == LARGE)
		return (realloc_large(ptr, round_up(new_size, getpagesize())));
	if ((room = find_area(g_data[type], ptr)) == -1)
	{
		ft_printf("oupsi\n");
		return (NULL);
	}
	if ((size_t)room >= size)
		return (ptr);
	new_ptr = malloc(new_size);
	ft_memmove(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
