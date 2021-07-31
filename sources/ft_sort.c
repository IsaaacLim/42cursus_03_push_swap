#include "push_swap.h"
#include "libft.h"

void	ft_sort_push(t_list **lst_from, t_list **lst_to)
{
	t_list	*from_first;
	t_list	*from_second;

	if (!(lst_from && *lst_from && lst_to))
		return ;
	from_first = ft_lstnew((*lst_from)->num);
	ft_lstadd_front(lst_to, from_first);
	from_second = (*lst_from)->next;
	ft_lstdelone(*lst_from);
	*lst_from = from_second;
}

void	ft_sort_rotate(t_list **lst)
{
	t_list	*second;
	t_list	*last;

	if (!(lst && *lst && (*lst)->next))
		return ;
	second = (*lst)->next;
	last = ft_lstlast(*lst);
	(*lst)->next = NULL;
	last->next = *lst;
	*lst = second;
}

void	ft_sort_rotate_rev(t_list **lst)
{
	t_list	*before_last;
	t_list	*last;

	if (!(lst && *lst && (*lst)->next))
		return ;
	last = ft_lstlast(*lst);
	before_last = *lst;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	ft_sort_swap(t_list **lst)
{
	t_list	*second;
	t_list	*third;

	if (!(lst && *lst && (*lst)->next))
		return ;
	second = (*lst)->next;
	third = ((*lst)->next)->next;
	(*lst)->next = third;
	second->next = *lst;
	*lst = second;
}

/*
**ft_strncmp: if string exist, return == 0, else > 0
*/
void	ft_sort(char *sort, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strncmp("sa", sort, 2) && ft_strncmp("ss", sort, 2)))
		ft_sort_swap(stack_a);
	if (!(ft_strncmp("sb", sort, 2) && ft_strncmp("ss", sort, 2)))
		ft_sort_swap(stack_b);
	if (!(ft_strncmp("pa", sort, 2)))
		ft_sort_push(stack_b, stack_a);
	if (!(ft_strncmp("pb", sort, 2)))
		ft_sort_push(stack_a, stack_b);
	if (!(ft_strncmp("ra", sort, 2) && ft_strncmp("rr", sort, 3)))
		ft_sort_rotate(stack_a);
	if (!(ft_strncmp("rb", sort, 2) && ft_strncmp("rr", sort, 3)))
		ft_sort_rotate(stack_b);
	if (!(ft_strncmp("rra", sort, 3) && ft_strncmp("rrr", sort, 3)))
		ft_sort_rotate_rev(stack_a);
	if (!(ft_strncmp("rrb", sort, 3) && ft_strncmp("rrr", sort, 3)))
		ft_sort_rotate_rev(stack_b);
	ft_putstr_fd(sort, 1);
	ft_putchar_fd('\n', 1);
}
