/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/30 00:37:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player(t_data *data)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;
	t_player	*player;

	player = &data->player;
	player->rot_angle += player->turn_dir * player->turn_speed;
	normalize_angle(&player->rot_angle);
	move_step = player->walk_dir * player->walk_speed;
	new_player_x = player->x + cos(player->rot_angle) * move_step;
	new_player_y = player->y + sin(player->rot_angle) * move_step;
	if (!map_has_wall_at(new_player_x, new_player_y, data))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}
