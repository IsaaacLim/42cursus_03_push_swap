#include "push_swap.h"
#include <stdbool.h>

/*
** Checks if list is sorted
*/
bool	ft_is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->num > (lst->next)->num)
			return (false);
		lst = lst->next;
	}
	return (true);
}

/*
** Returns the smallest value in the list
*/
int	ft_smallest(t_list *lst)
{
	int smallest;

	smallest = lst->num;
	lst = lst->next;
	while (lst)
	{
		if (lst->num < smallest)
			smallest = lst->num;
		lst = lst->next;
	}
	return (smallest);
}

/*
** Returns the position of the smallest value in the list
*/
int	ft_smallest_lst_pos(t_list *lst)
{
	int lst_pos;
	int smallest;
	int	smallest_lst_pos;

	smallest = lst->num;
	smallest_lst_pos = 1;
	lst = lst->next;
	lst_pos = 2;
	while (lst)
	{
		if (lst->num < smallest)
		{
			smallest = lst->num;
			smallest_lst_pos = lst_pos; 
		}
		lst = lst->next;
		lst_pos++;
	}
	return (smallest_lst_pos);
}

/*
** Returns the middle position of the list (unsorted / sorted)
**	If even number, the middle is rounded down
*/
int	ft_middle_lst_pos(t_list *stack_a)
{
	int lst_size;
	int lst_mid;

	lst_size = ft_lstsize(stack_a);
	lst_mid = lst_size / 2;
	if (lst_size % 2 != 0)
		lst_mid += 1;
	return (lst_mid);
}

/*
** Returns the position of the largest value in the list
*/
int	ft_largest_lst_pos(t_list *lst)
{
	int lst_pos;
	int largest;
	int largest_lst_pos;

	largest = lst->num;
	largest_lst_pos = 1;
	lst = lst->next;
	lst_pos = 2;
	while (lst)
	{
		if (lst->num > largest)
		{
			largest = lst->num;
			largest_lst_pos = lst_pos; 
		}
		lst = lst->next;
		lst_pos++;
	}
	return (largest_lst_pos);
}
