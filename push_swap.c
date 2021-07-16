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

t_list	*ft_next(t_list *lst)
{
	if (!lst->next)
		return (lst);
	lst = lst->next;
	return (lst);
}

void	ft_sort_swap(t_list **lst)
{
	t_list	*second;
	t_list	*third;

	if (!(lst && *lst && (*lst)->next))
		return;
	second = ft_next(*lst);
	third = ((*lst)->next)->next;
	(*lst)->next = third;
	second->next = *lst;
	*lst = second;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*new;
	// t_list	*top;

	if (argc < 2)
		return (0);
	// stack_a = (t_list *)ft_calloc(1, sizeof(t_list));
	// if (!stack_a)
		// return (-1);
	// top = NULL;
	// top->next = stack_a;
	stack_a = NULL;
	argv++;
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
	ft_putchar_fd('\n', 1);
	ft_putlst(stack_a);
	ft_putchar_fd('\n', 1);
	ft_sort_swap(&stack_a);
	ft_putlst(stack_a);
	ft_putchar_fd('\n', 1);
	ft_lstclear(&stack_a);
	// free(stack_a);
}
