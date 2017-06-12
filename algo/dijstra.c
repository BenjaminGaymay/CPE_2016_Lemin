/*
** dijstra.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Apr 11 11:53:27 2017 Benjamin GAYMAY
** Last update Thu Apr 13 14:22:21 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "algo.h"
#include "my_printf.h"
#include "my_fprintf.h"

static int	**malloc_dijstra(int size)
{
  int		i;
  int		j;
  int		**dijstra;

  if ((dijstra = malloc(sizeof(int *) * (size + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i != size)
    {
      if ((dijstra[i] = malloc(sizeof(int) * (size + 1))) == NULL)
	return (NULL);
      j = -1;
      while (++j != size)
	dijstra[i][j] = -1;
    }
  return (dijstra);
}

static int	fill_dijstra(t_graph *graph, int **dijstra)
{
  t_node	*tmp;
  int		i;

  i = -1;
  while (++i != graph->nb_room)
    {
      tmp = graph->list_arr[i].node;
      while (tmp != NULL)
	{
	  dijstra[i][tmp->dest] = 1;
	  tmp = tmp->next;
	}
    }
  return (SUCCESS);
}

static void	dead_end(int **dijstra, int start, int end, int size)
{
  int		i;
  int		j;
  int		k;

  i = -1;
  while (++i != size)
    {
      j = -1;
      while (++j != size)
	if (i != start && i != end &&
	    count_connections(dijstra[i], size) == 1)
	  {
	    k = -1;
	    while (++k != size)
	      if (dijstra[i][k] != -1)
		{
		  dijstra[i][k] = -1;
		  dijstra[k][i] = -1;
		}
	  }
    }
}

int	check_path_exist(int **dijstra, int size)
{
  int	i;

  i = -1;
  while (++i != size)
    if (count_connections(dijstra[i], size) != 0)
      return (SUCCESS);
  return (FAILURE);
}

int	**get_dijstra_tab(t_graph *graph, t_list *room_name, t_map_info info)
{
  int	**dijstra;
  int	id_start;
  int	id_end;

  if ((dijstra = malloc_dijstra(graph->nb_room)) == NULL)
    return (NULL);
  fill_dijstra(graph, dijstra);
  id_start = get_id_with_name(room_name, info.start);
  id_end = get_id_with_name(room_name, info.end);
  dead_end(dijstra, id_start, id_end, graph->nb_room);
  return (dijstra);
}
