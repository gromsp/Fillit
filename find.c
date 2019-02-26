
#include "ft_fillit.h"

char	*ft_strcpy(char *dest, char *str, int n)
{
	int i;

	i = 0;
	if (str == NULL)
		return (str);
	while (i <= n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}

int		ft_move(char *str1, char *str2, int crd, int d)
{
	char *str;
	int j;
	int g;

	j = 0;
	str = ft_strnew(d * d);
	str = ft_strcpy(str, str1, d * d);
	while (j < 16)
	{
		g = (crd + (j % 4)) + d * (j / 4);
		if ((crd + (j % 4)) + d * (j / 4) > d * d && str2[j] == 1)
			str[0] = 2;
		if ((g / d) - (crd / d) != (j / 4) && str2[j] == 1)
			str[0] = 2;
		if (str2[j] == 1 && g < d * d - 1)
			str[g] = str1[(crd + j % 4) + d * (j / 4)] + str2[j];
		if (str[0] == 2 || (((crd + (j % 4)) + d * (j / 4)) < d * d - 1))
		{
			if ((str[0] == 2) || (crd < 0) || (str[g] >= 2 && (str2[j] == 1)))
			{
				free(str);
				return (1);
			}
		}
		j++;
	}
	free(str);
	return (0);
}

int		ft_fsmb(char *str)
{
	int i;

	i = 0;

	while (str[i] != 1)
	{
		i++;
	}
	return (i);
}

int		ft_coordinate(char *str1, char *str2, int d)
{
	int i;
	int flag;
	char *tmp;
	int s;

	i = 0;
	flag = 0;
	if (str1 == NULL || str2 == NULL)
		return (-5);
	tmp = ft_strnew(d * d);
	tmp = ft_strcpy(tmp, str1, d * d - 1);
	s = ft_fsmb(str2);
	while (i != d * d)
	{
		if (tmp[i] > 0)
			i++;
		else
		{
			flag = ft_move(tmp, str2, i - s, d);
			if (flag == 0)
			{
				free(tmp);
				return (i);
			}
			i++;
		}
	}
	free(tmp);
	return (-5);
}