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
**	Push stack_b top number to correct location in stack_a (ft_before_stack_a)
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
		before_stack_a = ft_before_stack_a(*stack_a, (*stack_b)->num);
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

int	ft_chunk_max(t_list *stack_a, int chunk_size)
{
	int *array;
	int	lst_size;
	int	i;
	int	chunk_max;

	lst_size = ft_lstsize(stack_a);
	array = (int *)malloc(lst_size * sizeof(int));
	if (!array)
	{
		ft_putstr_fd("Error: ft_chunk_max\n", 2);
		ft_lstclear(&stack_a);
		exit (0);
	}
	i = 0;
	while (stack_a)
	{
		array[i] = stack_a->num;
		stack_a = stack_a->next;
		i++;
	}
	ft_quicksort(array, 0, lst_size - 1);
	chunk_max = array[chunk_size - 1];
	printf("Sorted array:\t"); //remove
	for (int j = 0; j < lst_size; j++) //remove
		printf("%d ", array[j]); //remove
	printf("\nChunk_max:\t%d\n", chunk_max); //remove
	free(array);
	return (chunk_max);
}

/*
** Counts the position from the front
** Count starts from 0
** If none found, position == lst_size
*/
int	ft_chunk_top_pos(t_list *stack_a, int chunk_max)
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
		{
			// printf("\nChunk_top:\t%d", stack_a->num); //remove
			return (chunk_top_pos - 1);
		}
		stack_a = stack_a->next;
		chunk_top_pos++;
	}
	return (lst_size);
}

/*
** Counts the position from the back
** Count starts from 1
** If none found, position == lst_size
*/
int	ft_chunk_bot_pos(t_list *stack_a, int chunk_max)
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
	// int temp = stack_a->num; //remove
	while (stack_a)
	{
		if (stack_a->num <= chunk_max)
		{
			chunk_bot_pos = pos;
			// temp = stack_a->num; //remove
		}
		stack_a = stack_a->next;
		pos++;
	}
	// printf("\nChunk_bot:\t%d", temp); //remove
	return (lst_size - chunk_bot_pos + 1);
}

void	ft_push_from_top(t_list **stack_a, t_list **stack_b, int chunk_max)
{
	int lst_mid_b;
	int	before_stack_b;

	while ((*stack_a)->num > chunk_max)
		ft_sort("ra", stack_a, stack_b);
	if (*stack_b)
	{
		before_stack_b = ft_onTopOf_decending(*stack_b, (*stack_a)->num);
		lst_mid_b = ft_middle_lst_pos(*stack_b);
		while ((*stack_b)->num != before_stack_b)
		{
			if (before_stack_b <= lst_mid_b)
				ft_sort("rb", stack_a, stack_b);
			else if (before_stack_b > lst_mid_b)
				ft_sort("rrb", stack_a, stack_b);
		}
	}
	ft_sort("pb", stack_a, stack_b);
}

void	ft_push_from_bottom(t_list **stack_a, t_list **stack_b, int chunk_max)
{
	int lst_mid_b;
	int	before_stack_b;

	while ((*stack_a)->num > chunk_max)
		ft_sort("rra", stack_a, stack_b);
	if (*stack_b) //gotta check that this works
	{
		before_stack_b = ft_onTopOf_decending(*stack_b, (*stack_a)->num); 
		lst_mid_b = ft_middle_lst_pos(*stack_b);
		while ((*stack_b)->num != before_stack_b)
		{
			if (before_stack_b <= lst_mid_b)
				ft_sort("rb", stack_a, stack_b);
			else if (before_stack_b > lst_mid_b)
				ft_sort("rrb", stack_a, stack_b);
		}
	}
	ft_sort("pb", stack_a, stack_b);
}

/*
** If 6 <= numbers given <= 100
*/ 
void	ft_sort_m(t_list **stack_a, t_list **stack_b)
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
			// printf ("\nChunk_top_pos:\t%d", chunk_top_pos); //remove
			// printf ("\nChunk_bot_pos:\t%d\n", chunk_bot_pos); //remove
			// printf ("\nList_size:\t%d\n", ft_lstsize(*stack_a)); //remove
			if (chunk_top_pos <= chunk_bot_pos && chunk_top_pos < ft_lstsize(*stack_a))
				ft_push_from_top(stack_a, stack_b, chunk_max);
			else if (chunk_bot_pos <= chunk_top_pos && chunk_bot_pos < ft_lstsize(*stack_a))
				ft_push_from_bottom(stack_a, stack_b, chunk_max);
		}
	}
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
