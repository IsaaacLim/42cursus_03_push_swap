#include "push_swap.h"
#include "libft.h"

void	ft_putlst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_fd(lst->num, 1);
		ft_putchar_fd(' ', 1);
		lst = lst->next;
	}
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new;
	// t_list	*top;

	if (argc < 2)
		return (0);
	// stack_a = (t_list *)ft_calloc(1, sizeof(t_list));
	// if (!stack_a)
		// return (-1);
	// top = NULL;
	// top->next = 
	stack_a = NULL;
	stack_b = NULL;
	argv++;
	ft_putstr_fd("\nArgv:\t\t", 1);
	while (*argv)
	{
		new = ft_lstnew(ft_atoi(*argv));
		// if (top->next == NULL)
		// if (top == NULL)
			// top = new;
		ft_putnbr_fd(new->num, 1);
		ft_lstadd_back(&stack_a, new);
		// ft_lstdelone(new);
		ft_putchar_fd(' ', 1);
		argv++;
	}
	ft_putstr_fd("\nStack_a:\t", 1);
	ft_putlst(stack_a);

	ft_sort_swap(&stack_a);
	ft_putstr_fd("\nsa:\t\t", 1);
	ft_putlst(stack_a);

	ft_sort_push(&stack_a, &stack_b);
	ft_putstr_fd("\npb_a:\t\t", 1);
	ft_putlst(stack_a);
	ft_putstr_fd("\npb_b:\t\t", 1);
	ft_putlst(stack_b);

	ft_sort_rotate(&stack_a);
	ft_putstr_fd("\nra:\t\t", 1);
	ft_putlst(stack_a);

	ft_sort_rotate_rev(&stack_a);
	ft_putstr_fd("\nrra:\t\t", 1);
	ft_putlst(stack_a);

	ft_putchar_fd('\n', 1);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	// free(stack_a);
}
