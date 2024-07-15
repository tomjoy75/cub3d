/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 13:53:01 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_UTILS_H
# define CB_UTILS_H

# define CB_RETURN_SUCCESS 0
# define CB_RETURN_FAILURE 1
# define CB_COLLISION_ANTICLIP 0.001
# define CB_COLLISION_TOL 0.001
# define CB_TILE_OOB 99
# define CB_TILE_FLOOR 0
# define CB_TILE_WALL 1
# define CB_TILE_DOOR 2
# define CB_TILE_DOOR_OPEN 3
# define CB_MAP_EMPTY -1
# define CB_PLAYER_X_INDEX 0
# define CB_PLAYER_Y_INDEX 1
# define CB_PLAYER_RAD_INDEX 2
# define CB_PLAYER_COS_INDEX 3
# define CB_PLAYER_SIN_INDEX 4
# define CB_CAM_W 1.0
# define CB_RAY_MAX_D 1.0e10
# define CB_PLAYER_SPEED 0.1 //Tile/Frame
# define CB_PLAYER_LR_TURN 10 //pixel
# define CB_DOOR_OPEN_DIST 0.5 //Tile

# define CB_PLAYER_MP_SIZE 5 // Pixel
# define CB_MAP_ARROW_SIZE 1
# define CB_MAP_ARROW_DIST 3.0
# define CB_MAP_EMPTY -1
# define CB_MAP_WALL 1
# define CB_MAP_FLOOR 0
# define CB_MAP_EMPTY_COLOR 0x000000
# define CB_MAP_WALL_COLOR 0xFF0000
# define CB_MAP_FLOOR_COLOR 0x00FF00
# define CB_MAP_DOOR_COLOR 0x0000FF
# define CB_MAP_ARROW_COLOR 0x00FFFF
# define CB_MAP_TILE_SIZE 5

#define DEBUG_FLOOR 0x00FF00
#define DEBUG_CEIL 0x0000FF
#define DEBUG_WALL 0xFFFFFF

# define CB_EMSG "Error\n"

#endif
