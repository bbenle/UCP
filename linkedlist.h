#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;
} LinkedListNode;

typedef struct 
{
    LinkedListNode* head;
    LinkedListNode* tail;
    int numNodes;
} LinkedList;

LinkedList* createLinkedList(void);
void insertStart(LinkedList* list, void* data);
void* removeStart(LinkedList* list);
void insertLast(LinkedList* list, void* data);
void* removeLast(LinkedList* list);
void printLinkedList(LinkedList* list, void (*fptr)(void*));
/* void writeLinkedList(LinkedList* list, void (*fptr)(void*, FILE*), FILE* outFile); */
void freeLinkedList(LinkedList* list, void (*fptr)(void*)); 
#endif
