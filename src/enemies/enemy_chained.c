/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-guillaume.lebreton
** File description:
** enemy_chained
*/
#include "my.h"

Enemy_t *add_node_graph(Enemy_t *enemy)
{
    Enemy_t *ptr = enemy;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = malloc(sizeof(Enemy_t));
    ptr->next->next = NULL;
    ptr->next->prev = ptr;
    return (enemy);
}
