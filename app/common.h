/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит первое слово из каждой строки в прямом порядке следования строк
 */
void showfirstwords(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняем файл 
 */
void save(text txt, char *filename);

/**
 * Перемещение курсора
 */
text move_cursor(text txt, int line, int pos);

/**
 * Перемещение курсора в конец текущего слова
 */
text mwef(text txt);

/**
 * Удаление строки, заданной номером number
 */

text rn(text txt, unsigned long number);

#endif
