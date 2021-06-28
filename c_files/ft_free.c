/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_sprites(t_vars *vars)
{
	if (vars->ply.spr.img)
		mlx_destroy_image(vars->mlx, vars->ply.spr.img);
	if (vars->monde.space.img)
		mlx_destroy_image(vars->mlx, vars->monde.space.img);
	if (vars->monde.collect.img)
		mlx_destroy_image(vars->mlx, vars->monde.collect.img);
	if (vars->monde.cdoor.img)
		mlx_destroy_image(vars->mlx, vars->monde.cdoor.img);
	if (vars->monde.odoor.img)
		mlx_destroy_image(vars->mlx, vars->monde.odoor.img);
}

void	ft_free_map(t_map *monde)
{
	int	i;

	i = 0;
	while (monde->map[i])
	{
		free(monde->map[i]);
		i++;
	}
	if (monde->map)
		free(monde->map);
}

void	ft_free(t_vars *vars)
{
	ft_free_sprites(vars);
	ft_free_map(&vars->monde);
}
