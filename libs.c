
#include "ft_fillit.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		((char*)s)[n] = (char)0;
	}
}

void	*ft_memalloc(size_t size)
{
	void	*dest;

	if (size == 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)ft_memalloc(size + 1);
	return (str);
}