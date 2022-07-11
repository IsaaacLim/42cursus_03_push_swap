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

static void	ft_clearArray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_bzero(arr[i], ft_strlen(arr[i]));
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**ft_copyArgv(int argc, char **argv)
{
	char	**arr;
	int		i;

	arr = (char **)malloc((argc - 1) * sizeof(char *) + 1);
	if (!arr)
	{
		ft_putstr_fd("Error: Malloc** @ ft_copyArgv\n", 2);
		exit (0);
	}
	i = 0;
	while (i <= argc - 2)
	{
		arr[i] = ft_strdup(argv[i + 1]);
		if (!arr[i])
		{
			ft_clearArray(arr);
			ft_putstr_fd("Error: Malloc* @ ft_copyArgv\n", 2);
			exit (0);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	ft_createStack(t_list **stack_a, int argc, char **argv)
{
	t_list	*new;
	char	**arr;
	int		i;

	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = ft_copyArgv(argc, argv);
	i = -1;
	while (arr[++i])
	{
		if (!(ft_check_input(arr[i], *stack_a)))
		{
			ft_putstr_fd("Error\n", 2);
			ft_lstclear(stack_a);
			ft_clearArray(arr);
			exit (0);
		}
		new = ft_lstnew(ft_atoi(arr[i]));
		ft_lstadd_back(stack_a, new);
	}
	ft_clearArray(arr);
}
