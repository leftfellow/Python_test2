#include <stdio.h>
#include <assert.h>
#include "common.h"
#include <string.h>
#include "text.h"

static void show_word(int index, char *contents, int cursor, void *data);

/**
 * Выводит первое слово из каждой строки в прямом порядке следования строк
 */
void showfirstwords(text txt)
{
    /* Применяем функцию show_word к каждой строке текста */
    process_forward(txt, show_word, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_word(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    UNUSED(cursor);

    int i;
    int count = 0;
    int len = strlen(contents);

    /* Цикл с поиском слова */
    for (i=0; (contents[i] != '\n') && (i < len) ; i++) {
        /* Проверка на конец слова и кол-во выведенных символов */
        if ((contents[i] == ' ') && (count > 0))
            break;

        /* Проверка на букву */
        if (((int)contents[i] >= (int)'a') && (int)(contents[i] <= (int)'z')) {
            printf("%c",contents[i]);
            count++;
        }
        if (((int)contents[i] >= (int)'A') && ((int)contents[i] <= (int)'Z')) {
            printf("%c",contents[i]);
            count++;
        }
    }

    if (count == 0) {
        printf("No words");
    }

    printf("\n");
}
