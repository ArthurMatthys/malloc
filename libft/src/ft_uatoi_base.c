/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 11:31:45 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 10:07:13 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		uint_len(uintmax_t i, int t)
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

int		ucreate_char(t_tab *tab, char **str)
{
	int		t;

	t = 0;
	if (tab->conv)
	{
		str[0][t++] = '0';
		if (tab->type == 'X')
			str[0][t++] = 'X';
		else if (tab->type == 'x' || tab->type == 'p')
			str[0][t++] = 'x';
	}
	return (t);
}

int		len_base(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		cond(uintmax_t i, t_tab *tab)
{
	if ((tab->w == 4 || tab->w == 1) && !tab->width &&
			(tab->type == 'X' || tab->type == 'x' || ((tab->type == 'o' ||
			tab->type == 'O') && !tab->conv)) && !(i))
		return (1);
	else if (tab->w == 1 && !tab->width && tab->type == 'x' && !(i))
		return (1);
	else if ((tab->conv || (!tab->width && tab->w == 1) ||
				(!tab->acc && tab->w == 2)) && !(i) &&
			(tab->type != 'x' && tab->type != 'p'))
		return (2);
	else if (tab->type == 'x' && tab->conv && !tab->len &&
			(tab->fill || tab->w == 1 || tab->w == 10) && !(i))
		return (2);
	else if (tab->conv && tab->type == 'x' && !(i) &&
			(tab->w == 1 && tab->width))
		return (2);
	else
		return (3);
}

char	*ft_uatoi_base(uintmax_t i, char *base, t_tab *tab, char *str)
{
	int		k;
	int		j;
	int		t;

	t = len_base(base);
	k = uint_len(i, t);
	j = ucreate_char(tab, &str);
	if (cond(i, tab) == 1)
		return ("");
	if (cond(i, tab) == 2)
		return ("0");
	if (tab->type == 'p' && ((tab->w == 1 && !tab->width) || tab->w == 4))
		return ("0x");
	k += j;
	str[k--] = '\0';
	while (j <= k)
	{
		str[k] = base[i % t];
		i /= t;
		k--;
	}
	return (str);
}
