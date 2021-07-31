#include "push_swap.h"
#include "libft.h"
#include "limits.h"

/*
** Used to print stack to stdout for verification
*/
void	ft_putlst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_fd(lst->num, 1);
		ft_putchar_fd(' ', 1);
		lst = lst->next;
	}
}

static bool	ft_check_input(char *argv, t_list *lst)
{
	int		flag;
	long	tot;
	int		i;

	i = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == ' ')
		i++;
	flag = 1;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			flag *= -1;
		i++;
	}
	tot = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
		tot = tot * 10 + (argv[i++] - '0');
	tot *= flag;
	while (lst && tot != lst->num)
		lst = lst->next;
	if (lst || argv[i] || tot > INT_MAX || tot < INT_MIN)
		return (false);
	else
		return (true);
}

void	ft_createStack(t_list **stack_a, char **argv)
{
	t_list	*new;
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (!(ft_check_input(argv[i], *stack_a)))
		{
			ft_putstr_fd("Error\n", 2);
			ft_lstclear(stack_a);
			exit (0);
		}
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
	}
}
