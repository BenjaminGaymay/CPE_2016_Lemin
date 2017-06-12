/*
** room.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Apr  6 17:30:48 2017 Benjamin GAYMAY
** Last update Wed Apr 12 10:51:21 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "graph.h"

char		*get_name_with_id(t_list *room_name, int id)
{
  t_list	*tmp;

  tmp = room_name;
  while (tmp != NULL && id != tmp->id)
    tmp = tmp->next;
  if (tmp == NULL)
    return (NULL);
  return (tmp->name);
}

int		get_id_with_name(t_list *room_name, char *name)
{
  t_list	*tmp;

  tmp = room_name;
  while (tmp != NULL && my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (-1);
  return (tmp->id);
}

int		room_in_list(t_list *room_name, char *room)
{
  t_list	*tmp;

  tmp = room_name;
  while (tmp != NULL)
    {
      if (my_strcmp(room, tmp->name) == SUCCESS)
	return (SUCCESS);
      tmp = tmp->next;
    }
  return (FAILURE);
}

int		add_room(t_list **room_name, char *new_name, int pos[2])
{
  t_list	*tmp;
  int		nb;

  tmp = *room_name;
  nb = 0;
  while (tmp != NULL && my_strcmp(tmp->name, new_name) != 0)
    {
      tmp = tmp->next;
      ++nb;
    }
  if (tmp == NULL)
    my_put_in_list(room_name, nb, new_name, pos);
  else
    {
      free(new_name);
      return (disp_error("Error : Room define twice.\n", ERROR));
    }
  return (SUCCESS);
}
