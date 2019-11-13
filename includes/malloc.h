/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:29 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 17:09:19 by amatthys    ###    #+. /#+    ###.fr     */
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

# define TINY 0
# define SMALL 1
# define LARGE 2

# define FIND_ALLOC 0
# define FIND_ROOM 1

/*
** Metadata to put before an allocated memory
*/

typedef struct				s_metadata
{
	struct s_metadata		*previous;
	struct s_metadata		*next;
	size_t					size;
	char					freed;
}							t_metadata;

/*
** Metadata to put at the start of a page
*/

typedef struct				s_metablock
{
	struct s_metablock		*previous;
	struct s_metablock		*next;
	size_t					size;
	int						type;
}							t_metablock;

/*
** Global used to store which memory has been aloocated
*/

void *g_data[3];

/*
** Size of Tiny area : 2 Mo. Soit assez d'espace pour 2048 Tiny.
** Size of Small area : 16 Mo. Soit assez d'espace pour 2048 Small.
*/

# define TINY_SIZE 1024
# define TINY_BLOCK_SIZE getpagesize() * 512

# define SMALL_SIZE 8192
# define SMALL_BLOCK_SIZE getpagesize() * 4096

/*
** Store a function regarding its index
*/

typedef void				*(*t_dispatcher)();

void						*malloc(size_t size);
void						*calloc(size_t count, size_t size);
void						*realloc(void *ptr, size_t size);
void						free(void *ptr);
void						show_alloc_mem(void);

/*
** Dispatch functions
*/

void						*handle_tiny(size_t size, int type);
void						*handle_small(size_t size, int type);
void						*handle_large(size_t size, int type);

/*
** Utils malloc
*/

size_t						round_up(size_t start, size_t to_round);
int							get_type(size_t size);
void						*do_mmap(size_t size_alloc, int type);
t_metadata					*find_alloc(void *ptr);
t_metadata					*find_block(t_metablock *block,
		void *ptr, int fun, size_t size);
t_metadata					*find_metadata(t_metadata *data,
		void *ptr, int fun, size_t size);
void						update_data(t_metadata *data,
		size_t size, int type);

#endif
