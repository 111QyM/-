#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include"sort.h"

void insertSort(int *a,int n){//插入排序 
	int i,j,t,b;
	for(i=1;i<n;i++){
		t=a[i];
		for(j=i-1;j>=0;j--){
			b=j;
			while(a[b]>t){
				a[b+1]=a[b];
				a[b]=t;
			}
		}
	}
}

void MergeArray(int *a,int begin,int mid,int end,int *temp){//归并排序-合并数组 
	int i,fro,bac,k=0,j;
	fro=begin;
	bac=mid+1;
	while(fro<=mid&&bac<=end){
		if(a[fro]<a[bac]){
			temp[k]=a[fro];
			fro++;
		}
		else{
			temp[k]=a[bac];
			bac++;
		}
		k++;
	}
	if(fro==mid+1){
		while(bac<=end){
			temp[k]=a[bac];
			k++,bac++;
		}
	}
	if(bac==end+1){
		while(fro<=mid){
			temp[k]=a[fro];
			k++,fro++;
		}
	}
	for(i=begin,j=0;i<=end;i++,j++)		a[i]=temp[j];
}

void MergeSort(int *a,int begin,int end,int *temp){//归并排序 
	if(begin>=end)	return;
	int mid;
	mid=(begin+end)/2;
	MergeSort(a,begin,mid,temp);
	MergeSort(a,mid+1,end,temp);
	MergeArray(a,begin,mid,end,temp);
}

void QuickSort_Recursion(int *a, int begin, int end){//快排 递归
	if(begin>=end)	return;
	int key;
	key=Partition(a,begin,end);
	QuickSort_Recursion(a,begin,key-1);
	QuickSort_Recursion(a,key+1,end);
}
int Partition(int *a, int begin, int end){//快排-枢轴 
	int t,temp;
	t=a[begin];
	while(begin<end){
		while(begin<end&&a[end]>=t)	end--;
		a[begin]=a[end];
		while(begin<end&&a[begin]<t)	begin++;
		a[end]=a[begin];
	}
	a[begin]=t;
	return begin;
}

void QuickSort(int *a,int size);//选做 快排 非递归 

void CountSort(int *a, int size , int max){//计数排序 >=0 数据不太大？
	int *temp1,*temp2,i;
	temp1=(int*)malloc(sizeof(int)*(max+1));
	temp2=(int*)malloc(sizeof(int)*size);
	for(i=0;i<=max;i++)		temp1[i]=0;
	for(i=0;i<size;i++)		temp1[a[i]]++;
	for(i=1;i<=max;i++)		temp1[i]=temp1[i-1]+temp1[i];
	for(i=size-1;i>=0;i--){
		temp2[temp1[a[i]]-1]=a[i];
		temp1[a[i]]--;
	}
	for(i=0;i<size;i++)
		a[i]=temp2[i];
	free(temp1);
	free(temp2);
}

void RadixCountSort(int *a,int size){//基数计数排序
	int t[10][size],i,j,k,temp1[10],temp2[size],m=0,n=0,s=1;
	for(i=0;i<size;i++){
		temp2[i]=a[i];
		if(a[i]>m)	m=a[i];
	}
	while(m!=0){
		m=m/10;
		n++;
	}//最大值n位数
	for(i=0;i<n;i++){
		for(j=0;j<10;j++)		temp1[j]=0;
		k=0;
		for(m=0;m<10;m++){
			for(j=0;j<size;j++)
				t[m][j]=0;
		}//初始化 
		for(j=0;j<size;j++){
			t[temp2[j]/s%10][temp1[temp2[j]/s%10]]=temp2[j];
			temp1[temp2[j]/s%10]++;
		}
		for(m=0;m<10;m++){
			for(j=0;j<temp1[m];j++){
				temp2[k]=t[m][j];
				k++;
			}
		}
		s=s*10;
	}
	for(i=0;i<size;i++)
		a[i]=temp2[i];
}

void ColorSort(int *a,int size){//颜色排序 
	int p,p1,p2,tem;
	p=0,p1=0,p2=size-1;
	while(p<p2){
		if(a[p]==0){
			tem=a[p];
			a[p]=a[p1];
			a[p1]=tem;
			p1++;
			if(p<p1)	p++;
			continue;
		}
		if(a[p]==2){
			tem=a[p];
			a[p]=a[p2];
			a[p2]=tem;
			p2--;
			continue;
		}
		p++;
	}
}

