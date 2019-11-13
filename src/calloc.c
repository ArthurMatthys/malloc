/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:37:23 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 10:25:43 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

//	ft_printf("\tptr = calloc(%lu, %lu);\n", count, size);
	ptr = malloc(count * size);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
