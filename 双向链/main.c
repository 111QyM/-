#include<stdio.h>
#include<stdlib.h> 
#include"T.c"

int main(){
	int m,n,t,i,situ,flag;Link *p;static Link *head;
	flag=1;
	while(flag!=0){
		system("cls");
		printf("1create\n2initialize\n3destroy\n4insert\n5delete\n6traverse\n7search\n8reverse\n9reverse even\n10mid node\n11exit\n");
		printf("==========================\nѡ���Ӧ��Ž��빦�ܣ�");
		scanf("%d",&m);
		printf("==========================\n");
		switch(m){
			case 1:{
				printf("���������ȣ�");
				scanf("%d",&n);
				if(head!=NULL)	free(head);
				head=Create(n);
				printf("SUCCESS\n");
				system("pause");
				break;
			}//========================
			case 2:{
				InitLink(head);
				system("pause");
				break;
			}//============================
			case 3:{
				head=DesLink(head);
				printf("SUCCESS\n");
				system("pause");
				break;
			}//=========================
			case 4:{
				printf("����������___֮��");
				scanf("%d",&n);
				p=head;
				while(p!=NULL){
					if(p->num==n)	break;
					p=p->next;
					}
				if(p==NULL)	printf("ERROR\n"); 
				printf("�������ڵ�����ݣ�");
				scanf("%d",&t);
				situ=InsertNode(p,t);
				if(situ==1)	printf("SUCCESS\n");
				else	printf("ERROR\n");
				system("pause");
				break;
			}//=========================�����ظ���û���� 
			case 5:{
				printf("����Ҫɾ���Ľڵ�����ݣ�");
				scanf("%d",&t);
				situ=DelNode(head,t);
				if(situ==1)	printf("SUCCESS\n");
				else	printf("ERROR\n");
				system("pause");
				break;
			}//============================== 
			case 6:{
				TraverseLink(head,visit);
				system("pause");
				break;
			}//===============================des���������
			case 7:{
				printf("����������ݣ�");
				scanf("%d",&t);
				SearchNode(head,t);
				system("pause");
				break;
			}//===============================
			case 8:{
				head=ReverseLink(head);
				system("pause");
				break;
			}//===============================
			case 9:{
				ReverseEvenLink(head);
				system("pause");
				break;
			}//===============================ż������λ��ûд 
			case 10:{
				FindMidNode(head);
				system("pause");
				break;
			}//==============================
			case 11:{
				flag=0;
				break;
			}
			default:{
				printf("����������������\n");
				system("pause");
				break;
			}
		}
	}

}
