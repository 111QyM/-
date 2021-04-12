#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"

void InitAQueue(AQueue *Q){
	if(Q==NULL){
		printf("ERROR\n");
		return;
	}
	int i;
	for(i=0; i<MAXQUEUE; i++){
		Q->data[i]=(char*)malloc(sizeof(char));
	}
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	printf("SUCCESS\n");
}

void DestoryAQueue(AQueue *Q){
	if(Q==NULL||Q->data[0]==NULL){
		printf("ERROR\n");
		return;
	}
	int i;
	for(i=0;i<MAXQUEUE;i++)
		Q->data[i]=NULL;
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	printf("SUCCESS\n");
}

Status IsFullAQueue(const AQueue *Q){
	if(Q==NULL||Q->data[0]==NULL)	return FALSE;
	if(Q->length==MAXQUEUE)	printf("is Full.\n");
	else	printf("not Full.\n");
	return TRUE;
}

Status IsEmptyAQueue(const AQueue *Q){
	if(Q==NULL||Q->data[0]==NULL)	return FALSE;
	if(Q->length==0)	printf("is Empty.\n");
	else	printf("not Empty.\n");
	return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void *e){
	if(Q==NULL||Q->data[0]==NULL)	return FALSE;
	if(Q->length==0){
		printf("Empty Queue\n");
		return FALSE;
	}
	e=Q->data[Q->front];
	printf("Head element is %c\n",*(char*)e);
	return TRUE;
}

int LengthAQueue(AQueue *Q){
	if(Q==NULL||Q->data[0]==NULL)	return -1;
	int k;
	k=Q->length;
	return k;
}

Status EnAQueue(AQueue *Q, void *data){
	if(Q->length==MAXQUEUE){
		printf("Full Queue.\n");
		return FALSE;
	}
	Q->data[Q->rear]=data;
	if(Q->rear==MAXQUEUE-1)	Q->rear=0;
	else	Q->rear+=1;
	Q->length+=1;
	return TRUE;
}

Status DeAQueue(AQueue *Q){
	if(Q==NULL||Q->data[0]==NULL)	return FALSE;
	if(Q->length==0){
		printf("Empty Queue.\n");
		return FALSE;
	}
	if((Q->front)==MAXQUEUE-1){
		Q->front=0;
	}
	else{
		Q->front+=1;
	}
	Q->length-=1;
	return TRUE;
}

void ClearAQueue(AQueue *Q){
	if(Q==NULL||Q->data[0]==NULL){
		printf("ERROR\n");
		return;
	}
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	printf("SUCCESS\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	if(Q==NULL||Q->data[0]==NULL)	return FALSE;
	if(Q->length==0){
		printf("Empty Queue.\n");
		return FALSE;
	}
	int i;
	if(Q->rear==0){
		for(i=Q->front;i<MAXQUEUE;i++)
			foo(Q->data[i]);
	}
	else if(Q->front<Q->rear){
		for(i=Q->front;i<Q->rear;i++)
			foo(Q->data[i]);
	}
	else if(Q->front>Q->rear){
		for(i=Q->front;i<MAXQUEUE;i++)
			foo(Q->data[i]);
		for(i=0;i<Q->rear;i++)
			foo(Q->data[i]);
	}
	printf("end\n");
	return TRUE;
}

void APrint(void *q){
	printf("%c->",*(char*)q);
}









