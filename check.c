/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:49:11 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/13 21:04:21 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	mapping(char *buf, int cnt_tetri)
{
	int		count_sharp;
	int		size_of_map;
	int		i;
	int		j;
	char	map[4][4];

	count_sharp = 0;
	size_of_map = 0;
	i = 0;
	while (*buf)
	{
		if (*buf == '#')
			count_sharp++;
		buf++;
	}
	size_of_map = ft_sqrt(count_sharp * cnt_tetri);
	while (i < size_of_map)
	{
		j = 0;
		while (j < size_of_map)
			map[i][j++] = '.';
		i++;
	}
	return (size_of_map);
}
/*
void	display_map(int size_of_map)
{
	int 	i;
	int 	j;
	char 	map[4][4];

	i = 0;
	while (i < size_of_map)
	{
		j = 0;
		ft_putchar('\n');
		while (j < size_of_map)
			ft_putchar(map[i][j++]);
		i++;
	}
		ft_putchar('\n');
}
*/
static int	check_block(char *buf)
{
	int i;
	int dot;
	int sharp;
	int line;

	i = 0;
	dot = 0;
	sharp = 0;
	line = 0;
	while (i < 20)
	{
		buf[i] == '\n' ? line++ : line;
		buf[i] == '.' ? dot++ : dot;
		buf[i] == '#' ? sharp++ : sharp;
		i++;
	}
	if (dot != 12 || sharp != 4 || line != 4)
		return (0);
	if (buf[20] == '\n')
		line++;
	return (line);
}

static int	check_tetri(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			(i + 1) < 20 && buf[i + 1] == '#' ? count++ : count;
			(i - 1) >= 0 && buf[i - 1] == '#' ? count++ : count;
			(i + 5) < 20 && buf[i + 5] == '#' ? count++ : count;
			(i - 5) >= 0 && buf[i - 5] == '#' ? count++ : count;
		}
		i++;
	}
	return (count == 6 || count == 8 ? count : 0);
}

int			input(char *av)
{
	int		fd;
	int		ret;
	char	buf[21];
	int 	size;
	int		cnt_tetri;

	t_map	*map;
	fd = open(av, O_RDONLY);
	cnt_tetri = 0;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (!check_block(buf))
			return (0);
		if (!check_tetri(buf))
			return (0);
		cnt_tetri++;
	}
	size = mapping(buf, cnt_tetri);
	map = (t_map*)malloc(sizeof(char *) * size);
	map = create_map(size);
	print_map(map);
	close(fd);
	return (1);
}
