#include "push_swap.h"

/*
** Copies stack into an array
**	Used by ft_sort_radix @ ft_substitudeNum
*/
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
