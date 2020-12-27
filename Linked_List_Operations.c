#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

	struct node * first=NULL;
	struct node * last=NULL;
	struct node * ptr;
	
int main(int argc, char *argv[]) {
	
	//to input choice

	int choice;
	printf("1.create\n2.list\n3.insert at start\n4.insert at end\n5.insert at between\n6.delete from start\n7.delete from end\n8.delete from index\n9.exit\n\n");
	
	while(1){
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				createNode();
				break;
			case 2:
				list();
				break;
			case 3:
				first=insert(first);
				break;
			case 4:
				first=insertAtEnd(first);
				break;
			case 5:
				first=insertAtBetween(first);
				break;
			case 6:
				first=deleteFromStart(first);
				break;
			case 7:
				first=deleteFromEnd(first);
				break;
			case 8:
				first=deleteFromBetween(first);
				break;
			case 9:
				exit(0);
				break;
			
		}
		printf("1.create\n2.list\n3.insert at start\n4.insert at end\n5.insert at between\n6.delete from start\n7.delete from end\n8.delete from index\n9.exit\n\n");

	}
	
	return 0;
}

//create a node 

int createNode(){
	
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to insert :\n");
	scanf("%d",&ptr->data);
		
	ptr->next=NULL;
	
	if(first==NULL){
		first=ptr;	
	}
			
	else{
		last->next=ptr;
	}

	last=ptr;
	return 0;
}
//see the Linked List 

int list(){
	struct node * p=first;
	if(first==NULL){
		printf("Linked List is empty\n");
	}
	else{
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}		
	}
	return 0;
}

//insert node to starting of Linked List

int insert(struct node * first){
	
	struct node * pntr=(struct node *)malloc(sizeof(struct node));
	
	int indata;
	printf("enter data to insert\n");
	scanf("%d",&indata);
	
	pntr->data=indata;
	pntr->next=first;
	
	return pntr;
}
//insert node to end of Linked List

int insertAtEnd(struct node *first){
	struct node * pntr=(struct node *)malloc(sizeof(struct node));
	struct node * p=first;
	int indata;
	
	printf("enter data to insert\n");
	scanf("%d",&indata);
	
	pntr->data=indata;

	while(p->next!=NULL){
		p=p->next;
	}
	p->next=pntr;
	pntr->next=NULL;

	return first;
}

// insert node at between of Linked List

int insertAtBetween(struct node * first){
	struct node * pntr=first;
	struct node * p = first;
	int pos,indata;

	printf("enter the position\n");
	scanf("%d",&pos);

	printf("enter the data :\n");
	scanf("%d",&indata);
	
	for(int i=0; i<pos-1; i++){
		p=p->next;
		pntr=pntr->next;
	}
	pntr->data=indata;
	pntr->next=p->next;
	return first;
}

//delete node from starting of Linked List

int deleteFromStart(struct node * first){
	struct node * pntr=first;
	first=first->next;
	printf("%d is deleting from Linked List \n",pntr->data);
	free(pntr);

	return first;
}
// delte node from ending of Linked List

int deleteFromEnd(struct node * first){
	
	struct node * p=first;
	struct node * q=first->next;
	
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	printf("%d is deleting from Linked List\n",q->data);
	p->next=NULL;
	free(q);
	return first;
}
// delete node from between of Linked List

int deleteFromBetween(struct node * first){
	int pos;

	struct node * p=first;
	struct node * q=first->next;
	printf("enter the position\n");
	scanf("%d",&pos);

	for(int i=0; i<pos-1; i++ ){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	q->next=NULL;
	free(q);
	return first;
}