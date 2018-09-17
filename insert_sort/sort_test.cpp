#include <stdio.h>  
#include <iostream>
using namespace std;

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//��������
void insert_sort(int A[],int n)
{
    for (int i = 1 ; i < n; i++)
    {
        int get_value = A[i]; //��ȡ��ǰ����ֵ
        int j = i -1;  //��ֵ��ߵ���
        while(j>=0 && A[j] > get_value)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = get_value;
    }
}

//ð������
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

//��������
void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // ���������ҵ�һ��С��x����  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // �ݹ����  
        quickSort(s, i + 1, r);  
    }  
}  

//ѡ������
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