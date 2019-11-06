/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_dd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 16:51:04 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 18:14:12 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_d(va_list ap, t_tab *tab)
{
	intmax_t	i;
	char		str[21];

	if (!(tab->len))
		i = va_arg(ap, int);
	else if (tab->len == 1)
		i = (short)va_arg(ap, int);
	else if (tab->len == 2)
		i = (signed char)va_arg(ap, int);
	else if (tab->len == 3)
		i = va_arg(ap, long int);
	else if (tab->len == 4)
		i = va_arg(ap, long long int);
	else if (tab->len == 5)
		i = va_arg(ap, ssize_t);
	else
		i = va_arg(ap, intmax_t);
	return (ft_intputstr_def(ft_atoi_base(i, "0123456789",
					tab, str), tab, FIL));
}

int		ft_printf_dd(va_list ap, t_tab *tab)
{
	intmax_t	i;
	char		str[21];

	if (!(tab->len) || tab->len == 2)
		i = va_arg(ap, long int);
	else if (tab->len == 1)
		i = (unsigned short)va_arg(ap, int);
	else if (tab->len == 2)
		i = (signed char)va_arg(ap, int);
	else if (tab->len == 4)
		i = va_arg(ap, long long int);
	else if (tab->len == 5)
		i = va_arg(ap, ssize_t);
	else
		i = va_arg(ap, intmax_t);
	return (ft_intputstr_def(ft_atoi_base(i, "0123456789",
					tab, str), tab, FIL));
}

int		ft_printf_i(va_list ap, t_tab *tab)
{
	return (ft_printf_d(ap, tab));
}

int		ft_printf_u(va_list ap, t_tab *tab)
{
	intmax_t	i;
	char		str[21];

	if (!tab->len)
		i = va_arg(ap, unsigned int);
	else if (tab->len == 1)
		i = (unsigned short)va_arg(ap, int);
	else if (tab->len == 2)
		i = (unsigned char)va_arg(ap, int);
	else if (tab->len == 3)
		i = va_arg(ap, unsigned long int);
	else if (tab->len == 4)
		i = va_arg(ap, unsigned long long int);
	else if (tab->len == 5)
		i = va_arg(ap, size_t);
	else
		i = va_arg(ap, uintmax_t);
	if ((tab->w == 1 || tab->w == 2) && !(i) && !tab->width && !tab->acc)
		tab->w = 0;
	if (tab->w == 4 && !tab->width && !tab->acc && !(i))
		tab->w = 0;
	if (tab->fill && tab->acc && tab->width)
		tab->fill = 0;
	return (ft_intputstr_def(ft_uatoi_base(i, "0123456789",
					tab, str), tab, FIL));
}

int		ft_printf_uu(va_list ap, t_tab *tab)
{
	if (tab->len <= 2)
		tab->len = 3;
	return (ft_printf_u(ap, tab));
}
