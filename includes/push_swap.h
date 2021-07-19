#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>
# include <stdio.h> //REMOVE

//algo_utils.c
int ft_onTopOf_ascending(t_list *lst_to, int num_from);
int	*ft_copyStack(t_list *lst);

//algorithms.c
void	ft_sort_xs(t_list **stack_a, t_list **stack_b);
void	ft_sort_s(t_list **stack_a, t_list **stack_b);
void	ft_sort_radix(t_list **stack_a, t_list **stack_b);

//eval_lst.c
bool	ft_is_sorted(t_list *lst);
int		ft_smallest(t_list *lst);
int		ft_smallest_lst_pos(t_list *lst);
int		ft_middle_lst_pos(t_list *stack_a);
int		ft_largest_lst_pos(t_list *lst);

//ft_quicksort.c
void	ft_quicksort(int *a, int start, int end);

//ft_sort.c
void	ft_sort(char *sort, t_list **stack_a, t_list **stack_b);
void	ft_sort_push(t_list **lst_from, t_list **lst_to);
void	ft_sort_rotate(t_list **lst);
void	ft_sort_rotate_rev(t_list **lst);
void	ft_sort_swap(t_list **lst);

//extra
void	ft_putlst(t_list *lst);

#endif
