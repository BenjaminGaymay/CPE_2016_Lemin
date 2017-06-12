/*
** my_calloc.c for my_calloc in /home/benjamin.g
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Fri Mar 17 08:26:29 2017 Benjamin GAYMAY
** Last update Mon Apr 10 17:07:26 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "use_array.h"

void	*my_memset(void *var, int val, size_t size, size_t nb)
{
  int	i;

  i = -1;
  while (nb--)
    ((char *)var)[++i * size] = val;
  return (var);
}

void	*my_calloc(size_t nb, size_t size)
{
  void	*ptr;

  if ((ptr = malloc(nb * size)) == NULL)
    return (NULL);
  ptr = my_memset(ptr, 0, size, nb);
  return (ptr);
}

char	**my_array_realloc(char **old, const int add)
{
  int		i;
  char		**new;

  i = 0;
  while (old[i] != NULL)
    ++i;
  if ((new = my_calloc(i + add, sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  while (old[++i])
    new[i] = old[i];
  new[i + 1] = NULL;
  free(old);
  return (new);
}
