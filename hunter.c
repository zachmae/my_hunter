/*
** EPITECH PROJECT, 2021
** hunter.c
** File description:
** hunter function
*/

#include "hunter.h"

void move_enn(window *win, ennemy *enn, lives *live)
{
    int c;

    for (c = 0; c < 25; c++) {
        if (enn[c].pos_ennemy.x > 1500) {
            live->lives--;
            enn[c].pos_ennemy = set_init_ennpos();
            enn[c].move_ennemy = set_moveenn();
        }
        enn[c].pos_ennemy.x += enn[c].move_ennemy.x;
        sfSprite_setPosition(enn[c].sp_ennemy, enn[c].pos_ennemy);
    }
    show_lives(win, enn, live);
}

void animate_enn(ennemy *enn, int move, int max, window *win)
{
    int c;

    win->timer = sfClock_getElapsedTime(win->clock);
    win->seconds = sfTime_asSeconds(win->timer);
    sfRenderWindow_clear(win->win, sfWhite);
    if (win->seconds > 0.20) {
        for (c = 0; c < 25; c++) {
            enn[c].show.left += move;
            if (enn[c].show.left > max - move)
                enn[c].show.left = 0;
        sfSprite_setTextureRect(enn[c].sp_ennemy, enn[c].show);
        }
    win->seconds = 0;
    sfClock_restart(win->clock);
    }
    sfRenderWindow_drawSprite(win->win, win->backg, NULL);
}

void rand_target(ennemy *enn)
{
    int c;

    srand(time(NULL));
    for (c = 0; c < 25; c++) {
        enn[c].sp_ennemy = create_ennemy();
        enn[c].show = get_ennemy();
        enn[c].pos_ennemy = set_init_ennpos();
        enn[c].move_ennemy = set_moveenn();
    }
}

void game(window *win, ennemy *enn, lives *live)
{
    live->vide = sfTexture_createFromFile("sprites/empty.png", NULL);
    live->tx_lost = get_lost();
    live->new_game = get_restart();
    while (sfRenderWindow_isOpen(win->win)) {
        animate_enn(enn, 96, 384, win);
        move_enn(win, enn, live);
        events(win, enn, live);
        draw_enn(win, enn);
        draw(win, live);
    }
    clean(win, enn, live);
}

void hunter(window *win, ennemy *enn, lives *live)
{
    init_live(live);
    win->video = set_videomode();
    win->music = sfMusic_createFromFile("sprites/music.flac");
    win->gunshot = sfMusic_createFromFile("sprites/gun.ogg");
    put_asset(win, enn, live);
    win->score = set_score();
    win->score_str = malloc(4);
    win->score_str = my_strcpy(win->score_str, "000\0");
    win->score_int = 0;
    win->backg = set_background();
    win->clock = sfClock_create();
    sfMusic_play(win->music);
    sfMusic_getLoop(win->music);
    rand_target(enn);
    game(win, enn, live);
}