/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-guillaume.lebreton
** File description:
** clock
*/
#include "my.h"

Enemy_t *create_clocks(Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;

    while (ptr != NULL) {
        ptr->chrono.clock = sfClock_create();
        ptr = ptr->next;
    }
    return (enemy);
}

Button_t *gest_chrono(Global_t *global, Button_t **list_towers, Enemy_t *enemy, Castle_t *castle)
{
    static float time_spawn = 0.0001;

    global->chrono->time = sfClock_getElapsedTime(global->chrono->clock);
    global->chrono->seconds = global->chrono->time.microseconds / 1000000.0;
    if (time_spawn < 0.5) {
        time_spawn = time_spawn + 0.0001;
    }
    if (global->chrono->seconds > 1.5 - time_spawn) {
        enemy = create_enemy(enemy);
        sfClock_restart(global->chrono->clock);
    }
    gest_chrono_enemy(enemy);
    check_castle(enemy, castle);
    gest_chrono_tower(list_towers, enemy);
    return 0;
}

Enemy_t *check_castle(Enemy_t *enemy, Castle_t *castle)
{
    Enemy_t *ptr_enemy = enemy;

    while (ptr_enemy->next != NULL) {
        if (ptr_enemy->coord.x >= 1770) {
            ptr_enemy->state = DEAD;
            castle->nb_life = castle->nb_life - 1;
        }
        ptr_enemy = ptr_enemy->next;
    }
    return (enemy);
}

Button_t **gest_chrono_tower(Button_t **list_towers, Enemy_t *enemy)
{
    Enemy_t *ptr_enemy = enemy;
    size_t nb_effects = 0;
    int i = 0;

    while (i < 5) {
        list_towers[i]->chrono.time = sfClock_getElapsedTime(list_towers[i]->chrono.clock);
        list_towers[i]->chrono.seconds = list_towers[i]->chrono.time.microseconds / 1000000.0;
        if (list_towers[i]->tower_type == FIRE && list_towers[i]->chrono.seconds > 3) {
            while (ptr_enemy->next != NULL) {
                if (ptr_enemy->coord.x >= (list_towers[i]->coord.x - 270)
                && ptr_enemy->coord.y >= (list_towers[i]->coord.y - 270)
                && ptr_enemy->coord.x <= (list_towers[i]->coord.x + 270)
                && ptr_enemy->coord.y <= (list_towers[i]->coord.y + 100)) {
                    if (ptr_enemy->effect == GOOD) {
                        sfClock_restart(list_towers[i]->chrono.clock);
                        sfClock_restart(list_towers[i]->chrono_display.clock);
                        sfClock_restart(ptr_enemy->chrono_effect.clock);
                        ptr_enemy->effect = ELECK_SOLO;
                        list_towers[i]->tower_state = ACTIVATED;
                        sfSound_play(list_towers[i]->sound);
                        return (list_towers);
                    }
                }
                ptr_enemy = ptr_enemy->next;
            }
        }
        if (list_towers[i]->tower_type == ICE && list_towers[i]->chrono.seconds > 3) {
            while (ptr_enemy->next != NULL) {
                if (ptr_enemy->coord.x >= (list_towers[i]->coord.x - 270)
                && ptr_enemy->coord.y >= (list_towers[i]->coord.y - 270)
                && ptr_enemy->coord.x <= (list_towers[i]->coord.x + 270)
                && ptr_enemy->coord.y <= (list_towers[i]->coord.y + 100)) {
                    if (ptr_enemy->effect == GOOD) {
                        sfClock_restart(list_towers[i]->chrono.clock);
                        sfClock_restart(list_towers[i]->chrono_display.clock);
                        sfClock_restart(ptr_enemy->chrono_effect.clock);
                        ptr_enemy->effect = SLOW;
                        list_towers[i]->tower_state = ACTIVATED;
                        sfSound_play(list_towers[i]->sound);
                        return (list_towers);
                    }
                }
                ptr_enemy = ptr_enemy->next;
            }
        }
        if (list_towers[i]->tower_type == ZAP && list_towers[i]->chrono.seconds > 6) {
            while (ptr_enemy->next != NULL) {
                if (ptr_enemy->coord.x >= (list_towers[i]->coord.x - 270)
                && ptr_enemy->coord.y >= (list_towers[i]->coord.y - 270)
                && ptr_enemy->coord.x <= (list_towers[i]->coord.x + 270)
                && ptr_enemy->coord.y <= (list_towers[i]->coord.y + 100)) {
                    if (ptr_enemy->effect == GOOD) {
                        sfClock_restart(list_towers[i]->chrono.clock);
                        sfClock_restart(list_towers[i]->chrono_display.clock);
                        sfClock_restart(ptr_enemy->chrono_effect.clock);
                        ptr_enemy->effect = ELECK_MULTIP;
                        list_towers[i]->tower_state = ACTIVATED;
                        nb_effects = nb_effects + 1;
                        sfSound_play(list_towers[i]->sound);
                        if (nb_effects == 3) {
                            return (list_towers);
                        }
                    }
                }
                ptr_enemy = ptr_enemy->next;
            }
        }
        if (list_towers[i]->tower_type == TELEPORT && list_towers[i]->chrono.seconds > 3) {
            while (ptr_enemy->next != NULL) {
                if (ptr_enemy->coord.x >= (list_towers[i]->coord.x - 270)
                && ptr_enemy->coord.y >= (list_towers[i]->coord.y - 270)
                && ptr_enemy->coord.x <= (list_towers[i]->coord.x + 270)
                && ptr_enemy->coord.y <= (list_towers[i]->coord.y + 100)) {
                    if (ptr_enemy->effect == GOOD) {
                        sfClock_restart(list_towers[i]->chrono.clock);
                        sfClock_restart(list_towers[i]->chrono_display.clock);
                        sfClock_restart(ptr_enemy->chrono_effect.clock);
                        ptr_enemy->effect = MOVED;
                        list_towers[i]->tower_state = ACTIVATED;
                        sfSound_play(list_towers[i]->sound);
                        return (list_towers);
                    }
                }
                ptr_enemy = ptr_enemy->next;
            }
        }
        ptr_enemy = enemy;
        i = i + 1;
    }
    return (list_towers);
}

