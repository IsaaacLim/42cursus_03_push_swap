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

	array = ft_copyStack(*stack_a);
	ft_substitudeNum(stack_a, array);




	printf("Stack copy:\t");
	for (int g = 0; array[g]; g++)
		printf("%d ", array[g]);
	printf("\n");

	free(array);

	(void) stack_b;
}
