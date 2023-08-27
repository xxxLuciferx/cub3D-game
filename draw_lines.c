/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichiba <yichiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:41:21 by khaimer           #+#    #+#             */
/*   Updated: 2023/08/27 15:01:47 by yichiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int get_pixel_color_from_image(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
int    get_pixel_color(t_tools *tools, float x, float y)
{
    unsigned int    color;
    unsigned char red ;
    unsigned char green;
    unsigned char blue;

    
    tools->img.addr = mlx_get_data_addr(tools->img.img, &tools->img.bits_per_pixel, &tools->img.line_length, &tools->img.endian);
    color = get_pixel_color_from_image(&tools->img, x, y);
    red = (color >> 16) & 0xFF;
    green = (color >> 8) & 0xFF;
    blue = color & 0xFF;

    if (red > 150 && green < 100 && blue < 100)
            return (1);
    return (0);
}


void draw_direction_line(t_tools *tools,float angle)
{
    float x;
	float	y;
	int i = 1;
    
    while(i) 
	{
        x = tools->player_x + i * cos(angle);
        y = tools->player_y + i * sin(angle);
        // printf("%d, %d\n",(int)x/50,(int)y/50);
        if(get_pixel_color(tools, x, y) == 1)
        {
            break;
        }
        my_mlx_pixel_put(&tools->img, x, y, 0x00FF00);
    // return;
		i++;
    }
}