/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:42:21 by envyilma          #+#    #+#             */
/*   Updated: 2024/02/12 21:05:01 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../minilibx/mlx.h"
#include "../../include/game.h"

int	main(int ac, char **av)
{
	t_program	program;
	t_map		map;

	if (check_arg(ac, av, &map) == 1)
		return (1);
	program.mlx = mlx_init();
	program.window = mlx_new_window(program.mlx, 1000, 1000, "cub3d");
	init_program(&program, &map);
	mlx_hook(program.window, 2, (1L << 0), key_down, &program);
	mlx_hook(program.window, 3, (1L << 1), key_up, &program);
	mlx_hook(program.window, 17, 0, exit_game_mouse, &program);
	program.img1.img = mlx_new_image(program.mlx, 150, 150);
	program.img1.addr = mlx_get_data_addr(program.img1.img, \
	&program.img1.bits_per_pixel, &program.img1.line_length, \
	&program.img1.endian);
	program.img2.img = mlx_new_image(program.mlx, 1000, 1000);
	program.img2.addr = mlx_get_data_addr(program.img2.img, \
	&program.img2.bits_per_pixel, &program.img2.line_length, \
	&program.img2.endian);
	render_next_frame(&program);
	mlx_loop(program.mlx);
}
