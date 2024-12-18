/*
** WINTER CAMP EPITECH
** CESAR CODE - COBRA CODING CLUB
** THIS PROJECT IS DERIVED FROM THE "L'attaque de Cesar" PROJECT
** File description:
** Makefile use to compile the project
*/

#include "include/project.h"


void decrypt(char *message, int steps)
{
    char *decrypted_message = NULL;
    char curChar = 0;
    if (!message)
        return;
    steps = steps % 26; // optimization to avoid doing useless iterations
    decrypted_message = calloc(strlen(message) + 1, sizeof(char));
    for (int i = 0; message[i] != '\0'; i++) {
        curChar = message[i];
        if (isalpha(curChar) == 0) {
            decrypted_message[i] = curChar;
        } else if ('A' <= curChar && curChar <= 'Z') {
            decrypted_message[i] =  (curChar - steps - 'A' + 26) % 26 + 'A';
        } else {
            decrypted_message[i] = (curChar - steps - 'a' + 26) % 26 + 'a';
        }
    }
    decrypted_message[strlen(message)] = '\0'; // this line is useless because memory allocated from calloc and not malloc
    printf("%s\n", decrypted_message);
}