Enemy_t *gest_chrono_enemy(Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;
    Enemy_t *ptr_ptr = ptr;

    while (ptr->next->next != NULL) {
        if(ptr->state == ALIVE) {
            ptr->chrono = start_chrono(ptr->chrono);
        } else {
            ptr_ptr = ptr;
            if (ptr_ptr->next != NULL) {
                ptr_ptr->prev->next = ptr_ptr->next;
                ptr_ptr->next->prev = ptr_ptr->prev;
                free(ptr_ptr);
            } else {
                ptr_ptr->prev->next = NULL;
                free(ptr_ptr);
            }
        }
        ptr = ptr->next;
    }
    ptr = enemy;
    if (enemy->chrono.seconds > 0.127) {
        while (ptr->next->next != NULL) {
            if (ptr->effect == ELECK_SOLO) {
                if (ptr->rect.left < 660) {
                    ptr->rect.left = 660;
                }
                ptr->rect.left = move_rect_enemy(ptr->rect, 94, 660, 835);
            } else if (ptr->effect == ELECK_MULTIP) {
                if (ptr->rect.left < 960) {
                    ptr->rect.left = 960;
                }
                ptr->rect.left = move_rect_enemy(ptr->rect, 94, 960, 1040);
            } else if (ptr->effect == SLOW) {
                if (ptr->rect.left < 1128) {
                    ptr->rect.left = 1128;
                }
                ptr->rect.left = move_rect_enemy(ptr->rect, 94, 1128, 1220);
            } else if (ptr->effect == MOVED) {
                if (ptr->rect.left < 1316) {
                    ptr->rect.left = 1316;
                }
                ptr->rect.left = move_rect_enemy(ptr->rect, 94, 1316, 1400);
            } else {
                ptr->rect.left = move_rect_enemy(ptr->rect, 94, 0, 650);
            }
            if (ptr->altitude == UP) {
                if (ptr->effect == SLOW) {
                    ptr->coord.y = ptr->coord.y - 1;
                } else if (ptr->effect == MOVED || ptr->effect == ELECK_MULTIP
                || ptr->effect == ELECK_SOLO){
                    ptr->coord.y = ptr->coord.y;
                } else {
                    ptr->coord.y = ptr->coord.y - 3;
                }
            } else if (ptr->altitude == DOWN) {
                if (ptr->effect == SLOW) {
                    ptr->coord.y = ptr->coord.y + 1;
                } else if (ptr->effect == MOVED || ptr->effect == ELECK_MULTIP
                || ptr->effect == ELECK_SOLO){
                    ptr->coord.y = ptr->coord.y;
                } else {
                    ptr->coord.y = ptr->coord.y + 3;
                }
            }
            if (ptr->longitude == RIGHT) {
                if (ptr->effect == SLOW) {
                    ptr->coord.x = ptr->coord.x + 2;
                } else if (ptr->effect == MOVED || ptr->effect == ELECK_MULTIP
                || ptr->effect == ELECK_SOLO){
                    ptr->coord.y = ptr->coord.y;
                } else {
                    ptr->coord.x = ptr->coord.x + 5;
                }
            } else if (ptr->longitude == LEFT) {
                if (ptr->effect == SLOW) {
                    ptr->coord.x = ptr->coord.x - 2;
                } else if (ptr->effect == MOVED || ptr->effect == ELECK_MULTIP
                || ptr->effect == ELECK_SOLO){
                    ptr->coord.y = ptr->coord.y;
                } else {
                    ptr->coord.x = ptr->coord.x - 5;
                }
            }
            ptr = ptr->next;
        }
        sfClock_restart(enemy->chrono.clock);
    }
    return (enemy);
}

int move_rect_enemy(sfIntRect rect, int value, int offset, int max_value)
{
    if (rect.left > max_value) {
        rect.left = offset;
        return (rect.left);
    } else {
        rect.left = rect.left + value;
        return (rect.left);
    }
    return (FAILURE);
}

Chrono_t start_chrono(Chrono_t chrono)
{
    chrono.time = sfClock_getElapsedTime(chrono.clock);
    chrono.seconds = chrono.time.microseconds / 1000000.0;
    return (chrono);
}
