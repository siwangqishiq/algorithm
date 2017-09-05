#include <stdio.h>
#include <stdlib.h>

typedef int Data_Type;

typedef struct Node{
	Data_Type data;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
} Node;

struct _BinaryTree{
	Node *root;
};
typedef struct _BinaryTree BinaryTree;

int insertNode(BinaryTree *tree, Data_Type insert){
	if(!tree)
		return -1;
	
	
	Node *insert_node = (Node *)malloc(sizeof(Node));
	if(!insert_node){
		printf("malloc insert node error!\n");
		return -1;
	}
	insert_node->data = insert;
	insert_node->left = NULL;
	insert_node->right = NULL;
	insert_node->parent = NULL;
	
	Node *p = tree->root;
	if(!p){
		tree->root = insert_node;
	}else{
		while(p){
			if(insert < p->data){
				if(p->left == NULL){//p==NULL
					p->left = insert_node;
					insert_node->parent = p;
					break;
				}else{
					p = p->left;	
				}
				
			}else{
				if(p->right == NULL){
					p->right = insert_node;
					insert_node->parent = p;
					break;
				}else{
					p = p->right;	
				}	
			}//end if
				
		}//end while
	}//end if
}

BinaryTree *buildBinaryTree(){
	BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree)); 
	
	if(!tree){
		printf("malloc tree error!\n");
		return NULL;
	}
	tree->root = NULL;
	return tree;
}

typedef void (*PrintFunc)(Node *node);

void printNode(Node *node){
	if(node){
		printf("%d ",node->data);
	}
} 

void printBinaryTreeNode(Node *node,PrintFunc fun){
	if(!node)
		return;
	
	if(node->left)
		printBinaryTreeNode(node->left,fun);
	fun(node);
	if(node->right)
		printBinaryTreeNode(node->right,fun);
	
}

void printBinaryTree(BinaryTree *tree){
	if(!tree)
		return;
	
	printBinaryTreeNode(tree->root,printNode);
	printf("\n");
}

int freeBinaryTreeNode(Node *tree_node){
	if(!tree_node)
		return 0;
	
	if(tree_node->left){
		freeBinaryTreeNode(tree_node->left);
	}
	
	if(tree_node->right){
		freeBinaryTreeNode(tree_node->right);
	}
	printf("free node %d \n",tree_node->data);
	
	free(tree_node);
	return 0;
}


int freeBinaryTree(BinaryTree *tree){
	if(!tree)
		return -1;
	
	freeBinaryTreeNode(tree->root);	
	free(tree);
	return 0;
}

Node *findNode(BinaryTree *tree,Data_Type value){
	if(!tree)
		return NULL;
	
	Node *p = tree->root;
	while(p){
		if(p->data > value){
			p = p->left;
		}else if(p->data < value){
			p = p->right;
		}else{
			return p;
		}
		//(*searchCount)++;
	}//end while
	
	return p;
}

Node *findSuccessor(Node *node){
	if(!node)
		return NULL;
	
	Node *p = node->right;
	while(p){
		if(p->left != NULL){
			p = p->left;
		}else{
			return p;
		}
	}//end while	
	return p;
}

//use newNode to place oldNode
int transPlant(BinaryTree *tree,Node *oldNode,Node *newNode){
	if(tree == NULL || oldNode == NULL)
		return -1;
	
	Node *parent = oldNode->parent;
	if(parent == NULL){
		tree->root = newNode;
		newNode->left = oldNode->left;
		newNode->right = oldNode->right;
		
		oldNode->left->parent = newNode;
		oldNode->right->parent = newNode;
	}else{// root delete
		if(parent->left == oldNode){
			parent->left = newNode;
		}else if(parent->right == oldNode){
			parent->right = newNode;
		}
		
		if(newNode!=NULL){
			newNode->parent = parent;	
		}
	}
	
	return 1;
}

int deleteBinaryTreeNode(BinaryTree *tree,Data_Type value){
	if(!tree)
		return -1;
	
	Node *p = findNode(tree,value);
	if(!p){
		printf("not found delete node\n");
		return -1;//not found delete 
	}
	
	if(p->left == NULL && p->right == NULL){
		transPlant(tree,p,NULL);
	}else if(p->left != NULL && p->right == NULL){
		transPlant(tree,p,p->left);
	}else if(p->left == NULL && p->right != NULL){
		transPlant(tree,p,p->right);
	}else{//left and right all not NULL
		Node * successorNode = findSuccessor(p);//
		if(successorNode != NULL){
			transPlant(tree,successorNode,successorNode->right);
			transPlant(tree , p ,successorNode);
			successorNode->left = p->left;
			successorNode->right = p->right;
			if(p->right!=NULL){
				p->right->parent = successorNode;
			}
			
			if(p->left!=NULL){
				p->left->parent = successorNode;
			}
		}
	}
	
	free(p);
	return 0;
}


int main(int argc,char *argv[]){
	BinaryTree *tree = buildBinaryTree();
	
	insertNode(tree, 2);
	insertNode(tree, 4);
	insertNode(tree, 6);
	insertNode(tree, 5);
	insertNode(tree, 7);
	insertNode(tree, 1);
	insertNode(tree, 8);
	insertNode(tree, 3);
	insertNode(tree, 10);
	
	printBinaryTree(tree);
	
	//deleteBinaryTreeNode(tree,10);
	//printBinaryTree(tree);
	
	deleteBinaryTreeNode(tree,3);
	printBinaryTree(tree);
	
	deleteBinaryTreeNode(tree,2);
	printBinaryTree(tree);
	
	freeBinaryTree(tree);
	
	return 0;
}