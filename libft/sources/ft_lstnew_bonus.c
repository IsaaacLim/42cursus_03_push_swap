#include "libft.h"

t_list	*ft_lstnew(int num)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->num = num;
	temp->next = NULL;
	return (temp);
}
