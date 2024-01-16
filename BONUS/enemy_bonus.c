/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkannane <tkannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:09:46 by tkannane          #+#    #+#             */
/*   Updated: 2024/01/16 21:55:15 by tkannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_enemy_moves(t_base *tmap)
{
    int     width;
    int     height;

    tmap->enemyleft_2 = mlx_xpm_file_to_image(tmap->mlx,
        "./textures/walk1L.xpm", &width, &height);
    tmap->enemyleft_3 = mlx_xpm_file_to_image(tmap->mlx,
        "./textures/walk1L.xpm", &width, &height);
    tmap->enemyleft_4 = mlx_xpm_file_to_image(tmap->mlx,
        "./textures/walk1L.xpm", &width, &height);
    tmap->enemyright_1 = mlx_xpm_file_to_image(tmap->mlx,
        "./textures/walk1.xpm", &width, &height);
    tmap->enemyright_2 = mlx_xpm_file_to_image(tmap->mlx,
        "./textures/walk1.xpm", &width, &height);
    tmap->enemyright_3 = mlx_xpm_file_to_image(tmap->mlx,
        "./textures/walk1.xpm", &width, &height);
}

void    move_enemy_to_left(t_base *tmap, int i, int j)
{
    static int  count = 0;

    tmap->game->map[i][j] = '0';
    tmap->game->map[i][j - 1] = 'X';
    count++;
    if (count == 1)
        tmap->enemy = tmap->enemy;
    if (count == 2)
        tmap->enemy = tmap->enemyleft_2;
    if (count == 3)
        tmap->enemy = tmap->enemyleft_3;
    if (count == 4)
    {
        tmap->enemy = tmap->enemyleft_4;
        count = 0;
    }
}

void    move_enemy_to_right(t_base *tmap, int i, int j)
{
    static int  count = 0;

    tmap->game->map[i][j] = '0';
    tmap->game->map[i][j + 1] = 'X';
    count++;
    if (count == 1)
        tmap->enemy = tmap->enemyright_1;
    if (count == 2)
        tmap->enemy = tmap->enemyright_1;
    if (count == 3)
        tmap->enemy = tmap->enemyright_2;
    if (count == 4)
    {
        tmap->enemy = tmap->enemyright_3;
        count = 0;
    }
}
void    move_enemy_to_bottom(t_base *tmap, int i, int j)
{
    tmap->game->map[i][j] = '0';
    tmap->game->map[i + 1][j] = 'X';
    tmap->enemy = tmap->enemyleft_2;
}
void    move_enemy_to_top(t_base *tmap, int i, int j)
{
    tmap->game->map[i][j] = '0';
    tmap->game->map[i - 1][j] = 'X';
    tmap->enemy = tmap->enemyleft_2;
}

void    you_lose(t_base *tmap, int i, int j)
{   
    tmap->game->map[i][j] = '0';
    tmap->game_over++;
    ft_putstr("You loose HHH\n");
   close_game(tmap);
}
void    chose_the_move(t_base *tmap, int i, int j, int *retour)
{
    if (tmap->game->map[i][j + 1] == 'P' && !*retour)
        you_lose(tmap, i, j + 1);
    if (tmap->game->map[i][j - 1] == 'P' && *retour)
        you_lose(tmap, i, j - 1);
    
    if (tmap->game->map[i][j + 1] == '0' && !*retour)
        move_enemy_to_right(tmap, i, j);
    else if (tmap->game->map[i][j - 1] == '0')
        {
            *retour = 1;
            move_enemy_to_left(tmap, i, j);
        }
    else if (tmap->game->map[i + 1][j] == '0' && !*retour)
       {
            *retour = 1;
            move_enemy_to_bottom(tmap, i, j);
        }
    else if (tmap->game->map[i - 1][j] == '0'&& !*retour)
    {
        *retour = 1;
        move_enemy_to_top(tmap,i ,j);
    }
    else
        *retour = 0;
}

void  display_moves(t_base *tmap)
{
    char    *str;
    char    *moves;
    char    *total;
    moves = ft_strdup("Moves : ");
    str = ft_itoa(tmap->moves);
    total = ft_strjoin(moves, str);
    if (!moves || !str || !total)
    {
        free(str);
        free(total);
        affich_error(tmap, "Probleme to alloacte for moves\n");
    }
    mlx_string_put(tmap->mlx, tmap->mlx_win, 0, 0, 0xFFFFFF, total);
    free(str);
    free(total);
}
int     move_enenmy(t_base *tmap)
{
    int i;
    int j;
    static  int retour = 0;
    static  int frame_count = 0;

    i = 0;
    while (i < tmap->game->height)
    {
        j = 0;
        while (j < tmap->game->width)
        {
            if (tmap->game->map[i][j] == 'X')
                break;
            j++;
        }
        if (tmap->game->map[i][j] == 'X')
            break;
        i++;
    }
    if(frame_count % 30 == 0)
        chose_the_move(tmap, i, j, &retour);
    render_map(tmap);
    display_moves(tmap);
    frame_count++;
    return (1);
}

