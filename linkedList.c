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
	Element *ele = list.first;
	while(ele != NULL){
		e(ele->value);
		ele = ele->next;
	}
};

void * getElementAt(LinkedList list, int index){
	Element *ele = list.first;
	for (int i = 0; i < list.length; ++i){
		if (index == i){
			return ele->value;
		}
		ele = ele->next;
	}
	return NULL;
};

int indexOf(LinkedList list, void *number){
	int element = *(int *)number;
	Element *ele = list.first;
	for (int i = 0; i < list.length; ++i){
		if (element == *((int *)ele->value)){
			return 1;
		}
		ele = ele->next;
	}
	return -1;
};

void * deleteElementAt(LinkedList *list, int index){
	Element *ele = list->first;
	for (int i = 0; i < index; ++i){
		if (i == index-1){
			Element *deletedValue = ele->next->value;
			ele->next = ele->next->next;
			list->length--;
			return deletedValue;
		}
		ele = ele->next;
	}
	return NULL;
};

int asArray(LinkedList list, void ** array, int maxElements){
	Element *ele = list.first;
	int length;
	if (maxElements < list.length){
		length = maxElements;
	}
	length = list.length;
	for (int i = 0; i < length; ++i){
		array[i] = ele->value;
		ele = ele->next;
	}
	return maxElements;
};

int isOdd(void* hint, void* item){
	int value = *(int *)item;
	if (value % 2 != 0){
		return 1;
	}
	return 0;
};

LinkedList  filter(LinkedList list, MatchFunc func, void * hint){
	Element *ele = list.first;
	LinkedList odd_list = createList();
	for (int i = 0; i < list.length; ++i){
		if(func(hint, ele->value)){
			add_to_list(&odd_list, ele->value);
		}
		ele = ele->next;
	}
	return odd_list;
};

LinkedList reverse(LinkedList list){
	Element *ele = list.first;
	LinkedList reversedList = createList();
	for (int i = list.length-1; i >= 0; --i){
		add_to_list(&reversedList, getElementAt(list, i));
		ele = ele->next;
	}
	return reversedList;
};

void get_square(void * hint, void * sourceItem, void * destinationItem){
	int value = *(int *)sourceItem;
	int square = value * value;
	*(int *)destinationItem = square;
};

void increment_by_10(void * hint, void * sourceItem, void * destinationItem){
	int value = *(int *)sourceItem;
	int incremented_value = value + 10;
	*(int *)destinationItem = incremented_value;
};

LinkedList map(LinkedList list, ConvertFunc func, void *hint){
	Element *ele = list.first;
	LinkedList new_list = createList();
	for (int i = 0; i < list.length; ++i){
		void *dest = malloc(sizeof(void *));
		func(hint, ele->value, dest);
		add_to_list(&new_list, dest);
		ele = ele->next;
	}
	return new_list;
};

void* get_sum_of_list(void* hint, void* previousItem, void* item){
	*(int *) previousItem = *(int *)previousItem + *(int *)item;
	return previousItem;
};

void* reduce(LinkedList list, Reducer func, void *hint, void *initialValue){
	Element *ele = list.first;
	for (int i = 0; i < list.length; ++i){
		func(hint, initialValue, ele->value);
		ele = ele->next;
	}
	return initialValue;
};














