/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conv.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 10:05:37 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/12 18:10:52 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_x(va_list ap, t_tab *tab)
{
	intmax_t	i;
	char		str[18];

	tab->conv *= 2;
	if (!(tab->len))
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
	if ((tab->width || tab->w == 1 || tab->w == 4) && tab->acc && tab->fill)
		tab->fill = 0;
	return (ft_intputstr_def(ft_uatoi_base(i, "0123456789abcdef", tab, str)
				, tab, FIL));
}

int				ft_printf_xx(va_list ap, t_tab *tab)
{
	intmax_t	i;
	char		str[18];

	tab->conv *= 2;
	if (!(tab->len))
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
	return (ft_intputstr_def(ft_uatoi_base(i, "0123456789ABCDEF", tab, str)
				, tab, FIL));
}

int				ft_printf_o(va_list ap, t_tab *tab)
{
	intmax_t	i;
	char		str[22];

	if (!(tab->len))
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
	if ((tab->width || tab->w == 1 || tab->w == 4) && tab->acc && tab->fill)
		tab->fill = 0;
	return (ft_intputstr_def(ft_uatoi_base(i, "01234567", tab, str), tab, FIL));
}

int				ft_printf_oo(va_list ap, t_tab *tab)
{
	if (!tab->len)
		tab->len = 3;
	else if (tab->len == 2)
		tab->len = 0;
	return (ft_printf_o(ap, tab));
}

int				ft_printf_p(va_list ap, t_tab *tab)
{
	tab->conv = 1;
	tab->len = 3;
	return (ft_printf_x(ap, tab));
}
