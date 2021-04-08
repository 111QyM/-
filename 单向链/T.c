#include <stdio.h>
#include <stdlib.h>
#include "T.h"

Link* Create(int n){
	static Link *L;Link *p1,*p2; int i,t;
	if(L!=NULL)	DesLink(L);
	L=(Link*)malloc(sizeof(Link));
	L->next=NULL;
	p1=L;
	printf("输入每个节点的内容：");
	for(i=0;i<n;i++){
		p2=(Link*)malloc(sizeof(Link));
		p2->next=NULL;
		scanf("%d",&t);
		p2->num=t; 
		p1->next=p2;
		p1=p2;
	}
	return L;
}

//initialize an empty linked list with only the head node without value
void InitLink(Link *L){
	free(L);
	L=(Link*)malloc(sizeof(Link));
	L->next=NULL;
	printf("SUCCESS\n");
}

//destroy a linked list, free all the nodes
Link* DesLink(Link *L){
	Link *p1,*p2;
	p1=L;
	while(p1!=NULL){
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	L=NULL;
	return L;
}

//insert node q after node p
Status InsertNode(Link *p,int t){
	Link *p1,*q;
	if(p==NULL)	return ERROR;
	q=(Link*)malloc(sizeof(Link));
	q->num=t;
	q->next=p->next;
	p->next=q;
	return SUCCESS;
}

//delete the first 
Status DelNode(Link *L,int a){
	Link *p1,*p2;
	if(L==NULL)	return ERROR;
	p1=L->next;
	if(L->num==a){
		p2=L->next;
		free(L);
		L=p2;
		return SUCCESS;
	}
	p2=L;
	while(p1!=NULL){
		if(p1->num==a)	break;
		p2=p1;
		p1=p1->next;
	}
	if(p1==NULL)	return ERROR;
	p2->next=p1->next;
	return SUCCESS;
}

//traverse the linked list and call the funtion visit
void TraverseLink(Link *L,void (*visit)(int n)){
	Link *p1;
	if(L==NULL){
		printf("ERROR\n");
		return;
	}
	if(L->next==NULL){
		printf("空链表\n");
		return;
	}
	p1=L;
	p1=p1->next;
	while(p1!=NULL){
		visit(p1->num);
		p1=p1->next;
	}
	printf("end\n");
}
void visit(int n){
	printf("%d->",n);
}

//find the first node in the linked list according to e
void SearchNode(Link *L,int a){
	Link *p1;int i;
	if(L==NULL){
		printf("ERROR\n");
		return;
	}
	p1=L;
	i=0;
	while(p1!=NULL){
		if(p1->num==a){
			printf("在第%d个节点\n",i);
			return;
			}
		i++;
		p1=p1->next;
	}
	printf("找不到\n");
}

//reverse the linked list
Link* ReverseLink(Link *L){
	Link *p1,*q,*p3;
	if(L==NULL)		printf("ERROR\n");
	p1=L->next;
	p3=(Link*)malloc(sizeof(Link));
	p3->next=NULL;
	while(p1!=NULL){
		q=(Link*)malloc(sizeof(Link));
		q->next=p3->next;
		p3->next=q;
		q->num=p1->num;
		p1=p1->next;
	}
	printf("SUCCESS\n");
	return p3;
}

//reverse the nodes which value is an even number in the linked list
void ReverseEvenLink(Link *L){
	int tem;Link *p1,*p2;
	if(L==NULL){
		printf("ERROR\n");
		return;
	}
	p1=L->next;
	p2=L;
	while(p1!=NULL){
		if(p1->num%2==0){
			tem=p2->num;
			p2->num=p1->num;
			p1->num=tem;
		}
		p1=p1->next;
		p2=p2->next;
	}
	printf("SUCCESS\n");
}

//find the middle node in the linked list
void FindMidNode(Link *L){
	Link *p1,*p2;int mid;
	if(L==NULL){
		printf("ERROR\n");
		return;
	}
	p1=L;
	p2=L->next;
	while(p2!=NULL){
		p1=p1->next;
		mid++;
		p2=p2->next;
		if(p2!=NULL)	p2=p2->next;
	}
	printf("中间节点是第%d个\n",mid);
}

/*judge whether the linked list is looped
Status isLoopLink(Link *L){
	Link *sl,*fa;
	if(L==NULL)	return ERROR;
	sl=L;
	fa=L->next;
	while(fa){
		if(sl==fa)	return SUCCESS;
		sl=sl->next;
		fa=fa->next->next;
	}
	return ERROR;
}不确定能用*/

