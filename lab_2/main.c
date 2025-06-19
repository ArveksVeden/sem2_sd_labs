#include <stdio.h>
#include "stack.h"
#include "tokenizer.h"

int main(void)
{
    struct Stack s; // создаем сам стек
    init_stack(&s); // инициализируем (обнуляем top)

    const char* expr = "sin(a)^2 + cos(b)^2 * 3.14";
    struct Token tokens[100];
    int count = tokensize(expr, tokens, 100);

    for (int i = 0; i < count; i++)
    {
        printf("Token [%d]: type=%d, str=%s, value=%.3f\n", 
                i, tokens[i].type, tokens[i].str, tokens[i].value);
    }


    return 0;
}