/*
** EPITECH PROJECT, 2022
** fs_get_number_from_first_line
** File description:
** return first line of file
*/

#include <fcntl.h>
#include <unistd.h>
#include "include/windowsfuncs.h"

static int r_u_a_winner(int *printer, char buff, int *prev, int win)
{
    if (win == 1)
        return (1);
    if (*prev == -1 && (buff < 48 || buff > 57)){
        *prev = 0;
        return (0);
    }
    if ((*prev == 0 || *prev == -1) && buff == '-'){
        *prev = -1;
        return (0);
    }
    if (*prev >= 0 && buff > 47 && buff < 58){
        (*printer) = ((*printer) * 10) + (buff - 48);
        *prev += 1;
        return (0);
    }
    if (*prev > 0 && (buff < 48 || buff > 57))
        return (1);
}

static int ifunc(char buff)
{
    if (buff == '\n')
        return (1);
    return (0);
}

int get_score(char *filepath)
{
    char buff[100];
    int printer, prev, win, i, j, k;
    int fd = open(filepath, O_RDWR);

    printer = prev = win = i = j = k = 0;
    if (fd == -1){
        makehigh(filepath, 0);
        fd = open(filepath, O_RDWR);
    }
    while (j != 1){
        i = read(fd, buff, 100);
        for (k = 0; (k < i) && (buff[k] != '\n') && (buff[k] != '\0'); k ++) {
            j = ifunc(buff[k + 1]);
            win = r_u_a_winner(&printer, buff[k], &prev, win);
        }
    }
    close(fd);
    if (prev <= 0)
        return (0);
    return (printer);
}
