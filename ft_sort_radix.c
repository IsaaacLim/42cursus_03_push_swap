#include "push_swap.h"

int	*ft_copyStack(t_list *lst)
{
	int *array;
	int	lst_size;
	int	i;

	lst_size = ft_lstsize(lst);
	array = (int *)malloc(lst_size * sizeof(int));
	if (!array)
	{
		ft_putstr_fd("Error: Malloc @ ft_copyStack\n", 2);
		ft_lstclear(&lst);
		exit (0);
	}
	i = 0;
	while (lst)
	{
		array[i] = lst->num;
		lst = lst->next;
		i++;
	}
	return (array);
}

void	ft_substitudeNum(t_list **stack_a, int *array)
{
	int	lst_size;
	int i;
	t_list *head;

	lst_size = ft_lstsize(*stack_a);
	ft_quicksort(array, 0, lst_size - 1);
	head = *stack_a;
	while (*stack_a)
	{
		i = 0;
		while (i < lst_size && (*stack_a)->num != array[i])
			i++;
		(*stack_a)->num = i;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = head;
}

void	ft_sort_radix(t_list **stack_a, t_list **stack_b)
{
	int *array;
	int	max_num;
	int	max_bits;
	int i;
	int j;

	array = ft_copyStack(*stack_a);
	ft_substitudeNum(stack_a, array);
	max_num = ft_lstsize(*stack_a) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	// i = 0;
	// while (i < max_bits)
	// {
	// 	j = 0;
	// 	while (j <= max_num )
	// 	{
	// 		if ((((*stack_a)->num >> i) & 1) == 0)
	// 			ft_sort("pb", stack_a, stack_b);
	// 		else
	// 			ft_sort("ra", stack_a, stack_b);
	// 		j++;
	// 	}
	// 	while (*stack_b)
	// 		ft_sort("pa", stack_a, stack_b);
	// 	i++;
	// }

	// int lst_size_a;
	// int lst_size_b;
	// i = 0;
	// while (i < max_bits)
	// {
	// 	j = 0;
	// 	lst_size_a = ft_lstsize(*stack_a);
	// 	while (j < lst_size_a)
	// 	{
	// 		if ((((*stack_a)->num >> i) & 1) == 0)
	// 			ft_sort("pb", stack_a, stack_b);
	// 		else
	// 			ft_sort("ra", stack_a, stack_b);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	lst_size_b = ft_lstsize(*stack_b);
	// 	while (j < lst_size_b)
	// 	{
	// 		if ((i + 1) == max_bits)
	// 			ft_sort("pa", stack_a, stack_b);
	// 		else if ((((*stack_b)->num >> (i + 1)) & 1) == 1)
	// 			ft_sort("pa", stack_a, stack_b);
	// 		else
	// 			ft_sort("rb", stack_a, stack_b);
	// 		j++;
	// 	}
	// 	i++;
	// }

	int lst_size_a;
	int lst_size_b;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		lst_size_a = ft_lstsize(*stack_a);
		while (j < lst_size_a)
		{
			if ((((*stack_a)->num >> i) & 1) == 0)
				ft_sort("pb", stack_a, stack_b);
			else
				ft_sort("ra", stack_a, stack_b);
			j++;
		}
		// ft_putstr_fd("\nStack_b:\t", 1);
		// ft_putlst(*stack_b);
		// ft_putchar_fd('\n', 1);
		j = 0;
		lst_size_b = ft_lstsize(*stack_b);
		while (j < lst_size_b)
		{
			if ((i + 1) == max_bits)
				ft_sort("pa", stack_a, stack_b);
			else if ((((*stack_b)->num >> (i + 1)) & 1) == 1)
				ft_sort("pa", stack_a, stack_b);
			else
				ft_sort("rb", stack_a, stack_b);
			j++;
		}
		// ft_putstr_fd("\nStack_a:\t", 1);
		// ft_putlst(*stack_a);
		// ft_putstr_fd("\nStack_b:\t", 1);
		// ft_putlst(*stack_b);
		// ft_putchar_fd('\n', 1);
		i++;
	}



	// printf("Max_num:\t%d Max_bits: %d\n", max_num, max_bits);
	// printf("Stack copy:\t");
	// for (int g = 0; array[g]; g++)
	// 	printf("%d ", array[g]);
	// printf("\n");

	free(array);
}
