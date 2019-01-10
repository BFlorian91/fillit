/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:43:53 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/10 19:36:27 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

/*
 *	bufucture creation du news
 *
*/
typedef struct 	s_tri
{
	char c;
	t_point pos[4];
	struct s_tri *next;
}				t_tri;

t_tri *parsing(int fd);


#endif
