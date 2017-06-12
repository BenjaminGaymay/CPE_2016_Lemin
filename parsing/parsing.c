/*
** parsing.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr  5 16:15:57 2017 Benjamin GAYMAY
** Last update Fri Apr 28 22:53:09 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "parsing.h"
#include "my_printf.h"
#include "my_fprintf.h"
#include "get_next_line.h"

char	**fill_file()
{
  int	i;
  char	*s;
  char	**my_file;

  if ((my_file = my_calloc(1, sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  my_file[0] = NULL;
  while ((s = get_next_line(0)))
    {
      s = clear_str(transform_char(s, '\t', ' '), ' ');
      if ((my_strncmp(s, "#", 1) == 0 && my_strcmp(s, "##end") != 0 &&
	   my_strcmp(s, "##start") != 0))
	free(s);
      else
	{
	  my_file = my_array_realloc(my_file, 2);
	  my_file[++i] = s;
	}
    }
  my_file[++i] = NULL;
  clear_file(my_file);
  return (my_file);
}

int	get_rooms(t_list **room_name, char **file, int *i)
{
  int	pos[2];

  while (file[++*i] != NULL)
    {
      if (line_is_connect(file[*i]) != SUCCESS)
	my_printf((*i == 1) ? "#rooms\n%s\n" : "%s\n", file[*i]);
      if (my_strncmp(file[*i], "#", 1) != 0 &&
	  line_is_connect(file[*i]) != SUCCESS && count_space(file[*i]) != 2)
	return (disp_error("Error : Bad line format.\n", ERROR));
      if (my_strncmp(file[*i], "#", 1) != 0 && count_space(file[*i]) != 2)
	break ;
      else if (my_strncmp(file[*i], "#", 1) != 0)
	if (check_room(room_name, pos, file[*i]) == ERROR)
	  return (ERROR);
    }
  --*i;
  return (SUCCESS);
}

int	add_connec_in_graph(char *n_1, char *n_2, t_list *room, t_graph *graph)
{
  int	id_1;
  int	id_2;

  if (room_in_list(room, n_1) != SUCCESS)
    my_fprintf("Error : '%s' room not define.\n", n_1);
  else if (room_in_list(room, n_2) != SUCCESS)
    my_fprintf("Error : '%s' room not define.\n", n_2);
  else
    {
      id_1 = get_id_with_name(room, n_1);
      id_2 = get_id_with_name(room, n_2);
      add_edge(graph, room, id_1, id_2);
      free(n_1);
      free(n_2);
      return (SUCCESS);
    }
  return (ERROR);
}

int	cut_line_to_add_edge(t_list *room_name, t_graph *graph, char *line)
{
  int	i;
  char	*name_1;
  char	*name_2;

  i = -1;
  while (line[++i] != '\0' && line[i] != '-');
  if (i == 0)
    return (disp_error("Error : Bad connection.\n", ERROR));
  name_1 = my_malloc_strncpy(line, i);
  if (line[i] != '\0' && line[i + 1] != '\0')
    name_2 = my_malloc_strcpy(&line[i + 1]);
  else
    {
      free(name_1);
      return (disp_error("Error : Bad connection.\n", ERROR));
    }
  if (add_connec_in_graph(name_1, name_2, room_name, graph) == SUCCESS)
    return (SUCCESS);
  free(name_1);
  free(name_2);
  return (ERROR);
}

int	get_connections(t_list *room_name, t_graph *graph, char **file, int *i)
{
  my_printf("#tunnels\n");
  while (file[++*i] != NULL)
    {
      my_printf("%s\n", file[*i]);
      if (my_strncmp(file[*i], "#", 1) != 0 &&
	  line_is_connect(file[*i]) != SUCCESS &&
	  count_space(file[*i]) == 2)
	return (disp_error("Error : Tunnel is define before a room.\n", ERROR));
      else if (my_strncmp(file[*i], "#", 1) != 0 &&
	       line_is_connect(file[*i]) != SUCCESS)
	return (disp_error("Error : Bad line format.\n", ERROR));
      else if (my_strncmp(file[*i], "#", 1) != 0 &&
	       my_strncmp(file[*i], "\0", 1) != 0 &&
	       count_space(file[*i]) == 0)
	if (cut_line_to_add_edge(room_name, graph, file[*i]) == ERROR)
	  return (ERROR);
    }
  return (SUCCESS);
}
