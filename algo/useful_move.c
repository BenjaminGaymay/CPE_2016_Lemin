/*
** useful_move.c for  in /home/robin/delivery/CPE_2016_Lemin
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Thu Apr 20 11:46:24 2017 Robin Pronnier
** Last update Thu Apr 20 11:47:29 2017 Robin Pronnier
*/

#include <stdlib.h>
#include "my.h"
#include "algo.h"

int		find_pos(int pos, int *path)
{
  int		i;

  i = -1;
  while (path[++i] != pos && path[i] != -1);
  return (i + 1);
}

t_list		*get_room_addr(t_list *room, int get_or_give)
{
  static t_list	*save;

  if (get_or_give == 0)
    save = room;
  else
    return (save);
  return (NULL);
}
