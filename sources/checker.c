#include "push_swap.h"
#include "get_next_line.h"

bool	ft_modifyList(char *line, t_list **stack_a, t_list **stack_b)
{
	if(!(ft_strnstr("ssasbpapbrrrarrb", line, 16)))
		return (false);
	if (!(ft_strncmp("sa", line, 2) && ft_strncmp("ss", line, 2)))
		ft_sort_swap(stack_a);
	if (!(ft_strncmp("sb", line, 2) && ft_strncmp("ss", line, 2)))
		ft_sort_swap(stack_b);
	if (!(ft_strncmp("pa", line, 2)))
		ft_sort_push(stack_b, stack_a);
	if (!(ft_strncmp("pb", line, 2)))
		ft_sort_push(stack_a, stack_b);
	if (!(ft_strncmp("ra", line, 2) && ft_strncmp("rr", line, 2)))
		ft_sort_rotate(stack_a);
	if (!(ft_strncmp("rb", line, 2) && ft_strncmp("rr", line, 2)))
		ft_sort_rotate(stack_b);
	if (!(ft_strncmp("rra", line, 3) && ft_strncmp("rrr", line, 3)))
		ft_sort_rotate_rev(stack_a);
	if (!(ft_strncmp("rrb", line, 3) && ft_strncmp("rrr", line, 3)))
		ft_sort_rotate_rev(stack_b);
		// printf("YES: %s\n", line);
	// else
	// 	ft_sort(line, stack_a, stack_b);
	return (true);
}

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	int i;
	char *line;
	
	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_createStack(&stack_a, argv);
	i = 0;
	while (get_next_line(0, &line))
	{
		if (!(ft_modifyList(line, &stack_a, &stack_b)))
			break;
		free(line);
		i++;
	}
	free(line);
	if (ft_is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	printf("\nGNL count: %d\n", i);
	ft_putstr_fd("Stack_a:\t", 1);
	ft_putlst(stack_a);
	ft_putstr_fd("\nStack_b:\t", 1);
	ft_putlst(stack_b);
	ft_putchar_fd('\n', 1);

	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
