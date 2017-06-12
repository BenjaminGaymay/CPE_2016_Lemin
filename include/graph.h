/*
** graph.h for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr  5 16:20:43 2017 Benjamin GAYMAY
** Last update Wed Apr 12 11:13:27 2017 Benjamin GAYMAY
*/

#ifndef GRAPH_H_
# define GRAPH_H_

typedef	struct	s_node
{
  int		dest;
  int		ant;
  char		*name;

  struct s_node	*next;
}		t_node;

typedef struct	s_room
{
  t_node	*node;
}		t_room;

typedef struct	s_graph
{
  int		nb_room;
  t_room	*list_arr;
}		t_graph;

#include "chained_list.h"

void	print_graph(t_graph *, t_list *);
void	add_edge(t_graph *, t_list *, int, int);
t_graph	*create_graph(int);

#endif /* !GRAPH_H_ */
