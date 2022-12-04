/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** contains sprite info
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "my.h"

    typedef struct anim {
        sfIntRect dims;
        int tot;
    }anim_t;

    typedef struct sprite {
        sfTexture* tex;
        sfSprite* sprite;
        anim_t* anim;
        int is_spawn;
        double direction;
        int frame;
        double passed_frames;
        sfVector2f movment;
        sfVector2f scale_change;
        sfVector2f scale;
    }sprite_t;

    typedef struct win {
        sfRenderWindow *window;
        sfVideoMode vmode;
        sfText *score_text;
        sfText *hiscore_text;
        sfMusic *music;
        sfEvent event;
        sfClock *clock;
        sfVector2f mpos;
        int frame_passed;
        int game_over;
        int click;
        int action;
        int errval;
        int isinit;
        double score;
        sprite_t msprite1;
        sprite_t msprite2;
        sprite_t msprite3;
        sfFloatRect mbox;
        sfImage *ico1;
        sfImage *ico2;
        sfImage *ico3;
        sfSoundBuffer *sbuff;
        sfSound *sound;
    }win_t;

#endif /* STRUCT_H_ */
