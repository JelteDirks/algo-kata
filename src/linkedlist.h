#include <stdlib.h>
struct ListNode {
  int data;
  struct ListNode *next;
};

struct LinkedList {
  int size;
  struct ListNode *head;
};

struct LinkedList *make_list();
void free_list(struct LinkedList *ll);
int remove_position(struct LinkedList *ll, int position);
int head(struct LinkedList *ll, int *data);
int tail(struct LinkedList *ll, int *data);
int append(struct LinkedList *ll, int data);
int prepend(struct LinkedList *ll, int data);
char * to_str(struct LinkedList *ll);
