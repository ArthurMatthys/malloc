/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:05:29 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/10 13:13:25 by amatthys    ###    #+. /#+    ###.fr     */
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

# define TINY_SIZE 1024
# define TINY_BLOCK_SIZE TINY_SIZE * getpagesize()

# define SMALL_SIZE 4096
# define SMALL_BLOCK_SIZE SMALL_SIZE * getpagesize()

# define TINY 0
# define SMALL 1
# define LARGE 2

# define CONSTRUCTOR void	__attribute__((constructor))
# define DESTRUCTOR void	__attribute__((destructor))

CONSTRUCTOR					calledfirst(void);
DESTRUCTOR					calledlast(void);

/*
** Metadata to put before an allocated memory
*/

typedef struct				s_metadata
{
	char					freed;
	size_t					size;
	struct s_metadata		*previous;
	struct s_metadata		*next;
}							t_metadata;

/*
** Metadata to put at the start of a page
*/

typedef struct				s_metablock
{
	int						type;
	size_t					size;
	struct s_metablock		*previous;
	struct s_metablock		*next;
}							t_metablock;

/*
** Global used to store which memory has been aloocated
*/

t_metablock *g_data[3];

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
int							find_area(t_metablock *block, void *ptr);
void						*do_mmap(size_t size, int type);
void						*find_block(t_metablock *block,
		size_t size, int type);
void						update_data(t_metadata *data,
		size_t size, int type);

#endif
