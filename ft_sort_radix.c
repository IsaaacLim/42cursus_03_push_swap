#include "push_swap.h"

/*
** Copies stack into an array
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
