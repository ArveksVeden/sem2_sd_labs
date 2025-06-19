#include "token.h"

/*
    Парсит строку expr и заполняет массив tokens
    Возвращает количество найденных токенов
*/
int tokensize(const char* expr, struct Token tokens[], int max_tokens);