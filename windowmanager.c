/*
** EPITECH PROJECT, 2022
** windowmanager.c
** File description:
** graphic window
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"
#include <stdlib.h>

void setwin(win_t *win, int width, int height, int res)
{
    win->errval = win->isinit = win->action = win->mpos.x = win->mpos.y = 0;
    win->frame_passed = win->click = win->game_over = 0;
    win->score = 0.00;
    win->clock = sfClock_create();
    win->vmode.width = width;
    win->vmode.height = height;
    win->vmode.bitsPerPixel = res;
    win->score_text = sfText_create();
    win->hiscore_text = sfText_create();
    win->window = sfRenderWindow_create(win->vmode, "canterlot defender"\
    , sfResize | sfClose, NULL);
    sfWindow_setMouseCursorVisible(win->window, sfFalse);
    sfRenderWindow_setFramerateLimit(win->window, 25);
    sfRenderWindow_clear(win->window, sfBlack);
    setwin2(win);
}

void create_music(win_t *win, char *filepath)
{
    win->music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(win->music, sfTrue);
    sfMusic_play(win->music);
}

void free_music(win_t *win)
{
    sfMusic_stop(win->music);
    sfMusic_destroy(win->music);
}

void displayfunc(win_t *win)
{
    sfRenderWindow_display(win->window);
    win->click = 0;
}
