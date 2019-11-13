/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:36:09 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 17:09:43 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*realloc(void *ptr, size_t size)
{
	t_metadata	*found;
	void		*ret;
	size_t		new_size;

	if (!ptr)
		return (malloc(size));
	new_size = round_up(size, 16);
	found = find_alloc(ptr);
	if (!found)
		return (NULL);
	if (found->size >= new_size)
		return (ptr);
	else
	{
		ret = malloc(new_size);
		ft_memmove(ret, ptr, min(size, found->size));
		free(ptr);
		return (ret);
	}
	return (NULL);
}
