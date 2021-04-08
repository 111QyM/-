#include<stdio.h>
#include<stdlib.h>
#include "SqStack.h"

Status initStack(SqStack *s,int sizes){
	s->size=sizes;
	s->top=-1;
	s->elem=(ElemType*)malloc(sizeof(ElemType));
	if(s->elem==NULL)	return ERROR;
	return SUCCESS;
}
 
Status isEmptyStack(SqStack *s){
	if(s==NULL||s->top==-1)	return ERROR;
	else	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e){
	if(s==NULL||s->top==-1)	return ERROR;
	*e=s->elem[s->top];
	printf("栈顶元素：%d\n",*e);
	return SUCCESS;
}

Status clearStack(SqStack *s){
	if(s==NULL||s->top==-1)	return ERROR;
	s->top=-1;
	return SUCCESS;
}

Status destroyStack(SqStack *s){
	if(s==NULL||s->size==0)	return ERROR;
	free(s->elem);
	s->elem=NULL;
	s->size=0;
	s->top=-1;
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length){
	if(s==NULL)	return ERROR;
	*length=s->top+1;
	printf("长度为：%d\n",*length);
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data){
	if(s->top==s->size-1){
		printf("满栈\n");
		return ERROR;
	} 
	s->top+=1;
	s->elem[s->top]=data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data){
	if(s==NULL||s->top==-1)	return ERROR;
	*data=s->elem[s->top];
	s->top-=1;
	printf("取出数据:%d\n",*data);
	return SUCCESS;
}




