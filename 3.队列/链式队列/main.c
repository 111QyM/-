#include"LQueue.c"

int main(){
	int situ,n,flag=1;LQueue *head;
	head=(LQueue*)malloc(sizeof(LQueue));
	head->front=NULL;
	head->rear=NULL;
	head->length=0;
	while(flag){
		system("cls");
		printf("1.initialize\n2.destroy\n3.is Empty\n4.get head\n5.length\n6.Enter\n7.Delete\n8.clear\n9.traverse\n10.exit\n");
		printf("========================\n");
		printf("输入编号：");
		scanf("%d",&n);
		printf("========================\n");
		switch(n){
			case 1:{//initialize
				InitLQueue(head);
				system("pause");
				break;
			}
			case 2:{//Destroy
				DestoryLQueue(head);
				system("pause");
				break;
			}
			case 3:{//isEmpty
				situ=IsEmptyLQueue(head);
				if(situ==0)	printf("ERROR\n");
				else 	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 4:{//get head
				char *e;
				e=(char*)malloc(sizeof(char));
				situ=GetHeadLQueue(head,e);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 5:{//length
				int k;
				k=LengthLQueue(head);
				if(k<0)	printf("ERROR\n");
				else	printf("队列长度：%d\n",k);
				system("pause");
				break;
			}
			case 6:{//Enter
				if(head==NULL||head->front==NULL){
					printf("ERROR\n");
					system("pause");
					break;
				}
				char *data;
				data=(char*)malloc(sizeof(char));
				printf("输入新增元素：");
				fflush(stdin);
				*data=getchar();
				situ=EnLQueue(head,data);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 7:{//Delete
				situ=DeLQueue(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 8:{//clear
				ClearLQueue(head);
				system("pause");
				break;
			}
			case 9:{
				situ=TraverseLQueue(head,LPrint);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 10:{
				flag=0;
				break;
			}
			default:{
				printf("输入错误，重新输入\n");
				system("pause");
				break;
			}
		}
	}
	
}
