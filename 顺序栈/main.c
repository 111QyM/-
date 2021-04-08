#include<stdio.h>
#include<stdlib.h>
#include "SqStack.c"

int main(){
	int flag=1,situ,n;
	SqStack *head;
	head=(SqStack*)malloc(sizeof(SqStack));
	head->size=0;
	head->top=-1;
	head->elem=NULL;
	while(flag){
		system("cls");
		printf("1.初始化\n2.判断空栈\n3.获取栈顶元素\n4.清空\n5.销毁\n6.确认栈长度\n7.压栈\n8.出栈\n9.遍历\n10.退出\n");
		printf("===========================\n");
		printf("输入编号：");
		scanf("%d",&n);
		printf("===========================\n");
		switch(n){
			case 1:{//Initialize
				int sizes;
				printf("输入栈的长度：");
				scanf("%d",&sizes);
				situ=initStack(head,sizes);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 2:{//isEmpty
				situ=isEmptyStack(head);
				if(situ==0)	printf("空栈\n");
				else	printf("非空栈\n");
				system("pause");
				break;
			}
			case 3:{//getTop
				int *num;
				num=(ElemType*)malloc(sizeof(ElemType));
				situ=getTopStack(head,num);
				if(situ==0)	printf("ERROR\n");
				system("pause");
				break;
			}
			case 4:{//clear
				situ=clearStack(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 5:{//destroy
				situ=destroyStack(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 6:{//Length
				int *len;
				len=(ElemType*)malloc(sizeof(ElemType));
				situ=stackLength(head,len);
				if(situ==0)	printf("ERROR\n");
				system("pause");
				break;
			}
			case 7:{//push
				int data;
				if(head==NULL||head->size==0)	{
					printf("ERROR\n");
					system("pause");
					break;
				}
				printf("输入存储的数据：");
				scanf("%d",&data);
				situ=pushStack(head,data);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 8:{//pop
				int *data;
				data=(ElemType*)malloc(sizeof(ElemType));
				situ=popStack(head,data);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 9:{//Traverse
				int i,t;
				if(head==NULL||head->top==-1){
					printf("栈不存在或空栈\n");
					system("pause");
					break;
				}
				t=head->top;
				for(i=0;i<=head->top;i++){
					printf("%d<-",head->elem[t]);
					t--;
				}
				printf("栈底\n");
				system("pause");
				break;
			}
			case 10:{
				flag=0;
				break;
			}
		}
	}
	
}
