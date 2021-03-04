/*
** EPITECH PROJECT, 2020
** main
** File description:
** thats the main
*/

#include "hunter.h"

void handle_shot(window *win, ennemy *enn)
{
    int c;

    sfMusic_play(win->gunshot);
    for (c = 0; c < 25; c++) {
        if ((win->cursor.x < enn[c].pos_ennemy.x + 96 &&
            win->cursor.x > enn[c].pos_ennemy.x)
            && (win->cursor.y < enn[c].pos_ennemy.y + 96 &&
            win->cursor.y > enn[c].pos_ennemy.y)
            && enn[c].move_ennemy.x != 0) {
                win->score_int++;
                win->score_str = nbtostr(win->score_str, win->score_int);
                enn[c].pos_ennemy = set_init_ennpos();
                enn[c].move_ennemy = set_moveenn();
                sfText_setString(win->score, win->score_str);
        }
    }
}

sfVideoMode set_videomode(void)
{
    sfVideoMode video;

    video.width = 1220;
    video.height = 720;
    video.bitsPerPixel = 32;
    return (video);
}

int print_usage(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("this is my_hunter, an epitech project.\n");
        my_printf("Drakes are invading Origami World, you must stop them!\n");
        my_printf("Shoot drakes by pressing left click, press escape to exit");
        my_printf("\nGood luck, Have FUN!\n");
        return 1;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    window win;
    ennemy enn[25];
    lives life;

    if (env == NULL)
        return 84;
    if (print_usage(ac, av) == 1)
        return 0;
    hunter(&win, enn, &life);
    return 0;
}
