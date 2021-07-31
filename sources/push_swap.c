#include "push_swap.h"
#include "libft.h" //remove

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_createStack(&stack_a, argv);
	if (!(ft_is_sorted(stack_a)))
	{
		if (ft_lstsize(stack_a) <= 3)
			ft_sort_xs(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) <= 5)
			ft_sort_s(&stack_a, &stack_b);
		else
			ft_sort_radix(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

	// ft_putstr_fd("Stack_a:\t", 1);
	// ft_putlst(stack_a);
	// ft_putstr_fd("\nStack_b:\t", 1);
	// ft_putlst(stack_b);
	// ft_putchar_fd('\n', 1);
