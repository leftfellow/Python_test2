/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg2;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "showfirstwords") == 0) {
            showfirstwords(txt);
            continue;
        }

        /* Сохраняем в файл */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: upload filename\n");
            }
            else {
                save(txt, arg);
            }
            continue;
        }
	
        /* Перемещение курсора */
        if (strcmp(cmd, "move") == 0) {
        if ((arg = strtok(NULL, " \n")) == NULL ||
            (arg2 = strtok(NULL, "\n")) == NULL) {
            fprintf(stderr, "Not enough arguments");
        }
        else {
            int line = atoi(arg);
            int pos = atoi(arg2);
            txt = move_cursor(txt, line, pos);
//            show(txt);
        }
        continue;
        }

        /* Сохраняем в файл */
        if (strcmp(cmd, "mwef") == 0) {
            txt = mwef(txt);
            continue;
        }

        if (strcmp(cmd, "rn") == 0) {
            if ((arg = strtok(NULL, "\n")) == NULL) {
                fprintf(stderr, "Not enough arguments\n");
            }
            else {
                unsigned long number = arg[0] - '0';
                txt = rn(txt, number);
            }
            continue;
        }

          /* Если команда не известна */
          fprintf(stderr, "Unknown command: %s\n", cmd);
        }

    return 0;
}
