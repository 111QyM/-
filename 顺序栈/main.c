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
		printf("1.��ʼ��\n2.�жϿ�ջ\n3.��ȡջ��Ԫ��\n4.���\n5.����\n6.ȷ��ջ����\n7.ѹջ\n8.��ջ\n9.����\n10.�˳�\n");
		printf("===========================\n");
		printf("�����ţ�");
		scanf("%d",&n);
		printf("===========================\n");
		switch(n){
			case 1:{//Initialize
				int sizes;
				printf("����ջ�ĳ��ȣ�");
				scanf("%d",&sizes);
				situ=initStack(head,sizes);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 2:{//isEmpty
				situ=isEmptyStack(head);
				if(situ==0)	printf("��ջ\n");
				else	printf("�ǿ�ջ\n");
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
				printf("����洢�����ݣ�");
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
					printf("ջ�����ڻ��ջ\n");
					system("pause");
					break;
				}
				t=head->top;
				for(i=0;i<=head->top;i++){
					printf("%d<-",head->elem[t]);
					t--;
				}
				printf("ջ��\n");
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
