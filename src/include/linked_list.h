#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef node_data_type
#define node_data_type int
#endif // !node_data_type

typedef struct node
{
    node_data_type token;
    unsigned int count;
    struct node *next;
    struct node *prev;
} node_t;

int list_is_empty();
int list_length();
int list_add(node_data_type t, int c);
int list_remove();
int list_next();
node_t*list_get_current();

#endif // LINKED_LIST_H
