/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntome <ntome@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:31:19 by ntome             #+#    #+#             */
/*   Updated: 2026/01/31 10:25:22 by ntome            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_game(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.map[i])
	{
		free(mlx->map.map[i]);
		i++;
	}
	free(mlx->map.map);
	free(mlx->drawing_line);
}
