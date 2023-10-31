struct Stack {
  int size;
};

struct Stack *make_stack(void);
void free_stack(struct Stack *stack);
void push(struct Stack *stack, int data);
int pop(struct Stack *stack);
int peek(struct Stack *stack);
