/*
** my.h for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr  5 16:20:43 2017 Benjamin GAYMAY
** Last update Sat Apr 22 13:07:49 2017 Benjamin GAYMAY
*/

#ifndef MY_H_
# define MY_H_

# define ERROR 84
# define SUCCESS 0
# define FAILURE 1

void	my_putchar(char);
void	my_putstr(char *);
int	my_getnbr(char *);
int	my_strlen(char *);
int	count_space(char *);
int	my_str_isnum(char *);
int	disp_error(char *, int);
int	my_getnbr_error(char *);
int	my_strcmp(char *, char *);
int	free_and_return(char **, int);
int	my_strncmp(char *, char *, int);
int	free_str_and_return(char *, int);
char	*clear_str(char *, char);
char	*my_malloc_strcpy(char *);
char	*my_malloc_strncpy(char *, int);
char	*transform_char(char *, char, char);
char	**my_array_realloc(char **, int);

#endif /* !MY_H_ */
