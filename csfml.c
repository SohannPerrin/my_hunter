/*
** EPITECH PROJECT, 2022
** csfml.c
** File description:
** graphic window
*/

#include "include/my.h"
#include "include/ascii.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"

void eventlisten(win_t* win)
{
    win->mpos = sfRenderWindow_mapPixelToCoords(win->window\
    , sfMouse_getPosition(win->window), NULL);
    setspritepos(&win->msprite1, win->mpos.x, win->mpos.y);
    setspritepos(&win->msprite2, win->mpos.x, win->mpos.y);
    setspritepos(&win->msprite3, win->mpos.x, win->mpos.y);
    win->mbox = sfSprite_getGlobalBounds(win->msprite1.sprite);
    while (sfRenderWindow_pollEvent(win->window, &win->event)){
        if (win->event.type == sfEvtClosed){
            win->game_over = 0;
            win->isinit = 0;
            free_music(win);
            sfRenderWindow_close(win->window);
        }
        if (win->event.type == sfEvtMouseButtonPressed){
            win->click = 1;
        }
    }
}

void gameloop(win_t *win)
{
    sprite_t bg, ling;
    anim_t linganim[3];
    create_music(win, "sounds/gameloop.ogg");
    setsprite(&bg, "sprites/canterlot_bg.png", 1.00, 1.00);
    setsprite(&ling, "sprites/transpling.png", 5.00, 5.00);
    make_anim(&ling, linganim, "34 42 3 233 290 96 433 229 74");
    win->isinit = 1;
    sfWindow_setIcon(win->window, 27, 27, sfImage_getPixelsPtr(win->ico2));
    while (win->isinit == 1){
        eventlisten(win);
        if (sfClock_getElapsedTime(win->clock).microseconds >= 40000){
            framepassed(win);
            sfRenderWindow_drawSprite(win->window, bg.sprite, NULL);
            rollsprite(&ling, win, 1);
            isgameover(win, &ling, &bg);
            displayfunc(win);
        }
    }
    free_sprite(&bg);
    free_sprite(&ling);
}

int game_main(win_t *win)
{
    sprite_t start_men;
    sfFloatRect moonsprite = {194, 63, 261, 261};
    setsprite(&start_men, "sprites/home_screen.png", 1.00, 1.00);
    while (sfRenderWindow_isOpen(win->window)){
        eventlisten(win);
        sfWindow_setIcon(win->window, 27, 27, sfImage_getPixelsPtr(win->ico1));
        draw4(&start_men, win);
        if (win->click == 1 &&
        sfFloatRect_intersects(&win->mbox, &moonsprite, NULL) == sfTrue){
            win->click = 0;
            free_music(win);
            gameloop(win);
        }
        displayfunc(win);
    }
    free_sprite(&start_men);
    free_win(win);
    return (win->errval);
}

int main (int ac, char **av)
{
    time_t t1;
    win_t win;
    srand ( (unsigned) time (&t1));
    if (ac > 1)
        if (av[1][0] == '-' && av[1][1] == 'h'){
            my_putstr(asciitwi);
            my_putstr("              (\\_CANTERLOT DEFENDER_/)\n\n");
            my_putstr("in this game, your goal is to prevent your ennemies");
            my_putstr(" from invading canterlot\n\nCONTROLS:\n");
            my_putstr("aim with your mouse and shoot with left click\n");
            my_putstr("\ngood luck\n");
            return (0);
        }
    create_music(&win, "sounds/menu.ogg");
    setwin(&win, 1920, 1080, 32);
    return (game_main(&win));
}
