/*
** EPITECH PROJECT, 2021
** handle texture
** File description:
** function for texture handling
*/

#include "hunter.h"

sfSprite *set_background(void)
{
    sfIntRect locbg;
    sfTexture *tx_bground;
    sfSprite *sp_bground = sfSprite_create();

    locbg.top = 0;
    locbg.left = 0;
    locbg.width = 1920;
    locbg.height = 1080;
    tx_bground = sfTexture_createFromFile("sprites/bground.jpg", &locbg);
    sfSprite_setTexture(sp_bground, tx_bground, sfTrue);
    return sp_bground;
}

sfSprite *create_ennemy(void)
{
    sfSprite *enn = sfSprite_create();
    sfTexture *txt = sfTexture_createFromFile("sprites/ennemy.png", NULL);

    sfSprite_setTexture(enn, txt, sfTrue);
    return enn;
}

void init_live(lives *live)
{
    sfTexture *tx_heart = sfTexture_createFromFile("sprites/heart.png", NULL);
    sfVector2f pos;
    sfSprite *live1 = sfSprite_create();
    sfSprite *live2 = sfSprite_create();
    sfSprite *live3 = sfSprite_create();

    live->lives = 3;
    pos.x = 80;
    pos.y = 50;
    sfSprite_setTexture(live1, tx_heart, sfTrue);
    sfSprite_setPosition(live1, pos);
    live2 = sfSprite_copy(live1);
    pos.x += 70;
    sfSprite_setPosition(live2, pos);
    live3 = sfSprite_copy(live1);
    pos.x += 70;
    sfSprite_setPosition(live3, pos);
    live->live1 = live1;
    live->live2 = live2;
    live->live3 = live3;
}

window *init_window(void)
{
    window *win = malloc(sizeof(window));

    if (win == NULL) {
        write(2, "malloc error handling\n", 23);
    }
    return (win);
}

void clean(window *win, ennemy *enn, lives *live)
{
    sfRenderWindow_destroy(win->win);
    sfMusic_destroy(win->music);
    free(win->score_str);
}