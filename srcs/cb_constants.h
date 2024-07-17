/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_constants.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 19:53:56 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_CONSTANTS_H
# define CB_CONSTANTS_H

// Window
# define CB_WIN_NAME "cub3D"
# define CB_WIN_W 600 // pixels
# define CB_WIN_H 300 // pixels
// SUCCESS
# define CB_RETURN_SUCCESS 0
# define CB_RETURN_FAILURE 1
// Map
# define CB_TILE_OOB 99
# define CB_TILE_EMPTY -1
# define CB_TILE_FLOOR 0
# define CB_TILE_WALL 1
# define CB_TILE_DOOR 2
# define CB_TILE_DOOR_OPEN 3
// Data
# define CB_PLAYER_X_INDEX 0
# define CB_PLAYER_Y_INDEX 1
# define CB_PLAYER_RAD_INDEX 2
# define CB_PLAYER_COS_INDEX 3
# define CB_PLAYER_SIN_INDEX 4
// Camera
# define CB_CAM_W 1.0
# define CB_RAY_MAX_D 1.0e10 // tiles
// Player
# define CB_PLAYER_SPEED 0.1 //Tile/Frame
# define CB_PLAYER_LR_TURN 10 //pixel
# define CB_PLAYER_START_OFFX 0.50001
# define CB_PLAYER_START_OFFY 0.50001
// Distances
# define CB_COLLISION_TOL 0.001 // tiles
# define CB_DOOR_OPEN_DIST 0.5 //Tile
// Minimap
# define CB_MAP_TILE_SIZE 5
# define CB_MAP_EMPTY_COLOR 0x000000
# define CB_MAP_WALL_COLOR 0xFF0000
# define CB_MAP_FLOOR_COLOR 0x00FF00
# define CB_MAP_DOOR_COLOR 0x0000FF
# define CB_SPRITE_TRANSPARENT_COLOR 0x000000
# define CB_SPRITE_ANIMATION_SPEED 3000 // win_update / sprite_update
// Control
# define CB_MOUSE_SENSIBILITY 0.01
// Other
# define CB_PI 3.14159265359
# define CB_PI_HALF 1.57079632679 
# define CB_SOUTH_ANGLE CB_PI_HALF
# define CB_NORTH_ANGLE -CB_PI_HALF
# define CB_EAST_ANGLE 0.0
# define CB_WEST_ANGLE CB_PI
# define CB_TRIG_0 0.0
# define CB_TRIG_1 0.70710678118
# define CB_TRIG_2 1.0
// Bonus ressources
# define CB_SPRITE_PATH "data/sprite.xpm"
# define CB_DOOR_PATH "data/door.xpm"
//
# define CB_ELEMENT_FLOOR 'F'
# define CB_ELEMENT_CEIL 'C'
# define CB_ELEMENT_NORTH "NO"
# define CB_ELEMENT_SOUTH "SO"
# define CB_ELEMENT_EAST "EA"
# define CB_ELEMENT_WEST "WE"
# define CB_ELEMENT_PLAYER "NSEW"
//
# define CB_MAP_EXTENSION ".cub"
//COLORS
# define CB_TERM_RED		"\x1b[1;31m"
# define CB_TERM_ITALIC		"\x1b[1;3m"
# define CB_TERM_RESET		"\x1b[0m"
// BONUS
# if (!defined CB_BONUS_ENABLED || (CB_BONUS_ENABLED == 0))
#  define CB_BONUS_ENABLED 0
#  define CB_MAP_VALID_CHAR " 01"
# else
#  define CB_BONUS_ENABLED 1
#  define CB_MAP_VALID_CHAR " 012"
# endif

#endif
