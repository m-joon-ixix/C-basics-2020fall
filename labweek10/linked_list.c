/*
* Programming Practice week 10
* Singly Linked List 
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct __node{
  int data;
  struct __node* next;
}node;

typedef struct __list{
  node* head;
  int cnt;
}list;

void clear_list(list*);
void append_node(list*);
void insert_node(list*);  
void delete_node(list*);
void print_list(list*);
void reverse_list(list*); //hw1
void sort_list(list*);    //hw2

// defined new functions for hw2
void swap_list(list*, int);
int compare_data(list*, int);

int main(){
  printf("\033[2J\033[H"); //clear screen
  printf("\t**week10 practice**\n");
  /* init a list */
  list* L = (list*)malloc(sizeof(list));
  if(!L) printf("Failed to Init.\n");
  L->head = NULL;
  L->cnt = 0;
  while(1){
    printf("a : append   i : insert  d : delete\nr : reverse  s : sort    p : print\nq : quit\n");
    printf("Press key : ");    
    char c = getchar();
    getchar(); // remove '\n'   
    printf("\033[2J\033[H"); //clear screen   
    switch(c){
      case 'a' : append_node(L);  break;
      case 'i' : insert_node(L);  break;
      case 'd' : delete_node(L);  break;
      case 'r' : reverse_list(L); break;
      case 's' : sort_list(L);    break;
      case 'p' : print_list(L);   break;
      case 'q' : clear_list(L);   return 0;
      default : printf("Invalid Key\n");
    }
  }
  return 0;
}

void clear_list(list* L){
  while(L->head){
    node* tmp = L->head;
    L->head = L->head->next;
    free(tmp);
  }
  free(L);
}

void append_node(list* L){
  node* N = (node*)malloc(sizeof(node));
  if(!N){
    printf("Failed to create a node\n");
    return;
  }
  int n;
  printf("Data : ");
  scanf("%d", &n);
  getchar(); // remove '\n'
  N->data = n;
  N->next = L->head;
  L->head = N;
  L->cnt++;
  printf("\033[2J\033[H"); //clear screen
  printf("\t Append succeeded\n");   
}

void insert_node(list* L){
  /* implement this function */
  int idx, n;
  printf("Index(0~) : ");
  scanf("%d", &idx);
  getchar(); // remove '\n'
  printf("\033[2J\033[H"); //clear screen
  if(idx == 0){ //equals to append
    append_node(L);
    return;
  }
  else if(idx > L->cnt || idx < 0){
    printf("Invalid Index\n");
    return;
  }  
  node* N = (node*)malloc(sizeof(node));
  if(!N){
    printf("Failed to create a node\n");
    return;
  }
  printf("Data : ");
  scanf("%d", &n);
  getchar(); // remove '\n'
  node* t = L->head;
  while(idx-- != 1){    
    t = t->next;    
  }
  N->data = n;
  N->next = t->next;
  t->next = N;
  L->cnt++;
  printf("\033[2J\033[H"); //clear screen
  printf("\t Insert succeeded\n");
}

void delete_node(list* L){
  if(L->cnt == 0){
    printf("Empty\n");
    return;
  }
  int idx;
  node* curr = L->head;
  node* prev = NULL;
  printf("Index(0~) : ");
  scanf("%d", &idx);
  getchar(); // remove '\n'
  printf("\033[2J\033[H"); //clear screen
  if(idx > L->cnt-1 || idx < 0){
    printf("Invalid Index\n");
    return;
  }
  else if(idx == 0){
    L->head = L->head->next;
    free(curr);
  }
  else{    
    while(idx--){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
  }
  L->cnt--;
  printf("\t Delete succeeded\n");
}

void print_list(list* L){
  if(L->cnt == 0){
    printf("Empty\n");
    return;
  }
  node* t = L->head;
  while(t){
    printf("%d ", t->data);
    t = t->next;
  }
  printf("\n");
}

void reverse_list(list* L){
  /* hw1 */
	if((L->cnt == 0) || (L->cnt == 1)) return;

	node *left = NULL;
	node *center = NULL;
	node *right = L -> head;
	
	while(right){
		left = center;
		center = right;
		right = right -> next;
		center -> next = left;
	}
	L -> head = center;
}

void sort_list(list* L){
  /* hw2 */
	if((L->cnt == 0) || (L->cnt == 1)) return;
	
	for(int i = L->cnt; i > 1; i--){
		for(int j = 1; j < i; j++){
			// compare and swap jth, (j+1)th
			if(compare_data(L, j) > 0) swap_list(L, j);
		}
	}
}

void swap_list(list* L, int i){
	/* swap ith and (i+1)th node (i = 1, 2,..., L->cnt - 1) */
	assert((i > 0) && (i < L->cnt));

	node *left = NULL;
	node *center = NULL;
	node *right = L -> head;
	for(int j = 0; j < i; j++){
		left = center;
		center = right;
		right = right -> next;
	}
	if(i == 1){
		L -> head = right;
		center -> next = right -> next;
		right -> next = center;
	} else {
		left -> next = right;
		center -> next = right -> next;
		right -> next = center;
	}
}

int compare_data(list* L, int i){
	/* compare ith and (i+1)th node (i = 1, 2,..., L->cnt - 1) */
	assert((i > 0) && (i < L->cnt));

	node *left = NULL;
	node *right = L -> head;
	for(int j = 0; j < i; j++){
		left = right;
		right = right -> next;
	}

	if((left->data) > (right->data)) return 1;
	else if((left->data) < (right->data)) return -1;
	else return 0;
}
