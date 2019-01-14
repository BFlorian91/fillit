/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:47:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/14 16:36:05 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



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

int		solving(t_tri **tetriminos, char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)

			if (map[i][j] == '.')
			{
				place_t(*tetriminos, map, i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
