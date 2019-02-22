#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fillit.h"

int		ft_search(char *str, int d)
{
	int i;
	
	i = 0;
	while(i < d * d)
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
    void *dest;

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

//char    *bzero(char *str, int d)
//{
//    int i;
//
//    i = 0;
//    while()
//}
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

	while(str[i] != 1)
	{
		i++;
	}
	return (i);
}

int		ft_move(char *str1, char *str2, int crd, int d)          //19.02 Изменены условия в 
{
	char *str;
	int i;
	int j;
	int g;

	i = 0;
	j = 0;
	str = ft_strnew(d * d);
	if (str1 == NULL)
		{
			str = ft_strcpy(str, str2, d * d);
			return (1);
		}
    str = ft_strcpy(str, str1, d * d);
	if (crd < 0)
		return (1);
	i = crd /  d;
	while(j < 16)   
	{
		if ((crd + (j % 4)) + d * (j / 4) > d * d && str2[j] == 1)
			str[0] = 2;
		if (((crd + (j % 4) + d * (j / 4)) / d) - i != (j /4) && str2[j] == 1)
			str[0] = 2;
		if (str2[j] == 1 && ((crd + (j % 4)) + d * (j / 4)) < d * d - 1)									 //19.02 Изменены условия в  этом ифе, для того, чтоб не вылетать за память
			str[(crd + (j % 4)) + d * (j / 4)] = str1[(crd + j % 4) + d * (j / 4)] + str2[j];
		if (str[0] == 2)
				return (1);
		if (((crd + (j % 4)) + d * (j / 4)) < d * d - 1)
		{
			if (str[(crd + (j % 4)) + d * (j / 4)] >= 2 && ((str2[j] == 1) || (str[0] == 2)))
			{
				return (1);
			}
		}
		j++;
	}
	// printf("000\n");
	return (0);
}

