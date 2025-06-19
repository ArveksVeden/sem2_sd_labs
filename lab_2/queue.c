#include <stdio.h>
#include <stdlib.h> //для выделения памяти под новые узлы
#include "queue.h"

int is_queue_empty(struct Queue* q) {
	return (q->front == NULL); //если пусто - 1, иначе значение 0
}

void init_queue(struct Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

void enqueue(struct Queue* q, double val) {

	struct QueueNode* new_node = malloc(sizeof(struct QueueNode));
	if (!new_node) return; //проверка на ошибку выделения памяти
	new_node->value = val;
	new_node->next = NULL;

	//рассматриваем 2 случая: очередь пуста и new_node - первый ее элемент, и в очереди уже имеется хотя бы один узел, тогда new_node становится за ним

	if (q->rear == NULL) {
		q->front = new_node; //если очередь была пуста, то new_node - первый и послдений ее элемент
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node; //элемент, стоящий в конце очереди теперь указывает на новый элемент как на следующего в очереди
		q->rear = new_node; //rear теперь указывает на последний, только что пришедший элемент
	}

}

double dequeue(struct Queue* q) {
	//первая проверка - что вернуть если очередь пуста
	if (q->front == NULL) {
		return 0.0;
	}
	//далее - если очередь не пуста, то нам нужно 1) достать значение 2) обозначить элемент, стоящий после front за front 3) если очередь стала пустой, обнулить 4) удалить самый первый элемент с концами
	
	//1)
	double val = q->front->value;

	//2) передадим temp ссылку на первый элемень, чтобы позже почистить за собой память
	struct QueueNode* temp = q->front;
	q->front = q->front->next; //так как мы смотрим на очередь в виде front -> a -> b -> c <- rear, то чтобы элемент, стоящий ПОСЛЕ первого элемента сам им стал, нам надо передать ему флаг первенства через next
	
	//3) если очередь опустела, то мы по сути повторяем инициализацию
	if (q->front == NULL) q->rear = NULL;

	//4) 
	free(temp);
	return val;
}

void free_queue(struct Queue* q) {
	while (!(is_queue_empty(q))) {
		dequeue(q); 
	}
}