
#include"cube3d.h"

float	dst(t_vector2f a, t_vector2f b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}

void	read_map(t_game *game, char **av)
{	
	int	file;
	char	*line;
	int	x;
	int	y;
	int	z;

	// sky and floor color
	game->map.col[0] = 0x2E1A47FF;
	game->map.col[1] = 0x1E3226FF;
	game->fov = 70;
	game->column_size = WIDTH / (game->fov * 2);
	game->tile_size = 50;
	// read map.cub file
	x = 50;
	y = 50;
	game->map.map = (int **) malloc(y * sizeof(int *));
	z = -1;
	while (++z < y)
		game->map.map[z] = (int *) malloc(x * sizeof(int));
	y = -1;
	while (++y < 50)
	{
		x = -1;
		while (++x < 50)
			game->map.map[x][y] = -1;
	}
	file = open(av[1], O_RDONLY);
	line = get_next_line(file);
	y = 0;
	while (line)
	{
		printf("%s", line);
		x = -1;
		while (line[++x] && line[x] != '\n')
		{
			game->map.map[x][y] = line[x] - '0';
			if (line[x] == 'N')
			{
				game->map.map[x][y] = 0;
				game->player.pos.x = (float) x * game->tile_size;
				game->player.pos.y = (float) y * game->tile_size;
				game->player.rot = P2;
			}
		}
		y++;
		line = get_next_line(file);
	}
	printf("player (%f, %f)\n", game->player.pos.x, game->player.pos.y);
}

void	draw_cube(t_game *game, t_vector2i start, t_vector2i end, int color)
{
	t_vector2i	v;

	v.x = start.x;
	v.y = start.y;
	while (v.x < end.x)
	{
		mlx_put_pixel(game->img, v.x, v.y, color);
		v.y++;
		if (v.y == end.y)
		{
			v.x++;
			v.y = start.y;
		}
	}
}

void	draw_colum(t_game *game, int x, float faraway, int col)
{
	t_vector2i	a;
	t_vector2i	b;
	int		c;
	int		s;
	int		h;
	int		o;

	// column
	s = game->tile_size;
	c = game->column_size;
	//o = WIDTH - (int) h / 2;
	h = (int) faraway ;
	if (h > HEIGHT / 2)
		h = HEIGHT / 2;
	a.x = x * c;
	a.y = h;
	b.x = x * c + c;
	b.y = HEIGHT - h + 1;
	//printf("x = %d, d = %d | %f, h = %d\n",x,  (int) faraway, faraway, h);
	//printf("a = x = %d, y = %d\n", a.x, a.y);
	//printf("b = x = %d, y = %d\n", b.x, b.y);
	if (a.x > 0 && a.x < WIDTH - 10 && b.x > 0 && b.y < HEIGHT - 10)
		draw_cube(game, a, b, col);
}

