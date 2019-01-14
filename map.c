/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:15:10 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/14 20:54:12 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//[Thibault] faire une fonction qui détruit tout les éléments de notre tab[i] utilisé ft_memdel ont délete tout en mémoire
//[Florian] Si tu fais une alloc dyn je pense plutot a un strdel perso (FREE + NULL) faut voir memdel peut se tenter aussi a check ce qui est mieux..

void	print_map(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
/*	while (map[i])
	{
		ft_putstr(&map[i]);
		ft_putchar('\n');
		i++;
	}
*/
	while (i < size)
	{
		j = 0;
		while (j < size)
			ft_putchar(map[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

char	**create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j <= size)
			map[i][j++] = '.';
		i++;
	}
    map[i][j] = '\0';
    
	return (map);
}
