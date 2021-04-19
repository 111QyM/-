#include"sort.c"

int main() {
	int n,i,flag=1,size;
	FILE *fp;
	while(flag!=0){
		system("cls");
		printf("(随机数组取值范围100以内)\n1.不同大数据量下排序用时\n2.长度100小数组循环100k次用时\n3.insertSort\n4.MergeSort\n5.QuickSort\n6.CountSort\n7.RadixCountSort\n8.ColorSort\n9.findNoK\n10.退出\n");
		printf("==========================\n");
		printf("选择编号：");
		scanf("%d",&n);
		printf("==========================\n");
		switch(n){
			case 1:{
				printf("输入数据量(10000/50000/200000):");
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
				printf("输入数组长度：");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("原数组：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				insertSort(data,size);
				printf("\n排序后：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 4:{
				printf("输入数组长度：");
				scanf("%d",&size);
				int data[size],temp[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("原数组：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				MergeSort(data,0,size-1,temp);
				printf("\n排序后：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 5:{
				printf("输入数组长度：");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("原数组：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				QuickSort_Recursion(data,0,size-1);
				printf("\n排序后：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 6:{
				printf("输入数组长度：");
				scanf("%d",&size);
				int data[size],max;
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("原数组：\n");
				for(i=0;i<size;i++){
					printf("%d ",data[i]);
					if(max<data[i])		max=data[i];
				}
				CountSort(data,size,max);
				printf("\n排序后：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 7:{
				printf("输入数组长度：");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("原数组：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				RadixCountSort(data,size);
				printf("\n排序后：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 8:{
				printf("输入数组长度(数据为0/1/2)：");
				scanf("%d",&size);
				int data[size];
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
					data[i]=data[i]%3;
				}
				printf("==========================\n");
				printf("原数组：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				ColorSort(data,size);
				printf("\n排序后：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n");
				fclose(fp);
				system("pause");
				break;
			}
			case 9:{
				printf("输入数组长度：");
				scanf("%d",&size);
				int data[size],k,p;
				printf("输入k=");
				scanf("%d",&k); 
				createData(size);
				fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
				for(i=0;i<size;i++){
					fread(&data[i],sizeof(int),1,fp);
				}
				printf("==========================\n");
				printf("原数组：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				p=findNoK(data,size,k);
				printf("\n排序后：\n");
				for(i=0;i<size;i++)
					printf("%d ",data[i]);
				printf("\n第k位数是：%d",p);
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
				printf("编号错误\n");
				system("pause");
				break;
			}
		}
	}
}
