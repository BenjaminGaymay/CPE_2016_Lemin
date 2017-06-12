/*
** my_showtab.c for my_showtab in /home/benjamin.g/save/Create/library
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Tue Jan 17 20:56:55 2017 Benjamin GAYMAY
** Last update Tue Apr 11 12:08:35 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

void	my_showtab(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      my_putstr(array[i++]);
      my_putchar('\n');
    }
}

void	my_show_int_tab(int **array, int nb_line, int nb_col)
{
  int	i;
  int	j;

  i = -1;
  while (++i != nb_line)
    {
      j = -1;
      while (++j != nb_col)
	my_printf("%d ", array[i][j]);
      my_putchar('\n');
    }
}
