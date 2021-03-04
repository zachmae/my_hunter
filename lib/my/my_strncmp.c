/*
** EPITECH PROJECT, 2020
** my strncmp
** File description:
** contain my strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (n; s1[n] != '\0' && s2[n] != '\0';n++) {
        if (s1[n] > s2[n])
            return 1;
        if (s2[n] > s1[n])
            return -1;
    }
    return 0;
}
