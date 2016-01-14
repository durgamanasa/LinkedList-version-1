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
typedef int MatchFunc(void *,void *);
typedef void ConvertFunc(void *, void *, void *);

LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void increment(void *);
void forEach(LinkedList, ElementProcessor e);
void * getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int maxElements);
int isOdd(void*, void*);
LinkedList  filter(LinkedList, MatchFunc, void *);
LinkedList reverse(LinkedList);
