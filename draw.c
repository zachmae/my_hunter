/*
** EPITECH PROJECT, 2021
** draw
** File description:
** display all
*/

#include "hunter.h"

void show_lives(window *win, ennemy *enn, lives *live)
{
    int c;

    if (live->lives == 2)
        sfSprite_setTexture(live->live1, live->vide, sfTrue);
    else if (live->lives == 1) {
        sfSprite_setTexture(live->live1, live->vide, sfTrue);
        sfSprite_setTexture(live->live2, live->vide, sfTrue);
    }
    if (live->lives <= 0) {
        sfSprite_setTexture(live->live1, live->vide, sfTrue);
        sfSprite_setTexture(live->live2, live->vide, sfTrue);
        sfSprite_setTexture(live->live3, live->vide, sfTrue);
        for (c = 0; c < 25; c++)
            enn[c].move_ennemy.x = 0;
        sfRenderWindow_drawText(win->win, live->tx_lost, NULL);
        sfRenderWindow_drawText(win->win, live->new_game, NULL);
    }
}

void draw_enn(window *win, ennemy *enn)
{
    int c;

    for (c = 0; c < 25; c++) {
        sfSprite_setTextureRect(enn[c].sp_ennemy, enn[c].show);
        sfRenderWindow_drawSprite(win->win, enn[c].sp_ennemy, NULL);
    }
}

void draw(window *win, lives *live)
{
    sfRenderWindow_drawSprite(win->win, live->live1, NULL);
    sfRenderWindow_drawSprite(win->win, live->live2, NULL);
    sfRenderWindow_drawSprite(win->win, live->live3, NULL);
    sfRenderWindow_drawText(win->win, win->score, NULL);
    sfRenderWindow_display(win->win);
}

void events(window *win, ennemy *enn, lives *live)
{
    while (sfRenderWindow_pollEvent(win->win, &win->event)) {
        if (win->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win->win);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->cursor = sfMouse_getPositionRenderWindow(win->win);
            handle_shot(win, enn);
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue &&
            enn[0].move_ennemy.x == 0) {
            init_live(live);
            win->score = set_score();
            win->score_str = my_strcpy(win->score_str, "000\0");
            win->score_int = 0;
            rand_target(enn);
        }
    }
}