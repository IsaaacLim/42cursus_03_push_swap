#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	ft_sort(char *sort, t_list **stack_a, t_list **stack_b);
void	ft_sort_push(t_list **lst_from, t_list **lst_to);
void	ft_sort_rotate(t_list **lst);
void	ft_sort_rotate_rev(t_list **lst);
void	ft_sort_swap(t_list **lst);

void	ft_putlst(t_list *lst);

#endif
