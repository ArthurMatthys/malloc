/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   divide.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 15:24:10 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 10:00:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		divide_case(va_list ap, t_tab *tab, t_fun *fun)
{
	int i;

	i = 0;
	while ((tab->type != fun[i].type))
		i++;
	return (fun[i].ptr(ap, tab));
}

int		init_tab(t_tab *tab)
{
	tab->type = 'a';
	tab->len = 0;
	tab->sign = 0;
	tab->side = 0;
	tab->fill = 0;
	tab->conv = 0;
	tab->width = 0;
	tab->w = 10;
	tab->acc = 0;
	return (1);
}

int		inner_inner(const char *fmt, va_list ap2, t_tab *tab)
{
	init_tab(tab);
	if (ft_strchr((char *)fmt, '%') && !check_next(fmt, ap2, tab))
	{
		init_tab(tab);
		return (1);
	}
	else
	{
		init_tab(tab);
		return (0);
	}
}
