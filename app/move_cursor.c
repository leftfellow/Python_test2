#include <stdio.h>
#include "common.h"
#include "_text.h"
#include "text.h"

text move_cursor(text txt, int line, int pos) {
  if (txt == NULL || txt->length == 0) {
    fprintf(stderr, "There are already no any lines in the text!\n");
    return txt;
  }

  node *current = txt->begin;
  int k = 1;

  if (pos >= 0)
  {
      txt->cursor->position = pos;
  }
  else
  {
      txt->cursor->position = 0;
  }

  if (line <= 0) {
      txt->cursor->line = current;
      return txt;
  }

  int l = txt->length;

  if (line > l) {
      line = l;
  }

  while(current) {
    if (k == line) {
      txt->cursor->line = current;
      break;
    }
    current = current->next;
    k++;
  }
  return txt;
}