void	draw_walls(t_game *game)
{
	t_vector2i	ptile;
	t_vector2i	tile;
	t_vector2f	tilestep;
	t_vector2f	ray;
	t_vector2f	vray;
	t_vector2f	hray;
	t_vector2f	d;
	t_vector2f	p;
	t_vector3f	step;
	float		ray_angel;
	int		dof;
	float		ds;
	int		ts;
	int		c;
	int		fov;
	float		arctan;
	float		fish;

	// walls 
	/*
	ray_angel = game->player.rot - 45;
	x = 0;
	while ((int) ray_angel < game->player.rot + 45)
	{
		distance = 0;
		ray.x = game->player.pos.x;
		ray.y = game->player.pos.y;
		tile.x = ray.x / game->tile_size;
		tile.y = ray.y / game->tile_size;
		printf("ray %f (%d, %d)\n", ray_angel, ray.x, ray.y);
		printf("tile (%d, %d) = %d\n", tile.x, tile.y, game->map.map[tile.x][tile.y]);
		while (game->map.map[tile.x][tile.y] == 1)
		{
			distance++;
			printf("a = x = %d, y = %d\n", a.x, a.y);
			printf("b = x = %d, y = %d\n", b.x, b.y);
			ray.x += cos(ray_angel);
			ray.y += sin(ray_angel);
			tile.x = ray.x / game->tile_size;
			tile.y = ray.y / game->tile_size;
			//printf("ray %d (%d, %d)\n", ray_angel, ray.x, ray.y);
			//printf("tile (%d, %d) = %d\n", tile.x, tile.y, game->map.map[tile.x][tile.y]);
		}
		//printf("col (%d, %d)\n", x, distance);
		if (distance > 300)
			distance = 300;
		draw_colum(game, x, distance, 0xAAAA99FF);
		ray_angel += 0.1;
		x += game->column_size;
	}
	*/
	/*
	fov = 30;
	ray_angel = game->player.rot - fov;
	ptile.x = game->player.pos.x / game->tile_size;
	ptile.y = game->player.pos.y / game->tile_size;
	d.x = game->player.pos.x - ptile.x; 
	d.y = game->player.pos.y - ptile.y;
	c = 100;
	x = 0;
	if (cos(ray_angel) >= 0)
	{
		tilestep.x = 1;
		step.x = -tan(ray_angel);
		ray.x = ptile.x + d.x - d.y / tan(ray_angel);
	}
		draw_line1(game, p, ray);
	else
	{
		tilestep.x = -1;
		step.x = tan(ray_angel);
		ray.x = ptile.x + d.x - d.y / tan(ray_angel);
	}
	if (sin(ray_angel) >= 0)
	{
		tilestep.y = 1;
		step.y = 1/tan(ray_angel);
		ray.y = ptile.y + d.y + d.x / tan(ray_angel);
	}
	else
	{
		tilestep.y = -1;
		step.y = -1/tan(ray_angel);
		ray.y = ptile.y + d.y + d.x / tan(ray_angel);
	}
	while (1)
	{
		distance = ray.x * cos(game->player.rot) + ray.y * sin(game->player.rot);
		printf("d = %d\n", distance);
		while (ray.x > ptile.x)
		{
			printf("x = %d, p = %d\n", ray.x, ptile.x);
			if (game->map.map[ray.x / game->tile_size][ptile.y] == 2)
			{
				draw_colum(game, x, distance / c, 0xAAAA99FF);
				break ;
			}
			ptile.y += tilestep.x;
			ray.x += step.x;
		}
		while (ray.y < ptile.y)
		{
			printf("y = %d, p = %d\n", ray.y, ptile.y);
			if (game->map.map[ptile.x][ray.y / game->tile_size] == 2)
			{
				draw_colum(game, x, distance / c, 0xAAAA99FF);
				break ;
			}
			ptile.x += tilestep.y;
			ray.y += step.y;
		}
	}
	*/
	c = 1;
	fov = game->fov / 2;
	p = game->player.pos;
	ts = game->tile_size;
	ray_angel = game->player.rot - fov * DR;
	//ray_angel = game->player.rot;
	//printf("rot=%f\n", game->player.rot);
	d.x = 10000;
	d.y = 10000;
	//while (ray_angel == game->player.rot)
	while (ray_angel <= game->player.rot + fov * DR)
	{
		// horizon
		dof = 16;
		arctan = -1 / tan(ray_angel);
		if (ray_angel > PI)
		{
			ray.y = ((int) p.y / ts) * ts - 0.001;
			ray.x = (p.y - ray.y) * arctan + p.x;
			step.y = -ts;
			step.x = -step.y * arctan;
		}
		else if (ray_angel < PI)
		{
			ray.y = ((int) p.y / ts) * ts + ts;
			ray.x = (p.y - ray.y) * arctan + p.x;
			step.y = ts;
			step.x = -step.y * arctan;
		}
		else
		{
			ray.x = p.x;
			ray.y = p.y;
			dof = 0;
		}
		while (dof > 0)
		{
			tile.x = ray.x / ts;
			tile.y = ray.y / ts;
			//printf("hray %f (%f, %f)\n", ray_angel, ray.x, ray.y);
			//printf("tile (%d, %d)\n", tile.x, tile.y);
			if (tile.x > 0 && tile.y > 0 && tile.x < 50 && tile.y < 50 && game->map.map[tile.x][tile.y] == 1)
			{
				//printf("htile (%d, %d) = %d\n", tile.x, tile.y, game->map.map[tile.x][tile.y]);
				dof = 0;
				hray = ray;
				d.x = dst(hray, p);
			}
			else
			{
				dof--;
				ray.x += step.x;
				ray.y += step.y;
			}
		}
		// vertical
		dof = 16;
		arctan = -tan(ray_angel);
		if (ray_angel > P2 && ray_angel < P3)
		{
			ray.x = ((int) p.x / ts) * ts - 0.001;
			ray.y = (p.x - ray.x) * arctan + p.y;
			step.x = -ts;
			step.y = -step.x * arctan;
		}
		else if (ray_angel < P2 || ray_angel > P3)
		{
			ray.x = ((int) p.x / ts) * ts + ts;
			ray.y = (p.x - ray.x) * arctan + p.y;
			step.x = ts;
			step.y = -step.x * arctan;
		}
		else
		{
			ray.x = p.x;
			ray.y = p.y;
			dof = 0;
		}
		//printf("vray %f (%f, %f)\n", ray_angel, ray.x, ray.y);
		while (dof > 0)
		{
			tile.x = ray.x / ts;
			tile.y = ray.y / ts;
		//printf("vray %f (%f, %f)\n", ray_angel, ray.x, ray.y);
			if (tile.x > 0 && tile.y > 0 && tile.x < 50 && tile.y < 50
					&& game->map.map[tile.x][tile.y] == 1)
			{
		//printf("vtile (%d, %d) = %d\n", tile.x, tile.y, game->map.map[tile.x][tile.y]);
				dof = 0;
				vray = ray;
				d.y = dst(vray, p);
			}
			else
			{
				dof--;
				ray.x += step.x;
				ray.y += step.y;
			}
		}
		// distance
		if (d.x > d.y)
		{
			ds = d.y;
			ray = hray;
		}
		else
		{
			ds = d.x;
			ray = vray;
		}
		fish = game->player.rot - ray_angel;
		if (fish > 2 * PI)
			fish -= 2 * PI;
		if (fish < 0)
			fish += 2 * PI;
		ds = ds * cos(fish);
		//if (ray.x > 0 && ray.y > 0 && ray.x < WIDTH && ray.y < HEIGHT)
		//	draw_line1(game, p, ray);
		//printf("c = %d ,ds = %d\n", c, ds / 30);
		draw_colum(game, c, ds, 0xAAAA99FF);
		//printf("%.1f ", ds);
		ray_angel += DR / 2;
		c += 1;
	}
	//printf("\n");
}

