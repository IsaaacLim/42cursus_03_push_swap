#include "push_swap.h"
#include "libft.h"

void	ft_sort_push(t_list **lst_from, t_list **lst_to)
{
	t_list *from_first;
	t_list *from_second;

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
	t_list 	*last;

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
		return;
	second = (*lst)->next;
	third = ((*lst)->next)->next;
	(*lst)->next = third;
	second->next = *lst;
	*lst = second;
}
