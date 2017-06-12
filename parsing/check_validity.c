/*
** check_validity.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Apr 21 16:29:37 2017 Benjamin GAYMAY
** Last update Sat Apr 22 13:38:39 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"
#include "my_fprintf.h"

int		check_name_validity(t_list **room_name)
{
  t_list	*tmp;
  int		i;

  tmp = *room_name;
  while (tmp != NULL)
    {
      i = -1;
      while (tmp->name[++i])
	if (tmp->name[i] == '-')
	  return (disp_error("Error : Name must not contain '-'.\n", ERROR));
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int		check_pos_validity(t_list **room_name)
{
  t_list	*tmp;
  t_list	*tmp_2;

  tmp = *room_name;
  while (tmp->next != NULL)
    {
      tmp_2 = tmp->next;
      while (tmp_2 != NULL)
	{
	  if (tmp->x == tmp_2->x && tmp->y == tmp_2->y)
	    {
	      my_fprintf("Error : ");
	      my_fprintf("Rooms '%s' and '%s'", tmp_2->name, tmp->name);
	      return (disp_error(" have same positions.\n", ERROR));
	    }
	  tmp_2 = tmp_2->next;
	}
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int	check_room(t_list **room_name, int pos[2], char *file_line)
{
  char	*line;
  int	i;

  i = -1;
  if ((line = my_malloc_strcpy(file_line)) == NULL)
    return (ERROR);
  while (line[++i] != '\0' && line[i] != ' ');
  line[i] = '\0';
  if (get_pos(file_line, pos) == ERROR)
    return (free_str_and_return(line, ERROR));
  if (add_room(room_name, line, pos) == ERROR ||
      check_name_validity(room_name) == ERROR ||
      check_pos_validity(room_name) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
