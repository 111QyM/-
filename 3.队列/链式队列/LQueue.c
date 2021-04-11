#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

void InitLQueue(LQueue *Q){
	if(Q==NULL){
		printf("ERROR\n");
		return;
	}
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->data=(char*)malloc(sizeof(char));
	if(p==NULL||p->data==NULL){
		printf("ERROR\n");
		return;
	}
	p->next=NULL;
	Q->front=p;
	Q->rear=p;
	printf("SUCCESS\n");
}

void DestoryLQueue(LQueue *Q){
	if(Q==NULL||Q->front==NULL){
		printf("ERROR\n");
		return;
	}
	Node *p1,*p2;
	p1=Q->front;
	while(p1!=NULL){
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	Q->front=NULL;
	Q->rear=NULL; 
	Q->length=0;
	printf("SUCCESS\n");
}

Status IsEmptyLQueue(const LQueue *Q){
	if(Q==NULL||Q->front==NULL)	return FALSE;
	if(Q->length==0){
		printf("is Empty.\n");
		return TRUE;
	}
	else{
		printf("not Empty.\n");
		return TRUE;
	}
}

Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q==NULL||Q->front==NULL)	return FALSE;
	if(Q->length==0){
		printf("Empty Queue.\n");
		return FALSE;
	}
	e=Q->front->data;
	printf("head Element is %c\n",*(char*)e);
	return TRUE;
}

int LengthLQueue(LQueue *Q){
	if(Q==NULL||Q->front==NULL)	return -1;
	return Q->length;
}

Status EnLQueue(LQueue *Q, void *data){
	if(Q->length==0){
		Q->front->data=data;
	}
	else{
		Node *p;
		p=(Node*)malloc(sizeof(Node));
		if(!p)	return FALSE;
		p->data=data;
		p->next=NULL;
		Q->rear->next=p;
		Q->rear=p;
	}
	Q->length+=1;
	return TRUE;
}

Status DeLQueue(LQueue *Q){
	if(Q==NULL||Q->front==NULL)	return FALSE;
	if(Q->length==0){
		printf("Empty Queue.\n");
		return FALSE;
	}
	if(Q->length==1){
		Q->length=0;
		Q->front->data=NULL;
	}
	else{
		Node *p1,*p2;
		p1=Q->front;
		p2=Q->front->next;
		while(p2->next!=NULL){
			p1=p1->next;
			p2=p2->next;
		}
		Q->rear=p1;
		p1->next=NULL;
		free(p2);
		Q->length-=1;
	}
	return TRUE;
}

void ClearLQueue(LQueue *Q){
	if(Q==NULL||Q->front==NULL){
		printf("ERROR\n");
		return;
	}
	if(Q->length==0){
		printf("Empty Queue.\n");
		return;
	}
	if(Q->length==1){
		Q->front->data=NULL;
	}
	else{
		Node *p1,*p2;
		p1=Q->front->next;
		while(p1!=NULL){
			p2=p1->next;
			free(p1);
			p1=p2;
		}
		Q->rear=Q->front;
		Q->front->data=NULL;
		Q->front->next=NULL;
	}
	Q->length=0;
	printf("SUCCESS\n");
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q==NULL||Q->front==NULL)	return FALSE;
	if(Q->length==0){
		printf("Empty Queue.\n");
		return FALSE;
	}
	Node *p;
	p=Q->front;
	while(p!=NULL){
		foo(p->data);
		p=p->next;
	}
	printf("end\n");
	return TRUE;
}

void LPrint(void *q){
	printf("%c->",*(char*)q);
}












