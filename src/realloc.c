/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   realloc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:36:09 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 13:15:19 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	new_size;
	int		type;

//	ft_printf("Realloc call\n");
	new_size = round_up(size, 16);
	type = get_type(new_size);
	if (!find_area(g_data[type], ptr))
		return (NULL);
	ft_printf("1\n");
	new_ptr = malloc(size);
	ft_printf("2\n");
	ft_memcpy(new_ptr, ptr, size);
	ft_printf("3\n");
	free(ptr);
	ft_printf("4\n");
	return (new_ptr);
}
