#include"sort.c"

int main() {
	int n,i,flag=1,size;
	FILE *fp;
	while(flag!=0){
		system("cls");
		printf("(�������ȡֵ��Χ100����)\n1.��ͬ����������������ʱ\n2.����100С����ѭ��100k����ʱ\n3.insertSort\n4.MergeSort\n5.QuickSort\n6.CountSort\n7.RadixCountSort\n8.ColorSort\n9.findNoK\n10.�˳�\n");
		printf("==========================\n");
		printf("ѡ���ţ�");
		scanf("%d",&n);
		printf("==========================\n");
		switch(n){
			case 1:{
				printf("����������(10000/50000/200000):");
				scanf("%d",&size);
				printf("==========================\n");
				testAmount(size);
				system("pause");
				break;
			}
			case 2:{
				testTimes();
				system("pause"); 
				break;
			}
			case 3:{
				printf("�������鳤�ȣ�");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("ԭ���飺\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				insertSort(data,size);
				printf("\n�����\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 4:{
				printf("�������鳤�ȣ�");
				scanf("%d",&size);
				int data[size],temp[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("ԭ���飺\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				MergeSort(data,0,size-1,temp);
				printf("\n�����\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 5:{
				printf("�������鳤�ȣ�");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("ԭ���飺\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				QuickSort_Recursion(data,0,size-1);
				printf("\n�����\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 6:{
				printf("�������鳤�ȣ�");
				scanf("%d",&size);
				int data[size],max;
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("ԭ���飺\n");
				for(i=0;i<size;i++){
					printf("%d ",data[i]);
					if(max<data[i])		max=data[i];
				}
				CountSort(data,size,max);
				printf("\n�����\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 7:{
				printf("�������鳤�ȣ�");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("ԭ���飺\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				RadixCountSort(data,size);
				printf("\n�����\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 8:{
				printf("�������鳤��(����Ϊ0/1/2)��");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
					data[i]=data[i]%3;
				}
				printf("==========================\n");
				printf("ԭ���飺\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				ColorSort(data,size);
				printf("\n�����\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 9:{
				printf("�������鳤�ȣ�");
				scanf("%d",&size);
				int data[size],k,p;
				printf("����k=");
				scanf("%d",&k); 
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("ԭ���飺\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				p=findNoK(data,size,k);
				printf("\n�����\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n��kλ���ǣ�%d",p);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 10:{
				flag=0;
				break;
			}
			default:{
				printf("��Ŵ���\n");
				system("pause");
				break;
			}
		}
	}
}
