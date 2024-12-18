/*
** WINTER CAMP EPITECH
** CESAR CODE - COBRA CODING CLUB
** THIS PROJECT IS DERIVED FROM THE "L'attaque de Cesar" PROJECT
** File description:
** Makefile use to compile the project
*/

#include "include/project.h"

void encrypt(char *message, int steps)
{
    char *encrypted_message = NULL;
    char curChar = 0;
    if (!message)
        return;
    encrypted_message = calloc(strlen(message) + 1, sizeof(char));
    for (int i = 0; message[i] != '\0'; i++) {
        curChar = message[i];
        if (isalpha(curChar) == 0) {
            encrypted_message[i] = curChar;
        } else if ('A' <= curChar && curChar <= 'Z') {
            encrypted_message[i] = (curChar + steps - 'A') % 26 + 'A';
        } else {
            encrypted_message[i] = (curChar + steps - 'a') % 26 + 'a';
        }
    }
    encrypted_message[strlen(message)] = '\0'; // this line is useless because memory allocated from calloc and not malloc
    printf("%s\n", encrypted_message);
}
