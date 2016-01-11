#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList createList(void){
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
	return *list;
};

int add_to_list(LinkedList *list,void *number){
	Element *temp = (Element *)malloc(sizeof (Element));
	temp->value = number; 
	temp->next = NULL;
	if(list->length == 0){
		list->first = list->last = temp;
	}
	else{
		list->last->next = temp;
		list->last = temp;
	}
	list->length++;
	return list->length;
};

void *get_first_element(LinkedList list){
	return list.first->value;
};

void *get_last_element(LinkedList list){
	return list.last->value;
};

void increment(void * item){
	*(int *)item += 1;
};

void forEach(LinkedList list, ElementProcessor e){
	Element *temp = list.first;
	while(temp != NULL){
		e(temp->value);
		temp = temp->next;
	}
};






















