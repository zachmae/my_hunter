/*
** EPITECH PROJECT, 2020
** include
** File description:
** contain all of my includes
*/

#ifndef _HUNTER_H_
#define _HUNTER_H_

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include <time.h>
#include "include/my.h"

typedef struct ennemy
{
    sfSprite *sp_ennemy;
    sfIntRect show;
    sfVector2f pos_ennemy;
    sfVector2f move_ennemy;
}ennemy;

typedef struct tries
{
    sfSprite *live1;
    sfSprite *live2;
    sfSprite *live3;
    sfTexture *vide;
    int lives;
    sfText *tx_lost;
    sfText *new_game;
}lives;

typedef struct win
{
    sfRenderWindow *win;
    sfVideoMode video;
    sfText *score;
    char *score_str;
    int score_int;
    sfSprite *backg;
    sfEvent event;
    sfVector2i cursor;
    sfMusic *music;
    sfClock *clock;
    sfTime timer;
    float seconds;
    sfMusic *gunshot;
}window;

char *nbtostr(char *str, int nb);
int print_usage(int ac, char **av);
sfVideoMode set_videomode(void);
void handle_shot(window *win, ennemy *enn);
void move_enn(window *win, ennemy *enn, lives *live);
void animate_enn(ennemy *enn, int move, int max, window *win);
void rand_target(ennemy *enn);
void game(window *win, ennemy *enn, lives *live);
sfSprite *set_background(void);
sfSprite *create_ennemy(void);
window *init_window(void);
void clean(window *win, ennemy *enn, lives *live);
void show_lives(window *win, ennemy *enn, lives *live);
void draw_enn(window *win, ennemy *enn);
void draw(window *win, lives *live);
void events(window *win, ennemy *enn, lives *live);
sfVector2f set_init_ennpos(void);
sfVector2f set_moveenn(void);
sfIntRect get_ennemy(void);
sfText *set_score(void);
sfText *get_restart(void);
sfText *get_lost(void);
void put_asset(window *win, ennemy *enn, lives *live);
void hunter(window *win, ennemy *enn, lives *live);
void init_live(lives *live);

#endif