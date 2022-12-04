/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** frees mallocs
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"

void free_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->tex);
    sprite->passed_frames = 0.00;
}

void free_win(win_t *win)
{
    sfRenderWindow_destroy(win->window);
    free_sprite(&win->msprite1);
    free_sprite(&win->msprite2);
    free_sprite(&win->msprite3);
    sfImage_destroy(win->ico1);
    sfImage_destroy(win->ico2);
    sfImage_destroy(win->ico3);
    sfClock_destroy(win->clock);
    sfText_destroy(win->score_text);
    sfText_destroy(win->hiscore_text);
}
