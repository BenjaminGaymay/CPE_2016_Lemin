/*
** clear_file.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr 19 14:53:48 2017 Benjamin GAYMAY
** Last update Thu Apr 20 13:07:21 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "parsing.h"

void	clear_file(char **file)
{
  int	line;
  int	col;

  line = -1;
  while (file[++line] != NULL)
    {
      col = -1;
      while (file[line][++col] != '\0')
	if (my_strcmp(file[line], "##start") != 0 &&
	    my_strcmp(file[line], "##end") != 0 &&
	    file[line][col] == '#')
	  {
	    file[line][col] = '\0';
	    file[line] = clear_str(file[line], ' ');
	    break ;
	  }
    }
}