void	draw_map(t_game *game)
{
	t_vector2i	a;
	t_vector2i	b;
	t_vector2i	i;
	t_vector2f	p1;
	t_vector2f	p2;
	int		t;
	int		scale;

	// map
	scale = 5;
	t = game->tile_size / scale;
	i.y = 0;
	while (i.y < 50)
	{
		i.x = 0;
		while (i.x < 50)
		{
			a.x = i.x * t;
			a.y = i.y * t;
			b.x = (i.x + 1) * t;
			b.y = (i.y + 1) * t;
			//draw_cube(game, a, b, 0xedf2f4ff);
			if (game->map.map[i.x][i.y] == 0)
				draw_cube(game, a, b, 0x8d99aeff);
			if (game->map.map[i.x][i.y] == 1)
				draw_cube(game, a, b, 0x2b2d42ff);
			i.x++;
		}
		i.y++;
	}
	// player
	/*
	p1.x = (int) game->player.pos.x;
	p1.y = (int) game->player.pos.y;
	p1.c = int2rgb(0xffffffff);
	p2.x = (int) game->player.pos.x + cos(game->player.rot) * 5;
	p2.y = (int) game->player.pos.y + sin(game->player.rot) * 5;
	p2.c = int2rgb(0xffffffff);
	draw_lineDDA(game, p1, p2);
	*/
	p1.x = game->player.pos.x / scale;
	p1.y = game->player.pos.y / scale;
	p2.x = game->player.pos.x / scale + cos(game->player.rot) * 5;
	p2.y = game->player.pos.y / scale + sin(game->player.rot) * 5;
	draw_line1(game, p1, p2);
}

void	draw_game(t_game *game)
{
	t_vector2i	a;
	t_vector2i	b;

	// sky
	a.x = 0;
	a.y = 0;
	b.x = WIDTH;
	b.y = HEIGHT / 2;
	draw_cube(game, a, b, game->map.col[0]);
	// floor
	a.x = 0;
	a.y = HEIGHT / 2;
	b.x = WIDTH;
	b.y = HEIGHT;
	draw_cube(game, a, b, game->map.col[1]);
	// walls
	draw_walls(game);
}

void    render(t_game *game)
{
        mlx_delete_image(game->mlx, game->img);
        game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	draw_game(game);
        draw_map(game);
        if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
                return ;
}

void    hook(void *param)
{
        t_game  *game;
	float	pdx;
	float	pdy;

        game = (t_game *)param;
        render(game);
	if (game->player.rot > 2 * PI)
		game->player.rot -= 2 * PI;
	if (game->player.rot < 0)
		game->player.rot += 2 * PI;
	pdx = cos(game->player.rot) * 3;
	pdy = sin(game->player.rot) * 3;
        if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        {
		game->player.rot += DR * 2;
        }
        if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        {
		game->player.rot -= DR * 2;
        }
        if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player.pos.x += pdx;
		game->player.pos.y += pdy;
        }
        if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        {
		game->player.pos.x -= pdx;
		game->player.pos.y -= pdy;
        }
        if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        {
                mlx_close_window(game->mlx);
                //free(game->p);
        }
}

void movehook(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	float	pdx;
	float	pdy;

	if (game->player.rot > 2 * PI)
		game->player.rot -= 2 * PI;
	if (game->player.rot < 0)
		game->player.rot += 2 * PI;
	pdx = cos(game->player.rot) * 10;
	pdy = sin(game->player.rot) * 10;
	param = (t_game *) game;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->player.rot += DR;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->player.rot += DR;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->player.pos.x += 10;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->player.pos.y += 10;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		read_map(&game, av);
		game.mlx = mlx_init(WIDTH, HEIGHT, "mossy rocks", true);
		game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
		if (!game.img || mlx_image_to_window(game.mlx, game.img, 0, 0) < 0)
			return (0);
		draw_game(&game);
		mlx_loop_hook(game.mlx, hook, &game);
		//mlx_key_hook(game.mlx, &movehook, &game);
		mlx_loop(game.mlx);
		mlx_terminate(game.mlx);
	}
}
