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

char	*ft_paste(char *str1, char *str2, int crd, int d)
{
	char *str;
	int i;
	int j;

	j = 0;
	str = ft_strnew(d * d);
	crd = crd - ft_fsmb(str2);
	str = ft_strcpy(str, str1, d * d - 1);
	i = crd / d;
	while (j < 16)
	{
		if ((crd + (j % 4)) + d * (j / 4) > d * d && str2[j] == 1)
			str[0] = 2;
		if (((crd + (j % 4) + d * (j / 4)) / d) - i != (j / 4) && str2[j] == 1)
			str[0] = 2;
		if (str2[j] == 1 && (crd + (j % 4)) + d * (j / 4) < d * d)
			str[(crd + (j % 4)) + d * (j / 4)] = str2[16];
		if ((crd + (j % 4)) + d * (j / 4) < d * d || str[0] == 2)
		{
			if (str[(crd + (j % 4)) + d * (j / 4)] == 2 || str[0] == 2)
			{
				free(str1);
				return (str);
			}
		}
		j++;
	}
	free(str1);
	return (str);
}

char	*ft_paste3(char *str1, char *str2, int crd, int d)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = ft_strnew(d * d);
	str = ft_strcpy(str, str1, d * d);
	while (j < 16)
	{
		if (str[j] == 1)
			str[j] = str1[9];
		j++;
	}
	i = crd / d;
	j = 0;
	while (j < 16)
	{
		if ((crd + (j % 4)) + d * (j / 4) > d * d && str2[j] == 1)
			str[0] = 2;
		if (((crd + (j % 4) + d * (j / 4)) / d) - i != (j / 4) && str2[j] == 1)
			str[0] = 2;
		if (str2[j] == 1)
			str[(crd + (j % 4)) + d * (j / 4)] = str2[16];
		if (str[(crd + (j % 4)) + d * (j / 4)] == 2 || str[0] == 2)
			return (str);
		j++;
	}
	return (str);
}