/*
** EPITECH PROJECT, 2022
** drawfunc.c
** File description:
** draws sprite
*/

#include "include/struct.h"
#include "include/my.h"
#include <stdlib.h>

void setsprite(sprite_t *sprite, char *spritefiles, double sizex, double sizey)
{
    sprite->is_spawn = 0;
    sprite->scale.x = sizex;
    sprite->scale.y = sizey;
    sprite->tex = sfTexture_createFromFile(spritefiles, NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setTexture(sprite->sprite, sprite->tex, sfTrue);
}

void setspritepos(sprite_t *sprite, double posx, double posy)
{
    sfVector2f spos;
    spos.x = posx;
    spos.y = posy;
    sfSprite_setPosition(sprite->sprite, spos);
}

void setspritescale(sprite_t *sprite, double scalex, double scaley)
{
    sfVector2f sscale;
    sscale.x = scalex;
    sscale.y = scaley;
    sfSprite_setScale(sprite->sprite, sscale);
}

void setspriteorigin(sprite_t *sprite, double posx, double posy)
{
    sfVector2f spos;
    spos.x = posx;
    spos.y = posy;
    sfSprite_setOrigin(sprite->sprite, spos);
}
