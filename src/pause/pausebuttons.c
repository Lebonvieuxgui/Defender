/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-guillaume.lebreton
** File description:
** pausebuttons
*/

#include "my.h"

Button_t **create_pause_button(Button_t **pause_buttons)
{
    pause_buttons[0] = malloc(sizeof(Button_t));
    pause_buttons[0]->state = ISNT_CLICKED;
    pause_buttons[1] = malloc(sizeof(Button_t));
    pause_buttons[1]->state = ISNT_CLICKED;
    pause_buttons[2] = malloc(sizeof(Button_t));
    pause_buttons[2]->state = ISNT_CLICKED;
    return pause_buttons;
}

void button_pause(Global_t *global, sfEvent event, Button_t **pause_buttons)
{
    if (event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= 600 && event.mouseButton.y >= 390 &&
        event.mouseButton.x <= 1050 && event.mouseButton.y <= 730) {
            pause_buttons[1]->state = IS_CLICKED;
        }
        if (event.mouseButton.x >= 900 && event.mouseButton.y >= 390 &&
        event.mouseButton.x <= 1200 && event.mouseButton.y <= 730) {
            pause_buttons[2]->state = IS_CLICKED;
        }
        if (event.mouseButton.x >= 1300 && event.mouseButton.y >= 190 &&
        event.mouseButton.x <= 1410 && event.mouseButton.y <= 300) {
            pause_buttons[0]->state = IS_CLICKED;
        }
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyQ)
        global->GAMESTATE = END;
        }
    }
}

Global_t *check_pause_buttons(Button_t **pause_buttons, Global_t *global)
{
    if (pause_buttons[0]->state == IS_CLICKED) {
        global->GAMESTATE = GAME;
    }
    if (pause_buttons[1]->state == IS_CLICKED){
        global->GAMESTATE = END;
        myLoop();
    }
    if (pause_buttons[2]->state == IS_CLICKED){
        global->GAMESTATE = END;
    }
    return global;
}
