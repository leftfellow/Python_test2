#include <stdio.h>
#include "common.h"
#include "_text.h"
#include "text.h"

void save(text txt, char *filename)
{
    FILE *f;

    if (txt == NULL || txt->length == 0)
    {
        fprintf(stderr, "The text doesn't exist\n");
        return;
    }

    if ((f = fopen(filename, "w")) == NULL)
    {
        fprintf(stderr, "File %s can't be opened\n", filename);
        return;
    }

    assert(txt->begin != NULL && txt->end != NULL);

    node *current = txt->begin;

    do
    {
        fprintf(f, "%s\n", current->contents);
        current = current->next;
    } while(current);

    fclose (f);
}
