/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/15 19:50:40 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tri	*lst;
	char	**map;
	int		size;
	int		i;
	char 	c;

	i = 4;
	c = 'A';
	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (ac == 2)
	{
		if ((size = input(av[1])))
		{
			map = create_map(size);
			lst = parse(av[1]);
			ft_putendl("if == 1");		// <--- NEW test;
			if (!backtrack(&lst, map, size, c))
				ft_putendl("Work?");
			print_map(map, size);
			delete_map(map);
		}
		else
			ft_putstr("Error");
	}
	return (0);
}
