/*
** EPITECH PROJECT, 2022
** drawfunc2.c
** File description:
** manages other draws
*/

#include "include/struct.h"
#include "include/my.h"
#include <stdlib.h>

void draw4(sprite_t *sprite, win_t *win)
{
    sfRenderWindow_drawSprite(win->window, sprite->sprite, NULL);
    sfSprite_rotate(win->msprite1.sprite, 1.00);
    sfSprite_rotate(win->msprite2.sprite, -1.00);
    sfSprite_rotate(win->msprite3.sprite, 1.00);
    sfRenderWindow_drawSprite(win->window, win->msprite1.sprite, NULL);
    sfRenderWindow_drawSprite(win->window, win->msprite2.sprite, NULL);
    sfRenderWindow_drawSprite(win->window, win->msprite3.sprite, NULL);
}

void draw3(win_t *win, sprite_t *sprite1, sfText *sprite2, sfText *sprite3)
{
    sfRenderWindow_drawSprite(win->window, sprite1, NULL);
    sfRenderWindow_drawText(win->window, sprite2, NULL);
    sfRenderWindow_drawText(win->window, sprite3, NULL);
}
