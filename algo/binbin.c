/*
** binbin.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Apr 11 13:08:37 2017 Benjamin GAYMAY
** Last update Fri Apr 28 11:23:41 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"
#include "algo.h"

int	add_case_in_path_list(int **path_list, t_algo *algo)
{
  if (algo->dij_x == algo->nb_col)
    {
      if (algo->room <= 1)
	return (FAILURE);
      path_list[algo->nb_line - 1][algo->room] = -1;
      algo->dij_x = path_list[algo->nb_line - 1][algo->room - 1];
      algo->dij_y = path_list[algo->nb_line - 1][algo->room - 2];
      --algo->room;
    }
  else
    {
      path_list[algo->nb_line - 1][algo->room] = algo->dij_x;
      algo->dij_y = algo->dij_x;
      ++algo->room;
      if (algo->dij_x != algo->id_end)
	algo->dij_x = -1;
    }
  return (SUCCESS);
}

void	copy_pre(int *src, int *dest, t_algo *algo)
{
  algo->room = -1;
  while (++algo->room != algo->nb_col && src[algo->room] != algo->id_end)
    dest[algo->room] = src[algo->room];
  algo->dij_x = src[algo->room];
  algo->dij_y = dest[algo->room - 1];
  algo->loop = 0;
}

int	find_path(int **dijstra, int **path_list, t_algo *algo)
{
  path_list[algo->nb_line - 1][0] = algo->id_start;
  algo->dij_y = path_list[algo->nb_line - 1][0];
  algo->dij_x = -1;
  algo->room = 1;
  if (algo->nb_line != 1)
    copy_pre(path_list[algo->nb_line - 2], path_list[algo->nb_line - 1], algo);
  while (algo->dij_x != algo->id_end || algo->loop == 0)
    {
      while (++algo->dij_x != algo->nb_col)
	if (check_double(path_list[algo->nb_line - 1],
			 algo->nb_col, algo->dij_x) == 0 &&
	    dijstra[algo->dij_y][algo->dij_x] != -1)
	  break ;
      if (add_case_in_path_list(path_list, algo) == FAILURE)
	return (last_line(algo, path_list));
      ++algo->loop;
    }
  return (SUCCESS);
}

int	**get_path_list(int **dijstra, t_algo *algo)
{
  int	**path_list;
  int	i;

  i = -1;
  if ((path_list = realloc_int_tab(NULL, algo)) == NULL)
    {
      free_dijstra(dijstra, algo->nb_col);
      return (NULL);
    }
  while (find_path(dijstra, path_list, algo) == SUCCESS &&
	 algo->nb_line < 1000)
    if ((path_list = realloc_int_tab(path_list, algo)) == NULL)
      {
	free_dijstra(dijstra, algo->nb_col);
	return (NULL);
      }
  if (algo->nb_line >= 1000)
    while (++i != algo->nb_col)
      path_list[algo->nb_line - 1][i] = -1;
  return (path_list);
}
