/*
** EPITECH PROJECT, 2022
** yeah
** File description:
** yeah
*/

#include "my.h"

sfSprite *create_pause(void)
{
    sfTexture *pause_texture = sfTexture_createFromFile("Ressources/Pause.png", NULL);
    sfSprite *pause_sprite = sfSprite_create();

    sfSprite_setTexture(pause_sprite, pause_texture, sfFalse);
    return (pause_sprite);
}

void my_events_pause(sfEvent event, Global_t *global, Button_t **pause_buttons)
{
    close_window(event, global);
    button_pause(global, event, pause_buttons);
}
