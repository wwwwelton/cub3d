/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/21 21:41:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	animate_guard(t_sprite *sprite, t_data *data)
{
	if (sprite->frame == 0)
		sprite->texture = SPT_GUARD1;
	if (sprite->frame == 1)
		sprite->texture = SPT_GUARD2;
	if (sprite->frame == 2)
		sprite->texture = SPT_GUARD3;
	if (data->frame.cycle % 10 == 0)
		sprite->frame++;
	sprite->frame = sprite->frame % 3;
}

static void	animate_weapon(t_data *data)
{
	if (data->player.action_shoot)
	{
		if (data->player.frame < 2)
		{
			data->player.weapon = WEAPON_2;
			data->player.frame = 2;
		}
		else
		{
			data->player.weapon = WEAPON_3;
			data->player.frame = 3;
		}
	}
	else
	{
		data->player.frame = 0;
		data->player.weapon = WEAPON_1;
	}
	data->player.frame = (data->frame.cycle % 4);
}

void	update_animations(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_sprites)
	{
		if (data->sprites[i].id == GUARD)
			animate_guard(&data->sprites[i], data);
	}
	animate_weapon(data);
}