char	*ft_paste(char *str1, char *str2, int crd, int d)
{
	char *str;
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * d * d);
	ft_bzero(str, d * d);
	s = ft_fsmb(str2);
	crd = crd - s;
	if (crd < 0)						//Добавлено условие в эту функцию .как и в другую похожую. Может быть ошибочно, понадлюдать
		crd = 0;
	if (str1 == NULL)
	{
	//	str = ft_strcpy(str, str2, d * d);
		while(i < d * d)
		{
			if ((i % d) == (j % 4) && j < 16)
			{
				if (str2[j] == 1)
					str[i] = str2[16];
				else
					str[i] = str2[j];
				j++;
			}
			i++;
		}
		return (str);
	}
	str = ft_strcpy(str, str1, d * d - 1);
	i = crd / d;
	while(j < 16)
	{
		// printf ("index - %d crd - %d j - %d\n", (crd + (j % 4)) + d * (j / 4), crd, j);
		if ((crd + (j % 4)) + d * (j / 4) > d * d && str2[j] == 1)
			str[0] = 2;
		if (((crd + (j % 4) + d * (j / 4)) / d) - i != (j /4) && str2[j] == 1)
			str[0] = 2;
		if (str2[j] == 1 && (crd + (j % 4)) + d * (j / 4) < d * d)
			str[(crd + (j % 4)) + d * (j / 4)] = str2[16];
		if ((crd + (j % 4)) + d * (j / 4) < d * d || str[0] == 2)							//Добавлены условия для незахода за память
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
	while(j < 16)
	{
		if (str[j] == 1)
			str[j] = str1[9];
		j++;
	}
	i = crd / d;
	j = 0;
	while(j < 16)
	{
		if ((crd + (j % 4)) + d * (j / 4) > d * d && str2[j] == 1)
			str[0] = 2;
		if (((crd + (j % 4) + d * (j / 4)) / d) - i != (j /4) && str2[j] == 1)
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

	// printf ("%d d3\n", d);
	i = 0;
	flag = 0;
	if (str1 == NULL)
		return (-5);
	if (str2 == NULL)
		return (-5);
	tmp = ft_strnew(d * d);
    tmp = ft_strcpy(tmp, str1, d * d - 1);
	s = ft_fsmb(str2);
	while(i != d * d)
	{
		if (tmp[i] > 0)
			i++;
		else
		{
			flag = ft_move(tmp, str2, i - s, d);
			// printf("flag - %d\n", flag);
//			flag = ft_search(str1, d);
			if (flag == 0)
				return(i);
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
	while(i < nd * nd)
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

char	*ft_quadforprin(char *str, int d)
{
	char *strn;
	int i;
	int j;
	int r;

	strn = ft_strnew(d * d + d);
	i = 0;
	j = 0;
    //str = ft_strcpy(strn, str, d * d);
	while(i <= d * d + d)
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
	return (strn);
}


void	ft_qprintdbg(char *str, int d) // DEBAG EPTA
{
	int i;
	int n;

	i = 0;
	while(i < d * d)
	{
		if (i % d == 0)
			printf("\n");
	    if (str[i] == 0)
	        printf(".");
//	    else if (str[i] == 1)
//	        str[i] = '#';
//	    else if (str[i] != 0 && str[i] != '\n')
//	        str[i] = '1';
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n_________________\n");
}

void	ft_qprint(char *str, int d)
{
	int i;
	int n;

	i = 0;
	while(i < d * d + d)
	{
	    if (str[i] == 0)
	        str[i] = '.';
//	    else if (str[i] == 1)
//	        str[i] = '#';
//	    else if (str[i] != 0 && str[i] != '\n')
//	        str[i] = '1';
		printf("%c", str[i]);
		i++;
	}
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

int g_size;

int		ft_flag(int *ovl, int d)
{
	int i;

	i = d * d;
	while (i--)
	{
		if (ovl[i] != 0)
			return(i);
	}
	return (0);
}

int		ft_checkmass(int *mass, int n)
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
	while(i < d * d)
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

char	*ft_subs(char **str, t_tetro *tetro)
{
	int second;
	int crd;
	int flag;

	second = 1;
	tetro->ccrd[0] = -1;
//	flag = ft_flag(tetro->ovl, tetro->d);
	while (second <= tetro->n)
	{
		// printf("1\n");
		crd = -1;
		if (tetro->mass[second] != 0)
			crd = ft_coordinate(str[0], str[second], tetro->d); // gde to tut
		// printf("sec - %d, crd - %d\n", second, crd);
		if (crd >= 0 && (crd < tetro->ccrd[0] || tetro->ccrd[0] < 0))
		{
			printf("crd0 - %d, second0 - %d\n", crd, second);
			tetro->ccrd[0] = crd;
			tetro->ccrd[1] = second;
		}
		else if (crd == tetro->ccrd[0] && crd >= 0 && tetro->rtr[crd][second] != 1)
		{
			printf("crd - %d, second - %d\n", crd, second);
			tetro->ovl[crd]++;
			tetro->rtr[crd][second] = 1;
		}
		second++;
	}
	if (tetro->ccrd[0] >= 0)
	{
		str[0] = ft_paste(str[0], str[tetro->ccrd[1]], tetro->ccrd[0], tetro->d);
		// printf("0\n");
		tetro->mass[tetro->ccrd[1]] = 0;
		tetro->fld[tetro->ccrd[1]] = tetro->ccrd[0];
	}
	return (str[0]);
}

char	*ft_back(char **str, t_tetro *tetro)
{
	int i;
	int j;

	j = 1;
	i = ft_flag(tetro->ovl, tetro->d);
	// printf("ovl - %d\n", i);
	while(j <= tetro->n)
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
	while(j <= tetro->n)
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

char	*ft_brute2(char **str, t_tetro *tetro)
{
	int first;
	int crd;
	int cflg;
	int flg;
//	int i = 0;

	first = 1;
	flg = 0;
	str[0] = ft_strnew(tetro->d * tetro->d);
	while (first <= tetro->n)
	{
		// printf("ovl0 %c\n", str[0][18]);
		str[0] = ft_subs(str, tetro);
		// printf("ovl1 %d\n", tetro->ovl[18]);
		// ft_qprintdbg(str[0], tetro->d);
		// dbgmassd(tetro->ovl);
		// dbgmassn(tetro->fld);
		//printf("PS - %d\n", str[0][35]);
		first++;
		if (first == tetro->n)
		{
			//exit(1);
			// ft_qprintdbg(str[0], tetro->d);
			// dbgmassd(tetro->ovl);
			// dbgmassn(tetro->fld);
			cflg = ft_checkmass(tetro->mass, tetro->n);
			if (cflg > 0 && ft_checkrtr(tetro) < 0)
			{
				str[0] = ft_back(str, tetro);
				first = 1;
				// ft_qprintdbg(str[0], tetro->d);
				// dbgmassd(tetro->ovl);
				// dbgmassn(tetro->fld);
				// dbgmassn(tetro->rtr[18]);
				str[0] = ft_fpaste(str, tetro);
				// printf("Posle\n");
				// ft_qprintdbg(str[0], tetro->d);
				// dbgmassd(tetro->ovl);
				// dbgmassn(tetro->fld);
				// dbgmassn(tetro->rtr[18]);
			}
			else if (cflg <= 0)
			{
				str[0] = ft_quadforprin(str[0], tetro->d);
				ft_qprint(str[0], tetro->d);
				// ft_qprintdbg(str[0], tetro->d);
				// dbgmassn(tetro->fld);
				return (str[0]);
			}
			cflg = ft_checkrtr(tetro);
			if (cflg == 0)
			{
				str[0] = ft_newquad(str[0], tetro->d, tetro->d + 1);
				first = 1;
			}
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
	tetro->rtr= (int **)malloc(sizeof(int *) * (diag * diag));

	c = 0;
	while(c < diag * diag)
	{
		tetro->rtr[c]=malloc(sizeof(int) * (count + 1));
		c++;
	}
	
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


// char	*ft_brute1(char **str, const int n, int d)
// {
// 	int first;
// 	int second;
// 	int crd;
// 	int ccrd[2];
// 	int flag;
// 	int count;
// 	int mass[n + 1];
// 	int ovl[d * d];
// 	int fld[n + 1];
// 	int gg;

// 	count = 0;
// 	ft_bzero(ovl, d * d);
// 	ft_bzero(fld, n + 1);
// 	while (count <= n)
// 	{
// 		mass[count] = 1;
// 		count++;
// 	}
// 	first = 1;
// 	crd = -1;
// 	flag = -1;
// 	gg = 0;
// 	while (first != n + 1)
// 	{
// 		second = 1;
// 		ccrd[0] = -1;
// 		while(second != (n + 1))
// 		{
// 			if (mass[second] != 0)
// 				crd = -1;
// 			if (mass[second] != 0)
// 				crd = ft_coordinate(str[0], str[second], d);
// 			if (crd >= 0 && (crd < ccrd[0] || ccrd[0] < 0))
// 			{
// 				ccrd[0] = crd;
// 				ccrd[1] = second;
// 			}
// 			else if (crd >= 0 && crd == ccrd[0] && mass[second] != 0)
// 			{
// 				if (flag != crd)
// 					ovl[crd]++;
// 				else if (flag != -1)
// 				{
// 					ccrd[1] = second;
// 					ovl[crd]--;
// 					flag = -1;
// 				}				
// 			}
// 			if (ccrd[0] >= 0 && second == n)
// 			{
// 				str[0] = ft_paste(str[0], str[ccrd[1]], ccrd[0], d);
// 				fld[ccrd[1]] = ccrd[0];
// 				mass[ccrd[1]] = 0;
// 				crd = -1;
// 			}
// 			second++;
// 		}
// 		first++;
// 		gg++;
// 		if (first >= n && crd < -3)
// 		{
// 			str[0] = ft_strnew(d * d);
// 			g_size = d * d;
// 			flag = ft_flag(ovl);
// 			ft_bzero(ovl,d * d);
// 			count = 0;
// 			while (count <= n)
// 			{
// 				mass[count] = 1;
// 				count++;
// 			}
// 			first = 1;
// 			crd = -1;
// 			if (gg > 100000)
// 			{
// 		 		d++;
// 		 		str[0] = ft_strnew(d * d);
// 				ft_bzero(ovl,d * d);
// 		 		first = 1;
// 		 		crd = -1; 
// 			}
// 		}
// 		// if (gg > 100)
// 		// {
// 		//  	d++;
// 		//  	str[0] = ft_newquad(str[0], d - 1, d);
// 		//  	first = 1;
// 		//  	crd = -1; 
// 		// }
// 	}
// 	str[0] = ft_quadforprin(str[0], d);
// 	ft_qprint(str[0], d);
// 	return (str[0]);
// }


char	*ft_brute(char **str, int n)
{
	int d;
	int first;
	int second;
	int crd;

	d = 6;
	// d = floor(sqrt(n * 4)) + 1;
	first = 1;
	// while (first != n + 1 && d == 3)
	// {
	// 	second = 1;
	// 	while(second != n + 1)
	// 	{
	// 		crd = -1;
	// 		if ((first != second && (str[first] != NULL || str[second] != NULL)) && (d == 3))
	// 			crd = ft_coordinate(ft_d3(str[first]),str[second], d);
	// 		else if (first != second && (str[first] != NULL || str[second] != NULL))
	// 			crd = ft_coordinate(str[first], str[second], d);
	// 		if (first != second && crd >= 0)
	// 		{
	// 			str[0] = ft_paste3(ft_d3(str[first]), str[second], crd, d);
	// 			str[first] = NULL;
	// 			str[second] = NULL;
	// 			str[0] = ft_brute1(str, n, d);
	// 			return (str[0]);
	// 		}
	// 		second++;
	// 	}
	// 	first++;
	// }
	str[0] = NULL;
	str[0] = ft_init(str, n, d);
	return (str[0]);
}


void	ft_fillit(char **str, int n)
{
	str[0] = ft_brute(str, n);
	// ft_qprint(str[0]);	
}
