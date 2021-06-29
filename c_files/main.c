#include "so_long.h"

int	ft_resize_hook(t_vars *vars)
{
	ft_draw(vars);
	return (1);
}

void	ft_parse_line(char *line, t_vars *vars)
{
	vars->monde.map = ft_parse_map(line, vars->monde.map);
}

int	main()
{
	t_vars	vars;
	int	fd;
	char	*line;
	int	res;


	res = ft_init_before_parse(&vars);
	if (!(res))
		return (0);
	fd = open("map.ber", O_RDONLY);
	if(!(fd))
		return (0);
	while (get_next_line(fd, &line) > 0)
		ft_parse_line(line, &vars);
	close(fd);
	if (!(ft_ismap_valid(vars.monde.map)))
		return (ft_exit(&vars));
	res = ft_init_world(&vars, &vars.monde);
	if (!(res))
		return (ft_exit(&vars));
	vars.win = mlx_new_window(vars.mlx, vars.rsl.w, vars.rsl.h,
			"./so_long");
	res = ft_load_xpmfiles(&vars);
	if (!(res))
		return (ft_exit(&vars));
	ft_draw(&vars);
	mlx_hook(vars.win, 3, 1L<<1, ft_key_hook, &vars);
	/*mlx_hook(vars.win, 17, 1L<<17, ft_exit, &vars);*/
	/*mlx_hook(vars.win, 9, 1L<<21, ft_resize_hook, &vars);*/
	mlx_loop(vars.mlx);
	return (0);
}
