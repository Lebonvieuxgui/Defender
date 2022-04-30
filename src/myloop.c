/*
** EPITECH PROJECT, 2020
** csml_basics
** File description:
** myLoop.cpp.c
*/
#include "my.h"

myWindow_t *init_window(int width, int height)
{
    myWindow_t *win = malloc(sizeof(myWindow_t));

    win->mode.width = width;
    win->mode.height = height;
    win->mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(win->mode, "my_defender", \
    sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(win->window, 30);
    return win;
}

sfTexture *create_new_texture(char *file_path)
{
    sfTexture *texture = sfTexture_createFromFile(file_path, NULL);
    return texture;
}

sfSprite *create_sprite_and_set_texture(sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    return sprite;
}

sfSprite *create_map(void)
{
    sfTexture *map_texture = sfTexture_createFromFile("Ressources/map.png", NULL);
    sfSprite *map_sprite = sfSprite_create();

    sfSprite_setTexture(map_sprite, map_texture, sfFalse);
    return (map_sprite);
}

int myLoop(void)
{
    sfEvent event;
    sfSprite *map = create_map();
    sfSprite *menu = create_menu();
    sfSprite *pause = create_pause();
    sfSprite *lose = create_lose();
    Enemy_t *duck = malloc(sizeof(Enemy_t));
    Enemy_t *duck2 = malloc(sizeof(Enemy_t));
    Button_t **menu_buttons = malloc(sizeof(Button_t)* 2);
    Button_t **lose_buttons = malloc(sizeof(Button_t)* 2);
    Button_t **pause_buttons = malloc(sizeof(Button_t)* 3);
    Global_t *global = malloc(sizeof(Global_t));
    global->chrono = malloc(sizeof(Chrono_t));
    global->GAMESTATE = MENU;
    Enemy_t *enemy = malloc(sizeof(Enemy_t));
    myWindow_t *window = init_window(1920, 1080);
    Button_t **list_towers = malloc(sizeof(Button_t) * 5);
    Button_t **list_ux = malloc(sizeof(Button_t) * 1);
    Button_t **list_lives = malloc(sizeof(Button_t) * 5);
    Castle_t *castle = malloc(sizeof(Castle_t));
    castle->nb_life = 5;
    global->chrono->clock = sfClock_create();
    global->music = sfMusic_createFromFile("Ressources/music.ogg");

    duck = create_duck1(duck);
    duck2 = create_duck2(duck2);
    sfMusic_play(global->music);
    sfMusic_setLoop(global->music, sfTrue);
    create_menu_button(menu_buttons);
    create_pause_button(pause_buttons);
    create_lose_button(lose_buttons);
    sfRenderWindow_setFramerateLimit(window->window, 120);
    create_buttons(list_towers, list_ux, list_lives);
    create_first_enemy(enemy);
    create_enemy(enemy);
    while (sfRenderWindow_isOpen(window->window)) {
        if (global->GAMESTATE == GAME) {
            while (sfRenderWindow_pollEvent(window->window, &event)) {
                my_events(event, global, list_towers, list_ux);
            }
            if (castle->nb_life == 0) {
                global->GAMESTATE = LOSE;
            }
            if (list_ux[0]->state == IS_CLICKED) {
                gest_chrono(global, list_towers, enemy, castle);
                set_textures(enemy);
                set_postitions(enemy);
                effect_enemy(enemy);
            }
            set_textures_towers(list_towers);
            sfRenderWindow_clear(window->window, sfBlack);
            sfRenderWindow_drawSprite(window->window, map, NULL);
            draw_enemies(window, enemy);
            display_ux(window, list_ux);
            display_towers(window, list_towers);
            display_lives(window, list_lives, castle);
            sfRenderWindow_display(window->window);
        }
        if (global->GAMESTATE == LOSE) {
            while(sfRenderWindow_pollEvent(window->window, &event)) {
                my_events_lose(event, global, lose_buttons);
            }
            sfRenderWindow_clear(window->window, sfBlack);
            sfRenderWindow_drawSprite(window->window, lose, NULL);
            sfRenderWindow_display(window->window);
            global = check_lose_buttons(lose_buttons, global);
        }
        if (global->GAMESTATE == PAUSE) {
            while(sfRenderWindow_pollEvent(window->window, &event)) {
                my_events_pause(event, global, pause_buttons);
            }
            sfRenderWindow_clear(window->window, sfBlack);
            sfRenderWindow_drawSprite(window->window, map, NULL);
            draw_enemies(window, enemy);
            display_ux(window, list_ux);
            display_towers(window, list_towers);
            sfRenderWindow_drawSprite(window->window, pause, NULL);
            sfRenderWindow_display(window->window);
            global = check_pause_buttons(pause_buttons, global);
        }
        if (global->GAMESTATE == MENU) {
            while (sfRenderWindow_pollEvent(window->window, &event)) {
                my_events_menu(event, global, menu_buttons);
            }
            sfRenderWindow_clear(window->window, sfBlack);
            gest_chrono_duck1(duck);
            gest_chrono_duck2(duck2);
            sfSprite_setTextureRect(duck->sprite, duck->rect);
            sfSprite_setTextureRect(duck2->sprite, duck2->rect);
            sfRenderWindow_drawSprite(window->window, menu, NULL);
            sfRenderWindow_drawSprite(window->window, duck->sprite, NULL);
            sfRenderWindow_drawSprite(window->window, duck2->sprite, NULL);
            sfRenderWindow_display(window->window);
            global = check_menu_buttons(window, menu_buttons, global);
        }
        if (global->GAMESTATE == END) {
            free_towers(list_towers);
            sfRenderWindow_destroy(window->window);
            sfMusic_destroy(global->music);
            return 0;
        }
    }
    return (0);
}

Enemy_t *effect_enemy(Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;

    while (ptr->next != NULL) {
        if (ptr->effect == ELECK_SOLO) {
            ptr->chrono_effect = start_chrono(ptr->chrono_effect);
            if (ptr->chrono_effect.seconds > 1) {
                ptr->state = DEAD;
            }
        }
        if (ptr->effect == ELECK_MULTIP) {
            ptr->chrono_effect = start_chrono(ptr->chrono_effect);
            if (ptr->chrono_effect.seconds > 1) {
                ptr->state = DEAD;
            }
        }
        if (ptr->effect == SLOW) {
            ptr->chrono_effect = start_chrono(ptr->chrono_effect);
            if (ptr->chrono_effect.seconds > 5) {
                ptr->effect = GOOD;
            }
        }
        if (ptr->effect == MOVED) {
            ptr->chrono_effect = start_chrono(ptr->chrono_effect);
            if (ptr->chrono_effect.seconds > 5) {
                ptr->effect = GOOD;
            }
        }
        ptr = ptr->next;
    }
    return (enemy);
}

void free_towers(Button_t **list_towers)
{
    size_t i = 0;

    while (i < 5) {
        sfSound_destroy(list_towers[i]->sound);
        i = i + 1;
    }
}

Enemy_t *set_textures(Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;

    while (ptr->next != NULL) {
        sfSprite_setTextureRect(ptr->sprite, ptr->rect);
        ptr = ptr->next;
    }
    return (enemy);
}

Button_t **set_textures_towers(Button_t **list_towers)
{
    size_t i = 0;

    while (i < 5) {
        list_towers[i]->chrono_display.time = sfClock_getElapsedTime(list_towers[i]->chrono_display.clock);
        list_towers[i]->chrono_display.seconds = list_towers[i]->chrono_display.time.microseconds / 1000000.0;
        if (list_towers[i]->nb_display > 10) {
            list_towers[i]->tower_state = INACTIVATED;
            list_towers[i]->nb_display = 0;
            list_towers[i]->rect.top = 0;
        }
        if (list_towers[i]->tower_state == ACTIVATED
        && list_towers[i]->chrono_display.seconds > 0.1
        && list_towers[i]->tower_type != ZAP) {
            list_towers[i]->rect.top = list_towers[i]->rect.top + 250;
            list_towers[i]->nb_display = list_towers[i]->nb_display + 1;
            sfClock_restart(list_towers[i]->chrono_display.clock);
        } else if (list_towers[i]->tower_state == ACTIVATED
        && list_towers[i]->chrono_display.seconds > 0.1) {
            list_towers[i]->rect.top = list_towers[i]->rect.top + 350;
            list_towers[i]->nb_display = list_towers[i]->nb_display + 1;
            sfClock_restart(list_towers[i]->chrono_display.clock);
        }
        if (list_towers[i]->rect.top > 500 && list_towers[i]->tower_type != ZAP) {
            list_towers[i]->rect.top = 250;
        } else if (list_towers[i]->rect.top > 700) {
            list_towers[i]->rect.top = 350;
        }
        if (list_towers[i]->tower_type != NONE) {
            sfSprite_setTextureRect(list_towers[i]->button->sprite, list_towers[i]->rect);
        }
        i = i + 1;
    }
    return (list_towers);
}

void draw_enemies(myWindow_t *window, Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    while (ptr->prev != NULL) {
        if (ptr->state == ALIVE) {
            sfRenderWindow_drawSprite(window->window, ptr->sprite, NULL);
        }
        ptr = ptr->prev;
    }
}

void display_ux(myWindow_t *window, Button_t **list_ux)
{
    sfRenderWindow_drawSprite(window->window, list_ux[0]->button->sprite, NULL);
}

void display_towers(myWindow_t *window, Button_t **list_towers)
{
    size_t i = 0;

    while (i < 5) {
        if (list_towers[i]->state == IS_CLICKED || list_towers[i]->tower_type != NONE) {
            sfRenderWindow_drawSprite(window->window, list_towers[i]->button->sprite, NULL);
        }
        i = i + 1;
    }
}

Button_t **create_buttons(Button_t **list_towers, Button_t **list_ux, Button_t **lives)
{
    list_towers[0] = malloc(sizeof(Button_t));
    list_towers[0]->sound = sfSound_create();
    list_towers[0]->tower_state = INACTIVATED;
    list_towers[0]->state = ISNT_CLICKED;
    list_towers[0]->type = TOWER;
    list_towers[0]->tower_type = NONE;
    list_towers[0]->button = game_button(200, 350);
    list_towers[0]->chrono_display.clock = sfClock_create();
    list_towers[0]->chrono.clock = sfClock_create();
    list_towers[0]->coord.x = 320;
    list_towers[0]->coord.y = 500;
    list_towers[1] = malloc(sizeof(Button_t));
    list_towers[1]->sound = sfSound_create();
    list_towers[1]->chrono_display.clock = sfClock_create();
    list_towers[1]->tower_state = INACTIVATED;
    list_towers[1]->state = ISNT_CLICKED;
    list_towers[1]->type = TOWER;
    list_towers[1]->tower_type = NONE;
    list_towers[1]->button  = game_button(910, 170);
    list_towers[1]->chrono.clock = sfClock_create();
    list_towers[1]->coord.x = 1030;
    list_towers[1]->coord.y = 320;
    list_towers[2] = malloc(sizeof(Button_t));
    list_towers[2]->sound = sfSound_create();
    list_towers[2]->chrono_display.clock = sfClock_create();
    list_towers[2]->tower_state = INACTIVATED;
    list_towers[2]->state = ISNT_CLICKED;
    list_towers[2]->type = TOWER;
    list_towers[2]->tower_type = NONE;
    list_towers[2]->button  = game_button(890, 470);
    list_towers[2]->chrono.clock = sfClock_create();
    list_towers[2]->coord.x = 1000;
    list_towers[2]->coord.y = 620;
    list_towers[3] = malloc(sizeof(Button_t));
    list_towers[3]->sound = sfSound_create();
    list_towers[3]->chrono_display.clock = sfClock_create();
    list_towers[3]->tower_state = INACTIVATED;
    list_towers[3]->state = ISNT_CLICKED;
    list_towers[3]->type = TOWER;
    list_towers[3]->tower_type = NONE;
    list_towers[3]->button  = game_button(1090, 770);
    list_towers[3]->chrono.clock = sfClock_create();
    list_towers[3]->coord.x = 1210;
    list_towers[3]->coord.y = 920;
    list_towers[4] = malloc(sizeof(Button_t));
    list_towers[4]->sound = sfSound_create();
    list_towers[4]->chrono_display.clock = sfClock_create();
    list_towers[4]->tower_state = INACTIVATED;
    list_towers[4]->state = ISNT_CLICKED;
    list_towers[4]->type = TOWER;
    list_towers[4]->tower_type = NONE;
    list_towers[4]->button  = game_button(1280, 480);
    list_towers[4]->chrono.clock = sfClock_create();
    list_towers[4]->coord.x = 1400;
    list_towers[4]->coord.y = 630;
    list_ux[0] = malloc(sizeof(Button_t));
    list_ux[0]->state = ISNT_CLICKED;
    list_ux[0]->type = UX;
    list_ux[0]->tower_type = NONE;
    list_ux[0]->button  = game_button_wave(1580, 30);
    lives[0] = malloc(sizeof(Button_t));
    lives[0]->button = live_button(1300, 50);
    lives[1] = malloc(sizeof(Button_t));
    lives[1]->button = live_button(1350, 50);
    lives[2] = malloc(sizeof(Button_t));
    lives[2]->button = live_button(1400, 50);
    lives[3] = malloc(sizeof(Button_t));
    lives[3]->button = live_button(1450, 50);
    lives[4] = malloc(sizeof(Button_t));
    lives[4]->button = live_button(1500, 50);
    return (list_towers);
}

Enemy_t *set_postitions(Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;

    while (ptr != NULL) {
        if (ptr->coord.x >= 180 && ptr->coord.y >= 80
        && ptr->coord.x <= 300 && ptr->coord.y <= 350) {
            ptr->altitude = UP;
        } else if (ptr->coord.x >= 640 && ptr->coord.y >= 80
        && ptr->coord.x <= 920 && ptr->coord.y <= 460) {
            ptr->altitude = DOWN;
        } else if (ptr->coord.x >= 380 && ptr->coord.y >= 420
        && ptr->coord.x <= 580 && ptr->coord.y <= 930) {
            ptr->altitude = DOWN;
        } else if (ptr->coord.x >= 820 && ptr->coord.y >= 710
        && ptr->coord.x <= 990 && ptr->coord.y <= 940) {
            ptr->altitude = UP;
        } else if (ptr->coord.x >= 1500 && ptr->coord.y >= 650
        && ptr->coord.x <= 1670 && ptr->coord.y <= 940) {
            ptr->altitude = DOWN;
        } else {
            ptr->altitude = NEUTRAL;
        }
        if (ptr->coord.x >= 780 && ptr->coord.y >= 170
        && ptr->coord.x <= 830 && ptr->coord.y <= 390) {
            ptr->longitude = IMMOBILE;
        } else if (ptr->coord.x >= 130 && ptr->coord.y >= 260
        && ptr->coord.x <= 940 && ptr->coord.y <= 520) {
            ptr->longitude = LEFT;
        } else if (ptr->coord.x >= 460 && ptr->coord.y >= 520
        && ptr->coord.x <= 560 && ptr->coord.y <= 720) {
            ptr->longitude = IMMOBILE;
        } else {
            ptr->longitude = RIGHT;
        }
        sfSprite_setPosition(ptr->sprite, ptr->coord);
        ptr = ptr->next;
    }
    return (enemy);
}