int findNoK(int *a,int size,int k){//找第k大的数 
	insertSort(a,size);
	return a[k-1];	
}

void createData(int size){
	FILE *fp;
	time_t ti;
	int data[size],data2[size],i;
	fp=fopen("D:\\qg\\src\\dataTest.txt","wb+");
	time(&ti);
	srand(ti%101);
	for(i=0;i<size;i++){
		data[i]=(rand()%101);
		fwrite(&data[i],sizeof(int),1,fp);
	}
	rewind(fp);
	for(i=0;i<size;i++){
		fread(&data2[i],sizeof(int),1,fp);
	}
	fclose(fp);
}

void testAmount(int size){//50000基数死了 200000带不动的样子…… 
	FILE *fp;
	int data[size],data2[size],temp[size],max=0,i;
	clock_t start,end;
	long dif;
	createData(size);

	fp=fopen("D:\\qg\\src\\dataTest.txt","rb+");
	for(i=0;i<size;i++){
		fread(&data[i],sizeof(int),1,fp);
	}
	rewind(fp);
	for(i=0;i<size;i++){
		fread(&data2[i],sizeof(int),1,fp);
	}

	for(i=0;i<size;i++){
		data[i]=data2[i];
	}
	start=clock();
	insertSort(data,size);
	end=clock();
	dif=end-start;
	printf("插入排序：%dms\n",dif);
	
	for(i=0;i<size;i++){
		data[i]=data2[i];
	}
	start=clock();
	MergeSort(data,0,size-1,temp);
	end=clock();
	dif=end-start;
	printf("归并排序：%dms\n",dif);
	
	for(i=0;i<size;i++){
		data[i]=data2[i];
	}
	start=clock();
	QuickSort_Recursion(data,0,size-1);
	end=clock();
	dif=end-start;
	printf("快速排序：%dms\n",dif);
	
	for(i=0;i<size;i++){
		data[i]=data2[i];
	}
	for(i=0;i<size;i++){
		if(max<data[i])		max=data[i];
	}
	start=clock();
	CountSort(data,size,max);
	end=clock();
	dif=end-start;
	printf("计数排序：%dms\n",dif);//?
	
	for(i=0;i<size;i++){
		data[i]=data2[i];
	}
	start=clock();
	RadixCountSort(data,size);
	end=clock();
	dif=end-start;
	printf("基数排序：%dms\n",dif);

	fclose(fp);
}

void testTimes(){
	FILE *fp;
	int data[100],data2[100],temp[100],max=0,size=100,i,j;
	clock_t start,end;
	long dif;
	
	createData(100);
	
	fp=fopen("D:\\qg\\src\\dataTest.txt","rb");
	for(i=0;i<size;i++){
		fread(&data[i],sizeof(int),1,fp);
	}
	rewind(fp);
	for(i=0;i<size;i++){
		fread(&data2[i],sizeof(int),1,fp);
	}
	
	start=clock();
	for(j=0;j<100000;j++){
		for(i=0;i<size;i++){
			data[i]=data2[i];
		}
		insertSort(data,size);
	}
	end=clock();
	dif=end-start;
	printf("插入排序：%dms\n",dif);
	
	start=clock();
	for(j=0;j<100000;j++){ 
		for(i=0;i<size;i++){
			data[i]=data2[i];
		}
		MergeSort(data,0,size-1,temp);
	}
	end=clock();
	dif=end-start;
	printf("归并排序：%dms\n",dif);
	
	start=clock();
	for(j=0;j<100000;j++){
		for(i=0;i<size;i++){
			data[i]=data2[i];
		}
		QuickSort_Recursion(data,0,size-1);
	}
	end=clock();
	dif=end-start;
	printf("快速排序：%dms\n",dif);

	start=clock();
	for(j=0;j<100000;j++){
		for(i=0;i<size;i++){
			data[i]=data2[i];
		}
		for(i=0;i<size;i++){
			if(max<data[i])		max=data[i];
		}
		CountSort(data,size,max);
	}
	end=clock();
	dif=end-start;
	printf("计数排序：%dms\n",dif);
	
	start=clock();
	for(j=0;j<100000;j++){
		for(i=0;i<size;i++){
			data[i]=data2[i];
		}
		RadixCountSort(data,size);
	}
	end=clock();
	dif=end-start;
	printf("基数排序：%dms\n",dif);

	fclose(fp);
}





