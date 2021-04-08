#include"LinkStack.c"

int main() {
	LinkStack *head;int flag=1,n,situ;
	head=(LinkStack*)malloc(sizeof(LinkStack));
	head->top=NULL;
	head->count=0;
	while(flag){
		system("cls");
		printf("1.initialize\n2.isEmpty\n3.getTop\n4.clear\n5.destroy\n6.Length\n7.push\n8.pop\n9.traverse\n10.exit\n");
		printf("========================\n");
		printf("输入编号：");
		scanf("%d",&n);
		printf("=========================\n");
		switch(n){
			case 1:{//initialize
				situ=initLStack(head);
				if(situ==0)	printf("ERROR\n");
				else printf("SUCCESS\n");
				break;
			}
			case 2:{//isEmpty
				situ=isEmptyLStack(head);
				if(situ==0)	printf("ERROR\n");
				break;
			}
			case 3:{//getTop
				int *e;
				e=(int*)malloc(sizeof(int));
				situ=getTopLStack(head,e);
				if(situ==0)	printf("ERROR\n");
				break;
			}
			case 4:{//clear
				situ=clearLStack(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				break;
			}
			case 5:{//destroy
				situ=destroyLStack(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				break;
			}
			case 6:{//length
				int *len;
				len=(int*)malloc(sizeof(int));
				situ=LStackLength(head,len);
				if(situ==0)	printf("ERROR\n");
				break;
			}
			case 7:{//push
				int data;
				if(head==NULL||head->top==NULL){
					printf("ERROR\n");
					break;
				}
				printf("输入添加数据：");
				scanf("%d",&data);
				situ=pushLStack(head,data);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				break;
			}
			case 8:{//pop
				int *data;
				data=(int*)malloc(sizeof(int));
				situ=popLStack(head,data);
				if(situ==0)	printf("ERROR\n");
				break;
			}
			case 9:{//traverse
				situ=Traverse(head);
				if(situ==0)	printf("ERROR\n");
				break;
			}
			case 10:{
				flag=0;
				break;
			}
			default:{
				printf("编号输入错误\n");
				break;
			}
		}
		system("pause");
	}
}
