/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omsanfor <omsanfor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:18:57 by omsanfor          #+#    #+#             */
/*   Updated: 2022/04/05 15:08:06 by omsanfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_key_wasd_utils(t_game *game, int *x_y, int sign)
{
	int		n;
	char	*num_str;

	n = 0;
	if (sign == 1)
		*x_y += 1;
	else
		*x_y -= 1;
	game->player->steps++;
	n = game->player->steps;
	write(1, "Steps: ", 8);
	num_str = ft_itoa(n);
	write(1, num_str, ft_strlen(num_str));
	write(1, "\n", 1);
	free(num_str);
}

static void	ft_key_wasd(int keycode, t_game *game)
{
	if ((keycode == 13) && (game->map->map[game->player->y - 1][game->player->x]
		!= '1'))
		ft_key_wasd_utils(game, &game->player->y, 0);
	else if ((keycode == 1) && (game->map->map[game->player->y
				+ 1][game->player->x] != '1'))
		ft_key_wasd_utils(game, &game->player->y, 1);
	else if ((keycode == 2) && (game->map->map[game->player->y]
			[game->player->x + 1] != '1'))
		ft_key_wasd_utils(game, &game->player->x, 1);
	else if ((keycode == 0) && (game->map->map[game->player->y]
			[game->player->x - 1] != '1'))
		ft_key_wasd_utils(game, &game->player->x, 0);
}

int	ft_key_control(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		ft_key_wasd(keycode, game);
	ft_check_collectable(game);
	ft_check_die(game);
	ft_check_exit(keycode, game);
	return (0);
}
