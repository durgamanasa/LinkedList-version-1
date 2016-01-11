typedef struct element{
	void *value;
	struct element *next;
} Element;

typedef struct list{
	struct element *first;
	struct element *last;
	int length;
	
} LinkedList;

typedef void (*ElementProcessor)(void *);

LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void increment(void *);
void forEach(LinkedList, ElementProcessor e);