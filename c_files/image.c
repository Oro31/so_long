/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:50:28 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/08 11:03:50 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	ft_mymlx_pixelput(t_all *vars, t_data *data)
{
	char	*dst;
	int	x;
	int	y;
	double	px;
	double	py;


	x = -1;
	while (++x < vars->rsl.w)
	{
		y = -1;
		while (++y < vars->rsl.h)
		{
			dst = data->addr + (y * data->ll + x * (data->bpp / 8));
			px = (double)(x / ((double)vars->rsl.w / 64));
			py = (double)(y / ((double)vars->rsl.h / 64));
			px = (int)px % 64;
			py = (int)py % 64;
			*(unsigned int*)dst = 
				ft_get_xpm_pixel(&vars->spr.data[3],px, py);
		}
	}
}*/

int	ft_myxpm_pixelput(t_vars *vars, int x, int y)
{
	int	color;

	if (vars->monde.map[y / 24][x / 24] == 'P')
	{
		x = (x % 24) + (vars->ply.xdir * 24);
		y = (y % 24) + (vars->ply.ydir * 24);
		color = ft_get_ply_xpm_pixel(&vars->ply.spr, x, y);
	}
	else if (vars->monde.map[y / 24][x / 24] == 'e')
		color = ft_get_xpm_pixel(&vars->monde.odoor, x % 24, y % 24);
	else if (vars->monde.map[y / 24][x / 24] == 'E')
		color = ft_get_xpm_pixel(&vars->monde.cdoor, x % 24, y % 24);
	else if (vars->monde.map[y / 24][x / 24] == 'C')
		color = ft_get_xpm_pixel(&vars->monde.collect, x % 24, y % 24);
	return (color);
}

int	ft_get_xpm_pixel(t_data *data, int x, int y)
{
	int	color;

	color = *((int*)data->addr + (x + y * 24));
	return (color);
}

int	ft_get_ply_xpm_pixel(t_data *data, int x, int y)
{
	int	color;

	color = *((int*)data->addr + (x + y * 48));
	return (color);
}
