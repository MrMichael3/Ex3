//Michael K�chler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

struct list{
	struct node* head;
};
struct node{
	int val;
	struct node* next;
};

struct list* init(){
	
	struct list* list = malloc(sizeof(struct list));
	list ->head = NULL;
	return list;
}

void append(struct list *listA, int val){
	if(listA->head == NULL){
		listA->head = malloc(sizeof(struct node));
		listA->head->val = val;
		listA->head->next = NULL;
	}
	else{
		struct node* p=listA->head;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = malloc(sizeof(struct node));
		p->next->val = val;
		p->next->next = NULL;
	}
}

void reverse(struct list *listA){
	if(listA->head != NULL || listA->head->next != NULL){
		struct node *p = listA->head;
		struct node *q = p->next;
		struct node *r = q->next;
		while(q != NULL){
			q->next = p;
			p = q;
			q = r;
			if(r!= NULL){
				r = r->next;
			}
		}
		listA->head->next = NULL;
		listA->head = p;
	}
	else if(listA->head->next != NULL){
		struct node *p = listA->head;
		p->next->next = p;
		p = p->next;
		listA->head->next = NULL;
		listA->head=p;
	}
}

void clear(struct list *listA){
	struct node *p = listA->head;
    struct node *q = p->next;

    while(p != NULL){
		free(p);
		p = q;
		if(q != NULL){
	    	q = q->next;
		}
    }
    listA->head = malloc(sizeof(struct node));
    listA->head = NULL;
}

void print(struct list *listA){
    struct node *p = listA->head;

    if(p == NULL){
		printf("[ ]\n");
    }
	else{
		printf("[ ");
		while(p->next != NULL){
	    	printf("%d ", p->val);
	   		p = p->next;
		}	
		printf("%d ]\n", p->val);
    }
}


void delete(struct list *listA, int i){

    if(i == 0){
		struct node *p = listA->head->next;
		free(listA->head);
		listA->head = p;
    }
    else{
		struct node *p = listA->head;
		int j=0;
		while(j < i-1){
	    	p = p->next;
	    	j++;
		}
		if(p->next->next != NULL){
	    	struct node *q = p->next;
	    	p->next = p->next->next;
	    	free(q);
		}
		else if(p->next->next == NULL){
	    	free(p->next);
	    	p->next = NULL;
		}
    }
}


void deleteLast(struct list *listA){

    if(listA->head != NULL){
		struct node *p = listA->head;
		if(p->next == NULL){
	    	free(p);
	    	listA->head == NULL;   
		}
		else{
	    	while(p->next->next != NULL){
				p = p->next;
	    	}
	    	free(p->next);
	    	p->next = NULL;
		}
    }
}
    


void max(struct list *listA){ 
    int max = 0;
    int i = 0;
    int tmp;
    if(listA->head == NULL){
		printf("List is empty\n");
		return;
    }
    if(listA->head->next != NULL){
		struct node *p = listA->head;
		tmp = p->val;
		while(p->next != NULL){
	    	i++;
	    	if(tmp < p->next->val){
				max = i;
				tmp = p->next->val;
	    	}
	    	p = p->next;
		}
    }
    printf("max = %d\n", max);
}


int main(){

    struct list *list = init();
    //1.
    append(list,9);
    append(list,4);
    append(list,5);
    append(list,3);
    append(list,1);
    append(list,2);
    append(list,0);
    //2.
    print(list);
    //3.
    reverse(list);
    //4.
    print(list);
    //5.
    delete(list,6);
    delete(list,3);
    delete(list,0);
    //6.
    print(list);
    //7.
    deleteLast(list);
    //8.
    print(list);
    //9.
    max(list);
    //10.
    clear(list);
    //11.
    print(list);
    
    free(list);
    
    return 0;
}
