/*
** pos.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Apr 13 13:52:54 2017 Benjamin GAYMAY
** Last update Fri Apr 21 16:13:29 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"

static int	free_pos(char *pos)
{
  free(pos);
  return (ERROR);
}

int	get_pos(char *line, int pos[2])
{
  int	i;
  int	f;
  char	*c_pos;

  i = -1;
  while (line[++i] != '\0' && line[i] != ' ');
  ++i;
  if ((c_pos = my_malloc_strncpy(&line[i], i)) == NULL)
    return (ERROR);
  f = -1;
  while (c_pos[++f] != '\0' && c_pos[f] != ' ');
  c_pos[f] = '\0';
  if (my_str_isnum(c_pos) != SUCCESS || my_getnbr_error(c_pos) != SUCCESS)
    return (free_pos(c_pos));
  pos[0] = my_getnbr(c_pos);
  free(c_pos);
  while (line[++i] != '\0' && line[i] != ' ');
  if ((c_pos = my_malloc_strcpy(&line[++i])) == NULL)
    return (ERROR);
  if (my_str_isnum(c_pos) != SUCCESS || my_getnbr_error(c_pos) != SUCCESS)
    return (free_pos(c_pos));
  pos[1] = my_getnbr(c_pos);
  free(c_pos);
  return (SUCCESS);
}
