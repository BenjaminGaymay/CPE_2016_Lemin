/*
** final_paths.c for  in /home/robin/delivery/CPE_2016_Lemin
**
** Made by Robin Pronnier
** Login   <robin@epitech.net>
**
** Started on  Fri Apr 14 18:59:47 2017 Robin Pronnier
** Last update Thu Apr 20 12:07:51 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "algo.h"
#include "my_printf.h"
#include "my_fprintf.h"

static int	check_same_ways(t_algo *algo, int **tab,
				int *line, int size)
{
  int		i;
  int		j;
  int		x;

  if (size == 0)
    size = 1;
  i = -1;
  while (++i != size)
    {
      j = 0;
      while (line[++j] != algo->id_end && line[j] != -1)
	{
	  x = 0;
	  while (tab[i][++x] != algo->id_end && tab[i][x] != -1)
	    if (tab[i][x] == line[j])
	      return (i);
	}
    }
  return (-1);
}

static int	modify_paths(t_algo *algo, int **paths,
			     int **final_paths)
{
  int		i;
  int		j;

  j = 1;
  i = -1;
  while (algo->nb_line - 1 != ++i)
    {
      if (paths[i][1] != final_paths[j - 1][1] &&
	  paths[i][1] != final_paths[0][1] &&
	  check_same_ways(algo, final_paths, paths[i], j - 1) == -1)
	final_paths[j++] = paths[i];
      else if (count_connections(final_paths[j - 1], algo->nb_col) >
	       count_connections(paths[i], algo->nb_col) &&
	       paths[i][1] != final_paths[0][1] &&
	       check_same_ways(algo, final_paths, paths[i], j - 1) == -1)
	final_paths[j - 1] = paths[i];
    }
  final_paths[j++] = paths[i];
  return (j);
}

static void	delete_doubles(t_algo *algo, int **final_paths,
			       int size)
{
  int		i;
  int		nb;

  i = 0;
  while (final_paths[++i][0] != -1)
    {
      if ((nb = check_same_ways(algo, final_paths, final_paths[i], i)) != -1)
	{
	  if (count_connections(final_paths[nb], algo->nb_col) <=
	      count_connections(final_paths[i], algo->nb_col))
	    nb = nb + 1;
	  while (++nb < size)
	    final_paths[nb - 1] = final_paths[nb];
	}
    }
}

static void	put_in_asc(t_algo *algo, int **final_paths)
{
  int		i;
  int		*bis;

  i = 0;
  while (final_paths[++i][0] != -1)
    {
      if (count_connections(final_paths[i - 1], algo->nb_col) >
	  count_connections(final_paths[i], algo->nb_col))
	{
	  bis = final_paths[i - 1];
	  final_paths[i - 1] = final_paths[i];
	  final_paths[i] = bis;
	  i = 0;
	}
    }
}

int		**get_final_paths(t_algo *algo, int **paths)
{
  int		i;
  int		j;
  int		**final_paths;

  i = -1;
  if ((final_paths = malloc(sizeof(int *) * (algo->nb_line + 1))) == NULL)
    return (NULL);
  final_paths[0] = paths[0];
  while (algo->nb_line - 1 != ++i)
    if (count_connections(final_paths[0], algo->nb_col) >
	count_connections(paths[i], algo->nb_col))
      final_paths[0] = paths[i];
  j = modify_paths(algo, paths, final_paths);
  delete_doubles(algo, final_paths, j);
  put_in_asc(algo, final_paths);
  return (final_paths);
}
