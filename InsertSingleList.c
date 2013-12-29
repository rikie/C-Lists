/****************************************************************
**************** Author: Arijit Upadhyaya ***********************
*** Create a list, add elements at begining and end and then ****
*** rotate it on the node number provided and then print it. ****
*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}list;

void InsertBegin(list **head, int val) {
	list *temp = (list *)malloc(sizeof(list));
	temp->data=val;
	temp->next=*head;
	*head=temp;
}

void InsertEnd(list **head, int val) {
	list *current=*head;
	while(current->next != NULL) {
		current=current->next;
	}
	list *temp =(list *)malloc(sizeof(list));
	temp->data=val;
	temp->next=NULL;
	current->next=temp;
}

void rotate(list **head, int loc) {
	list *current=*head;
	int i=1;
	while(i < loc && current!=NULL) {
		current=current->next;
		i++;
	}

	if(current==NULL)
		return;
	list *kthNode=current;
	while(current->next != NULL) {
		current=current->next;
	}
	current->next=*head;
	*head=kthNode->next;
	kthNode->next=NULL;
}

void PrintList(list *head) {
	list *current=head;
	while(current) {
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
}

int main() {
	list *head=(list *)malloc(sizeof(list));
	head=NULL;
	int n,i,k;
	printf("Enter how many elements in the list\n");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		InsertBegin(&head,i);
	}
	for (i=0; i<n; i++) {
		InsertEnd(&head, i+n);
	}
	PrintList(head);
	printf("rotating the list, enter the node number after which you want to rotate\n");
	scanf("%d",&k);
	rotate(&head, k);
	printf("After rotating the new list is:\n");
	PrintList(head);
	return 0;
}
