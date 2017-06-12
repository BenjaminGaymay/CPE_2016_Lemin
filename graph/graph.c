/*
** graph.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr  5 16:15:42 2017 Benjamin GAYMAY
** Last update Fri Apr  7 14:44:20 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"
#include "graph.h"
#include "my_printf.h"

t_graph		*create_graph(int nb_room)
{
  int		i;
  t_graph	*graph;

  i = 0;
  if ((graph = malloc(sizeof(*graph))) == NULL)
    return (NULL);
  graph->nb_room = nb_room;
  if ((graph->list_arr = malloc(sizeof(t_room) * nb_room)) == NULL)
    return (NULL);
  while (i < nb_room)
    graph->list_arr[i++].node = NULL;
  return (graph);
}

t_node		*new_node(t_list *room_name, int dest)
{
  t_node	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->dest = dest;
  new->name = get_name_with_id(room_name, dest);
  new->ant = 0;
  new->next = NULL;
  return (new);
}

void		add_edge(t_graph *graph, t_list *room_name, int src, int dest)
{
  t_node	*new;

  new = new_node(room_name, dest);
  new->next = graph->list_arr[src].node;
  graph->list_arr[src].node = new;
  new = new_node(room_name, src);
  new->next = graph->list_arr[dest].node;
  graph->list_arr[dest].node = new;
}

void		print_graph(t_graph *graph, t_list *room_name)
{
  t_node	*tmp;
  int		i;

  i = 0;
  while (i < graph->nb_room)
    {
      tmp = graph->list_arr[i].node;
      my_printf("Room : %s", get_name_with_id(room_name, i));
      my_printf(" -- id : %d\nconnect with :\n", i);
      while (tmp != NULL)
	{
	  my_printf("\t -> %s -- id : %d\n", tmp->name, tmp->dest);
	  tmp = tmp->next;
	}
      my_putchar(++i < graph->nb_room ? '\n' : '\0');
    }
}
