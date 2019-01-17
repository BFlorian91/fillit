/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:47:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/17 18:45:17 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Check si on peut poser la piece
*/
static int	can_place(char **map, t_tri *minos, int i, int j, int size)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (i + minos->pos[k].x < 0 || i + minos->pos[k].x >= size)
			return (0);
		if (j + minos->pos[k].y < 0 || j + minos->pos[k].y >= size)
			return (0);
		if (map[j + minos->pos[k].y][i + minos->pos[k].x] != '.')
			return (0);
		k++;
	}
	return (1);
}

void		place_t(t_tri *lst, char **map, int i, int j)
{
	map[j][i] = lst->c;
	map[j + lst->pos[1].y][i + lst->pos[1].x] = lst->c;	
	map[j + lst->pos[2].y][i + lst->pos[2].x] = lst->c;	
	map[j + lst->pos[3].y][i + lst->pos[3].x] = lst->c;	
}

   static void		remove_t(t_tri *lst, char **map, int i, int j)
   {
   map[j][i] = '.';
   map[j + lst->pos[1].y][i + lst->pos[1].x] = '.';	
   map[j + lst->pos[2].y][i + lst->pos[2].x] = '.';	
   map[j + lst->pos[3].y][i + lst->pos[3].x] = '.';
   }

/*
 * BACKTRACK HERE
 */

int		solving(t_tri *minos, char **map, int size, char c)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (can_place(map, minos, i, j, size))
			{
				place_t(minos, map, i, j);
				//print_map(map, size);
				if (minos->next == NULL || solving(minos->next, map, size, c + 1))
					return (1);
				remove_t(minos, map, i, j);
			}
			i++;
		}
		j++;
	}
	return (0);
}
