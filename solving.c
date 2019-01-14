/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:47:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/14 19:57:29 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Check si on peut poser la piece
*/
static int	check_for_solving(char **map, t_tri *minos, int i, int j, int size)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (i + minos->pos[k].x < 0 || i + minos->pos[k].x > size)	
			return (0);
		if (j + minos->pos[k].y < 0 || j + minos->pos[k].y > size)	
			return (0);
		if (map[i + minos->pos[k].y][j + minos->pos[k].x] != '.')
			return (0);
		k++;
	}
	return (1);
}

void		place_t(t_tri *lst, char **map, int i, int j)
{
	map[i][j] = lst->c;
	map[i + lst->pos[1].y][j + lst->pos[1].x] = lst->c;	
	map[i + lst->pos[2].y][j + lst->pos[2].x] = lst->c;	
	map[i + lst->pos[3].y][j + lst->pos[3].x] = lst->c;	
}
/*
   static void		remove_t(t_tri *lst, char **map, int i, int j)
   {
   map[i][j] = '.';
   map[i + lst->pos[1].y][j + lst->pos[1].x] = '.';	
   map[i + lst->pos[2].y][j + lst->pos[2].x] = '.';	
   map[i + lst->pos[3].y][j + lst->pos[3].x] = '.';
   }
   */
/*
 * BACKTRACK HERE
 */

int		solving(t_tri **minos, char **map, int size)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (check_for_solving(map, *minos, i, j, size))
			{
				place_t(*minos, map, i, j);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
