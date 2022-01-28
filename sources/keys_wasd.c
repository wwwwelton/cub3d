/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:26 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/28 18:59:51 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	keys_press_wasd(int key, t_data *data)
{
	if (key == KEY_W)
		data->player.walk_dir = 1;
	if (key == KEY_A)
		data->player.turn_dir = -1;
	if (key == KEY_S)
		data->player.walk_dir = -1;
	if (key == KEY_D)
		data->player.turn_dir = 1;
}

static void	keys_release_wasd(int key, t_data *data)
{
	if (key == KEY_W)
		data->player.walk_dir = 0;
	if (key == KEY_A)
		data->player.turn_dir = 0;
	if (key == KEY_S)
		data->player.walk_dir = 0;
	if (key == KEY_D)
		data->player.turn_dir = 0;
}

void	keys_wasd(int key, t_data *data, int event_type)
{
	if (event_type == K_PRESS)
		keys_press_wasd(key, data);
	if (event_type == K_RELEASE)
		keys_release_wasd(key, data);
}
