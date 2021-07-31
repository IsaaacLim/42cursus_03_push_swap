#include "push_swap.h"

/*
** Find the number in stack_a where stack_b top number should be placed 
** 		on top of (it is next number bigger than stack_b top number)
**	Used by ft_sort_s
*/
int	ft_onTopOf_ascending(t_list *lst_to, int num_from)
{
	int		onTopOf;
	int		smallest;
	int		stack_ori;
	t_list	*temp;

	stack_ori = lst_to->num;
	smallest = ft_smallest(lst_to);
	while (lst_to->num != smallest)
		ft_sort_rotate(&lst_to);
	temp = lst_to;
	while (temp && num_from > temp->num)
		temp = temp->next;
	if (temp)
		onTopOf = temp->num;
	else
		onTopOf = smallest;
	while (lst_to->num != stack_ori)
		ft_sort_rotate_rev(&lst_to);
	return (onTopOf);
}

/*
** Copies stack into an array
*/
static int	*ft_copyStack(t_list *lst)
{
	int	*array;
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

/*
** Substitude numbers in stack
**	Used ft_quicksort to get the order (ascending) of each number
**	Replaced them with 0 -> Max_Number_Count
** Used by ft_sort_radix
*/
void	ft_substitudeNum(t_list **stack_a)
{
	t_list	*head;
	int		*array;
	int		lst_size;
	int		i;

	array = ft_copyStack(*stack_a);
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
	free(array);
}

/*
** Used by ft_sort_radix
** 	Stack_a: Push numbers with bit '0' to stack_b at bit's nth position
** 	Stack_b: Push numbers with bit '1' to stack_a at bit's nth + 1 position
*/
void	ft_pushStack(t_list **stack_a, t_list **stack_b, int i, char lst)
{
	int	lst_size;
	int	j;

	if (lst == 'a')
		lst_size = ft_lstsize(*stack_a);
	else if (lst == 'b')
		lst_size = ft_lstsize(*stack_b);
	j = -1;
	while (++j < lst_size)
	{
		if (lst == 'a')
		{
			if ((((*stack_a)->num >> i) & 1) == 0)
				ft_sort("pb", stack_a, stack_b);
			else
				ft_sort("ra", stack_a, stack_b);
		}
		else if (lst == 'b')
		{
			if ((((*stack_b)->num >> (i + 1)) & 1) == 1)
				ft_sort("pa", stack_a, stack_b);
			else
				ft_sort("rb", stack_a, stack_b);
		}
	}
}
