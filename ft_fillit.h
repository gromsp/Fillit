#ifndef FT_FILLIT
# define FT_FILLIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct	s_tetro
{
	int **rtr;
	int ccrd[2];
	int flag;
	int *mass;
	int *ovl;
	int *fld;
	int n;
	int d;
}				t_tetro;
void	ft_bzeroint(int *s, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *dest, char *str, int n);
int		ft_fsmb(char *str);
int		ft_move(char *str1, char *str2, int crd, int d);
char	*ft_paste(char *str1, char *str2, int crd, int d);
char	*ft_paste3(char *str1, char *str2, int crd, int d);
int		ft_coordinate(char *str1, char *str2, int d);
char	*ft_quadforprin(char *str, int d, t_tetro *tetro);
char	*ft_newquad(char *str, int d, int nd);
void	ft_freetet(t_tetro *tetro);
void	ft_qprint(char *str, int d);
char	*ft_d3(char *str);
int		ft_flag(int *ovl, int d);
int		ft_cmass(int *mass, int n);
int		**rtrrestore(int **rtr, int i, int d, int n);
char	*ft_restore(char **str, t_tetro *tetro, int i);
void	ft_writecrd(t_tetro *tetro, int crd, int second);
void	ft_writerpt(t_tetro *tetro, int crd, int second);
char	*ft_write(char **str, t_tetro *tetro);
char	*ft_subs(char **str, t_tetro *tetro);
char	*ft_back(char **str, t_tetro *tetro);
char	*ft_fpaste(char **str, t_tetro *tetro);
int		ft_checkrtr(t_tetro *tetro);
char	*ft_freetetro(char *str, t_tetro *tetro);
char	*ft_bback(char **str, t_tetro *tetro);
char	*ft_brute2(char **str, t_tetro *tetro);
char	*ft_init(char **str, int count, int diag);
char	*ft_brute(char **str, int n);
void	ft_fillit(char **str, int n);

#endif