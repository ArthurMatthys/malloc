/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/10 14:06:57 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 18:18:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <inttypes.h>
# include "libft.h"
# define FIL 1

typedef struct		s_tab
{
	char			type;
	int				len;
	int				sign;
	int				side;
	int				fill;
	int				width;
	int				w;
	int				acc;
	int				conv;
}					t_tab;

typedef struct		s_fun
{
	char			type;
	int				(*ptr)();
}					t_fun;

int					ft_printf(const char *fmt, ...);
int					parse_handler(const char *str, t_tab *tab);
int					divide_case(va_list ap, t_tab *tab, t_fun *fun);

int					is_inc(const char str, const char *test);
int					ft_printf_s(va_list ap, t_tab *tab);
int					ft_printf_ss(va_list ap, t_tab *tab);
int					ft_printf_p(va_list ap, t_tab *tab);
int					ft_printf_d(va_list ap, t_tab *tab);
int					ft_printf_dd(va_list ap, t_tab *tab);
int					ft_printf_i(va_list ap, t_tab *tab);
int					ft_printf_o(va_list ap, t_tab *tab);
int					ft_printf_oo(va_list ap, t_tab *tab);
int					ft_printf_u(va_list ap, t_tab *tab);
int					ft_printf_uu(va_list ap, t_tab *tab);
int					ft_printf_x(va_list ap, t_tab *tab);
int					ft_printf_xx(va_list ap, t_tab *tab);
int					ft_printf_c(va_list ap, t_tab *tab);
int					ft_printf_cc(va_list ap, t_tab *tab);
int					ft_printf_other(t_tab *tab);

int					inner_inner(const char *fmt, va_list ap2, t_tab *tab);
char				*ft_strchr(const char *str, int c);
int					wchar_len(wchar_t c);
int					is_ok(wchar_t c);
int					is_wstr_ok(wchar_t *str, t_tab *tab);
int					check_next(const char *fmt, va_list ap, t_tab *tab);

char				*ft_atoi_base(intmax_t i, char *base,
					t_tab *tab, char *str);
char				*ft_uatoi_base(uintmax_t i, char *base,
					t_tab *tab, char *str);
int					min(int a, int b);
int					max(int a, int b);
int					abs(int a);

int					print_string(const char *str, char c, int fd);
int					ft_intputstr_def(char *str, t_tab *tab, int fd);
int					ft_putstr_def(char *str, t_tab *tab, int fd);
int					ft_putwstr_def(wchar_t *str, t_tab *tab, int fd);
int					ft_putwchar_fd(wchar_t c, int fd);

#endif
