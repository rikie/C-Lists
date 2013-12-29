/****************************************************************
**************** Author: Arijit Upadhyaya ***********************
***  	       	Move the last element to the front           ****
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

void MoveToFront(list **head) {
	list *current=*head;
	list *secondLast;
	while(current->next->next != NULL){
		current=current->next;
	}
	secondLast=current;
	printf("Second Last element is %d\n",current->data);
	current=current->next;
	printf("Last element is %d\n", current->data);
	current->next=*head;
	*head=current;
	secondLast->next=NULL;
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
	printf("Calling MoveToFront()\n");
	MoveToFront(&head);
	printf("Printing List...\n");
	PrintList(head);
	return 0;
}
