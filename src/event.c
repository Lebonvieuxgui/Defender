/*
** EPITECH PROJECT, 2020
** csml_basics
** File description:
** myLoop.cpp.c
*/

#include "my.h"

my_sprite_t *game_button(int x, int y)
{
    my_sprite_t *game_button = NULL;

    if (!(game_button = malloc(sizeof*(game_button)))) {
        return (NULL);
    }
    game_button->pos.x = x;
    game_button->pos.y = y;
    game_button->texture = sfTexture_createFromFile("Ressources/Builder.png", NULL);
    game_button->sprite = sfSprite_create();
    sfSprite_setPosition(game_button->sprite, game_button->pos);
    sfSprite_setTexture(game_button->sprite, game_button->texture, sfFalse);
    return (game_button);
}

my_sprite_t *game_button_wave(int x, int y)
{
    my_sprite_t *game_button = NULL;

    if (!(game_button = malloc(sizeof*(game_button)))) {
        return (NULL);
    }
    game_button->pos.x = x;
    game_button->pos.y = y;
    game_button->texture = sfTexture_createFromFile("Ressources/wave_button.png", NULL);
    game_button->sprite = sfSprite_create();
    sfSprite_setPosition(game_button->sprite, game_button->pos);
    sfSprite_setTexture(game_button->sprite, game_button->texture, sfFalse);
    return (game_button);
}

void close_window(sfEvent event, Global_t *global)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(global->window->window);
        sfMusic_destroy(global->music);
    }
}

void keyboard(sfEvent event, Global_t *global)
{
    if (event.key.code == sfKeyQ) {
        global->GAMESTATE = END;
    }
    if (event.key.code == sfKeyEscape) {
        global->GAMESTATE = PAUSE;
    }
}

void my_events(sfEvent event, Global_t *global, Button_t **list_towers, Button_t **list_ux)
{
    if (event.type == sfEvtKeyPressed)
        keyboard(event, global);
    close_window(event, global);
    click_towers(event, list_towers);
    click_ux(event, list_ux);
}

void click_ux(sfEvent event, Button_t **list_ux)
{
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x <= 1760 && event.mouseButton.y <= 130 &&
        event.mouseButton.x >= 1580 && event.mouseButton.y >= 30) {
            list_ux[0]->state = IS_CLICKED;
        }
    }
}

void click_towers(sfEvent event, Button_t **list_towers)
{
    size_t i = 0;
    size_t clicked = 0;

    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft) {
        clicked = click_builder(event, list_towers);
        if (clicked != 1) {
            while (i < 5) {
                click_builds(event, list_towers, i);
                i = i + 1;
            }
        }
    }
}

size_t click_builder(sfEvent event, Button_t **list_towers)
{
    if (event.mouseButton.x <= 400 && event.mouseButton.y <= 515 &&
    event.mouseButton.x >= 260 && event.mouseButton.y >= 470) {
        list_towers[0]->state = IS_CLICKED;
        list_towers = unclicked_towers(list_towers, 0);
        return (1);
    }
    if (event.mouseButton.x <= 1110 && event.mouseButton.y <= 340 &&
    event.mouseButton.x >= 960 && event.mouseButton.y >= 290) {
        list_towers[1]->state = IS_CLICKED;
        list_towers = unclicked_towers(list_towers, 1);
        return (1);
    }
    if (event.mouseButton.x <= 1110 && event.mouseButton.y <= 640 &&
    event.mouseButton.x >= 930 && event.mouseButton.y >= 590) {
        list_towers[2]->state = IS_CLICKED;
        list_towers = unclicked_towers(list_towers, 2);
        return (1);
    }
    if (event.mouseButton.x <= 1300 && event.mouseButton.y <= 950 &&
    event.mouseButton.x >= 1130 && event.mouseButton.y >= 890) {
        list_towers[3]->state = IS_CLICKED;
        list_towers = unclicked_towers(list_towers, 3);
        return (1);
    }
    if (event.mouseButton.x <= 1480 && event.mouseButton.y <= 640 &&
    event.mouseButton.x >= 1320 && event.mouseButton.y >= 600) {
        list_towers[4]->state = IS_CLICKED;
        list_towers = unclicked_towers(list_towers, 4);
        return (1);
    }
    return (0);
}

