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

void setwin2(win_t *win)
{
    setsprite(&win->msprite1, "sprites/glyph_L1.png", 1.00, 1.00);
    setsprite(&win->msprite2, "sprites/glyph_L2.png", 1.00, 1.00);
    setsprite(&win->msprite3, "sprites/glyph_L3.png", 1.00, 1.00);
    setspriteorigin(&win->msprite1, 14.00, 15.00);
    setspriteorigin(&win->msprite2, 50.00, 50.00);
    setspriteorigin(&win->msprite3, 62.00, 62.00);
    win->ico1 = sfImage_createFromFile("sprites/happytwi.png");
    win->ico2 = sfImage_createFromFile("sprites/angrytwi.png");
    win->ico3 = sfImage_createFromFile("sprites/gasptwi.png");
}
