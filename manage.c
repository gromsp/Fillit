
#include "ft_fillit.h"

char	*ft_fpaste(char **str, t_tetro *tetro)
{
	int i;
	int j;

	j = 1;
	i = ft_flag(tetro->ovl, tetro->d);
	while (j <= tetro->n)
	{
		if (tetro->rtr[i][j] == 1)
		{
			str[0] = ft_paste(str[0], str[j], i, tetro->d);
			tetro->mass[j] = 0;
			tetro->fld[j] = i;
			tetro->rtr[i][j] = 0;
			if (tetro->ovl[i] > 0)
				tetro->ovl[i]--;
			return (str[0]);
		}
		j++;
	}
	return (str[0]);
}

char	*ft_bback(char **str, t_tetro *tetro)
{
	str[0] = ft_back(str, tetro);
	str[0] = ft_fpaste(str, tetro);
	return (str[0]);
}

void	ft_qprintdbg(char *str, int d)
{
	int i;
	int n;

	i = 0;
	while (i < d * d)
	{
		if (i % d == 0)
			printf("\n");
		if (str[i] == 0)
			printf(".");
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n_________________\n");
}

char	*ft_brute2(char **str, t_tetro *tetro)
{
	int first;
	int crd;
	int flg;

	first = 1;
	flg = 0;
	str[0] = ft_strnew(tetro->d * tetro->d);
	while (first <= tetro->n)
	{
		str[0] = ft_subs(str, tetro);
		first++;
		ft_qprintdbg(str[0], tetro->d);
		if (first == tetro->n)
		{
			if (ft_cmass(tetro->mass, tetro->n) > 0 && ft_checkrtr(tetro) < 0)
				str[0] = ft_bback(str, tetro);
			else if (ft_cmass(tetro->mass, tetro->n) <= 0)
				return (ft_quadforprin(str[0], tetro->d, tetro));
			if (ft_checkrtr(tetro) == 0)
				str[0] = ft_freetetro(str[0], tetro);
			first = 1;
		}
	}
	return (str[0]);
}

char	*ft_brute(char **str, int n)
{
	int d;
	int first;
	int second;
	int crd;

	d = 4;
	first = 1;
	while (first != n + 1 && d == 3)
	{
		second = 1;
		while (second != n + 1)
		{
			crd = -1;
			if ((first != second && (str[first] != NULL || str[second] != NULL)) && (d == 3))
				crd = ft_coordinate(ft_d3(str[first]), str[second], d);
			else if (first != second && (str[first] != NULL || str[second] != NULL))
				crd = ft_coordinate(str[first], str[second], d);
			if (first != second && crd >= 0)
			{
				str[0] = ft_paste3(ft_d3(str[first]), str[second], crd, d);
				str[first] = NULL;
				str[second] = NULL;
				str[0] = ft_init(str, n, d);
				return (str[0]);
			}
			second++;
		}
		first++;
	}
	str[0] = NULL;
	str[0] = ft_init(str, n, d);
	return (str[0]);
}

void	ft_fillit(char **str, int n)
{
	str[0] = ft_brute(str, n);
	// ft_qprint(str[0]);	
}