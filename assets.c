/*
** EPITECH PROJECT, 2021
** assets
** File description:
** handle assets
*/

#include "hunter.h"

sfVector2f set_init_ennpos(void)
{
    sfVector2f pos;

    pos.x = -1 * (rand() % 1920);
    pos.y = rand() % 680;
    return pos;
}

sfVector2f set_moveenn(void)
{
    sfVector2f move;

    move.x = rand() % 4 + 2;
    move.y = 0;
    return move;
}

sfIntRect get_ennemy(void)
{
    sfIntRect show;
    int first_sprite[2] = {0, 96};

    show.top = 0;
    show.left = first_sprite[rand() % 2];
    show.width = 96;
    show.height = 96;
    return show;
}

sfText *set_score(void)
{
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile("sprites/font.ttf");
    sfVector2f loc;
    int height = 70;

    loc.x = 1000;
    loc.y = -10;
    sfText_setString(score, "000");
    sfText_setPosition(score, loc);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, height);
    sfText_setPosition(score, loc);
    return score;
}

void put_asset(window *win, ennemy *enn, lives *live)
{
    win->win = sfRenderWindow_create(win->video, "my_hunter",
    sfClose | sfResize, NULL);
    win->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(win->win, 60);
}