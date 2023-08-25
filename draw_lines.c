/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:41:21 by khaimer           #+#    #+#             */
/*   Updated: 2023/08/25 18:47:20 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_direction_line(t_tools *tools,float angle)
{
    int line_length = 150;

    int x;
	int	y;
	int i = 0;
    while(i <= line_length) 
	{
        x = tools->player_x + i * cos(angle);
        y = tools->player_y + i * sin(angle);
        my_mlx_pixel_put(&tools->img, x, y, 0x00FF00); // Green color
		i++;
    }
}