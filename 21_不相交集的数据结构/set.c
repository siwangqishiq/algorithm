#include <stdio.h>
#include <stdlib.h>

typedef char Elem;

struct Set_Node{
	Elem *data;
	struct Set *head;
	struct Set_Node *next;
};

typedef struct Set_Node Set_Node;
	
struct Set{
	Set_Node *head;
	Set_Node *tail;
	int rank;
};

typedef struct Set Set;

Set_Node *create_set_node(Elem *e);

Set *make_set(Set_Node *node);

Set *union_set(Set_Node *first,Set_Node *second);

Set *find_set(Set_Node *elem);

int is_same_set(Set_Node *elem_a,Set_Node *elem_b);

void print_set(Set *set);

int set_free(Set *set);

int set_node_free(Set_Node *node);

Set *link_set(Set *set,Set *append);

int main(int agrc,char *agrv[]){
	char A = 'a';
	char B = 'b';
	char C = 'c';
	char D = 'd';
	char E = 'e';
	char F = 'f';
	Set_Node *node_a = create_set_node(&A);
	Set_Node *node_b = create_set_node(&B);
	Set_Node *node_c = create_set_node(&C);
	Set_Node *node_d = create_set_node(&D);
	Set_Node *node_e = create_set_node(&E);
	Set_Node *node_f = create_set_node(&F);
	
	make_set(node_a);
	make_set(node_b);
	make_set(node_c);
	make_set(node_d);
	make_set(node_e);
	make_set(node_f);
	
	//union_set(node_a,node_b);
	
	union_set(node_a,node_b);
	union_set(node_a,node_c);
	union_set(node_a,node_d);
	
	union_set(node_e,node_f);
	union_set(node_e,node_f);
	
	print_set(find_set(node_a));
	print_set(find_set(node_b));
	print_set(find_set(node_c));
	print_set(find_set(node_d));
	print_set(find_set(node_e));
	print_set(find_set(node_f));
	//set_free(find_set(node_a));
	
	printf("a and b %s \n",is_same_set(node_a,node_b)==1?"in same set":"not in same set");
	printf("a and c %s \n",is_same_set(node_a,node_c)==1?"in same set":"not in same set");
	printf("a and f %s \n",is_same_set(node_a,node_f)==1?"in same set":"not in same set");
	
	return 0;
}//end main

Set *make_set(Set_Node *node){
	Set *set = (Set *)malloc(sizeof(Set));
	if(!set)
		return NULL;
	
	set->head = node;
	set->tail = node;
	set->rank = 1;
	
	node->head = set;
	
	return set;
}

Set *link_set(Set *set,Set *append){
	set->rank += append->rank;
	
	Set_Node *set_last_node = set->tail;
	Set_Node *append_head = append->head;
	set_last_node->next = append->head;
	
	set->tail = append->tail;
	
	Set_Node *node = append->head;
	while(node){
		node->head = set;
		node = node->next;
	}//end while
	
	free(append);
	
	return set;
}

Set *union_set(Set_Node *first,Set_Node *second){
	Set *set_a = find_set(first);
	Set *set_b = find_set(second);
	
	if(set_a == NULL && set_b==NULL)
		return NULL;
	
	if(set_a == NULL && set_b!=NULL)
		return set_b;
	
	if(set_a != NULL && set_b==NULL)
		return set_a;
	
	if(is_same_set(first,second)){
		return set_a;
	}
	
	if(set_a->rank >= set_b->rank){
		return link_set(set_a,set_b);
	}else{
		return link_set(set_b,set_a);
	}
}

Set *find_set(Set_Node *elem){
	return elem->head;
}

int is_same_set(Set_Node *elem_a,Set_Node *elem_b){
	return find_set(elem_a) == find_set(elem_b)?1:0;
}

void print_set(Set *set){
	if(!set){
		printf("The set is NULL\n");
		return;
	}
	
	printf("{");
	Set_Node *node = set->head;
	while(node){
		char *data_val = node->data;
		printf(" %c",*data_val);
		node = node->next;
	}//end while
	printf(" }\n");
}

int set_free(Set *set){
	if(!set)
		return -1;
	
	Set_Node *node = set->head;
	while(node){
		Set_Node *tmp = node;
		node = node->next;
		set_node_free(tmp);
	}//end while
	
	free(set);
	printf("free set\n");
	return 0;
}

int set_node_free(Set_Node *node){
	if(!node)
		return -1;
	
	free(node);
	return 0;
}

Set_Node *create_set_node(Elem *e){
	Set_Node *node = (Set_Node *)malloc(sizeof(Set_Node));
	if(!node)
		return NULL;
	
	node->head = NULL;
	node->next = NULL;
	node->data = e;
	
	return node;
}
