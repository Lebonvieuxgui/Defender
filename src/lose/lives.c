/*
** EPITECH PROJECT, 2022
** oui
** File description:
** lives
*/

#include "my.h"

my_sprite_t *live_button(int x, int y)
{
    my_sprite_t *lives = NULL;

    if (!(lives = malloc(sizeof*(lives)))) {
        return (NULL);
    }

    lives->pos.x = x;
    lives->pos.y = y;
    lives->texture = sfTexture_createFromFile("Ressources/heart.png", NULL);
    lives->sprite = sfSprite_create();

    sfSprite_setPosition(lives->sprite, lives->pos);
    sfSprite_setTexture(lives->sprite, lives->texture, sfFalse);
    return (lives);
}

void display_lives(myWindow_t *window, Button_t **list_lives, Castle_t *castle)
{
    if (castle->nb_life > 0)
    sfRenderWindow_drawSprite(window->window, list_lives[0]->button->sprite, NULL);
    if (castle->nb_life > 1)
    sfRenderWindow_drawSprite(window->window, list_lives[1]->button->sprite, NULL);
    if (castle->nb_life > 2)
    sfRenderWindow_drawSprite(window->window, list_lives[2]->button->sprite, NULL);
    if (castle->nb_life > 3)
    sfRenderWindow_drawSprite(window->window, list_lives[3]->button->sprite, NULL);
    if (castle->nb_life > 4)
        sfRenderWindow_drawSprite(window->window, list_lives[4]->button->sprite, NULL);
}

