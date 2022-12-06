/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:19:31 by omsanfor          #+#    #+#             */
/*   Updated: 2022/04/05 13:19:32 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_steps(t_game *game)
{
	char	*num;

	num = ft_itoa(game->player->steps);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, 10,
		10, 0x000000, "Steps: ");
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, 75,
		10, 0x000000, num);
	free(num);
}

static void	ft_render(t_game *game, int i, int j)
{
	if (game->map->map[i][j] != '1')
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->background->img_ptr, j * SCALE, i * SCALE);
	else
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->wall->img_ptr, j * SCALE, i * SCALE);
	if (game->map->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->key->img_ptr, j * SCALE, i * SCALE);
	if ((game->map->map[i][j] == 'E') && (game->player->exit_done == 0))
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->exit_0->img_ptr, j * SCALE, i * SCALE);
	else if ((game->map->map[i][j] == 'E') && (game->player->exit_done == 1))
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->exit_1->img_ptr, j * SCALE, i * SCALE);
}

static void	ft_pre_render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			ft_render(game, i, j);
			j++;
		}
		i++;
	}
}

int	ft_render_loop(t_game *game)
{
	static int	frame = 0;

	if (frame == 500)
	{
		ft_pre_render(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->player->player->img_ptr, game->player->x * SCALE,
			game->player->y * SCALE);
		ft_steps(game);
	}
	else if (frame == 1000)
		frame = 0;
	frame += 2;
	return (0);
}
