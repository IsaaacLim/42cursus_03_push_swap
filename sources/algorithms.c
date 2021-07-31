#include "push_swap.h"

/*
** If numbers given <= 3,
**	sort manually based on the 5 possible (max) combinations 
*/
void	ft_sort_xs(t_list **stack_a, t_list **stack_b)
{
	int	largest_lst_pos;
	int	smallest_lst_pos;

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
** If 4 <= numbers given <= 5,
**	Push top 2 numbers from stack_a to stack_b
**	Sort stack_a with ft_sort_xs
**	Push stack_b top number to correct location in stack_a (ft_onTopOf_ascending)
**	Repeat once more for the remaining number in stack_b
**	Rotate stack_a to an ascending order
*/
void	ft_sort_s(t_list **stack_a, t_list **stack_b)
{
	int	before_stack_a;
	int	lst_mid;

	ft_sort("pb", stack_a, stack_b);
	ft_sort("pb", stack_a, stack_b);
	ft_sort_xs(stack_a, stack_b);
	while (*stack_b)
	{
		before_stack_a = ft_onTopOf_ascending(*stack_a, (*stack_b)->num);
		lst_mid = ft_middle_lst_pos(*stack_a);
		if ((*stack_a)->num == before_stack_a)
			ft_sort("pa", stack_a, stack_b);
		else if (before_stack_a <= lst_mid)
			ft_sort("ra", stack_a, stack_b);
		else if (before_stack_a > lst_mid)
			ft_sort("rra", stack_a, stack_b);
	}
	lst_mid = ft_middle_lst_pos(*stack_a);
	while ((*stack_a)->num != ft_smallest(*stack_a))
	{
		if (ft_smallest_lst_pos(*stack_a) <= lst_mid)
			ft_sort("ra", stack_a, stack_b);
		else if (ft_smallest_lst_pos(*stack_a) > lst_mid)
			ft_sort("rra", stack_a, stack_b);
	}
}

/*
** Radix Sort with base 2 (If numbers given >= 6)
**	Mod: stack_b numbers that are going to be pushed back will remain there
**	1. Substitude numbers in stack with 0 -> Max_Number_Count
**	2. Find the number of bits of the biggest number (the list size - 1)
**	3. Stack_a: Push numbers with bit '0' to stack_b at bit's nth position
**	4. Stack_b: Push numbers with bit '1' to stack_a at bit's nth + 1 position
**	5. Repeat Steps 3&4 while shifting the bit's nth position to the left
**		until the max number of bits (biggest number)
**	6. Push all numbers from stack_b to stack_a
*/
void	ft_sort_radix(t_list **stack_a, t_list **stack_b)
{
	int	max_num;
	int	max_bits;
	int	i;

	ft_substitudeNum(stack_a);
	max_num = ft_lstsize(*stack_a) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		ft_pushStack(stack_a, stack_b, i, 'a');
		if (i + 1 != max_bits)
			ft_pushStack(stack_a, stack_b, i, 'b');
		i++;
	}
	while (*stack_b)
		ft_sort("pa", stack_a, stack_b);
}
