/*
** space.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Apr  7 09:27:33 2017 Benjamin GAYMAY
** Last update Mon Apr 10 17:08:59 2017 Benjamin GAYMAY
*/

int	count_space(char *line)
{
  int	i;
  int	space;

  i = -1;
  space = 0;
  while (line[++i])
    if (line[i] == ' ')
      ++space;
  return (space);
}
