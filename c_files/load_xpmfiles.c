#include "so_long.h"

void	ft_new_xpm_image(t_vars *vars, t_data *data, char *str)
{
	int	w;
	int	h;

	data->img = mlx_xpm_file_to_image(vars->mlx, str, &w, &h);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll,
			&data->e);
}

int	ft_load_xpmfiles(t_vars *vars)
{
	ft_new_xpm_image(vars, &vars->monde.space,
			"../images/ground.XPM");
	ft_new_xpm_image(vars, &vars->monde.collect,
			"../images/collectibles.XPM");
	ft_new_xpm_image(vars, &vars->monde.cdoor,
			"../images/closeddoor.XPM");
	ft_new_xpm_image(vars, &vars->monde.odoor,
			"../images/opendoor.XPM");
	ft_new_xpm_image(vars, &vars->ply.spr, "../images/playeur.XPM");
	if (vars->monde.space.img == NULL || vars->monde.collect.img == NULL ||
			vars->monde.cdoor.img == NULL ||
			vars->monde.odoor.img == NULL ||
			vars->ply.spr.img == NULL)
		return (0);
	return (1);
}
