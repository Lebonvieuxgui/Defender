/*
** EPITECH PROJECT, 2022
** oui
** File description:
** oui
*/

#include "my.h"

Global_t *check_menu_buttons(myWindow_t *window, Button_t **menu_buttons, Global_t *global)
{
    if(menu_buttons[0]->state == IS_CLICKED) {
        global->GAMESTATE = GAME;
    }
    if(menu_buttons[1]->state == IS_CLICKED){
        sfRenderWindow_close(window->window);
        sfMusic_destroy(global->music);
    }
    return global;
}

void button_menu(sfEvent event, Button_t **menu_buttons)
{

    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= 830 && event.mouseButton.y >= 400 &&
        event.mouseButton.x <= 1050 && event.mouseButton.y <= 650) {
            menu_buttons[0]->state = IS_CLICKED;
        }
        if (event.mouseButton.x >= 770 && event.mouseButton.y >= 780 &&
        event.mouseButton.x <= 1200 && event.mouseButton.y <= 980) {
            menu_buttons[1]->state = IS_CLICKED;
        }
    }
}

void my_events_menu(sfEvent event, Global_t *global, Button_t **menu_buttons)
{   
    if (event.type == sfEvtKeyPressed){
        if (event.key.code == sfKeyQ) {
            sfRenderWindow_close(global->window->window);
        }
    }
    close_window(event, global);
    button_menu(event, menu_buttons);
}

Button_t **create_menu_button(Button_t **menu_buttons)
{
        menu_buttons[0] = malloc(sizeof(Button_t));
        menu_buttons[0]->state = ISNT_CLICKED;
        menu_buttons[1] = malloc(sizeof(Button_t));
        menu_buttons[1]->state = ISNT_CLICKED;
        return menu_buttons;
}

sfSprite *create_menu(void)
{
    sfTexture *menu_texture = sfTexture_createFromFile("Ressources/Menu.png", NULL);
    sfSprite *menu_sprite = sfSprite_create();

    sfSprite_setTexture(menu_sprite, menu_texture, sfFalse);
    return (menu_sprite);
}
