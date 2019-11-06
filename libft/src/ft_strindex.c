/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strindex.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 13:30:20 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/19 13:31:42 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strindex(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	return (-1);
}
