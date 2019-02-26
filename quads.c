
#include "ft_fillit.h"

char	*ft_newquad(char *str, int d, int nd)
{
	char *strn;
	int i;
	int j;

	i = 0;
	j = 0;
	strn = ft_strnew(nd * nd);
	while (i < nd * nd)
	{
		if (((i + 1) % nd == 0 && i != 0) || (j + 1 > (d * d)))
			strn[i] = 0;
		else
		{
			strn[i] = str[j];
			j++;
		}
		i++;
	}
	return (strn);
}

void	ft_qprint(char *str, int d)
{
	int i;
	int n;

	i = 0;
	while (i < d * d + d)
	{
		if (str[i] == 0)
			str[i] = '.';
		printf("%c", str[i]); //putchar
		i++;
	}
}

char	*ft_quadforprin(char *str, int d, t_tetro *tetro)
{
	char *strn;
	int i;
	int j;
	int r;

	strn = ft_strnew(d * d + d);
	i = 0;
	j = 0;
	while (i <= d * d + d)
	{
		r = (i + 1) % (d + 1);
		if (r == 0 && i != 0)
			strn[i] = '\n';
		else
		{
			strn[i] = str[j];
			j++;
		}
		i++;
	}
	ft_qprint(strn, d);
	free(str);
	free(strn);
	return (strn);
}

char	*ft_d3(char *str)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(10);
	while (i < 9)
	{
		if ((j % 4) == 3 && j != 0)
			j++;
		tmp[i] = str[j];
		j++;
		i++;
	}
	if (str[3] == 1 || str[12] == 1)
		tmp[0] = 2;
	tmp[9] = str[16];
	return (tmp);
}