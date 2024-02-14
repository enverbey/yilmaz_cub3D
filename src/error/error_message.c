/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:53:24 by envyilma          #+#    #+#             */
/*   Updated: 2024/02/12 20:27:38 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include "../../include/cub3d.h"
#include <unistd.h>

void	error_massage(char *str, t_map *map, int fd)
{
	if (fd > 0)
		close(fd);
	free_tmap(map);
	ft_putstr("  \033[31m|  ERROR |\033[0m\n");
	ft_putstr(str);
	exit(-1);
}
