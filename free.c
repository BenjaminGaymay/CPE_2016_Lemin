/*
** free.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Apr  7 08:06:55 2017 Benjamin GAYMAY
** Last update Fri Apr 28 14:44:24 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "parsing.h"
#include "use_array.h"
#include "algo.h"

void		free_info(t_map_info *info)
{
  if (info->start != NULL)
    free(info->start);
  if (info->end != NULL)
    free(info->end);
}

void		free_room(t_list *room_name)
{
  t_list	*tmp;

  while (room_name != NULL)
    {
      tmp = room_name->next;
      free(room_name->name);
      free(room_name);
      room_name = tmp;
    }
}

void		free_graph(t_graph *graph)
{
  t_node	*tmp;
  int		i;

  i = 0;
  while (i < graph->nb_room)
    {
      while (graph->list_arr[i].node != NULL)
	{
	  tmp = graph->list_arr[i].node->next;
	  free(graph->list_arr[i].node);
	  graph->list_arr[i].node = tmp;
	}
      ++i;
    }
  free(graph->list_arr);
  free(graph);
}

void		do_my_free(t_map_info *info, t_list *room_name, t_graph *graph)
{
  free_info(info);
  free_room(room_name);
  free_graph(graph);
}

void	free_all(int **dijstra, int room, int **final_paths)
{
  free_dijstra(dijstra, room);
  free(final_paths);
}
