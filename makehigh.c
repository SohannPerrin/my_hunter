/*
** EPITECH PROJECT, 2022
** fs_get_number_from_first_line
** File description:
** return first line of file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"

int makehigh(char *filepath, int score)
{
    char *buff1 = "high score = ";
    char *buff2 = int_to_str(score);
    char *buff3 = "\nc'est pas bien de se mettre un faux high score";
    int fd = open(filepath, O_CREAT | O_RDWR | O_TRUNC);

    write(fd, buff1, 13);
    write(fd, buff2, my_strlen(buff2));
    free(buff2);
    write(fd, buff3, 47);
}
