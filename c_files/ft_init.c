/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data_pointer(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
}

void	ft_init_monde_pointer(t_map *monde)
{
	ft_init_data_pointer(&monde->space);
	ft_init_data_pointer(&monde->collect);
	ft_init_data_pointer(&monde->cdoor);
	ft_init_data_pointer(&monde->odoor);
	monde->map = NULL;
}

void	ft_init_pointer(t_vars *vars)
{
	ft_init_data_pointer(&vars->img);
	ft_init_data_pointer(&vars->ply.spr);
	vars->mlx = NULL;
	vars->win = NULL;
}

int	ft_init_before_parse(t_vars *vars)
{
	ft_init_pointer(vars);
	vars->rsl.w = 0;
	vars->rsl.h = 0;
	vars->ply.posx = -1;
	vars->ply.posy = -1;
	vars->ply.ndep = 0;
	vars->ply.dir = '\0';
	vars->ply.xdir = 0;
	vars->ply.ydir = 0;
	vars->monde.ncol = 0;
	vars->monde.posxe = -1;
	vars->monde.posye = -1;
	vars->mlx = mlx_init();
	if (!(vars->mlx))
		return (0);
	return (1);
}
