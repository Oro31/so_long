#include "so_long.h"

void	ft_close(t_vars *vars)
{
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		if (vars->mlx)
			free(vars->mlx);
	}
}

int	ft_exit(t_vars *vars)
{
	ft_free(vars);
	ft_close(vars);
	exit(0);
	return (0);
}

void	ft_moove(t_vars *vars, char c)
{
	vars->monde.map[vars->ply.posy][vars->ply.posx] = '0';
	if (c == 'w')
		vars->ply.dir = 'N';
	else if (c == 's')
		vars->ply.dir = 'S';
	else if (c == 'a')
		vars->ply.dir = 'W';
	else if (c == 'd')
		vars->ply.dir = 'E';
	ft_deplacer(vars);	
	if (vars->monde.map[vars->ply.posy][vars->ply.posx] == 'C')
		vars->monde.ncol--;
	if (vars->monde.ncol == 0)
		vars->monde.map[vars->monde.posye][vars->monde.posxe] = 'e';
	if (vars->monde.map[vars->ply.posy][vars->ply.posx] == 'e')
		vars->end = 1;
	vars->monde.map[vars->ply.posy][vars->ply.posx] = 'P';
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return (ft_exit(vars));
	else if (keycode == 119) /*may be 122 with azerty*/
		ft_moove(vars, 'w');
	else if (keycode == 115)
		ft_moove(vars, 's');
	else if (keycode == 97) /*may be 113 with azerty*/
		ft_moove(vars, 'a');
	else if (keycode == 100)
		ft_moove(vars, 'd');
	ft_draw(vars);
	if (vars->end == 1)
		return (ft_exit(vars));
	return (1);
}
