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

char	*ft_move(char *str1, char *str2, int crd, int d)
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
			return (str);
		}
    str = ft_strcpy(str, str1, d * d);
	i = crd / d;
	while(j < 16 && (crd % d + d * ((j / 4) + i)) < (d * d))
	{
		if (((crd / d) - i) != (j / 4) && str2[j] == 1 && j != 0)
			str[0] = 2;
		else if  ((crd % d + d * (j / 4)) > d * d && str2[j] == 1)
			str[0] = 2;
		else if(((crd / d) - i) == (j / 4))
            str[crd % d + d * ((j / 4) + i)] = str1[crd % d + d * ((j / 4) + i)] + str2[j];
//		    str[crd % d + d * (j / 4)] = str1[crd % d + d * (j / 4)] + str2[j];
//		    str[crd + d * (j / 4)] = str1[crd + d * (j / 4)] + str2[j];
		if (str[0] == 2 || str[crd % d + d * ((j / 4) + i)] == 2)
		    return (str);
//		if (str1[crd + d * (i / d)] == '0' && str2[j] == '0')
//            str[crd + d * (i / d)] = 0;
//        if (str1[crd + d * (i / d)] == '1' || str2[j] == '1')
//            str1[crd + d * (i / d)] = 2;
//        if (str1[crd + d * (i / d)] == '1' && str2[j] == '1')
//            str1[crd + d * (i / d)] = 3;
		j++;
		crd++;
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
		if (str1[i] == 1)
			i++;
		else
		{
			str1 = ft_move(tmp, str2, i - s, d);
			flag = ft_search(str1, d);
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
		if (((i + 1) % nd == 0 && i != 0) || (j > d * d))
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
	while(i <= d * d + d)
	{
	    if (str[i] == 0)
	        str[i] = '.';
	    else if (str[i] == 1)
	        str[i] = '#';
//	    else if (str[i] != 0 && str[i] != '\n')
//	        str[i] = '1';
		printf("%c", str[i]);
		i++;
	}
}


char	*ft_brute1(char **str, int n, int d)
{
	int first;
	int second;
	int crd;

	first = 1;
	while (first != n + 1)
	{
		second = 1;
		while(second != n + 1)
		{
			crd = -1;
			if (str[second] != NULL)
				crd = ft_coordinate(str[0], str[second], d);
			if (crd >= 0)
			{
				str[0] = ft_move(str[0], str[second], crd, d);
				str[second] = NULL;
			}
			second++;
		}
		first++;
		if (first == n && crd < -3)
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

	d = 4;
	first = 1;
	while (first != n + 1)
	{
		second = 1;
		while(second != n + 1)
		{
			crd = -1;
			if (first != second && (str[first] != NULL || str[second] != NULL))
				crd = ft_coordinate(str[first], str[second], d);
			if (first != second && crd >= 0)
			{
				str[0] = ft_move(str[first], str[second], crd, d);
				str[first] = NULL;
				str[second] = NULL;
				str[0] = ft_brute1(str, n, d);
				return (str[0]);
			}
			second++;
		}
		first++;
	}
	str[0] = ft_brute1(str, n, d);
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