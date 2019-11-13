/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 13:16:09 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 13:48:18 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/malloc.h"

int	main()
{
	void	*ptr1;
	void	*ptr2;
	void	*ptr3;
	void	*ptr4;
	void	*ptr5;
	void	*ptr6;
	void	*ptr7;
	void	*ptr8;
	void	*ptr9;
	void	*ptr10;
	void	*ptr11;

	ptr1 = malloc(16);
	ptr2 = malloc(16);
	ptr3 = malloc(16);
	ptr4 = malloc(16);
	ptr5 = malloc(16);
	ptr6 = malloc(16);
	ptr7 = malloc(16);
	ptr8 = malloc(16);
	ptr9 = malloc(16);
	ptr10 = malloc(16);
	ptr11 = malloc(16);
	show_alloc_mem();
	ft_printf("\n\n");
	free(ptr4);
	free(ptr5);
	free(ptr6);
//	void	*ptr;
//	void	*ptr1;
//
//	for (int i = 0; i < 2048; i++)
//		ptr1 = malloc(8160);
//	ptr = malloc(1024);
//	free(ptr1);
//
//	return (1);
}
