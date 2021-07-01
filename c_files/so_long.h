#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../gnl/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int	bpp;
	int	ll;
	int	e;
}		t_data;

typedef	struct	s_ply {
	t_data	spr;
	int	posx;
	int	posy;
	int	ndep;
	char	dir;
	int	xdir;
	int	ydir;
}		t_ply;

typedef	struct	s_map {
	t_data	space;
	t_data	collect;
	t_data	cdoor;
	t_data	odoor;
	char	**map;
	int	ncol;
	int	posxe;
	int	posye;
}		t_map;

typedef	struct	s_rsl {
	int	w;
	int	h;
}		t_rsl;

typedef	struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_ply	ply;
	t_map	monde;
	t_rsl	rsl;
	int	end;
	int	width;
	int	height;
}		t_vars;

char	*ft_itoa(int nb);
char	*ft_realloc_itoa(char *str, char c);

/*draw.c*/

void	ft_put_pixel_on_img(t_data *img, int color, int x, int y);
void	ft_get_background(t_vars *vars);
void	ft_get_visual(t_vars *vars);
void	ft_draw(t_vars *vars);	

/*#############################*/

/*image.c*/

int	ft_myxpm_pixelput(t_vars *vars, int x, int y);
int	ft_get_ply_xpm_pixel(t_data *data, int x, int y);
int	ft_get_xpm_pixel(t_data *img, int x, int y);

/*#############################*/

/*deplacer.c*/

int	ft_is_not_wall(t_vars *vars, char c, int s);
void	ft_change_ply_attributes(t_ply *ply, int x, int y, char c);
void	ft_deplacer(t_vars *vars);

/*#############################*/

/*ft_key_hook.c*/

void	ft_close(t_vars *vars);
int	ft_exit(t_vars *vars);
void	ft_moove(t_vars *vars, char c);
int	ft_key_hook(int keycode, t_vars *vars);

/*#############################*/

/*load_xpmfiles.c*/

void	ft_new_xpm_image(t_vars *vars, t_data *data, char *str);
int	ft_load_xpmfiles(t_vars *vars);

/*#############################*/

/*ft_free.c*/

void	ft_free_sprites(t_vars *vars);
void	ft_free_map(t_map *monde);
void	ft_free(t_vars *vars);

/*#############################*/

/*ft_init.c*/

void	ft_init_data_pointer(t_data *data);
void	ft_init_monde_pointer(t_map *monde);
void	ft_init_pointer(t_vars *vars);
int	ft_init_before_parse(t_vars *vars);

/*#############################*/

/*ft_parse_map.c*/

int	ft_ismap_member(char c);
int	ft_len_mpline(char *line);
char	*ft_linemap_realloc(char **map, int i, int maxlen);
char	*ft_linemap_fill(char *line, int maxlen);
char	**ft_parse_map(char *line, char **map);

/*#############################*/

/*valid_map.c*/

int	ft_lenmax_mpline(char **map);
int	ft_is_space_diagwalled_tool(char **map, int i, int j, int len);
int	ft_is_space_diagwalled(char **map, int i, int j, int len);
int	ft_is_space_walled(char **map, int, int j, int len);
int	ft_ismap_valid(char **map);

/*#############################*/

/*monde.c*/

int	ft_init_world(t_vars *vars, t_map *monde);

/*#############################*/
