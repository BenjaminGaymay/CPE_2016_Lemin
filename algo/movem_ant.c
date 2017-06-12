/*
** movem_ant.c for lemin in /home/benjamin.g/delivery/CPE_2016_Lemin
**
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
**
** Started on  Wed Apr 19 15:07:31 2017 Benjamin GAYMAY
** Last update Fri Apr 28 15:00:14 2017 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "algo.h"
#include "my_printf.h"
#include "chained_list.h"

# define EXIT 1
# define CONTINUE 0

int		print_loop(t_ants **ants, t_algo *algo, int leave)
{
  static int	nb_leave;
  t_list	*room;
  t_ants	*tmp;

  room = get_room_addr(NULL, 1);
  tmp = *ants;
  nb_leave += leave;
  while (tmp != NULL && tmp->id - 1 != nb_leave)
    {
      tmp->pos = tmp->path[find_pos(tmp->pos, tmp->path)];
      my_printf("P%d-%s", tmp->id, get_name_with_id(room, tmp->pos));
      if (tmp->next != NULL && tmp->next->id - 1 != nb_leave)
	my_putchar(' ');
      if (tmp->pos == algo->id_end)
	{
	  tmp = tmp->next;
	  free(*ants);
	  *ants = tmp;
	}
      else
	tmp = tmp->next;
    }
  my_putchar('\n');
  return (*ants == NULL ? EXIT : CONTINUE);
}

int		move_pos(int *leave, t_ants **tmp, int **paths, int i)
{
  ++*leave;
  (*tmp)->path = paths[i];
  return (0);
}

void		get_ants_path(t_ants **ant, t_algo *algo,
			      int **paths, int *nb_ant)
{
  t_ants	*tmp;
  int		leave;
  int		i;

  leave = 0;
  i = -1;
  tmp = *ant;
  while (tmp != NULL)
    {
      while (paths[++i][0] != -1)
	if (count_connections(paths[i], algo->nb_col) - 1 <= *nb_ant
	    && move_pos(&leave, &tmp, paths, i) == 0)
	  break ;
      if (paths[i][0] == -1 || tmp->next == NULL)
	{
	  *nb_ant -= leave;
	  i = -1;
	  if (print_loop(ant, algo, (leave == 0 ? 1 : leave)) == EXIT)
	    return ;
	  leave = 0;
	}
      else
	tmp = tmp->next;
    }
}

int		movem_ant(int **paths, t_algo *algo,
			  t_list *room, t_map_info *info)
{
  t_ants	*ant;
  int		i;
  int		nb_ant;

  ant = NULL;
  i = -1;
  nb_ant = info->nb_ant;
  while (++i != nb_ant)
    if ((ant_in_list(&ant, paths[0], algo->id_start, nb_ant)) == ERROR)
      return (ERROR);
  get_room_addr(room, 0);
  get_ants_path(&ant, algo, paths, &nb_ant);
  return (SUCCESS);
}
