#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;

} Node;

Node* top;

void partition(Node* head, Node**left, Node**right){ // technique to divide the linked list into 2 partitions
    Node* a;  Node* b; // 2 iterative nodes in order to partition the list

    if (head == NULL || head->link == NULL){ 
        *left = head;
        *right = NULL;
    }else{
        b = head;
        a = head->link;

        while(a != NULL){
            a = a->link;
            if(a != NULL){ b = b->link; a = a->link; }
        }
        *left = head;
        *right = b->link;
        b->link = NULL;
    }
}

Node* Merge(Node* left, Node* right){

    Node* result = NULL;

    if (left == NULL){
        return right;
    }else if (right == NULL){
        return left;
    }

    if (left->data <= right->data){
        result = left;
        result->link = Merge(left->link, right);
    }else{
        result = right;
        result->link = Merge(left, right->link);
    }

    return result;

}

void mergeSort(Node**source){

    Node* head = *source;
    Node* L = NULL;
    Node* R = NULL;

    if(head == NULL || head->link == NULL){
        return;
    }

    partition(head, &L, &R);

    mergeSort(&L);
    mergeSort(&R);

    *source = Merge(L, R);

}

void Push(int x){ // insert at the beginning
	Node *temp = (Node*) malloc(sizeof(Node));
	
	temp->data = x; 
	temp->link = top;
	top = temp;
}

void Print(){
	Node* temp = top;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main(){

    Push(4);
    Push(3);
    Push(1);
    Push(5);
    Push(7); 
    Push(12); 
    Push(9); 
    Push(2); 
    Push(10); 

    printf("The original list: ");
    Print();
    mergeSort(&top);
    printf("The sorted list: ");
    Print();
}

// Mergesort on an array has space complexity of O(n),
// while mergesort on a linked list has space complexity of O(log(n))

