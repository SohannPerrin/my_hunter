/*
** EPITECH PROJECT, 2022
** csfml2.c
** File description:
** graphic window 2
*/

#include "include/my.h"
#include "include/struct.h"
#include "include/windowsfuncs.h"
void eventlisten(win_t* win);

void go_event(win_t *win, sfFloatRect *newgame, sfFloatRect *quit)
{
    if (win->click == 1 &&
    sfFloatRect_intersects(&win->mbox, newgame, NULL) == sfTrue){
        win->click = 0;
        win->game_over = 0;
        win->score = 0;
        free_music(win);
        create_music(win, "sounds/menu.ogg");
    }
    if (win->click == 1 &&
    sfFloatRect_intersects(&win->mbox, quit, NULL) == sfTrue){
        win->click = 0;
        win->game_over = 0;
        free_music(win);
        sfRenderWindow_close(win->window);
    }
}

void score_show(win_t *win, sprite_t *sprite)
{
    double fscore = (win->score * 1000) / (sprite->passed_frames / win->score);
    int hi_score = get_score("scores.txt");
    if (hi_score < fscore){
        hi_score = fscore;
        makehigh("scores.txt" , (int)fscore);
    }
    char *hi_score_char = int_to_str(hi_score);
    char *fscore_char = int_to_str((int)fscore);
    set_textpos(win->score_text, 1508, 47.00);
    set_textpos(win->hiscore_text, 1158.00, 47.00);
    set_textfont(win->score_text, "font/Z003.ttf");
    set_textfont(win->hiscore_text, "font/Z003.ttf");
    set_textcolors(win->score_text, "0 0 0 255");
    set_textcolors(win->hiscore_text, "0 0 0 255");
    sfText_setCharacterSize(win->score_text, 48);
    sfText_setCharacterSize(win->hiscore_text, 48);
    sfText_setString(win->score_text, fscore_char);
    sfText_setString(win->hiscore_text, hi_score_char);
    free(hi_score_char);
    free(fscore_char);
}

void isgameover(win_t *win, sprite_t *sprite, sprite_t *sprite2)
{
    if (win->game_over == 1){
        sprite_t go_screen;
        sfFloatRect newgame = {1379, 159, 337, 81};
        sfFloatRect quit = {1377, 308, 339, 82};
        win->isinit = 0;
        free_music(win);
        create_music(win, "sounds/game_over.ogg");
        setsprite(&go_screen, "sprites/game_over.png", 1.00, 1.00);
        score_show(win, sprite);
        sfWindow_setIcon(win->window, 27, 27, sfImage_getPixelsPtr(win->ico3));
        while (win->game_over == 1){
            draw3(win, go_screen.sprite, win->score_text, win->hiscore_text);
            draw4(&win->msprite1, win);
            eventlisten(win);
            go_event(win, &newgame, &quit);
            displayfunc(win);
        }
        free_sprite(&go_screen);
    }
}
