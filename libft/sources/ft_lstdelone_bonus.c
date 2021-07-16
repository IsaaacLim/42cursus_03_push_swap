#include "libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		lst->num = 0;
		lst->next = NULL;
		free(lst);
	}
}
