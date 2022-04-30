/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-guillaume.lebreton
** File description:
** gest_enemy
*/
#include "my.h"

Enemy_t *create_enemy(Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = malloc(sizeof(Enemy_t));
    ptr->next->prev = ptr;
    ptr = ptr->next;
    ptr->next = NULL;
    ptr->coord.x = -70;
    ptr->coord.y = (rand() % (210 - 170 + 1)) + 170;
    ptr->rect.height = 94;
    ptr->rect.width = 84;
    ptr->rect.left = 0;
    ptr->rect.top = 0;
    ptr->state = ALIVE;
    ptr->effect = GOOD;
    ptr->texture = sfTexture_createFromFile("Ressources/Enemy4walk.png", NULL);
    ptr->sprite = sfSprite_create();
    ptr->chrono.clock = sfClock_create();
    ptr->chrono_effect.clock = sfClock_create();
    sfSprite_setPosition(ptr->sprite, ptr->coord);
    sfSprite_setTexture(ptr->sprite, ptr->texture, sfFalse);
    sfSprite_setTextureRect(ptr->sprite, ptr->rect);
    return (enemy);
}

Enemy_t *create_first_enemy(Enemy_t *enemy)
{
    enemy->prev = NULL;
    enemy->next = NULL;
    enemy->coord.x = -1000000;
    enemy->coord.y = 3500;
    enemy->rect.height = 94;
    enemy->rect.width = 84;
    enemy->rect.left = 0;
    enemy->rect.top = 0;
    enemy->state = ALIVE;
    enemy->texture = sfTexture_createFromFile("Ressources/Enemy4walk.png", NULL);
    enemy->sprite = sfSprite_create();
    enemy->chrono.clock = sfClock_create();
    sfSprite_setPosition(enemy->sprite, enemy->coord);
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfFalse);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return (enemy);
}
