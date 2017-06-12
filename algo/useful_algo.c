/*
** useful_algo.c for  in /home/robin/delivery/CPE_2016_Lemin
**
** Made by Robin Pronnier
** Login   <robin@epitech.net>
**
** Started on  Wed Apr 12 19:12:11 2017 Robin Pronnier
** Last update Thu Apr 13 14:22:36 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "algo.h"

void	copy_int_tab(int **old, int **new, t_algo *algo)
{
  int	i;

  i = -1;
  while (++i != algo->nb_line)
    new[i] = old[i];
}

int	**realloc_int_tab(int **old, t_algo *algo)
{
  int	i;
  int	**new;

  if (algo->nb_line != 0)
    {
      if ((new = malloc(sizeof(int *) * (algo->nb_line + 1))) == NULL)
	return (NULL);
      copy_int_tab(old, new, algo);
      free(old);
    }
  else
    if ((new = malloc(sizeof(int *))) == NULL)
      return (NULL);
  i = -1;
  if ((new[algo->nb_line] = malloc(sizeof(int) * (algo->nb_col))) == NULL)
    return (NULL);
  while (++i != algo->nb_col)
    new[algo->nb_line][i] = -1;
  ++algo->nb_line;
  return (new);
}

int	check_double(int *line, int size, int nb)
{
  int	i;

  i = -1;
  while (++i != size && line[i] != -1)
    if (line[i] == nb)
      return (1);
  return (0);
}

int	last_line(t_algo *algo, int **path_list)
{
  int	i;

  i = -1;
  while (++i != algo->nb_col)
    path_list[algo->nb_line - 1][i] = -1;
  return (FAILURE);
}

int	count_connections(int *line, int size)
{
  int	i;
  int	nb_one;

  i = -1;
  nb_one = 0;
  while (++i != size)
    if (line[i] != -1)
      ++nb_one;
  return (nb_one);
}
