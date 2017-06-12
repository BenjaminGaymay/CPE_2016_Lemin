/*
** chained_list.c for chained_list in /home/benjamin.g/save/test
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 24 19:01:02 2017 Benjamin GAYMAY
** Last update Fri Apr 21 16:07:53 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "graph.h"
#include "my_printf.h"

int		my_put_in_list(t_list **list, int id, char *name, int pos[2])
{
  t_list	*element;

  if ((element = malloc(sizeof(*element))) == NULL)
    return (84);
  element->id = id;
  element->x = pos[0];
  element->y = pos[1];
  element->name = name;
  element->next = *list;
  *list = element;
  return (0);
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("name : %s -- id : %d\n", tmp->name, tmp->id);
      tmp = tmp->next;
    }
}

int		my_len_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      ++i;
      tmp = tmp->next;
    }
  return (i);
}
