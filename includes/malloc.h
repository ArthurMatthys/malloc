/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:29 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 08:02:41 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

/*
** CHUNK
** PAGE
**
**
**
*/

#define TINY_SIZE
#define TINY_PAGE_SIZE TINY_SIZE * getpagesize()
#define TINY

/*
** Metadata to put before an allocated memory
*/

typedef struct			s_metadata
{
	char				freed;
	size_t				size;
	struct s_metadata	*previous;
	struct s_metadata	*next;
}						t_metadata;

/*
** Metadata to put at the start of a page
*/

typedef struct			s_metapage
{
	size_t				max_size;
	size_t				size;
	struct s_metapage	*previous;
	struct s_metapage	*next;
}						t_metapage;

/*
** Global used to store which memory has been aloocated
*/

typedef struct			s_allocated
{
}						t_allocated;


void	*malloc(size_t size);
void	*calloc(size_t count, size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);

#endif
