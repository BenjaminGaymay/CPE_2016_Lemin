/*
** chained_list.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr 19 15:25:22 2017 Benjamin GAYMAY
** Last update Thu Apr 20 10:43:52 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "graph.h"
#include "my_printf.h"
#include "chained_list.h"

int		ant_in_list(t_ants **list, int *path, int pos, int nb_ant)
{
  static int	id;
  t_ants	*element;

  if ((element = malloc(sizeof(*element))) == NULL)
    return (84);
  element->id = nb_ant - id;
  element->pos = pos;
  element->path = path;
  element->next = *list;
  *list = element;
  ++id;
  return (0);
}
