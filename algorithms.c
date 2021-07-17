#include "push_swap.h"

/*
** If numbers given are less than 3,
**	sort manually based on the 5 possible (max) combinations 
*/
void	ft_sort_xs(t_list **stack_a, t_list **stack_b)
{
	int largest_lst_pos;
	int smallest_lst_pos;

	if (ft_is_sorted(*stack_a))
		return ;
	smallest_lst_pos = ft_smallest_lst_pos(*stack_a);
	largest_lst_pos = ft_largest_lst_pos(*stack_a);
	if (largest_lst_pos == 1 && smallest_lst_pos == 2)
		ft_sort("ra", stack_a, stack_b);
	else if (largest_lst_pos == 2 && smallest_lst_pos == 3)
		ft_sort("rra", stack_a, stack_b);
	else
		ft_sort("sa", stack_a, stack_b);
	ft_sort_xs(stack_a, stack_b); 
}

/*
** Mimics Insertion Sort
**	Rotate smallest number in stack_a to the top
**	Push stack_a number to stack_b
**	Repeat until stack_a is empty
**	Push stack_b back to stack_a until empty
*/
void	ft_sort_insertion(t_list **stack_a, t_list **stack_b)
{
	int	smallest;
	int smallest_lst_pos;
	int lst_mid;

	while (*stack_a)
	{
		smallest = ft_smallest(*stack_a);
		smallest_lst_pos = ft_smallest_lst_pos(*stack_a);
		lst_mid = ft_middle_lst_pos(*stack_a);
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
