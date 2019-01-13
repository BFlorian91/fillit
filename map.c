/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:15:10 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/13 17:26:02 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//[Thibault] faire une fonction qui détruit tout les éléments de notre tab[i] utilisé ft_memdel ont délete tout en mémoire
//[Florian] Si tu fais une alloc dyn je pense plutot a un strdel perso (FREE + NULL) faut voir memdel peut se tenter aussi a check ce qui est mieux..

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*create_map(int size)
{
	int		i;
	int		j;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->size = size;
	map->tab = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		map->tab[i] = ft_strnew(size);
		while (j < size)
		{
			map->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
