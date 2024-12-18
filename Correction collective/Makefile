##
## WINTER CAMP EPITECH
## CESAR CODE - COBRA CODING CLUB
## THIS PROJECT IS DERIVED FROM THE "L'attaque de Cesar" PROJECT
## File description:
## Makefile use to compile the project
##

PROJECT_BINARY =	My_Cesar

SRC =	src/*.c

CFLAGS = -W -Wall -Wextra

all: build

build:
	gcc -o $(PROJECT_BINARY) $(SRC) $(CFLAGS)

clean:

fclean: clean
	@ rm -f ${PROJECT_BINARY}

style: fclean
	coding-style . .
	clear
	@cat coding-style-reports.log
	@rm -f coding-style-reports.log

re: fclean all
