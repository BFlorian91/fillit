/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:47:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/13 20:32:33 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		place_t(t_tri *lst, char **map, int i, int j)
{
	map[i][j] = lst->c;
	map[i + lst->pos[1].y][j + lst->pos[1].x] = lst->c;	
	map[i + lst->pos[2].y][j + lst->pos[2].x] = lst->c;	
	map[i + lst->pos[3].y][j + lst->pos[3].x] = lst->c;	
}

static void		remove_t(t_tri *lst, char **map, int i, int j)
{
	map[i][j] = '.';
	map[i + lst->pos[1].y][j + lst->pos[1].x] = '.';	
	map[i + lst->pos[2].y][j + lst->pos[2].x] = '.';	
	map[i + lst->pos[3].y][j + lst->pos[3].x] = '.';
}

/*
 * BACKTRACK HERE
*/ 
