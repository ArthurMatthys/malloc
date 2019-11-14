/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test5.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 16:18:13 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 09:52:18 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/malloc.h"

int	main(void)
{
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;
	void	*ptr5;

	ptr1 = malloc(1024);
	ptr2 = malloc(1024 * 32);
	ptr3 = malloc(1024 * 1024);
	ptr4 = malloc(1024 * 1024 * 16);
	ptr5 = malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}
