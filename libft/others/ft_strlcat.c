#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = -1;
	while (src[len])
		len++;
	while (dst[++i])
		len++;
	if (dstsize <= i)
		len = len - i + dstsize;
	if (dstsize > 0)
	{
		j = -1;
		while (src[++j] && i < (dstsize - 1))
		{
			dst[i] = src[j];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
