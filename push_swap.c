#include "push_swap.h"
#include "libft.h"
#include "stdbool.h"
#include "limits.h"
#include <stdio.h> //REMOVE

void	ft_putlst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_fd(lst->num, 1);
		ft_putchar_fd(' ', 1);
		lst = lst->next;
	}
}

bool	ft_check_input(char *argv, t_list *lst)
{
	int		flag;
	long	tot;
	int		i;

	i = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == ' ')
		i++;
	flag = 1;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			flag *= -1;
		i++;
	}
	tot = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
		tot = tot * 10 + (argv[i++] - '0');
	tot *= flag;
	while (lst && tot != lst->num)
		lst = lst->next;
	if (lst || argv[i] || tot > INT_MAX || tot < INT_MIN)
		return (false);
	else
		return (true);
}

void	ft_largest(t_list *lst, int *largest, int *largest_lst_pos)
{
	int lst_pos;

	if (!lst)
		return ;
	*largest = lst->num;
	*largest_lst_pos = 1;
	lst = lst->next;
	lst_pos = 2;
	while (lst)
	{
		if (lst->num > *largest)
		{
			*largest = lst->num;
			*largest_lst_pos = lst_pos; 
		}
		lst = lst->next;
		lst_pos++;
	}
}

void	ft_smallest(t_list *lst, int *smallest, int *smallest_lst_pos)
{
	int lst_pos;

	if (!lst)
		return ;
	*smallest = lst->num;
	*smallest_lst_pos = 1;
	lst = lst->next;
	lst_pos = 2;
	while (lst)
	{
		if (lst->num < *smallest)
		{
			*smallest = lst->num;
			*smallest_lst_pos = lst_pos; 
		}
		lst = lst->next;
		lst_pos++;
	}
}

void	ft_sort_1(t_list **stack_a, t_list **stack_b)
{
	int list_size;
	int	largest;
	int largest_lst_pos;
	int	smallest;
	int smallest_lst_pos;
	int lst_mid;

	ft_putchar_fd('\n', 1);
	while (*stack_a)
	{
		list_size = ft_lstsize(*stack_a);
		// printf("\nStack_a size:\t%d", list_size);
		ft_largest(*stack_a, &largest, &largest_lst_pos);
		ft_smallest(*stack_a, &smallest, &smallest_lst_pos);
		// printf("\nStack_a largest:%d", largest);
		// printf("\nStack_a L_pos:\t%d", largest_lst_pos);
		lst_mid = list_size / 2;
		if (list_size % 2 != 0)
			lst_mid++;
		while ((*stack_a)->num != smallest)
		{
			if ((*stack_a)->num > ((*stack_a)->next)->num)
				ft_sort("sa", stack_a, stack_b);
			else if (smallest_lst_pos <= lst_mid)
				ft_sort("ra", stack_a, stack_b);
			else if (smallest_lst_pos > lst_mid)
				ft_sort("rra", stack_a, stack_b);
		}
		ft_sort("pb", stack_a, stack_b);
	}
	while (*stack_b)
		ft_sort("pa", stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	ft_putstr_fd("\nArgv:\t\t", 1);
	while (argv[++i])
	{
		if (!(ft_check_input(argv[i], stack_a)))
		{
			ft_putstr_fd("\nError\n", 2);
			ft_lstclear(&stack_a);
			return (0);
		}
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_putnbr_fd(new->num, 1);
		ft_putchar_fd(' ', 1);
		ft_lstadd_back(&stack_a, new);
	}
	ft_putstr_fd("\nStack_a:\t", 1);
	ft_putlst(stack_a);

	// ft_sort_swap(&stack_a);
	// ft_putstr_fd("\nsa:\t\t", 1);
	// ft_putlst(stack_a);

	// ft_sort_push(&stack_a, &stack_b);
	// ft_putstr_fd("\npb_a:\t\t", 1);
	// ft_putlst(stack_a);
	// ft_putstr_fd("\npb_b:\t\t", 1);
	// ft_putlst(stack_b);

	// ft_sort_rotate(&stack_a);
	// ft_putstr_fd("\nra:\t\t", 1);
	// ft_putlst(stack_a);

	// ft_sort_rotate_rev(&stack_a);
	// ft_putstr_fd("\nrra:\t\t", 1);
	// ft_putlst(stack_a);

	ft_sort_1(&stack_a, &stack_b);
	ft_putstr_fd("\nSort 1:", 1);
	ft_putstr_fd("\nStack_a:\t", 1);
	ft_putlst(stack_a);
	ft_putstr_fd("\nStack_b:\t", 1);
	ft_putlst(stack_b);

	ft_putchar_fd('\n', 1);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	// free(stack_a);
}
