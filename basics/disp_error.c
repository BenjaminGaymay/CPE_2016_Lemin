/*
** disp_error.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Apr 10 16:27:40 2017 Benjamin GAYMAY
** Last update Sat Apr 22 13:11:18 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "use_array.h"
#include "my_fprintf.h"

int	free_and_return(char **array, int ret)
{
  free_array(array);
  return (ret);
}

int	free_str_and_return(char *str, int ret)
{
  free(str);
  if (ret == ERROR)
    return (disp_error("Error : Invalid postion format.\n", ERROR));
  return (ret);
}

int	disp_error(char *str, int ret)
{
  my_fprintf("%s", str);
  return (ret);
}
