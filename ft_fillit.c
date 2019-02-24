/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:25:58 by adoyle            #+#    #+#             */
/*   Updated: 2019/02/24 15:25:58 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fillit.h"

int		ft_search(char *str, int d)
{
	int i;
	
	i = 0;
	while (i < d * d)
	{
		if (str[i] == 2)
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzeroint(int *s, size_t n)
{
	while (n-- > 0)
	{
		((int*)s)[n] = (int)0;
	}
}

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
				return (1);
		}
		j++;
	}
	free(str);
	return (0);
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
				return (str);
		}
		j++;
	}
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
				return (i);
			i++;
		}
	}
	return (-5);
}

char	*ft_newquad(char *str, int d, int nd)
{
	char *strn;
	int i;
	int j;

	i = 0;
	j = 0;
	strn = (char *)malloc(nd * nd);
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
		printf("%c", str[i]);
		i++;
	}
}

char	*ft_quadforprin(char *str, int d)
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
	return (strn);
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

void	dbgmassn(int *mass)
{
	int i = 0;
	int n = 8;

	while (i <= n)
	{
		printf("%d ", mass[i++]);
	}
	printf("\n");
}

void	dbgmassd(int *mass)
{
	int i = 0;
	int n = 35;

	while (i <= n)
	{
		printf("%d ", mass[i++]);
	}
	printf("\n");
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

int		ft_flag(int *ovl, int d)
{
	int i;

	i = d * d;
	while (i--)
	{
		if (ovl[i] != 0)
			return (i);
	}
	return (0);
}

int		ft_cmass(int *mass, int n)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i <= n)
	{
		if (mass[i] == 1)
			count++;
		i++;
	}
	return (count);
}

int		**rtrrestore(int **rtr, int i, int d, int n)
{
	while (i < d * d)
	{
		ft_bzeroint(rtr[i], n);
		i++;
	}
	return (rtr);
}

char	*ft_restore(char **str, t_tetro *tetro, int i)
{
	int j;
	int tet;
	char c;

	c = str[i][16];
	j = 0;
	tetro->mass[i] = 1;
	tetro->fld[i] = 0;
	while (j < tetro->d * tetro->d)
	{
		if (str[0][j] == c)
			str[0][j] = 0;
		j++;
	}
	return (str[0]);
}

void	ft_writecrd(t_tetro *tetro, int crd, int second)
{
	tetro->ccrd[0] = crd;
	tetro->ccrd[1] = second;
}

void	ft_writerpt(t_tetro *tetro, int crd, int second)
{
	tetro->ovl[crd]++;
	tetro->rtr[crd][second] = 1;
}

char	*ft_write(char **str, t_tetro *tetro)
{
	str[0] = ft_paste(str[0], str[tetro->ccrd[1]], tetro->ccrd[0], tetro->d);
	tetro->mass[tetro->ccrd[1]] = 0;
	tetro->fld[tetro->ccrd[1]] = tetro->ccrd[0];
	return (str[0]);
}

char	*ft_subs(char **str, t_tetro *tetro)
{
	int s;
	int crd;
	int flag;

	s = 1;
	tetro->ccrd[0] = -1;
	while (s <= tetro->n)
	{
		crd = -1;
		if (tetro->mass[s] != 0)
			crd = ft_coordinate(str[0], str[s], tetro->d);
		if (crd >= 0 && (crd < tetro->ccrd[0] || tetro->ccrd[0] < 0))
			ft_writecrd(tetro, crd, s);
		else if (crd == tetro->ccrd[0] && crd >= 0 && tetro->rtr[crd][s] != 1)
			ft_writerpt(tetro, crd, s);
		s++;
	}
	if (tetro->ccrd[0] >= 0)
		str[0] = ft_write(str, tetro);
	return (str[0]);
}

char	*ft_back(char **str, t_tetro *tetro)
{
	int i;
	int j;

	j = 1;
	i = ft_flag(tetro->ovl, tetro->d);
	while (j <= tetro->n)
	{
		if (tetro->fld[j] >= i)
		{
			str[0] = ft_restore(str, tetro, j);
		}
		j++;
	}
	tetro->rtr = rtrrestore(tetro->rtr, i + 1, tetro->d, tetro->n);
	while (i < tetro->d * tetro->d)
	{
		i++;
		if (i < tetro->d * tetro->d)
			tetro->ovl[i] = 0;
	}
	return (str[0]);
}

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

int		ft_checkrtr(t_tetro *tetro)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= tetro->d * tetro->d)
	{
		while (j <= tetro->n)
		{
			if (tetro->rtr[i][j] == 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_freetetro(char *str, t_tetro *tetro)
{
	int c;
	int count;

	count = tetro->n;
	str = ft_newquad(str, tetro->d, tetro->d + 1);
	free(tetro->mass);
	free(tetro->ovl);
	free(tetro->fld);
	free(tetro->rtr);
	c = 0;
	while (c <= count)
	{
		ft_bzeroint(tetro->rtr[c], count + 1);
		tetro->mass[c] = 1;
		c++;
	}
	free(tetro);
	return (str);
}

char	*ft_bback(char **str, t_tetro *tetro)
{
	str[0] = ft_back(str, tetro);
	str[0] = ft_fpaste(str, tetro);
	return (str[0]);
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
		if (first == tetro->n)
		{
			if (ft_cmass(tetro->mass, tetro->n) > 0 && ft_checkrtr(tetro) < 0)
				str[0] = ft_bback(str, tetro);
			else if (ft_cmass(tetro->mass, tetro->n) <= 0)
				return (ft_quadforprin(str[0], tetro->d));
			if (ft_checkrtr(tetro) == 0)
				str[0] = ft_freetetro(str[0], tetro);
			first = 1;
		}
	}
	return (str[0]);
}


char	*ft_init(char **str, int count, int diag)
{
	t_tetro	*tetro;
	int c;

	tetro = malloc(sizeof(t_tetro));
	tetro->d = diag;
	tetro->n = count;
	tetro->mass = (int *)malloc((sizeof(int)) * (count + 1));
	tetro->ovl = (int *)malloc((sizeof(int)) * diag * diag);
	tetro->fld = (int *)malloc((sizeof(int)) * (count + 1));
	tetro->rtr = (int **)malloc(sizeof(int *) * (diag * diag));
	c = 0;
	while (c < diag * diag)
		tetro->rtr[c++] = malloc(sizeof(int) * (count + 1));
	ft_bzeroint(tetro->ovl, diag * diag);
	ft_bzeroint(tetro->fld, count + 1);
	c = 0;
	while (c <= count)
	{
		ft_bzeroint(tetro->rtr[c], count + 1);
		tetro->mass[c] = 1;
		c++;
	}
	str[0] = ft_brute2(str, tetro);
	return (str[0]);
}

char	*ft_brute(char **str, int n)
{
	int d;
	int first;
	int second;
	int crd;

	d = 6;
	first = 1;
	while (first != n + 1 && d == 3)
	{
		second = 1;
		while(second != n + 1)
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
