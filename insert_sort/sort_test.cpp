#include <stdio.h>  
#include <iostream>
using namespace std;

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//插入排序
void insert_sort(int A[],int n)
{
    for (int i = 1 ; i < n; i++)
    {
        int get_value = A[i]; //获取当前的数值
        int j = i -1;  //数值左边的列
        while(j>=0 && A[j] > get_value)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = get_value;
    }
}

//冒泡排序
void BuddleSort(int A[],int n)
{
    for (int i = 0; i< n - 1 ; i++)
    {
        for (int j = 0;j< n - 1 - i; j++)
        {
            if (A[j + 1] > A[j])
            {
                A[j] = A[j] + A[j + 1];
                A[j + 1] = A[j] - A[j + 1];
                A[j] = A[j] - A[j + 1];
            }
        }
    }
}

//快速排序
void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // 递归调用  
        quickSort(s, i + 1, r);  
    }  
}  

//选择排序
void selection_sort(int A[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[min] > A[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            Swap(A,min,i);
        }
    }
}

int main()
{
    int A[] = {6,8,7,9,4,5,2,3,1};
    int n = sizeof(A)/sizeof(int);
    //insert_sort(A,n);
    //BuddleSort(A,n);
    //selection_sort(A,n);
    quickSort(A,0,n-1);
    for (int i = 0 ; i<= n -1; i++)
    {
        cout<< A[i];
    }
    getchar();
    return 0;
}