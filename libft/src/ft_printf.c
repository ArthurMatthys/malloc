/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 12:37:19 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 10:26:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_fun2(t_fun *fun)
{
	fun[10].type = 'x';
	fun[10].ptr = &ft_printf_x;
	fun[11].type = 'X';
	fun[11].ptr = &ft_printf_xx;
	fun[12].type = 'c';
	fun[12].ptr = &ft_printf_c;
	fun[13].type = 'C';
	fun[13].ptr = &ft_printf_cc;
	return (1);
}

int		init_fun(t_fun *fun)
{
	fun[0].type = 's';
	fun[0].ptr = &ft_printf_s;
	fun[1].type = 'S';
	fun[1].ptr = &ft_printf_ss;
	fun[2].type = 'p';
	fun[2].ptr = &ft_printf_p;
	fun[3].type = 'd';
	fun[3].ptr = &ft_printf_d;
	fun[4].type = 'D';
	fun[4].ptr = &ft_printf_dd;
	fun[5].type = 'i';
	fun[5].ptr = &ft_printf_i;
	fun[6].type = 'o';
	fun[6].ptr = &ft_printf_o;
	fun[7].type = 'O';
	fun[7].ptr = &ft_printf_oo;
	fun[8].type = 'u';
	fun[8].ptr = &ft_printf_u;
	fun[9].type = 'U';
	fun[9].ptr = &ft_printf_uu;
	return (init_fun2(fun));
}

int		inner_fun(va_list ap, t_tab *tab, t_fun *fun)
{
	if (is_inc(tab->type, "sSpdDioOuUxXcC"))
		return (divide_case(ap, tab, fun));
	else
		return (ft_printf_other(tab));
}

int		ft_printf(const char *fmt, ...)
{
	va_list			ap;
	va_list			ap2;
	static t_tab	tab[9];
	int				t[2];
	t_fun			fun[14];

	t[1] = 0;
	va_start(ap, fmt);
	while (*fmt && init_fun(fun))
	{
		t[0] = 0;
		va_copy(ap2, ap);
		if (inner_inner(fmt, ap2, tab))
			return (-1);
		t[0] += print_string(fmt, '%', FIL);
		t[1] += t[0];
		fmt += t[0];
		if (*fmt == '%' && fmt++)
		{
			fmt += parse_handler(fmt, tab);
			t[1] += inner_fun(ap, tab, fun);
		}
	}
	va_end(ap);
	return (t[1]);
}
