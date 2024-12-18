/*
** WINTER CAMP EPITECH
** CESAR CODE - COBRA CODING CLUB
** THIS PROJECT IS DERIVED FROM THE "L'attaque de Cesar" PROJECT
** File description:
** Makefile use to compile the project
*/

#ifndef __PROJECT_H__
    #define __PROJECT_H__

/*===========================INCLUDES=========================*/
    #include <stdio.h>
    #include <unistd.h>
    #include "stdbool.h"
    #include "string.h"
    #include "ctype.h"
    #include "stdlib.h"
    #include <sys/stat.h>

/*============================FILES============================*/

/* main.c */
int main(int argc, char **argv);
bool string_is_digit(char *string);
void print_help();
char *read_file(char *path);

/* decrypt.c */
void decrypt(char *message, int steps);

/* encrypt.c */
void encrypt(char *message, int steps);

#endif /* !__PROJECT_H__ */
