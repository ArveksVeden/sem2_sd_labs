#include <stdio.h>
#include <stdlib.h> // для malloc
#include "stack.h"

int is_stack_empty(struct Stack* s)
{
    return s->top == NULL;
}

void init_stack(struct Stack* s)
{
    s->top = NULL;
}

void push(struct Stack* s, double val)
{
    struct StackNode* new_node = malloc(sizeof(struct StackNode));

    new_node->value = val;
    new_node->next = s->top; // старый top уходит вниз
    s->top = new_node;       // новый элемент становится вершиной
}

double pop(struct Stack* s)
{
    if (s->top == NULL)
    {
        printf("warning! stack is empty.\n");
        return 0;
    }

    struct StackNode* temp = s->top;    // текущая вершина
    double val = temp->value;           // значение текущей вершины

    s->top = s->top->next;              // сдвигаем вершину вниз
    free(temp);                         // удаляем старый top

    return val;
}

double peek(struct Stack* s)
{
    if (s->top == NULL)
    {
        printf("warning! stack is empty.\n");
        return 0;
    }

    return s->top->value;
}

void free_stack(struct Stack* s)
{
    while (!is_stack_empty(s))
    {
        pop(s); // pop в нашей программе сам освобождает память
    }
}