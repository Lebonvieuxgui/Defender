/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-guillaume.lebreton
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "my.h"

enum GAMESTATE
{
    MENU,
    GAME,
    PAUSE,
    LOOSE,
    END,
    LOSE,
};

enum LIVES
{
    STILL,
    GONE
};

enum result
{
    SUCCESS = 0,
    FAILURE = -1,
    ERROR = 84
};

enum state_enemy
{
    ALIVE,
    DEAD
};

enum effect_enemy
{
    GOOD,
    ELECK_SOLO,
    ELECK_MULTIP,
    SLOW,
    MOVED
};

enum state_button
{
    ISNT_CLICKED,
    IS_CLICKED
};

enum state_enemy_altitude
{
    NEUTRAL,
    UP,
    DOWN
};

enum state_enemy_longitude
{
    LEFT,
    IMMOBILE,
    RIGHT
};

enum button_type
{
    TOWER,
    UX
};

enum tower_type
{
    NONE,
    FIRE,
    ICE,
    ZAP,
    TELEPORT
};

enum tower_state
{
    ACTIVATED,
    INACTIVATED
};

typedef struct Chrono_s
{
    sfTime time;
    float seconds;
    sfClock *clock;
} Chrono_t;

typedef struct myWindow_s
{
    int state;
    sfVideoMode mode;
    sfRenderWindow *window;
} myWindow_t;
typedef struct my_sprite_s
{
    sfEvent event;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
} my_sprite_t;

typedef struct Button_s
{
    sfSound *sound;
    sfIntRect rect;
    Chrono_t chrono;
    sfVector2f coord;
    size_t nb_display;
    my_sprite_t *button;
    Chrono_t chrono_display;
    sfSoundBuffer *buffer_sound;
    enum button_type type;
    enum state_button state;
    enum tower_type tower_type;
    enum tower_state tower_state;
} Button_t;

typedef struct Enemy_s
{
    sfIntRect rect;
    Chrono_t chrono;
    sfSprite *sprite;
    sfVector2f coord;
    sfTexture *texture;
    my_sprite_t *button;
    struct Enemy_s *next;
    struct Enemy_s *prev;
    Chrono_t chrono_effect;
    enum state_enemy state;
    enum effect_enemy effect;
    enum state_enemy_altitude altitude;
    enum state_enemy_longitude longitude;
} Enemy_t;
typedef struct Castle_s
{
    size_t nb_life;
    sfSound *sound;
    sfIntRect rect;
    Chrono_t *chrono;
    sfVector2f coord;
    myWindow_t *window;
    my_sprite_t *ressource;
    sfSoundBuffer *buffer_sound;
} Castle_t;

typedef struct Lives_s
{
    Castle_t *castle;
    sfVector2f coord;
    my_sprite_t *sprite;
    sfTexture *texture;
    enum LIVES LIVES;
}Lives_t;

typedef struct Global_s
{
    sfMusic *music;
    Chrono_t *chrono;
    myWindow_t *window;
    enum GAMESTATE GAMESTATE;
    Button_t *button;
} Global_t;

#endif
