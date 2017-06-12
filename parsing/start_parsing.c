/*
** start_parsing.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Apr  7 08:54:13 2017 Benjamin GAYMAY
** Last update Fri Apr 28 15:44:15 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "parsing.h"
#include "use_array.h"
#include "my_printf.h"
#include "my_fprintf.h"

static int	get_info(t_map_info *info, char **file)
{
  if (file[0] == NULL)
    return (disp_error("Error : File is empty.\n", ERROR));
  else if (my_str_isnum(file[0]) != SUCCESS)
    return (disp_error("Error : First line wrong format.\n", ERROR));
  info->nb_ant = my_getnbr(file[0]);
  if (info->nb_ant == 0)
    return (disp_error("Error : Ant number is null.\n", ERROR));
  my_printf("#number_of_ants\n%d\n", info->nb_ant);
  return (SUCCESS);
}

int	line_is_connect(char *line)
{
  int	i;

  i = -1;
  if (count_space(line) != 0)
    return (FAILURE);
  while (line[++i] != '\0' && line[i] != '-');
  if (line[i] == '\0' || i == 0)
    return (FAILURE);
  while (line[++i] != '\0' && line[i] != '-');
  if (line[i] == '-')
    return (FAILURE);
  return (SUCCESS);
}

static int	get_start_end(t_map_info *info, t_list **room_name,
			      char **file)
{
  if ((info->start = get_start(file)) == NULL)
    {
      free_room(*room_name);
      return (ERROR);
    }
  else if ((info->end = get_end(file)) == NULL)
    {
      free_room(*room_name);
      free(info->start);
      return (ERROR);
    }
  return (SUCCESS);
}

int	start_parsing(t_graph **graph, t_map_info *info, t_list **room_name)
{
  char	**file;
  int	i;

  i = 0;
  if ((file = fill_file()) == NULL)
    return (ERROR);
  if (get_info(info, file) == ERROR)
    return (free_and_return(file, ERROR));
  *room_name = NULL;
  if (get_rooms(room_name, file, &i) == ERROR)
    {
      free_room(*room_name);
      return (free_and_return(file, ERROR));
    }
  if (get_start_end(info, room_name, file) == ERROR)
    return (free_and_return(file, ERROR));
  *graph = create_graph(my_len_list(*room_name));
  if (get_connections(*room_name, *graph, file, &i) == ERROR)
    {
      free_info(info);
      free_room(*room_name);
      free_graph(*graph);
      return (free_and_return(file, ERROR));
    }
  return (free_and_return(file, SUCCESS));
}
