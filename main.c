/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/17 21:04:13 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tri	*lst;
	t_map	map;

	lst = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((map.size = input(av[1])) == -1)
	{
		ft_putstr("Invalid tetriminos\n");
		return (0);
	}
	if ((map.map = create_map(16)) == NULL)
		return (0);
	lst = parse(av[1]);
	while (!solving(lst, map, 'A'))
	{
		(map.size)++;
	}
	print_map(map);
	clean_map(map);
	return (0);
}
