
#include "ft_fillit.h"

void	ft_bzeroint(int *s, size_t n)
{
	while (n-- > 0)
	{
		((int*)s)[n] = (int)0;
	}
}

void	ft_freetet(t_tetro *tetro)
{
	int count;
	int c;

	count = tetro->d;
	free(tetro->mass);
	free(tetro->ovl);
	free(tetro->fld);
	c = 0;
	while (c < count * count)
	{
		free(tetro->rtr[c]);
		c++;
	}
	free(tetro->rtr);
	free(tetro);
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
	ft_freetet(tetro);
	return (str[0]);
}