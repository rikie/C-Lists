/****************************************************************
**************** Author: Arijit Upadhyaya ***********************
***  	       	Merge two lists into a single list           ****
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

void MergeList(list *list1, list *list2) {
	

}

int main() {
	list *head=(list *)malloc(sizeof(list));
	head=NULL;
	int n,i;	
	printf("How many elements\n");
	scanf("%d",&n);
	printf("Inserting the elements in the list.\n");
	for(i=1; i<=n; i++) {
		if(!(InsertBegin(&head, i)))
			printf("Insertion Failed\n");
	}
	printf("Printing List...\n");
	PrintList(head);
	return 0;
}
