/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:30:46 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 10:51:21 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;

	i = -1;
	cpy_dest = (unsigned char*)dest;
	cpy_src = (unsigned char*)src;
	if ((src - dest) > 0)
		while (++i < n)
			cpy_dest[i] = cpy_src[i];
	else
		while (++i < n)
			cpy_dest[n - 1 - i] = cpy_src[n - 1 - i];
	return (dest);
}
