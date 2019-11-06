/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   round_up.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:17 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 10:23:59 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t	round_up(size_t start, size_t to_round)
{
	return ((start & (to_round - 1)) | to_round);
}
