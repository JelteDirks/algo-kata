struct Stack {
  int size;

  int capacity;
  int *internal;
};

struct Stack *make_stack(void);
void free_stack(struct Stack *stack);
void push(struct Stack *stack, int data);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
