/*
** algo.h for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Apr 11 12:27:59 2017 Benjamin GAYMAY
** Last update Thu Apr 20 11:50:03 2017 Robin Pronnier
*/

#ifndef ALGO_H_
# define ALGO_H_

#include "parsing.h"

typedef struct	s_algo
{
  int		id_end;
  int		id_start;
  int		nb_col;
  int		nb_line;
  int		dij_x;
  int		dij_y;
  int		room;
  int		loop;
}		t_algo;

void	free_dijstra(int **, int);
void	free_all(int **, int, int **);
void	my_show_int_tab(int **, int, int);
int	check_path_exist(int **, int);
int	count_connections(int *, int);
int	start_algo(t_graph *, t_list *, t_map_info);
int	**get_dijstra_tab(t_graph *, t_list *, t_map_info);
int	**get_path_list(int **, t_algo *);
void	copy_int_tab(int **, int **, t_algo *);
int	**realloc_int_tab(int **, t_algo *);
int	check_double(int *, int, int);
int	last_line(t_algo *, int **);
int	**get_final_paths(t_algo *, int **);
int	movem_ant(int **, t_algo *, t_list *, t_map_info *);
int	find_pos(int, int *);
t_list	*get_room_addr(t_list *, int);

#endif /* !ALGO_H_ */
