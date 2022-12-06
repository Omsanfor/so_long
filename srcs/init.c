/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:18:53 by omsanfor          #+#    #+#             */
/*   Updated: 2022/04/05 13:18:54 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*ft_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_exit(1, "Error\nAllocation memory error\n", game);
	game->map = (t_map *)malloc(sizeof(t_map));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	game->wall = (t_img *)malloc(sizeof(t_img));
	game->background = (t_img *)malloc(sizeof(t_img));
	game->exit_0 = (t_img *)malloc(sizeof(t_img));
	game->exit_1 = (t_img *)malloc(sizeof(t_img));
	game->key = (t_img *)malloc(sizeof(t_img));
	game->player->player = (t_img *)malloc(sizeof(t_img));
	if (!(game->map) || !(game->mlx) || !(game->wall) || !(game->player)
		|| !(game->background) || !(game->exit_0) || !(game->key)
		|| !(game->player->player) || !(game->exit_1))
		ft_exit(1, "Error\nAllocation memory error\n", game);
	return (game);
}

void	ft_init_player(t_game *game)
{
	game->player->collect = 0;
	game->player->steps = 0;
	game->player->exit_done = 0;
}

void	ft_init_file(t_game *game, t_img *img, char *path)
{
	img->width = 0;
	img->height = 0;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, path,
			&img->width, &img->height);
}

void	ft_init_img(t_game *game)
{
	ft_init_file(game, game->background, BACKGROUND);
	ft_init_file(game, game->wall, WALL);
	ft_init_file(game, game->key, KEY);
	ft_init_file(game, game->player->player, PLAYER);
	ft_init_file(game, game->exit_0, EXIT_0);
	ft_init_file(game, game->exit_1, EXIT_1);
}
