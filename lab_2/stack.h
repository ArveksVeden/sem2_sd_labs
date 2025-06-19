// Узел стека: хранит значение и указатель на следующий узел (тот, что был до него)
struct StackNode
{
    double value;           // значение (например, число 3.14)
    struct StackNode* next; // следующий элемент в стеке (тот, что "под ним")
};

struct Stack
{
    struct StackNode* top; // верхний элемент стека 
};

// === ФУНКЦИИ РАБОТЫ СО СТЕКОМ ===

// инициализация стека (устанавливает top = NULL)
void init_stack(struct Stack* s);

// Добавить элемент в стек (вверх) - push
void push(struct Stack* s, double val);

// Удалить верхний элемент и вернуть его значение - pop
double pop(struct Stack* s);

// Посмотреть значение верхнего элемента, не удаляя - peek
double peek(struct Stack* s);

// Проверка: пуст ли стек?
int is_stack_empty(struct Stack* s);

// Очищает стек после выполнения программы
void free_stack(struct Stack* s);