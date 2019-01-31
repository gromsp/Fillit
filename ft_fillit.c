#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    dest = (char *)malloc(size);
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

int		ft_move(char *str1, char *str2, int crd, int d)
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
	i = crd / d;
	while(j < 16)
	{
		g = (j - (4 * j));
	//	printf (" %d j=%d\n", (j % 4), j);
		if ((crd + (j % 4)) + d * (j / 4) > d * d && str2[j] == 1)
			str[0] = 2;
		if (((crd + (j % 4) + d * (j / 4)) / d) - i != (j /4) && str2[j] == 1)
			str[0] = 2;
		if (str2[j] == 1)
			str[(crd + (j % 4)) + d * (j / 4)] = str1[(crd + j % 4) + d * (j / 4)] + str2[j];
		if (((str[(crd + (j % 4)) + d * (j / 4)] >= 2) && (str2[j] == 1)) || (str[0] == 2))
			return (1);
		j++;
	}
	return (0);
}

char	*ft_paste(char *str1, char *str2, int crd, int d)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = ft_strnew(d * d);
	if (str1 == NULL)
	{
		str = ft_strcpy(str, str2, d * d);
		while(j < 16)
		{
			if (str[j] == 1)
				str[j] = str2[16];
			j++;
		}
		return (str);
	}
	str = ft_strcpy(str, str1, d * d);
	i = crd / d;
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

int		ft_coordinate(char *str1, char *str2, int d)
{
	int i;
	int flag;
	char *tmp;
	int s;

	i = 0;
	flag = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	tmp = ft_strnew(d * d);
    tmp = ft_strcpy(tmp, str1, d * d);
	s = ft_fsmb(str2);
	while(i != d * d)
	{
		if (tmp[i] == 1 || tmp[i] == 2)
			i++;
		else
		{
			flag = ft_move(tmp, str2, i - s, d);
//			flag = ft_search(str1, d);
			if (flag == 0)
				return(i - s);
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

char	*ft_brute1(char **str, int n, int d)
{
	int first;
	int second;
	int crd;

	first = 1;
	crd = -1;
	while (first != n + 1)
	{
		second = 1;
		while(second != n + 1)
		{
			if (str[second] != NULL)
				crd = -1;
			if (str[second] != NULL)
				crd = ft_coordinate(str[0], str[second], d);
			if (crd >= 0)
			{
				str[0] = ft_paste(str[0], str[second], crd, d);
				str[second] = NULL;
				crd = -1;
			}
			second++;
		}
		first++;
		if (first >= n && crd < -3)
		{
			d++;
			str[0] = ft_newquad(str[0], d - 1, d);
			first = 1;
			crd = -1; 
		}
	}
	str[0] = ft_quadforprin(str[0], d);
	ft_qprint(str[0], d);
	return (str[0]);
}


char	*ft_brute(char **str, int n)
{
	int d;
	int first;
	int second;
	int crd;

	d = 3;
	first = 1;
	while (first != n + 1)
	{
		second = 1;
		while(second != n + 1)
		{
			crd = -1;
			if ((first != second && (str[first] != NULL || str[second] != NULL)) && (d == 3))
				crd = ft_coordinate(ft_d3(str[first]),str[second], d);
			else if (first != second && (str[first] != NULL || str[second] != NULL))
				crd = ft_coordinate(str[first], str[second], d);
			if (first != second && crd >= 0)
			{
				str[0] = ft_paste3(ft_d3(str[first]), str[second], crd, d);
				str[first] = NULL;
				str[second] = NULL;
				str[0] = ft_brute1(str, n, d);
				return (str[0]);
			}
			second++;
		}
		first++;
	}
	str[0] = NULL;
	str[0] = ft_brute1(str, n, d + 1);
	return (str[0]);
}



// char	*ft_brute(char **str, int n)
// {
// 	int d;
// 	int first;
// 	int second;
// 	int crd;

// 	d = 4;
// 	first = 0;
// 	while (first != n + 1)
// 	{
// 		second = 1;
// 		while(second != n + 1)
// 		{
// 			crd = -1;
// 			if (first != second && (str[first] != NULL || str[second] != NULL))
// 				crd = ft_coordinate(str[first], str[second], d);
// 			if (first != second && crd >= 0)
// 			{
// 				str[first] = ft_move(str[first], str[second], crd, d);
// 				str[second] = NULL;
// 			}
// 			second++;
// 		}
// 		first++;
// 		if (first == n && crd < 0)
// 		{
// 			d++;
// 			str[0] = ft_newquad(str[0], d - 1, d);
// 			first = 0;
// 			crd = -1; 
// 		}
// 	}
// 	str[0] = ft_quadforprin(str[0], d);
// 	return (str[0]);
// }

// void	ft_qprint(char *str, int d)
// {
// 	int i;
// 	int n;

// 	i = 0;
// 	while(i <= d * d + d)
// 	{
// 	    if (str[i] == 0)
// 	        str[i] = '.';
// 	    else if (str[i] == 1)
// 	        str[i] = '#';
// //	    else if (str[i] != 0 && str[i] != '\n')
// //	        str[i] = '1';
// 		printf("%c", str[i]);
// 		i++;
// 	}
// }

void	ft_fillit(char **str, int n)
{
	str[0] = ft_brute(str, n);
	// ft_qprint(str[0]);	
}

//int		main()
//{
//	char	**str;
//	int 	n;
//
//	printf("1");
//	str[1] = "0000110001000100";
//	str[2] = "0000111100000000";
//	// str[3] = "1000111000000000";
//	// str[4] = "0000110001100000";
//	n = 2;
//	printf("1");
//	ft_fillit(str, n);
//	return 0;
//}