/*
** chained_list.h for chained_list in /home/benjamin.g/save/test
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 24 19:05:21 2017 Benjamin GAYMAY
** Last update Fri Apr 21 16:08:51 2017 Benjamin GAYMAY
*/

#ifndef CHAINED_LIST_H_
# define CHAINED_LIST_H_

typedef struct		s_list
{
  int			id;
  int			x;
  int			y;
  char			*name;

  struct s_list		*next;
}			t_list;

typedef struct		s_ants
{
  int			id;
  int			pos;
  int			*path;

  struct s_ants		*next;
}			t_ants;

void	my_show_list(t_list *);
int	my_len_list(t_list *);
int	get_id_with_name(t_list *, char *);
int	add_room(t_list **, char *, int[2]);
int	ant_in_list(t_ants **, int *, int, int);
int	my_put_in_list(t_list **, int, char *, int[2]);
char	*get_name_with_id(t_list *, int);

#endif /* !CHAINED_LIST_H_ */
