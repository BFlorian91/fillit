/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:00:02 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/10 19:39:09 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tri		*parsing(int fd)
{
	int x;
	int y;
	int i;
	int j;
	int cnt;
	char *buf;
	t_tri *new;
	t_tri *lst;
	char c;

	c = 'A';
	while (read(fd, buf, 21))
	{
		x = 0;
		y = 0;
		i = 0;
		j = 0;
		cnt = 0;
		if ((new = malloc(sizeof(t_tri))) == NULL)
			return (NULL);
		new->next = lst;
		lst = new;
		new->c = c++;
		while (cnt < 4 && *buf)
		{
			if (*buf == '\n')
			{
				i = 0;
				j++;
				++buf;
			}
			if (*buf == '#')
			{
				if (cnt == 0)
				{
					new->pos[0].x = 0;
					new->pos[0].y = 0;
					x = i;
					y = j;
				} else {
					new->pos[cnt].x = i - x;
					new->pos[cnt].y = j - y;
				}
				++cnt;
			}
			++i;
			++buf;
		}
	}
	return (lst);
}
