/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_mmap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 09:07:15 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 09:09:22 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		*do_mmap(size_t size)
{
	return (mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0));
}

