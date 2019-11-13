/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 15:07:17 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 15:52:43 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t		round_up(size_t size, size_t to_round)
{
	return (((size + to_round - 1) & (0xFFFFFFFFFFFFFFFF - (to_round - 1))));
}

int			get_type(size_t size)
{
	if (size < TINY_SIZE)
		return (TINY);
	else if (size < SMALL_SIZE)
		return (SMALL);
	else
		return (LARGE);
}
