#include <stdio.h>
#include <string.h>

#define TAB_SIZE 5

/*|---A
	|----B
	     |----C1
		 |----C2
	|----B2
	     |----D
		 |----E*/
		
typedef char* Data_Type;
typedef struct Node{
	Data_Type data;
	char name[100];
	struct Node *left;
	struct Node *right;
} Node;

typedef struct _Tree{
	Node *head;
} Tree;




void print_tab(int count){
	if(count <= 0)
		return;
	
	for(int i = 0,size = count * TAB_SIZE; i<size;i++){
		printf(" ");
	}//end for i
}

void show_tree(Node *head,int offset){
	if(!head) 
		return;
	
	int offset_value = offset;
	print_tab(offset_value);
	printf("|----%s\n",head->name);
	if(head->left)
		show_tree(head->left , offset + 1);
	if(head->right)
		show_tree(head->right , offset + 1);
}

void test_tree(){
	Node root;
	strcpy(root.name,"A");
	root.left = NULL;
	root.right = NULL;
	
	Node node_B;
	strcpy(node_B.name,"B");
	node_B.left = NULL;
	node_B.right = NULL;
	root.left = &node_B;
	
	Node node_C1;
	strcpy(node_C1.name,"C1");
	node_C1.left = NULL;
	node_C1.right = NULL;
	
	Node node_C2;
	strcpy(node_C2.name,"C2");
	node_C2.left = NULL;
	node_C2.right = NULL;
	
	node_B.left = &node_C1;
	node_B.right = &node_C2;
	
	Node node_B2;
	strcpy(node_B2.name,"B2");
	node_B2.left = NULL;
	node_B2.right = NULL;
	root.right = &node_B2;
	
	Node node_D;
	strcpy(node_D.name,"D");
	node_D.left = NULL;
	node_D.right = NULL;
	
	Node node_E;
	strcpy(node_E.name,"E");
	node_E.left = NULL;
	node_E.right = NULL;
	
	node_B2.left = &node_D;
	node_B2.right = &node_E;
	
	show_tree(&root , 0);
}


int main(int argc , char *grgv[]){
	test_tree();
	return 0;
}

		 
