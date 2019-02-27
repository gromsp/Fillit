#include "ft_fillit.h"

char	*ft_paste(char *str1, char *str2, int crd, int d)
{
	char *str;
	int i;
	int j;

	j = 0;
	crd = crd - ft_fsmb(str2);
	i = crd / d;
	while (j < 16)
	{
		if (str2[j] == 1 && (crd + (j % 4)) + d * (j / 4) < d * d)
			str1[(crd + (j % 4)) + d * (j / 4)] = str2[16];
		j++;
	}
	return (str1);
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