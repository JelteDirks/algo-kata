#include "../src/linkedlist.h"
#include <stdio.h>
#include <string.h>

struct LinkedList *make_list() {
  struct LinkedList *ll = malloc(sizeof(struct LinkedList));
  ll->head = NULL;
  ll->size = 0;
  return ll;
}

int remove_position(struct LinkedList *ll, int position) {
  int cur_pos = 0;
  struct ListNode *cur = ll->head;
  struct ListNode *prev = ll->head;
  struct ListNode *new_node;

  if (position >= ll->size) {
    return 1;
  }

  if (position == 0) {
    new_node = ll->head->next;
    free(ll->head);
    ll->head = new_node;

    ll->size -= 1;
    return 0;
  }

  while (cur_pos < position && cur != NULL) {
    prev = cur;
    cur = cur->next;
    cur_pos += 1;
  }

  if (cur_pos != position) {
    return 1;
  }

  new_node = prev->next->next;
  free(prev->next);
  prev->next = new_node;

  ll->size -= 1;
  return 0;
}

int head(struct LinkedList *ll, int *data) {
  struct ListNode *head = ll->head;
  if (head == NULL) {
    return 1;
  }
  *data = head->data;
  return 0;
}

int tail(struct LinkedList *ll, int *data) {
  struct ListNode *cur = ll->head;

  if (cur == NULL) {
    return 1;
  }

  while (cur->next != NULL) {
    cur = cur->next;
  }

  *data = cur->data;

  return 0;
}

int prepend(struct LinkedList *ll, int data) {
  struct ListNode *ln = malloc(sizeof(struct ListNode));
  ln->data = data;
  ln->next = NULL;

  struct ListNode *old_head = ll->head;
  ll->head = ln;
  ll->head->next = old_head;

  ll->size += 1;

  return 0;
}

int append(struct LinkedList *ll, int data) {
  struct ListNode *ln = malloc(sizeof(struct ListNode));
  ln->data = data;
  ln->next = NULL;

  struct ListNode *cur = ll->head;

  if (cur == NULL) {
    ll->head = ln;
    ll->size += 1;
    return 0;
  }

  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = ln;
  ll->size += 1;

  return 0;
}

char *to_str(struct LinkedList *ll) {
  struct ListNode *cur = ll->head;
  char *str = malloc(256 * sizeof(char));
  while (cur != NULL) {
    char buf[20];
    sprintf(buf, "%d->", cur->data);
    strcat(str, buf);
    cur = cur->next;
  }
  strcat(str, "NULL");
  return str;
}

void free_list(struct LinkedList *ll) {
  struct ListNode *cur = ll->head;
  struct ListNode *prev = NULL;

  while (cur != NULL) {
    prev = cur;
    cur = cur->next;
    free(prev);
  }

  free(ll);
}
