/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 11:44:11 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 11:05:00 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		main()
{
	void *ptr;
	ft_printf("metadata : %lu\n", sizeof(t_metadata));
	ft_printf("metapage : %lu\n", sizeof(t_metapage));
	ft_printf("allocated : %lu\n", sizeof(t_allocated));
	
	ptr = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return (1);
}
