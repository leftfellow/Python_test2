#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "common.h"
#include "text.h"
#include "_text.h"

text rn(text txt, unsigned long number)
{
    unsigned long lenght = txt->length;


    /* Проверка на число, чтобы оно было >0 и <= кол-во строк */
    if ((number < 1) || (number > lenght)) {
        fprintf(stderr, "Incorrect data!\n");
        return txt;
    }

    unsigned long k = 1;
    node *current = txt->begin;
    node *next_str = current;
    node *prev_str = current;

    /* Перемещение к строке number */
    while(current) {
      if (k == number) {
        if (number != lenght)
            next_str = current->next;

        if (number != 1)
            prev_str = current->previous;

        break;
      }
      current = current->next;
      k++;
    }

//    free(current);

    if (txt->cursor->line == current) {
        if (k != lenght) {
            txt->cursor->line = next_str;
        }
        else {
            txt->cursor->line = prev_str;
        }
    }

    if ((number == 1) && (number == lenght)) {
        txt->begin = NULL;
        txt->end = NULL;
        txt->cursor->line = NULL;
        txt->length = 0;
    }

    if (number == 1) {
        if ((current != NULL) && (current->next != NULL)) {
            txt->begin = current->next;
        }
        else {
            txt->begin = NULL;
        }
        txt->length = lenght - 1;
        return txt;
    }

    if (number == lenght) {
        if ((current != NULL) && (current->previous != NULL)) {
            current = current->previous;
        }
        else {
            current = NULL;
        }
        if (current != NULL)
            current->next = NULL;

        txt->length = lenght - 1;
        return txt;
    }

    if (current != NULL) {
        current = current->next;
        current->previous = prev_str;
        current = current->previous;
        current->next = next_str;
        txt->length = lenght - 1;
    }
    return txt;
}
