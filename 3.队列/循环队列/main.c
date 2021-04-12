#include"AQueue.c"

int main(){
	int situ,n,x,flag=1;
	AQueue *head;
	head=(AQueue*)malloc(sizeof(AQueue));
	head->front=0;
	head->rear=0;
	head->length=0;
	for(x=0;x<MAXQUEUE;x++){
		head->data[x]=NULL;
	}
	while(flag!=0){
		system("cls");
		printf("1.initialize\n2.destroy\n3.isFull\n4.isEmpty\n5.getHead\n6.length\n7.Enter\n8.Delete\n9.clear\n10.traverse\n11.exit\n");
		printf("=========================\n");
		printf("输入编号：");
		scanf("%d",&n);
		printf("=========================\n");
		switch(n){
			case 1:{//initialize
				InitAQueue(head);
				system("pause");
				break;
			}
			case 2:{//destroy
				DestoryAQueue(head);
				system("pause");
				break;
			}
			case 3:{//isFull
				situ=IsFullAQueue(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 4:{//isEmpty
				situ=IsEmptyAQueue(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 5:{//get head
				char *e;
				e=(char*)malloc(sizeof(char));
				situ=GetHeadAQueue(head,e);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 6:{//length
				int k;
				k=LengthAQueue(head);
				if(k<0){
					printf("ERROR\n");
					system("pause");
					break;
				}
				printf("队列长度：%d\n",k);
				system("pause");
				break;
			}
			case 7:{//push
				char *data;
				if(head==NULL||head->data[0]==NULL){
					printf("ERROR\n");
					system("pause");
					break;
				}
				data=(char*)malloc(sizeof(char));
				printf("存储的数据：");
				fflush(stdin);
				*data=getchar();
				situ=EnAQueue(head,data);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 8:{//pop
				situ=DeAQueue(head);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 9:{//clear
				ClearAQueue(head);
				system("pause");
				break;
			}
			case 10:{//traverse
				situ=TraverseAQueue(head,APrint);
				if(situ==0)	printf("ERROR\n");
				else	printf("SUCCESS\n");
				system("pause");
				break;
			}
			case 11:{
				flag=0;
				break;
			}
			default:{
				printf("输入有误，重新输入\n");
				system("pause");
				break;
			}
		}
	}
}
