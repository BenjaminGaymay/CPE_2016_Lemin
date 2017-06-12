/*
** my_malloc_strcpy.c for my_malloc_strcpy in /home/benjamin.g/save/Create/library
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Thu Jan 19 18:13:18 2017 Benjamin GAYMAY
** Last update Thu Apr  6 14:07:37 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"

char	*my_malloc_strcpy(char *s2)
{
  int	i;
  char	*s1;

  if ((s1 = malloc(sizeof(char) * (my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s2[i] != '\0')
    {
      s1[i] = s2[i];
      ++i;
    }
  s1[i] = '\0';
  return (s1);
}

char	*my_malloc_strncpy(char *s2, int nb)
{
  int	i;
  char	*s1;

  if ((s1 = malloc(sizeof(char) * (my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (nb > i && s2[i] != '\0')
    {
      s1[i] = s2[i];
      ++i;
    }
  s1[i] = '\0';
  return (s1);
}
