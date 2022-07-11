#include "push_swap.h"

/*
** Radix Sort with base 2 (other versions)
**	Method 1: Original method
**	Method 2: Keep numbers in stack_b that are 0 with next bit shift,
**		then only looked through the new numbers in stack_b
*/
void	ft_sort_radix(t_list **stack_a, t_list **stack_b)
{
	int *array;
	int	max_num;
	int	max_bits;
	int i;
	int j;

	array = ft_copyStack(*stack_a);
	ft_substitudeNum(stack_a, array);
	free(array);
	max_num = ft_lstsize(*stack_a) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;

	/**** Methiod 1 ****/
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

	/**** Method 2 ****/
	// int lst_size_a;
	// int lst_size_b;
	// int lst_size_b_new;
	// int lst_size_b_prev;
	// i = 0;
	// lst_size_b_prev = 0;
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
	// 	lst_size_b_new = lst_size_b - lst_size_b_prev;
	// 	while (j < lst_size_b_new && (i + 1) != max_bits)
	// 	{
	// 		if ((((*stack_b)->num >> (i + 1)) != 0))
	// 			ft_sort("pa", stack_a, stack_b);
	// 		else
	// 			ft_sort("rb", stack_a, stack_b);
	// 		j++;
	// 	}
	// 	while (ft_lstlast(*stack_b)->num != 0)
	// 		ft_sort("rrb", stack_a, stack_b);
	// 	lst_size_b_prev = ft_lstsize(*stack_b);
	// 	i++;
	// }
	// while (*stack_b)	
	// 	ft_sort("pa", stack_a, stack_b);
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
	int	smallest_lst_pos;
	int	lst_mid;

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

/*
**** All for Split Chunk Insertion Sort****
*/
/*
** Finds the biggest number in each chunk, using a sorted array
*/
static int	ft_chunk_max(t_list *stack_a, int chunk_size)
{
	int *array;
	int	lst_size;
	int	i;
	int	chunk_max;

	array = ft_copyStack(stack_a);
	ft_quicksort(array, 0, lst_size - 1);
	chunk_max = array[chunk_size - 1];
	free(array);
	return (chunk_max);
}

/*
** Counts the position from the front
** Count starts from 0
** If none found, position == lst_size
*/
static int	ft_chunk_top_pos(t_list *stack_a, int chunk_max)
{
	int	lst_size;
	int	lst_mid;
	int	chunk_top_pos;

	lst_size = ft_lstsize(stack_a);
	lst_mid = ft_middle_lst_pos(stack_a);
	chunk_top_pos = 1;
	while (chunk_top_pos <= lst_mid)
	{
		if (stack_a->num <= chunk_max)
			return (chunk_top_pos - 1);
		stack_a = stack_a->next;
		chunk_top_pos++;
	}
	return (lst_size);
}

/*
** Counts the position from the back
** Count starts from 1 (it takes one extra move to get last num to top)
** If none found, position == lst_size
*/
static int	ft_chunk_bot_pos(t_list *stack_a, int chunk_max)
{
	int lst_size;
	int	lst_mid;
	int	chunk_bot_pos;
	int	pos;

	lst_size = ft_lstsize(stack_a);
	lst_mid = ft_middle_lst_pos(stack_a);
	pos = 1;
	while (pos <= lst_mid)
	{
		stack_a = stack_a->next;
		pos++;
	}
	chunk_bot_pos = 1;
	while (stack_a)
	{
		if (stack_a->num <= chunk_max)
			chunk_bot_pos = pos;
		stack_a = stack_a->next;
		pos++;
	}
	return (lst_size - chunk_bot_pos + 1);
}

/*
** Returns the largest value in the list
*/
static int	ft_largest(t_list *lst)
{
	int largest;

	largest = lst->num;
	lst = lst->next;
	while (lst)
	{
		if (lst->num > largest)
			largest = lst->num;
		lst = lst->next;
	}
	return (largest);
}

/*
** Used to align stack_b in decending order when receiving numbers from stack_a
*/
static int	ft_onTopOf_decending(t_list *lst_to, int num_from)
{
	int		onTopOf;
	int		largest;
	int		stack_ori;
	t_list	*temp;
	
	stack_ori = lst_to->num;
	largest = ft_largest(lst_to);
	while (lst_to->num != largest)
		ft_sort_rotate(&lst_to);
	temp = lst_to;
	while (temp && num_from < temp->num)
		temp = temp->next;
	if (temp)
		onTopOf = temp->num;
	else
		onTopOf = largest;
	while (lst_to->num != stack_ori)
		ft_sort_rotate_rev(&lst_to);
	return (onTopOf);
}

/*
** Push stack_a from TOP
**	Place number on top of appropriate stack_b num
**	Stack_b rotated based on the shortest route
*/
static void	ft_push_from_top(t_list **stack_a, t_list **stack_b, int chunk_max)
{
	int lst_mid_b;
	int	onTopOf_stack_b;

	while ((*stack_a)->num > chunk_max)
		ft_sort("ra", stack_a, stack_b);
	if (*stack_b)
	{
		onTopOf_stack_b = ft_onTopOf_decending(*stack_b, (*stack_a)->num);
		lst_mid_b = ft_middle_lst_pos(*stack_b);
		while ((*stack_b)->num != onTopOf_stack_b)
		{
			if (onTopOf_stack_b <= lst_mid_b)
				ft_sort("rb", stack_a, stack_b);
			else if (onTopOf_stack_b > lst_mid_b)
				ft_sort("rrb", stack_a, stack_b);
		}
	}
	ft_sort("pb", stack_a, stack_b);
}

/*
** Push stack_a from BOTTOM
**	Place number on top of appropriate stack_b num
**	Stack_b rotated based on the shortest route
*/
static void	ft_push_from_bottom(t_list **stack_a, t_list **stack_b, int chunk_max)
{
	int lst_mid_b;
	int	onTopOf_stack_b;

	while ((*stack_a)->num > chunk_max)
		ft_sort("rra", stack_a, stack_b);
	if (*stack_b) //gotta check that this works
	{
		onTopOf_stack_b = ft_onTopOf_decending(*stack_b, (*stack_a)->num); 
		lst_mid_b = ft_middle_lst_pos(*stack_b);
		while ((*stack_b)->num != onTopOf_stack_b)
		{
			if (onTopOf_stack_b <= lst_mid_b)
				ft_sort("rb", stack_a, stack_b);
			else if (onTopOf_stack_b > lst_mid_b)
				ft_sort("rrb", stack_a, stack_b);
		}
	}
	ft_sort("pb", stack_a, stack_b);
}

/*
** Split chunk Insertion Sort
**	1. Stack_a nums are split into 5 groups,
**		each having numbers lower than the next group of numbers
**	2. Push stack_a in groups. ra/rra based on the closest number wanted
**	3. When 3 numbers remain, sort stack_a with ft_sort_xs
**	4. Push stack_b on top of appropriate stack_a num
**	5. Align stack_a so that smallest number is at the top
*/ 
void	ft_sort_SCinsertion(t_list **stack_a, t_list **stack_b)
{
	int chunk_size;
	int	chunk_max;
	int	chunk_top_pos;
	int	chunk_bot_pos;
	int	count;

	chunk_size = ft_lstsize(*stack_a) / 5;
	// if (chunk_size % 5 != 0)
	// 	return ; //FIGURE THIS OUT 
	while (ft_lstsize(*stack_a) > 3)
	{	
		count = chunk_size;
		chunk_max = ft_chunk_max(*stack_a, chunk_size);
		while (--count >= 0 && ft_lstsize(*stack_a) > 3)
		{
			chunk_top_pos = ft_chunk_top_pos(*stack_a, chunk_max);
			chunk_bot_pos = ft_chunk_bot_pos(*stack_a, chunk_max);
			if (chunk_top_pos <= chunk_bot_pos && chunk_top_pos < ft_lstsize(*stack_a))
				ft_push_from_top(stack_a, stack_b, chunk_max);
			else if (chunk_bot_pos <= chunk_top_pos && chunk_bot_pos < ft_lstsize(*stack_a))
				ft_push_from_bottom(stack_a, stack_b, chunk_max);
		}
	}
	ft_sort_xs(stack_a, stack_b);
	int onTopOf_stack_a;
	int	lst_mid_a;
	while (*stack_b)
	{
		onTopOf_stack_a = ft_onTopOf_ascending(*stack_a, (*stack_b)->num); 
		lst_mid_a = ft_middle_lst_pos(*stack_a);
		while ((*stack_a)->num != onTopOf_stack_a)
		{
			if (onTopOf_stack_a <= lst_mid_a)
				ft_sort("ra", stack_a, stack_b);
			else if (onTopOf_stack_a > lst_mid_a)
				ft_sort("rra", stack_a, stack_b);
		}
		ft_sort("pa", stack_a, stack_b);
	}
	int smallest;
	smallest = ft_smallest(*stack_a);
	lst_mid_a = ft_middle_lst_pos(*stack_a);
	while ((*stack_a)->num != smallest)
	{
		if (smallest <= lst_mid_a)
			ft_sort("ra", stack_a, stack_b);
		else if (smallest > lst_mid_a)
			ft_sort("rra", stack_a, stack_b);
	}
}