void click_builds(sfEvent event, Button_t **list_towers, size_t i)
{
    sfVector2f pos;

    if (list_towers[i]->state == IS_CLICKED) {
        if (event.mouseButton.x >= (list_towers[i]->coord.x - 105)
        && event.mouseButton.y >= (list_towers[i]->coord.y - 130)
        && event.mouseButton.x <= (list_towers[i]->coord.x - 30)
        && event.mouseButton.y <= (list_towers[i]->coord.y - 30)) {
            list_towers[i]->tower_type = FIRE;
            pos.x = list_towers[i]->coord.x - 75;
            pos.y = list_towers[i]->coord.y - 200;
            list_towers[i]->rect.height = 250;
            list_towers[i]->rect.width = 175;
            list_towers[i]->rect.left = 350;
            list_towers[i]->rect.top = 0;
            list_towers[i]->buffer_sound = sfSoundBuffer_createFromFile("Ressources/Pew.ogg");
            sfSound_setBuffer(list_towers[i]->sound, list_towers[i]->buffer_sound);
            sfSprite_setPosition(list_towers[i]->button->sprite, pos);
            list_towers[i]->button->texture = sfTexture_createFromFile("Ressources/Tour1.png", NULL);
            sfSprite_setTexture(list_towers[i]->button->sprite, list_towers[i]->button->texture, sfFalse);
            sfSprite_setTextureRect(list_towers[i]->button->sprite, list_towers[i]->rect);
        }
        if (event.mouseButton.x >= (list_towers[i]->coord.x + 40)
        && event.mouseButton.y >= (list_towers[i]->coord.y - 130)
        && event.mouseButton.x <= (list_towers[i]->coord.x + 125)
        && event.mouseButton.y <= (list_towers[i]->coord.y - 30)) {
            list_towers[i]->tower_type = ICE;
            pos.x = list_towers[i]->coord.x - 75;
            pos.y = list_towers[i]->coord.y - 200;
            list_towers[i]->rect.height = 250;
            list_towers[i]->rect.width = 175;
            list_towers[i]->rect.left = 350;
            list_towers[i]->rect.top = 0;
            list_towers[i]->buffer_sound = sfSoundBuffer_createFromFile("Ressources/wind.ogg");
            sfSound_setBuffer(list_towers[i]->sound, list_towers[i]->buffer_sound);
            sfSprite_setPosition(list_towers[i]->button->sprite, pos);
            list_towers[i]->button->texture = sfTexture_createFromFile("Ressources/Tour2.png", NULL);
            sfSprite_setTexture(list_towers[i]->button->sprite, list_towers[i]->button->texture, sfFalse);
            sfSprite_setTextureRect(list_towers[i]->button->sprite, list_towers[i]->rect);
        }
        if (event.mouseButton.x >= (list_towers[i]->coord.x + 40)
        && event.mouseButton.y >= (list_towers[i]->coord.y + 10)
        && event.mouseButton.x <= (list_towers[i]->coord.x + 125)
        && event.mouseButton.y <= (list_towers[i]->coord.y + 70)) {
            list_towers[i]->tower_type = ZAP;
            pos.x = list_towers[i]->coord.x - 90;
            pos.y = list_towers[i]->coord.y - 305;
            list_towers[i]->rect.height = 350;
            list_towers[i]->rect.width = 175;
            list_towers[i]->rect.left = 350;
            list_towers[i]->rect.top = 0;
            list_towers[i]->buffer_sound = sfSoundBuffer_createFromFile("Ressources/electricity.ogg");
            sfSound_setBuffer(list_towers[i]->sound, list_towers[i]->buffer_sound);
            sfSprite_setPosition(list_towers[i]->button->sprite, pos);
            list_towers[i]->button->texture = sfTexture_createFromFile("Ressources/Tour4.png", NULL);
            sfSprite_setTexture(list_towers[i]->button->sprite, list_towers[i]->button->texture, sfFalse);
            sfSprite_setTextureRect(list_towers[i]->button->sprite, list_towers[i]->rect);
        }
        if (event.mouseButton.x >= (list_towers[i]->coord.x - 105)
        && event.mouseButton.y >= (list_towers[i]->coord.y + 10)
        && event.mouseButton.x <= (list_towers[i]->coord.x - 30)
        && event.mouseButton.y <= (list_towers[i]->coord.y + 70)) {
            list_towers[i]->tower_type = TELEPORT;
            pos.x = list_towers[i]->coord.x - 75;
            pos.y = list_towers[i]->coord.y - 200;
            list_towers[i]->rect.height = 250;
            list_towers[i]->rect.width = 175;
            list_towers[i]->rect.left = 350;
            list_towers[i]->rect.top = 0;
            list_towers[i]->buffer_sound = sfSoundBuffer_createFromFile("Ressources/teleport.ogg");
            sfSound_setBuffer(list_towers[i]->sound, list_towers[i]->buffer_sound);
            sfSprite_setPosition(list_towers[i]->button->sprite, pos);
            list_towers[i]->button->texture = sfTexture_createFromFile("Ressources/Tour3.png", NULL);
            sfSprite_setTexture(list_towers[i]->button->sprite, list_towers[i]->button->texture, sfFalse);
            sfSprite_setTextureRect(list_towers[i]->button->sprite, list_towers[i]->rect);
        }
    }
}

Button_t **unclicked_towers(Button_t **list_towers, size_t except)
{
    size_t i = 0;
    static size_t ancient_click = 0;
    static size_t nb_clicks = 0;

    while (i < 5) {
        if (i != except) {
            list_towers[i]->state = ISNT_CLICKED;
        }
        i = i + 1;
    }
    if (except == ancient_click) {
        nb_clicks = nb_clicks + 1;
        if (nb_clicks == 2) {
            list_towers[except]->state = ISNT_CLICKED;
            nb_clicks = 0;
        }
    }
    ancient_click = except;
    return (list_towers);
}
