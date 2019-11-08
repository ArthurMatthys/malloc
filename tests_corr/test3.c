/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test3.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 13:28:44 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 13:33:05 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <unistd.h>

#define M (1024 * 1024)

void	print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr1;
	char *addr3;

	addr1 = (char*)malloc(16 * M);
	ft_printf("yo %p\n", addr1);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)realloc(addr1, 128*M);
	addr3[127 * M] = 42;
	print(addr3);
	return (0);
}
