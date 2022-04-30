/*
** EPITECH PROJECT, 2020
** csml_basics
** File description:
** myLoop.cpp.c
*/
#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <struct.h>
    #include <float.h>
    #include <stdio.h>

    void my_events(sfEvent event, Global_t *global, Button_t **list_buttons, Button_t **list_ux);
    int my_strncmp(char const *s1, char const *s2, int n);
    void click_towers(sfEvent event, Button_t **list_towers);
    void keyboard(sfEvent event, Global_t *global);
    void close_window(sfEvent event, Global_t *global);
    my_sprite_t *game_button(int x, int y);
    myWindow_t *init_window(int width, int height);
    int myLoop(void);
    Button_t **create_buttons(Button_t **list_towers, Button_t **list_ux, Button_t **lives);
    sfSprite *create_map(void);
    void display_towers(myWindow_t *window, Button_t **list_buttons);
    Enemy_t *add_node_graph(Enemy_t *enemy);
    Enemy_t *create_enemy(Enemy_t *enemy);
    Enemy_t *create_first_enemy(Enemy_t *enemy);
    Enemy_t *create_clocks(Enemy_t *enemy);
    Enemy_t *gest_chrono_enemy(Enemy_t *enemy);
    Chrono_t start_chrono(Chrono_t chrono);
    int move_rect_enemy(sfIntRect rect, int value, int offset, int max_value);
    Enemy_t *set_postitions(Enemy_t *enemy);
    void draw_enemies(myWindow_t *window, Enemy_t *enemy);
    Enemy_t *set_textures(Enemy_t *enemy);
    my_sprite_t *game_button_wave(int x, int y);
    void click_ux(sfEvent event, Button_t **list_ux);
    void display_ux(myWindow_t *window, Button_t **list_ux);
    Button_t **gest_chrono_tower(Button_t **list_towers, Enemy_t *enemy);
    Button_t *gest_chrono(Global_t *global, Button_t **list_towers, Enemy_t *enemy, Castle_t *castle);
    Button_t **unclicked_towers(Button_t **list_towers, size_t except);
    Enemy_t *create_duck1(Enemy_t *enemy);
    Enemy_t *create_duck2(Enemy_t *enemy);
    Enemy_t *gest_chrono_duck1(Enemy_t *enemy);
    Enemy_t *gest_chrono_duck2(Enemy_t *enemy);
    size_t click_builder(sfEvent event, Button_t **list_towers);
    void click_builds(sfEvent event, Button_t **list_towers, size_t i);
    Button_t **set_textures_towers(Button_t **list_towers);
    Enemy_t *effect_enemy(Enemy_t *enemy);
    void free_towers(Button_t **list_towers);
    Enemy_t *check_castle(Enemy_t *enemy, Castle_t *castle);
    void my_print_h(void);
    void my_print_h2(void);
    void my_putstr(char *str);
    void my_putchar(char c);
    //lives
    my_sprite_t *live_button(int x, int y);
    void display_lives(myWindow_t *window, Button_t **list_lives, Castle_t *castle);
    Lives_t **alloc_and_set_pos_lives(Lives_t **lives);
    void click_lives(sfEvent event, Button_t **list_lives);
    //pause
    sfSprite *create_pause(void);
    void my_events_pause(sfEvent event, Global_t *global, Button_t **pause_buttons);
    Button_t **create_pause_button(Button_t **pause_buttons);
    void button_pause(Global_t *global, sfEvent event, Button_t **pause_buttons);
    Global_t *check_pause_buttons(Button_t **pause_buttons, Global_t *global);
    void pause_game(sfEvent event, Global_t *global);
    //menu
    sfSprite *create_menu(void);
    Button_t **create_menu_button(Button_t **menu_buttons);
    void button_menu(sfEvent event, Button_t **menu_buttons);
    void my_events_menu(sfEvent event, Global_t *global, Button_t **menu_buttons);
    Global_t *check_menu_buttons(myWindow_t *window, Button_t **menu_buttons, Global_t *global);
    //lose
    sfSprite *create_lose(void);
    Button_t **create_lose_button(Button_t **lose_buttons);
    void my_events_lose(sfEvent event, Global_t *global, Button_t **lose_buttons);
    void button_lose(sfEvent event, Button_t **lose_buttons);
    Global_t *check_lose_buttons(Button_t **lose_buttons, Global_t *global);

#endif
