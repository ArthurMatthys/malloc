/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 18:29:01 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 10:30:07 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(const char fmt, t_tab *tab)
{
	if (fmt == '-')
	{
		tab->side = 1;
		tab->fill = 0;
	}
	else if (fmt == '+')
	{
		tab->fill = 0;
		tab->sign = 2;
	}
	else if (fmt == ' ')
	{
		if (!tab->sign)
			tab->sign = 1;
	}
	else if (fmt == '0' && (!tab->side) && (tab->sign != 2))
		tab->fill = 1;
	else if (fmt == '#')
		tab->conv = 1;
	else
		tab->type = 'a';
	return (1);
}

int		check_width(const char *fmt, t_tab *tab, int i)
{
	if (!i)
	{
		tab->w = 1;
		tab->width = tab->width * 10 + (*fmt - '0');
	}
	else
	{
		tab->w = 2;
		tab->acc = tab->acc * 10 + (*fmt - '0');
	}
	return (1);
}

int		check_len(const char *fmt, t_tab *tab)
{
	if (*fmt == 'h' && tab->len <= 2)
		tab->len = (tab->len % 2) + 1;
	else if (*fmt == 'l' && tab->len <= 4)
		tab->len = 3 + (tab->len % 2);
	else if (*fmt == 'z' && tab->len <= 5)
		tab->len = 5;
	else
		tab->len = 6;
	return (1);
}

int		is_inc(const char fmt, const char *list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		if (fmt == list[i])
			return (1);
		i++;
	}
	return (0);
}

int		parse_handler(const char *fmt, t_tab *tab)
{
	int	j;

	j = 0;
	while (is_inc(*fmt, "-+ 0#123456789hljz."))
	{
		while (is_inc(*fmt, "-+ 0#"))
			j += check_flag(*fmt++, tab);
		while (is_inc(*fmt, "0123456789"))
			j += check_width(fmt++, tab, 1);
		if (*fmt == '.')
		{
			fmt++;
			j++;
			tab->w = 4;
			while (is_inc(*fmt, "0123456789"))
				j += check_width(fmt++, tab, 0);
		}
		while (is_inc(*fmt, "hljz"))
			j += check_len(fmt++, tab);
	}
	if (*fmt)
		tab->type = (char)*fmt++;
	else if (j || !j--)
		tab->type = 25;
	return (j + 1);
}
