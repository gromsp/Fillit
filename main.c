/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:49:30 by qhetting          #+#    #+#             */
/*   Updated: 2019/03/14 12:58:25 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

void		print_less(char *tetra, int *x, int *y, int *a)
{
	(*x) = find_x_r_offset(tetra);
	(*y) = find_y_r_offset(tetra);
	(*a) = 0;
}

void		print(char *tetra)
{
	int		x;
	int		y;
	int		a;
	int		intern;

	print_less(tetra, &x, &y, &a);
	intern = 0;
	y = y > x ? y : x;
	x = y > x ? y : x;
	while (a < 16)
	{
		if (x_(a) <= x && y_(a) <= y)
		{
			if (intern && intern % (x + 1) == 0)
				ft_putchar('\n');
			if (tetra[a] == 1)
				write(1, "A", 1);
			if (tetra[a] == 0)
				write(1, ".", 1);
			intern++;
		}
		a++;
	}
}

void		exit_check(char *tetraminos)
{
	ft_putstr("error\n");
	free(tetraminos);
	exit(123);
}

void		internal_while(int cnt, char **pr)
{
	print(pr[1]);
	cnt = -1;
	while (++cnt < 28)
		free(pr[cnt]);
	free(pr);
	exit(1);
}

int			main(int argc, char *argv[])
{
	int		fl;
	char	*tetraminos;
	int		cnt;
	char	**pr;

	cnt = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(10);
	}
	fl = open(argv[1], O_RDONLY);
	if (!((pre_parse(fl, &tetraminos)) && validate(&tetraminos)))
		exit_check(tetraminos);
	pr = generate_arrays(&tetraminos);
	fl = 0;
	while (++fl < 27)
		cnt += pr[fl] ? 1 : 0;
	if (cnt == 1)
		internal_while(cnt, pr);
	ft_fillit(pr, cnt);
	return (0);
}
