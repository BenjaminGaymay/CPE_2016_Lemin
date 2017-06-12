/*
** my_str_isnum.c for my_str_isnum in /home/benjamin.g/delivery/CPool_Day06
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Mon Oct 10 21:45:18 2016 Benjamin GAYMAY
** Last update Fri Apr 21 11:31:35 2017 Benjamin GAYMAY
*/

#include "my.h"

int		my_str_isnum(char *str)
{
  static int	rep;
  int		i;
  int		f;

  i = 0;
  f = 0;
  if (rep != 0)
    if (str[0] == '-')
      ++i;
  ++rep;
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9'))
	f++;
      i++;
    }
  return (f != 0 ? FAILURE : SUCCESS);
}
