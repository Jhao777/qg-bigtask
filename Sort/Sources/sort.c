#include"sort.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void insertSort(int *a,int n)
{
    /* 思路：将一组无序数据分为两个工作区间，其中把前半部分分为有序表，后半部分分为无序表
    中间存在“渐变区域”，即我想说的排序区间，交换排序和后移数据均在这里进行。*/
    int temp,i,j;
    for(i=1;i<n;i++){          //取出当前位置的值，去与前面已经排好序的比较
        temp=a[i];
        for(j=i;j>0&&a[j-1]>temp;j--){
            a[j]=a[j-1];       //比较完并后移一位
        }
        a[j]=temp;
    }
}

//拆分+递归
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin<end){
        int mid=begin+(end-begin)/2;
        MergeSort(a,begin,mid,temp);         //左边排序
        MergeSort(a,mid+1,end,temp);         //右边排序
        MergeArray(a,begin,mid,end,temp);    //将两个有序数列合并
    }
}

//实现归并
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int p=0;
    int left=begin;
    int right=mid+1;//从中间隔开两个部分
    while(left<=mid&&right<=end){
        if(a[left]<a[right])
            temp[p++]=a[left++];
        else
            temp[p++]=a[right++];
    }
    //下面这两个while加上去是因为，左部分或者右部分可能会遗漏一个最大的数
    while(left<=mid){
        temp[p++]=a[left++];
    }
    while(right<=end){
        temp[p++]=a[right++];
    }
    for(int i=0;i<p;i++){
        a[begin+i]=temp[i];
    }//temp这个地址传回a，temp的工作完成了
}

void QuickSort_Recursion(int *a, int begin, int end)
{
    //以递归的方式，实现对输入标签后一直排列的原理
    if(begin<end){
        int mid=Partition(a,begin,end);//标签
        QuickSort_Recursion(a,begin,mid-1);//以标签前半部分作为工作区间继续排序 
        QuickSort_Recursion(a,mid+1,end);//以标签后半部分作为工作区间继续排序 
    }
}

int Partition(int *a, int begin, int end)
{
    //思路：找到一个target作为标签，其他数与这个标签比较，根据标签值排大小，
    if(begin<end){
        int i=begin;
        int j=end;
        int target=a[i];
        while(i<j){
            while(i<j&&a[j]>=target)        //从右往左找到比target（标签）小的数
                j--;
            a[i]=a[j];
            while(i<j&&a[i]<=target)        //从左往右找到比target（标签）大的数
                i++;
            a[j]=a[i];
        }
        a[i]=target;
        return i;                            //返回标签
    }
    return 1;               //无意义，不想看到"warning"
}

void CountSort(int *a, int size , int max)
{
    int i,j;
    int *count_Arr=(int*)malloc(sizeof(int)*(max+1));      //收集数据，计算数据相同个数的临时数据
    int *sorted_Arr=(int*)malloc(sizeof(int)*size);        //要排序的数组
    for(i=0;i<max+1;i++){
        count_Arr[i]=0;       //初始化数组
    }
    for(i=0;i<size;i++){
        count_Arr[a[i]]++;    //收集相同数据的个数
    }
    for(i=1;i<max+1;i++){
        count_Arr[i]=count_Arr[i]+count_Arr[i-1];        //计算小于等于该值的元素个数，准备逆向排序，保证排序的稳定性
    }
    for(i=size-1;i>=0;i--){
        j=--count_Arr[a[i]];              //分配前需将表上对应的值减1（倒序进行）
        sorted_Arr[j]=a[i];
    }
    for(i=0;i<size;i++){
        a[i]=sorted_Arr[i];                 //赋值
    }
    free(count_Arr);
    free(sorted_Arr);
}

void RadixCountSort(int *a,int size)
{
    //一个神奇的算法，什么数学思想我也很难理解，只能画图来理解。
    int i;
    int temp[size];                  //创建临时数组
    int divisor=1;                   //divisor,即除数
    int max=a[0];
    for(i=1;i<size;i++){
        if(a[i]>max)                  //找出最大数
            max=a[i];
    }
    int bucket[10]={0};                    //创建十个(0~9)桶，
    while(max/divisor>0){                 //循环到除数比最大数高一位时，停止循环
        for(i=0;i<size;i++){
            bucket[(a[i]/divisor)%10]++;   //收集
        }
        for(i=1;i<10;i++){
            bucket[i]+=bucket[i-1];     //统计，为了开始下一步逆向排序
        }
        for(i=size-1;i>=0;i--){
            temp[--bucket[(a[i]/divisor)%10]]=a[i];         //逆向排序进行，保证稳定性
        }
        for(i=0;i<size;i++){
            a[i]=temp[i];                   //赋值
        }
        divisor*=10;                        //进一位
        for(int i=0;i<10;i++){
            bucket[i]=0;
        }                                   //刷新，进入下一循环的桶
    }
}

void ColorSort(int *a,int size)
{
    int begin=0;       //控制0的索引
    int end=size-1;    //控制2的索引
    int temp;
    for(int i=0;i<=end;i++){       //i索引进行遍历
        if(a[i]==0){
            temp=a[begin];
            a[begin]=a[i];
            a[i]=temp;
            begin++;
        }
        if(a[i]==2){
            temp=a[end];
            a[end]=a[i];
            a[i]=temp;
            end--;
            i--;            //如果交换过来有0的话，还必须在检查原来位置。不论怎样都需要重新原来位置的值，保证精确
        }
    }
}

int K(int *a,int size,int k)
{
    QuickSort_Recursion(a,0,size-1);            //快速排序法的递归版排序
    return a[k-1];
}