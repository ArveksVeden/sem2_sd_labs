#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    struct Queue q;
    init_queue(&q); //front -> NULL <- rear

    enqueue(&q, 10); //front -> [10] <- rear
    enqueue(&q, 20); //front -> [10] -> [20] <- rear
    printf("Dequeue: %.2f\n", dequeue(&q)); // Должно вывести 10
    printf("Dequeue: %.2f\n", dequeue(&q)); // Должно вывести 20
    if (is_queue_empty(&q))
    {
        printf("stack is empty\n");
    }
    else {
        printf("stack has elements\n");
    }

    return 0;
}
