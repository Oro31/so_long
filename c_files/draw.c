#include "so_long.h"

void	ft_put_pixel_on_img(t_data *img, int color, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_get_background(t_vars *vars)
{
	int	color;
	int	i;
	int	j;

	j = 0;
	while (j < vars->rsl.h)
	{
		i = 0;
		while (i < vars->rsl.w)
		{
			if (vars->monde.map[j / 24][i / 24] != '1')
			{
				color = ft_get_xpm_pixel(&vars->monde.space,
						i % 24, j % 24);
				ft_put_pixel_on_img(&vars->img, color, i, j);
			}
			i++;
		}
		j++;
	}
}

void	ft_get_visual(t_vars *vars)
{
	int	color;
	int	i;
	int	j;

	j = 0;
	while (j < vars->rsl.h)
	{
		i = 0;
		while (i < vars->rsl.w)
		{
			if (vars->monde.map[j / 24][i / 24] != '1' &&
					vars->monde.map[j / 24][i / 24] != '0')
			{
				color = ft_myxpm_pixelput(vars, i , j);
				ft_put_pixel_on_img(&vars->img, color, i, j);
			}
			i++;
		}
		j++;
	}
}

void	ft_draw(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, vars->rsl.w, vars->rsl.h);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.ll, &vars->img.e);
	ft_get_background(vars);
	ft_get_visual(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
