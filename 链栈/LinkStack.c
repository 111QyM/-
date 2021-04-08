#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

StackNode *first;

Status initLStack(LinkStack *s){
	if(s==NULL)	return ERROR;
	s->top=(StackNode*)malloc(sizeof(StackNode));
	if(!s->top)	return ERROR;
	s->count=0;
	first=s->top;
	s->top->data=0;
	s->top->next=NULL;
	return SUCCESS;
} 

Status isEmptyLStack(LinkStack *s){
	if(s==NULL||s->top==NULL)	return ERROR;
	if(s->count==0){
		printf("¿ÕÕ»\n");
		return SUCCESS;
	}
	printf("·Ç¿ÕÕ»\n");
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e){
	if(s==NULL||s->top==NULL)	return ERROR;
	if(s->count==0){
		printf("¿ÕÕ»\n");
		return ERROR;
	}
	*e=s->top->data;//
	printf("¶¥²¿ÔªËØ£º%d\n",*e);
	return SUCCESS;
}

Status clearLStack(LinkStack *s){
	StackNode *p,*t;
	if(s==NULL||s->top==NULL)	return ERROR;
	if(s->count==0){
		printf("¿ÕÕ»\n");
		return ERROR;
	}
	if(first->next==NULL){
		s->top->data=0;
		s->count=0;
		return SUCCESS;
	}
	p=first->next;
	s->count=0;
	while(p!=NULL){
		t=p;
		p=p->next;
		free(t);
	}
	s->top=first;
	s->top->data=0;
	s->top->next=NULL;
	return SUCCESS;
}

Status destroyLStack(LinkStack *s){
	if(s==NULL||s->top==NULL)	return ERROR;
	int p;
	if(s->count!=0){
		p=clearLStack(s);
		if(p==0)	return ERROR;
	}
	free(first);
	s->top=NULL;
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){
	if(s==NULL||s->top==NULL)	return ERROR;
	if(s->count==0){
		printf("¿ÕÕ»\n");
		return ERROR;
	}
	*length=s->count;
	printf("Á´Õ»³¤¶È£º%d\n",*length);
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data){
	if(s->count==0){
		s->top->data=data;
		s->count+=1;
		return SUCCESS;
	}
	StackNode *p;
	p=(StackNode*)malloc(sizeof(StackNode));
	if(p==NULL)	return ERROR;
	p->next=NULL;
	p->data=data;
	s->count+=1;
	s->top->next=p;
	s->top=p;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){
	if(s==NULL||s->top==NULL)	return ERROR;
	if(s->count==0){
		printf("¿ÕÕ»\n");
		return ERROR;
	}
	if(s->count==1){
		*data=first->data;
		s->count=0;
		first->data=0;
		printf("È¡³ö¶¥²ãÔªËØ£º%d\n",*data);
		return SUCCESS;
	}
	StackNode *p;
	p=first;
	while(p->next!=s->top){
		p=p->next;
	}
	*data=s->top->data;
	free(s->top);
	s->top=p;
	s->top->next=NULL;
	s->count-=1;
	printf("È¡³ö¶¥²ãÔªËØ£º%d\n",*data);
	return SUCCESS;
}

Status Traverse(LinkStack *s){
	if(s==NULL||s->top==NULL)	return ERROR;
	if(s->count==0){
		printf("¿ÕÕ»\n");
		return;
	}
	StackNode *p;
	p=first;
	while(p!=NULL){
		printf("%d->",p->data);
		p=p->next;
	} 
	printf("end");
}







