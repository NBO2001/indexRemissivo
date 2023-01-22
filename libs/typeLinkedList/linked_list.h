#ifndef _LINKED_LIST_H
#define _LIKEND_LIST_H

typedef struct typeList typeList;
typedef int (*compator)(void*, void*);

// Create new linked list
typeList * newLinkedList(compator cmp,unsigned long int sizeElement);

// Insert at the beginning of the list
void insert_start(typeList * list, void* data);

// Insert at the end of the list
void insert_end(typeList * list, void* data);

// Get the last value from the list
void* last_element(typeList * list);

// Remove at the beginning of the list
void* remove_start(typeList * list);

void* seach_in_list(typeList * list, void* key);

void* remove_with_key(typeList * list, void* key);


#endif
