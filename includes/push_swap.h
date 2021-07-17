#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h> //REMOVE

//algorithms.c
void	ft_sort_xs(t_list **stack_a, t_list **stack_b);
void	ft_sort_s(t_list **stack_a, t_list **stack_b);
void	ft_sort_insertion(t_list **stack_a, t_list **stack_b);

//ft_sort.c
void	ft_sort(char *sort, t_list **stack_a, t_list **stack_b);
void	ft_sort_push(t_list **lst_from, t_list **lst_to);
void	ft_sort_rotate(t_list **lst);
void	ft_sort_rotate_rev(t_list **lst);
void	ft_sort_swap(t_list **lst);

//lst_evalutate.c
bool	ft_is_sorted(t_list *lst);
int		ft_largest(t_list *lst);
int		ft_largest_lst_pos(t_list *lst);
int		ft_smallest(t_list *lst);
int		ft_smallest_lst_pos(t_list *lst);
int		ft_middle_lst_pos(t_list *stack_a);

//Unsure where to place
int ft_before_stack_a(t_list *stack_a, int stack_b_top);

//extra
void	ft_putlst(t_list *lst);

#endif
