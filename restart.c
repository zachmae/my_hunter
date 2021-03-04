/*
** EPITECH PROJECT, 2021
** restart.c
** File description:
** lost and restart function
*/

#include "hunter.h"

char *nbtostr(char *str, int nb)
{
    str[0] = nb / 100 + '0';
    str[1] = nb % 100 / 10 + '0';
    str[2] = nb % 10 + '0';
    return str;
}

sfText *get_lost(void)
{
    sfText *you_lost = sfText_create();
    sfFont *font = sfFont_createFromFile("sprites/font.ttf");
    sfVector2f loc;
    int height = 100;

    loc.x = 320;
    loc.y = 220;
    sfText_setString(you_lost, "YOU LOST");
    sfText_setPosition(you_lost, loc);
    sfText_setFont(you_lost, font);
    sfText_setCharacterSize(you_lost, height);
    sfText_setColor(you_lost, sfRed);
    return you_lost;
}

sfText *get_restart(void)
{
    sfText *restart = sfText_create();
    sfFont *font = sfFont_createFromFile("sprites/font.ttf");
    sfVector2f loc;
    int height = 40;

    loc.x = 250;
    loc.y = 350;
    sfText_setString(restart, "press space to try again");
    sfText_setPosition(restart, loc);
    sfText_setFont(restart, font);
    sfText_setCharacterSize(restart, height);
    sfText_setColor(restart, sfBlack);
    return restart;
}