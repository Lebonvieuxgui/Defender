/*
** EPITECH PROJECT, 2022
** oui
** File description:
** oui
*/

#include "my.h"

Button_t **create_lose_button(Button_t **lose_buttons)
{
    lose_buttons[0] = malloc(sizeof(Button_t));
    lose_buttons[0]->state = ISNT_CLICKED;
    lose_buttons[1] = malloc(sizeof(Button_t));
    lose_buttons[1]->state = ISNT_CLICKED;
    return lose_buttons;
}

Global_t *check_lose_buttons(Button_t **lose_buttons, Global_t *global)
{
    if(lose_buttons[0]->state == IS_CLICKED) {
        sfRenderWindow_close(global->window->window);
        sfMusic_destroy(global->music);
        myLoop();
    }
    if(lose_buttons[1]->state == IS_CLICKED){
        global->GAMESTATE = END;
    }
    return global;
}

void button_lose(sfEvent event, Button_t **lose_buttons)
{

    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= 680 && event.mouseButton.y >= 400 &&
        event.mouseButton.x <= 1230 && event.mouseButton.y <= 650) {
            lose_buttons[0]->state = IS_CLICKED;
        }
        if (event.mouseButton.x >= 770 && event.mouseButton.y >= 780 &&
        event.mouseButton.x <= 1200 && event.mouseButton.y <= 980) {
            lose_buttons[1]->state = IS_CLICKED;
        }
    }
}

void my_events_lose(sfEvent event, Global_t *global, Button_t **lose_buttons)
{   
    if (event.type == sfEvtKeyPressed){
        if (event.key.code == sfKeyQ) {
            global->GAMESTATE = END;
        }
    }
    close_window(event, global);
    button_lose(event, lose_buttons);
}

sfSprite *create_lose(void)
{
    sfTexture *lose_texture = sfTexture_createFromFile("Ressources/Lose.png", NULL);
    sfSprite *lose_sprite = sfSprite_create();

    sfSprite_setTexture(lose_sprite, lose_texture, sfFalse);
    return (lose_sprite);
}