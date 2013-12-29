/****************************************************************
**************** Author: Arijit Upadhyaya ***********************
*** Create a list, add elements at begining and then create  ****
***     loop and then detect if there is any loop            ****
*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} list;

int InsertBegin(list **head, int val) {
	list *temp=(list *)malloc(sizeof(list));
	if(!temp)
		return 0;
	temp->data=val;
	temp->next=*head;
	*head=temp;
	return 1;
}

void PrintList(list *head) {
	list *current=head;
	while(current) {
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
}

void CreateLoop(list *head) {
	list *current=head;
	while(current->next != NULL) {
		current=current->next;
	}
	current->next=head;
}

int DetectLoop(list *head) {
	list *slow, *fast;
	slow=fast=head;
	while(slow && fast && fast->next) {
		slow=slow->next;
		fast=fast->next->next;
		if(slow == fast)
			return 1;
	}
	return 0;
}

int main() {
	list *head=(list *)malloc(sizeof(list));
	head=NULL;
	int n,i;	
	printf("How many elements\n");
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		if(!(InsertBegin(&head, i)))
			printf("Insertion Failed\n");
	}
	printf("Printing List...\n");
	PrintList(head);
	printf("Creating Loop...\n");
	CreateLoop(head);
	//PrintList(head);
	if(DetectLoop(head))
		printf("Loop Detected\n");
	else
		printf("No Loop Detected\n");	
	return 0;
}
