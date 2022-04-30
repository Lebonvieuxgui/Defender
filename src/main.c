/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-guillaume.lebreton
** File description:
** main
*/
#include "my.h"

static int checkenv(char **env)
{
    if (env[0] == NULL)
        return 84;
    else {
        for (int i = 0; env[i] != NULL; i += 1) {
            if (my_strncmp(env[i], "DISPLAY", 7) == 0)
                return 0;
        }
        return 84;
    }
}

static int errors(char **env)
{
    if (checkenv(env) == 84)
        return 84;
    else
        return 0;
}

void my_print_h(void)
{
    my_putstr("\n        |");
    my_putstr("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    my_putstr("|\n        |");
    my_putstr("-------------------------------------");
    my_putstr("|\n        |");
    my_putstr(" MyDefender created with CSFML       ");
    my_putstr("|\n        |");
    my_putstr("-------------------------------------");
    my_putstr("|\n        |");
    my_putstr("                                     ");
    my_putstr("|\n        |");
    my_putstr(" USAGE:                              ");
    my_putstr("|\n        |");
    my_putstr("    ./my_defender     ");
    my_print_h2();
}

void my_print_h2(void)
{
    my_putstr("               ");
    my_putstr("|\n        |");
    my_putstr("                                     ");
    my_putstr("|\n        |");
    my_putstr("                                     ");
    my_putstr("|\n        |");
    my_putstr(" DESCRIPTION:                        ");
    my_putstr("|\n        |");
    my_putstr("  One wave of enemies comes from the ");
    my_putstr("|\n        |");
    my_putstr("  upper left corner.                 ");
    my_putstr("|\n        |");
    my_putstr("  Your mission is to defend the      ");
    my_putstr("|\n        |");
    my_putstr("  castle from the forces of evil !   ");
    my_putstr("|\n        |");
    my_putstr("_____________________________________|\n\n");
}

int main(int argc, char **argv, char **env)
{
    if (errors(env) == 84) {
        return 84;
    } else if (argc == 2 && argv[1][0] == '-' && argv[1][1]
     == 'h' && argv[1][2] == '\0') {
        my_print_h();
        return 0;
    } else {
    myLoop();
    return 0;
    }
}
