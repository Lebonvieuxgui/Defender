/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-guillaume.lebreton
** File description:
** basemenu
*/

#include "my.h"

Enemy_t *gest_chrono_duck2(Enemy_t *enemy)
{
    Enemy_t *duck2 = enemy;
    duck2->chrono = start_chrono(duck2->chrono);
    if (enemy->chrono.seconds > 0.1) {
        duck2->rect.left = move_rect_enemy(duck2->rect, 110, 0, 200);
        sfClock_restart(duck2->chrono.clock);
    }
    return enemy;
}

Enemy_t *gest_chrono_duck1(Enemy_t *enemy)
{
    Enemy_t *duck = enemy;
    duck->chrono = start_chrono(duck->chrono);
    if (enemy->chrono.seconds > 0.1) {
        duck->rect.left = move_rect_enemy(duck->rect, 110, 0, 200);
        sfClock_restart(duck->chrono.clock);
    }
    return enemy;
}

Enemy_t *create_duck1(Enemy_t *enemy)
{
    Enemy_t *duck = enemy;
    sfVector2f size;

    duck->texture = sfTexture_createFromFile("Ressources/duck.png", NULL);
    duck->rect.height = 110;
    duck->rect.width = 110;
    duck->rect.top = 0;
    duck->rect.left = 0;
    duck->coord.y = 70;
    duck->coord.x = 200;
    duck->chrono.clock = sfClock_create();
    duck->sprite = sfSprite_create();
    size.x = 1.5;
    size.y = 1.5;
        sfSprite_setScale(duck->sprite, size);
        sfSprite_setPosition(duck->sprite, duck->coord);
    sfSprite_setTexture(duck->sprite, duck->texture, sfFalse);
    sfSprite_setTextureRect(duck->sprite, duck->rect);

    return enemy;
}

Enemy_t *create_duck2(Enemy_t *enemy)
{
    Enemy_t *duck2 = enemy;
    sfVector2f size;

    duck2->texture = sfTexture_createFromFile("Ressources/duckr.png", NULL);
    duck2->rect.height = 110;
    duck2->rect.width = 110;
    duck2->rect.top = 0;
    duck2->rect.left = 0;
    duck2->coord.y = 70;
    duck2->coord.x = 1550;
    duck2->chrono.clock = sfClock_create();
    duck2->sprite = sfSprite_create();
    size.x = 1.5;
    size.y = 1.5;
    sfSprite_setScale(duck2->sprite, size);
    sfSprite_setPosition(duck2->sprite, duck2->coord);
    sfSprite_setTexture(duck2->sprite, duck2->texture, sfFalse);
    sfSprite_setTextureRect(duck2->sprite, duck2->rect);

    return enemy;
}
