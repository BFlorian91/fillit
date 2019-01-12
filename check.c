/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:45:56 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/12 03:23:54 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_line(char *buf)
{
    int i;
    int dot;
    int sharp;
    int cl;

    cl = 0;
    dot = 0;
    sharp = 0;
    i = 0;
    while (i < 20)
    {
        if (buf[i] == '\n')
            cl++;
        if (buf[i] == '.')
            dot++;
        if (buf[i] == '#')
            sharp++;
        i++;
    }

    if (dot != 12 || sharp != 4 || cl != 4)
        return (0);
    if (buf[20] == '\n')
        cl++;
    return (cl);
}

int			read_file(char *av)
{
    int fd;
    int ret;
    char buf[21];

    fd = open(av, O_RDONLY);
    while ((ret = read(fd, buf, 21)))
    {
        buf[ret] = '\0';
        if (!check_line(buf))
            return (0);
    }
//    close(fd);
    return (1);
}
