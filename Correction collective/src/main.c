/*
** WINTER CAMP EPITECH
** CESAR CODE - COBRA CODING CLUB
** THIS PROJECT IS DERIVED FROM THE "L'attaque de Cesar" PROJECT
** File description:
** Makefile use to compile the project
*/

#include "include/project.h"

int main(int argc, char **argv)
{
    char *message = NULL;
    if (argc == 2 && (strcmp(argv[1], "-h") == 0) ) {
        print_help();
        return 0;
    }
    if (argc == 4) {
        if (strcmp(argv[1], "decrypt") == 0) {
            if (string_is_digit(argv[3]) == false) {
                printf("Invalid STEPS '%s', should be an integer.", argv[2]);
                return -1;
            }
            message = read_file(argv[2]);
            if (message == NULL) {
                printf("Couldn't read file '%s'.", argv[1]);
                free(message);
                return -1;
            }
            decrypt(message, atoi(argv[3]));
            free(message);
            return 0;
        } else if (strcmp(argv[1], "encrypt") == 0) {
            if (string_is_digit(argv[3]) == false) {
                printf("Invalid STEPS '%s', should be an integer.", argv[2]);
                return -1;
            }
            message = read_file(argv[2]);
            if (message == NULL) {
                printf("Couldn't read file '%s'.", argv[1]);
                free(message);
                return -1;
            }
            encrypt(message, atoi(argv[3]));
            free(message);
            return 0;
        }
        printf("Invalid parameter: '%s'. Please use './My_Cesar -h' if you need help.\n", argv[1]);
        return -1;
    }
    printf("Invalid parameters. Please use './My_Cesar -h' if you need help.\n");
    return -1;
}

void print_help()
{
    printf("How to use this project:\n");
    printf("\t./My_Cesar [encrypt | decrypt] MESSAGE_FILE STEPS\n");
    printf("Where: \n");
    printf("\tYou have to chose an option between encrypt or decrypt\n");
    printf("\tMESSAGE_FILE is the file containing the message\n");
    printf("\tSTEPS is the number of steps required to cypher/decypher the message\n");
    return;
}

bool string_is_digit(char *string)
{
    int index = 0;
    if (string == NULL)
        return false;
    if (string[index] == '-') {
        index += 1;
    }
    for (; string[index] != '\0'; index++) {
        if (isdigit(string[index]) == false) {
            return false;
        }
    }
    return true;
}

char *read_file(char *path) {
    struct stat st;
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    size_t offset = 0;

    if (stat(path, &st) != 0) {
        perror("Failed to get file stats");
        return NULL;
    }
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }
    char *content = malloc(sizeof(char) * (st.st_size + 1));
    if (content == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }
    while ((read = getline(&line, &len, file)) != -1) {
        memcpy(content + offset, line, read);
        offset += read;
    }
    free(line);
    content[offset] = '\0';
    fclose(file);
    return content;
}