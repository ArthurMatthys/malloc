/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 08:34:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 16:21:49 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** ptr = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
*/
#include "../includes/malloc.h"

void		*malloc(size_t size)
{
	const static t_dispatcher	dispatch[] = {
		&handle_tiny, &handle_small, &handle_large};
	size_t						new_size;
	int							type;

	new_size = round_up(size, 16);
	type = get_type(new_size);
	return (fun[type]);
}
