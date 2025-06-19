#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h> // isalpha, etc
#include <stdlib.h> // atof
#include "tokenizer.h"

int tokensize(const char* expr, struct Token tokens[], int max_tokens)
{
    int i = 0; // позиция в expr
    int token_count = 0;

    while (expr[i] != '\0' && token_count < max_tokens)
    {
        // если _ проблем - пропускаем
        if (isspace(expr[i]))
        {
            i++;
            continue;;
        }

        // скобки
        if (expr[i] == '(')
        {
            tokens[token_count++] = (struct Token){TOKEN_LPAREN, "(", 0};
            i++;
        } else if (expr[i] == ')')
        {
            tokens[token_count++] = (struct Token){TOKEN_RPAREN, ")", 0};
            i++;
        }

        // операторы
        else if (strchr("+-*/^!", expr[i]) != NULL)
        {
            char op[2] = { expr[i], '\0' };
            tokens[token_count++] = (struct Token){TOKEN_OPERATOR, "", 0};
            strcpy(tokens[token_count - 1].str, op);
            i++;
        }

        // число (дробное или целое)
        else if (isdigit(expr[i]) || (expr[i]) == '.' && isdigit(expr[i + 1]))
        {
            char num_buf[32];
            int j = 0;

            // считываем число в буфер
            while (isdigit(expr[i]) || expr[i] == '.')
            {
                num_buf[j++] = expr[i++];
            }
            num_buf[j] = '\0';

            tokens[token_count].type = TOKEN_NUMBER;
            strcpy(tokens[token_count].str, num_buf);
            tokens[token_count].value = atof(num_buf); // atof - str to double | atoi - str to int
            token_count++;
        }

        // буквы (переменные или функции)
        else if (isalpha(expr[i]))
        {
            char word_buf[16];
            int j = 0;
            while (isalpha(expr[i]))
            {
                word_buf[j++] = expr[i++];
            }
            word_buf[j] = '\0';

            // пока считаем все как переменные
            tokens[token_count].type = TOKEN_VARIABLE;
            strcpy(tokens[token_count].str, word_buf);
            token_count++;
        }
        // неизвестный символ
        else
        {
            printf("неизвестный символ: '%c'\n", expr[i]);
            i++;
        }
    }

    return token_count;
}