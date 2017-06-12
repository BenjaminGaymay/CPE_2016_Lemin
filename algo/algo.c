/*
** algo.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr  5 16:15:29 2017 Benjamin GAYMAY
** Last update Fri Apr 28 11:11:17 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"
#include "algo.h"
#include "my_printf.h"
#include "my_fprintf.h"

void		free_dijstra(int **dijstra, int size)
{
  int		i;

  i = -1;
  while (++i != size)
    free(dijstra[i]);
  free(dijstra);
}

void		free_path_list(int **path_list, t_algo algo)
{
  int		i;

  i = -1;
  while (++i != algo.nb_line)
    free(path_list[i]);
  free(path_list);
}

int		check_path_error(int **dijstra, t_graph *graph,
			 t_list *room_name, t_map_info info)
{
  int		id_start;
  int		id_end;

  id_start = get_id_with_name(room_name, info.start);
  id_end = get_id_with_name(room_name, info.end);
  if ((check_path_exist(dijstra, graph->nb_room) == FAILURE) ||
      (count_connections(dijstra[id_start], graph->nb_room) == 0 ||
       (count_connections(dijstra[id_end], graph->nb_room) == 0)))
    my_fprintf("Error : No path available.\n");
  else
    return (SUCCESS);
  free_dijstra(dijstra, graph->nb_room);
  return (ERROR);
}

t_algo		set_algo(t_list *room_name, t_map_info info, int nb_col)
{
  t_algo	algo;

  algo.id_start = get_id_with_name(room_name, info.start);
  algo.id_end = get_id_with_name(room_name, info.end);
  algo.nb_col = nb_col;
  algo.nb_line = 0;
  algo.room = 1;
  algo.dij_x = -1;
  algo.dij_y = 0;
  algo.loop = 0;
  return (algo);
}

int		start_algo(t_graph *graph, t_list *room_name, t_map_info info)
{
  t_algo	algo;
  int		**dijstra;
  int		**path_list;
  int		**final_paths;

  if ((dijstra = get_dijstra_tab(graph, room_name, info)) == NULL)
    return (ERROR);
  if ((check_path_error(dijstra, graph, room_name, info)) == ERROR)
    return (ERROR);
  algo = set_algo(room_name, info, graph->nb_room);
  if ((path_list = get_path_list(dijstra, &algo)) == NULL)
    return (ERROR);
  if (algo.nb_line == 1)
    {
      free_path_list(path_list, algo);
      free_dijstra(dijstra, graph->nb_room);
      return (disp_error("Error : No path available.\n", ERROR));
    }
  if ((final_paths = get_final_paths(&algo, path_list)) == NULL)
    return (ERROR);
  if ((movem_ant(final_paths, &algo, room_name, &info)) == ERROR)
    return (ERROR);
  free_path_list(path_list, algo);
  free_all(dijstra, graph->nb_room, final_paths);
  return (SUCCESS);
}
