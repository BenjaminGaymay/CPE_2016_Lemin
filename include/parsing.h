/*
** parsing.h for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr  5 16:20:43 2017 Benjamin GAYMAY
** Last update Fri Apr 28 15:31:58 2017 Benjamin GAYMAY
*/

#ifndef PARSING_H_
# define PARSING_H_

typedef struct	s_map_info
{
  int		nb_ant;
  char		*start;
  char		*end;
}		t_map_info;

#include "graph.h"

void	show_rooms(char **);
void	clear_file(char **);
void	*my_calloc(int, int);
void	free_room(t_list *);
void	free_graph(t_graph *);
void	free_info(t_map_info *);
void	do_my_free(t_map_info *, t_list *, t_graph *);
int	get_pos(char *, int *);
int	line_is_connect(char *);
int	check_pos_validity(t_list **);
int	get_rooms(t_list **, char **, int *);
int	check_name_validity(t_list **);
int	room_in_list(t_list *, char *);
int	check_room(t_list **, int *, char *);
int	get_connections(t_list *, t_graph *, char **, int *);
int	start_parsing(t_graph **, t_map_info *, t_list **);
char	*get_start(char **);
char	*get_end(char **);
char	**fill_file();

#endif /* !PARSING_H_ */
