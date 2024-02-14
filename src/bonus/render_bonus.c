/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:14:51 by envyilma          #+#    #+#             */
/*   Updated: 2024/02/13 02:46:22 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../minilibx/mlx.h"
#include "../../include/game.h"

int	render_next_frame(t_program *program)
{
	t_coordinat	cord1;
	t_coordinat	cord2;
	t_coordinat	cord3;
	t_coordinat	cord4;

	cord1.x = 0;
	cord1.y = 0;
	cord2.x = 999;
	cord2.y = 500;
	put_rectangle(&program->img2, cord1, cord2, program->map->c_rgb);
	cord3.x = 0;
	cord3.y = 500;
	cord4.x = 999;
	cord4.y = 999;
	put_rectangle(&program->img2, cord3, cord4, program->map->f_rgb);
	set_bonus_map(program);
	move(program);
	all_rays(program, &program->img2);
	mlx_clear_window(program->mlx, program->window);
	mlx_put_image_to_window(program->mlx, \
	program->window, program->img2.img, 0, 0);
	mlx_put_image_to_window(program->mlx, \
	program->window, program->img1.img, 0, 0);
	return (1);
}
