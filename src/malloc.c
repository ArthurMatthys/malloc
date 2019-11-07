/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 09:07:06 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*malloc(size_t size)
{
	const static t_dispatcher	dispatch[] = {
		&handle_tiny, &handle_small, &handle_large};
	size_t						new_size;
	int							type;

	new_size = round_up(size, 16);
	type = get_type(new_size);
	return (dispatch[type]);
}
