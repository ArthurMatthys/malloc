/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:36:09 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:47:09 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;

//	ft_printf("Realloc call\n");
	new_ptr = malloc(size);
	ft_memmove(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
