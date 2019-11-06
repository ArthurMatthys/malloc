/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:17 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 13:54:09 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t	round_up(size_t start, size_t to_round)
{
	return ((start & (to_round - 1)) | to_round);
}

int		get_type(size_t size)
{
	if (size < TINY_SIZE)
		return (TINY);
	else if (size < TINY_SIZE)
		return (SMALL);
	else
		return (LARGE);
}
