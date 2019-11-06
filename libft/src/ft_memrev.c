/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:30:02 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 15:56:16 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memrev(void *ptr, int size)
{
	int				i;
	unsigned char	tmp;
	unsigned char	*mem;

	mem = (unsigned char *)ptr;
	i = -1;
	while (++i < --size)
	{
		tmp = mem[i];
		mem[i] = mem[size];
		mem[size] = tmp;
	}
	return (ptr);
}
