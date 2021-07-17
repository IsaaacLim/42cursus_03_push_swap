#include "push_swap.h"
#include <stdbool.h>

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
