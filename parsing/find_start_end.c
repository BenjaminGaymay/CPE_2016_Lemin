/*
** find_start_end.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Apr  7 09:25:39 2017 Benjamin GAYMAY
** Last update Thu Apr 13 11:11:36 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"
#include "my_fprintf.h"

static int	my_str_in_tab(char **array, char *str)
{
  int		i;
  int		nb_str;

  i = -1;
  nb_str = 0;
  while (array[++i] != NULL)
    if (my_strcmp(array[i], str) == 0)
      ++nb_str;
  if (nb_str == 0)
    my_fprintf("Error : %s line missing.\n", str);
  else if (nb_str != 1)
    my_fprintf("Error : %s multiple definitions.\n", str);
  return (nb_str);
}

char	*get_start(char **file)
{
  int	i;
  char	*line;

  i = -1;
  if (my_str_in_tab(file, "##start") != 1)
    return (NULL);
  while (file[++i] != NULL && my_strcmp(file[i], "##start") != 0);
  if (file[i + 1] == NULL ||
      my_strncmp(file[i + 1], "#", 1) == 0 ||
      count_space(file[i + 1]) != 2)
    my_fprintf("Error : ##start line wrong format.\n");
  else
    {
      line = my_malloc_strcpy(file[i + 1]);
      i = -1;
      while (line[++i] != '\0' && line[i] != ' ');
      line[i] = '\0';
      return (line);
    }
  return (NULL);
}

char	*get_end(char **file)
{
  int	i;
  char	*line;

  i = -1;
  if (my_str_in_tab(file, "##end") != 1)
    return (NULL);
  while (file[++i] != NULL && my_strcmp(file[i], "##end") != 0);
  if (file[i + 1] == NULL ||
      my_strncmp(file[i + 1], "#", 1) == 0 ||
      count_space(file[i + 1]) != 2)
    my_fprintf("Error : ##end line wrong format.\n");
  else
    {
      line = my_malloc_strcpy(file[i + 1]);
      i = -1;
      while (line[++i] != '\0' && line[i] != ' ');
      line[i] = '\0';
      return (line);
    }
  return (NULL);
}
