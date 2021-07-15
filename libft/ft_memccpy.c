#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (n-- > 0)
	{
		*d++ = s[i];
		i++;
		if (s[i - 1] == (unsigned char)c)
			return (dst + i);
	}
	return (NULL);
}
