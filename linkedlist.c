#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
    /* malloc linked list struct and set head to NULL to create
       a new empty linked list */
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->numNodes = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertStart(LinkedList* list, void* data)
{
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = data; /* was newNode->data = entry; */
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;   
        list->tail = newNode;
    }
    else
    {
        list->head->prev = newNode;
        newNode->next = list->head;
        list->head = newNode;
    }
    (list->numNodes)++;
}


void* removeStart(LinkedList* list)
{   
    void* data = NULL;
    LinkedListNode* tmp;
    if (list->head == NULL)
    {
        printf("Linked List is empty");
    }
    else if (list->head->next == NULL)
    {
        data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        data = list->head->data;
        tmp = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(tmp);
    }
    (list->numNodes)--;
    return data;
}


void insertLast(LinkedList* list, void* data)
{
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = data; /* was newNode->data = entry; */
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list->tail == NULL)
    {
        list->head = newNode;   
        list->tail = newNode;
    }
    else
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    (list->numNodes)++;
}

void* removeLast(LinkedList* list)
{
    void* data = NULL;
    LinkedListNode* tmp;

    if (list->tail == NULL)
    {
        printf("Linked List is empty");
    }
    else if (list->head->next == NULL)
    {
        data = list->head->data;
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
    }
    else    
    { 
        data = list->tail->data;
        tmp = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(tmp);
    }
    (list->numNodes)--;
    return data;
}
    
void printLinkedList(LinkedList* list, void (*fptr)(void*)) 
{
    LinkedListNode* newNode;
    newNode = list->head;

    while (newNode != NULL)
    {
        (*fptr)(newNode->data);
        newNode = newNode->next;
    }
    printf("There are %d nodes\n", list->numNodes);
}

void freeLinkedList(LinkedList* list, void (*fptr)(void*)) 
{
    LinkedListNode* newNode;
    LinkedListNode* nextNode;

    newNode = list->head;
    
    while (newNode != NULL)
    {
        nextNode = newNode->next;
        (*fptr)(newNode->data);
        free(newNode);
        newNode = nextNode;
    }
    free(list); 
} 
