#ifndef FT_SH_H
# define FT_SH_H

# include <term.h>

# include "libft.h"
# include "ft_printf.h"

# define ESC 0x1b
# define RET 0xa
# define RIGHT 0x435b1b
# define LEFT 0x445b1b
# define UP 0x415b1b
# define DOWN 0x425b1b
# define DEL_1 0x7f
# define DEL_2 0x7e335b1b

# define KEY(x) ((t_key*)(x->content))->key

# define V_DEL(x) (void(*)(void*, size_t))x

typedef struct	s_key
{
	int	key;
}		t_key;

typedef struct	s_sh
{
	t_dlist	*lst_key;
	int	index;
}		t_sh;

int	putit(int c);
t_sh	*ret_data(void);
int	init_term(t_sh *data);
int	get_key(t_sh *data);
void	del_data(t_sh *data, size_t ct_size);
void	del_key(t_key *ct, size_t ct_size);

#endif
