#include "so_long.h"

int	ft_is_not_wall(t_vars *vars, char c, int s)
{
	int	x;
	int	y;

	x = vars->ply.posx;
	y = vars->ply.posy;
	if (c == 'y')
		y += s;
	else if (c == 'x')
		x += s;
	if (vars->monde.map[y][x] == '1' || vars->monde.map[y][x] == 'E')
		return (0);
	return (1);
}

void	ft_change_ply_attributes(t_ply *ply, int x, int y, char c)
{
	char	*ndep;
	int	i;

	ply->ndep += 1;
	ndep = ft_itoa(ply->ndep);
	i = -1;
	while (ndep[++i])
		write(1, &ndep[i], 1);
	write(1, "\n", 1);
	free(ndep);
	if (c == 'y')
	{
		ply->ydir = (1 + y) / 2;
		ply->xdir = 1;
	}
	else if (c == 'x')
	{
		ply->xdir = 0;
		ply->ydir = (1 - x) / 2;
	}
	ply->posx += x;
	ply->posy += y;
}

void	ft_deplacer(t_vars *vars)
{
	if (vars->ply.dir == 'N')
	{
		if (ft_is_not_wall(vars, 'y', -1))
			ft_change_ply_attributes(&vars->ply, 0, -1, 'y');
	}
	else if (vars->ply.dir == 'S')
	{
		if (ft_is_not_wall(vars, 'y', 1))
			ft_change_ply_attributes(&vars->ply, 0, 1, 'y');
	}
	else if (vars->ply.dir == 'W')
	{
		if (ft_is_not_wall(vars, 'x', -1))
			ft_change_ply_attributes(&vars->ply, -1, 0, 'x');
	}
	else if (vars->ply.dir == 'E')
	{
		if (ft_is_not_wall(vars, 'x', 1))
			ft_change_ply_attributes(&vars->ply, 1, 0, 'x');
	}
}
