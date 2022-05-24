#include <stdio.h>
#include "common.h"
#include "_text.h"
#include "text.h"


text mwef(text txt) {
  int pos = txt->cursor->position;
  node *current = txt->begin;
  int i;
  int count = pos;
  int flag = 0;

  while(current) {
    if (txt->cursor->line == current) {
      flag = 1;
      break;
    }
    current = current->next;
  }
  if ((flag == 0) || (txt->cursor->line == NULL)) {
      fprintf(stderr, "There are already no any lines in the text!\n");
      return txt;
  }
  char *contents;
  int len;

  while(current) {
    contents = current->contents;
    len = strlen(contents);

    /* Цикл с поиском слова */
    for (i=pos; (contents[i] != '\n') && (i < len); i++) {
        /* Проверка на конец слова и кол-во выведенных символов */
        if ((contents[i] == ' ') && (count > 0)) {
            txt->cursor->position = count;
            return txt;
        }

        /* Проверка на букву */
        if (((int)contents[i] >= (int)'a') && (int)(contents[i] <= (int)'z')) {
            count++;
        }
        if (((int)contents[i] >= (int)'A') && ((int)contents[i] <= (int)'Z')) {
            count++;
        }
    }

    if (count == pos) {
        txt->cursor->position = 0;
        pos = 0;
        count = 0;
        if (current->next) {
            txt->cursor->line = current->next;
        }
        else {
            count = len-1;
            txt->cursor->position = count;
            return txt;
        }
    }

    current = current->next;
  }

  txt->cursor->position = count;

  return txt;
}
