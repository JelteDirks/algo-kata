#include "../src/linkedlist.h"
#include <stdio.h>
#include <string.h>

struct LinkedList *make_list() {
  struct LinkedList *ll = malloc(sizeof(struct LinkedList));
  ll->head = NULL;
  ll->size = 0;
  return ll;
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

void free_list(struct LinkedList *ll) { free(ll); }
