/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:29:14 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 10:29:42 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <keys.h>

static void try_move(t_mlx *mlx, double dx, double dy)
{
    double new_x = mlx->player.pos.x + dx;
    double new_y = mlx->player.pos.y + dy;
    if (mlx->map.map[(int)new_y][(int)new_x] != '1')
    {
        mlx->player.pos.x = new_x;
        mlx->player.pos.y = new_y;
    }
}

void move_player(t_mlx *mlx)
{
    if (mlx->keys[KEY_W])
        try_move(mlx, mlx->player.rot.x * SPEED, mlx->player.rot.y * SPEED);
    if (mlx->keys[KEY_S])
        try_move(mlx, -mlx->player.rot.x * SPEED, -mlx->player.rot.y * SPEED);
    if (mlx->keys[KEY_A])
        try_move(mlx, -mlx->player.plane.x * SPEED, -mlx->player.plane.y * SPEED);
    if (mlx->keys[KEY_D])
        try_move(mlx, mlx->player.plane.x * SPEED, mlx->player.plane.y * SPEED);

    if (mlx->keys[KEY_LEFT])
    {
        double old_dir_x = mlx->player.rot.x;
        mlx->player.rot.x = mlx->player.rot.x * cos(-ROT_SPEED) - mlx->player.rot.y * sin(-ROT_SPEED);
        mlx->player.rot.y = old_dir_x * sin(-ROT_SPEED) + mlx->player.rot.y * cos(-ROT_SPEED);
        double old_plane_x = mlx->player.plane.x;
        mlx->player.plane.x = mlx->player.plane.x * cos(-ROT_SPEED) - mlx->player.plane.y * sin(-ROT_SPEED);
        mlx->player.plane.y = old_plane_x * sin(-ROT_SPEED) + mlx->player.plane.y * cos(-ROT_SPEED);
    }
    if (mlx->keys[KEY_RIGHT])
    {
        double old_dir_x = mlx->player.rot.x;
        mlx->player.rot.x = mlx->player.rot.x * cos(ROT_SPEED) - mlx->player.rot.y * sin(ROT_SPEED);
        mlx->player.rot.y = old_dir_x * sin(ROT_SPEED) + mlx->player.rot.y * cos(ROT_SPEED);
        double old_plane_x = mlx->player.plane.x;
        mlx->player.plane.x = mlx->player.plane.x * cos(ROT_SPEED) - mlx->player.plane.y * sin(ROT_SPEED);
        mlx->player.plane.y = old_plane_x * sin(ROT_SPEED) + mlx->player.plane.y * cos(ROT_SPEED);
    }
}
