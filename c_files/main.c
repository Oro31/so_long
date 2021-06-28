#include "so_long.h"

int	ft_resize_hook(t_vars *vars)
{
	ft_draw(vars);
	return (1);
}

int	main()
{
	t_vars	vars;
	int	res;


	res = ft_init_before_parse(&vars);
	if (!(res))
		return (0);
	/*GNL*/
	res = ft_init_world(&vars, &vars.monde);
	if (!(res))
		ft_exit(&vars);
	ft_draw(&vars);
	mlx_hook(vars.win, 9, 1L<<21, ft_resize_hook, &vars);
	mlx_loop(vars.mlx);
}
