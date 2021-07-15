#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!(lst && *lst))
		return ;
	while (lst && *lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
}
