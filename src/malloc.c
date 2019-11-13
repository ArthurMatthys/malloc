/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 15:06:55 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 15:56:06 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*malloc(size_t size)
{
	int		type;

	size = round_up(size, 16);
	type = get_type(size);
	if (type == LARGE)
		return (malloc_large(size));
	else if (type == SMALL)
		return (malloc_small(size));
	else
		return (malloc_tiny(size));
}
