/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 11:31:45 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 10:25:39 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_len(intmax_t i, int t)
{
	int k;

	k = 0;
	if (!(i))
		return (1);
	else
	{
		while (i)
		{
			i /= t;
			k++;
		}
		return (k);
	}
}

char	*retu(t_tab *tab)
{
	if (tab->sign == 1)
		return (" ");
	else if (tab->sign == 2)
		return ("+");
	else
		return ("");
}

char	*ft_atoi_base(intmax_t i, char *base, t_tab *tab, char *str)
{
	int		t[4];

	t[2] = (i < 0);
	if ((tab->w == 1 || tab->w == 4) && !tab->width && !(i))
		return (retu(tab));
	if (t[2])
		tab->w = 1;
	t[1] = (int)ft_strlen(base);
	t[0] = int_len(i, t[1]) + t[2] + (t[2] ? 0 : (tab->sign > 0));
	str[t[0]] = '\0';
	t[0]--;
	while (t[0] >= (t[2] || tab->sign))
	{
		t[3] = (i < 0 ? -(i % t[1]) : i % t[1]);
		str[t[0]] = base[t[3]];
		i /= t[1];
		t[0]--;
	}
	if (t[2] == 1)
		str[0] = '-';
	else if (tab->sign == 1)
		str[0] = ' ';
	else if (tab->sign == 2)
		str[0] = '+';
	return (str);
}
