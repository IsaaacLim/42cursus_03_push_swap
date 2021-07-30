#include "push_swap.h"

/*
** Standard quicksort
**	Used by ft_sort_radix @ ft_substitudeNum 
*/
void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int ft_partition (int *a, int start, int end)
{
	int pivot;
	int partitionIndex;

	pivot = a[end];
	partitionIndex = start;
	for(int i = start; i < end; i++)
	{
		if (a[i] < pivot)
		{
			ft_swap(&a[i], &a[partitionIndex]);
			partitionIndex++;
		}
	}
	ft_swap(&a[partitionIndex], &a[end]);
	return (partitionIndex);
}

void ft_quicksort(int *a, int start, int end)
{
	int partitionIndex;

	if (start >= end)
		return ;
	partitionIndex = ft_partition(a, start, end);
	ft_quicksort(a, start, partitionIndex - 1);
	ft_quicksort(a, partitionIndex + 1, end);
}
