/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/18 20:52:44 by flbeaumo         ###   ########.fr       */
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
		return (1);
	}
	if (!(input(av[1])))
	{
		ft_putstr("error\n");
		return (1);
	}
	else
	{
		lst = parse(av[1]);
		if ((map.map = create_map(26)) == NULL)
			return (0);
		while (!solving(lst, map, 'A'))
			(map.size)++;
		print_map(map);
		clean_map(map);
	}
	return (0);
}
