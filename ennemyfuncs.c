/*
** EPITECH PROJECT, 2022
** ennemyfuncs.c
** File description:
** handles ennemy's funcs
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"

void moveling(sprite_t *sprite, win_t *win)
{
    if (sprite->is_spawn == 0){
        sprite->is_spawn = 1;
        int ry = rand() % 800;
        int flip = rand() % 100;
        if (flip < 50){
            setspritepos(sprite, -34.00, (double)ry);
            sprite->direction = 1.00;
            setspritescale(sprite, -5.00, 5.00);
        } else {
            setspritepos(sprite, 1921, (double)ry);
            sprite->direction = -1.00;
            setspritescale(sprite, 5.00, 5.00);
        }
    } else {
        double mx = sprite->direction;
        double my = 1.00;
        mx = mx * (win->score * 1.1) + (5 * mx);
        my = my * sin(sprite->passed_frames) * (win->score * 2 + 1);
        movesprite(sprite, win, mx, my);
    }
}

void checkhit(sprite_t *sprite, win_t *win)
{
    sfFloatRect srect = sfSprite_getGlobalBounds(sprite->sprite);
    if (win->click == 1 &&
    sfFloatRect_intersects(&win->mbox, &srect, NULL) == sfTrue){
        win->click = 0;
        sprite->is_spawn = 0;
        win->score += 1;
        sfSound_play(win->sound);
    }
}

void rollsprite(sprite_t *sprite, win_t *win, int isanim)
{
    checkhit(sprite, win);
    moveling(sprite, win);
    if (isanim == 1)
        roll_anim(win, sprite);
    float pos = sfSprite_getGlobalBounds(sprite->sprite).left;
    if ((pos > 1920 && sprite->direction > 0.00) ||
    (pos < -170.00 && sprite->direction < 0))
        win->game_over = 1;
    draw4(sprite, win);
}
