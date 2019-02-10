#ifndef FILIT_FILIT_H
# define FILIT_FILIT_H
#include "libft/libft.h"
#include "libft/get_next_line.h"

#define WIDTH 4
int check_1(char *tetr, int pos);
int check_2(char *tetr, int pos);
int check_3(char *tetr, int pos);
int check_4(char *tetr, int pos);
int check_5(char *tetr, int pos);
int check_6(char *tetr, int pos);
int check_7(char *tetr, int pos);
int check_8(char *tetr, int pos);
int check_9(char *tetr, int pos);
int find_x_offset(char *tetra);
int find_y_offset(char *tetra);
int find_x_r_offset(char *tetra);
int find_y_r_offset(char *tetra);
void	ft_fillit(char **str, int n);

#define DOWN 4
#define UP -4
typedef struct	s_tetro
{
	int ccrd[2];
	int flag;
	int *mass;
	int *ovl;
	int *fld;
	int n;
	int d;
}				t_tetro;
int _y(int pos);
int _x(int pos);
char **generate_arrays(char **tet_inpt);
char *read_file(int fd);
int is_req_symbols(char **ch);
int ft_count_symbol(char *str, char ch);
int pre_parse(int fd, char **tetraminos);
void remove_symbols(char **s, char c);
int validate(char **tet_inpt);
int validate_tetra(char **tetramino) ;

#endif //FILIT_FILIT_H