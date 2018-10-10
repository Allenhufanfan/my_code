#include <stdio.h>  
#include <iostream>
using namespace std;

void PrintArray(int A[])
{  
    for(int i = 0; i < 9; i++)
    {
        cout << A[i] <<  "";
    }  
}

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

/*--------插入排序--------------
对于未排序数据(右手抓到的牌)，在已排序序列(左手已经排好序的手牌)中从后向前扫描，找到相应位置并插入。
插入排序在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序），因而在从后向前扫描过程中，
需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。

具体算法描述如下：
1.从第一个元素开始，该元素可以认为已经被排序
2.取出下一个元素，在已经排序的元素序列中从后向前扫描
3.如果该元素（已排序）大于新元素，将该元素移到下一位置
4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
5.将新元素插入到该位置后
重复步骤2~5
*/
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

/*--------快速排序--------------
快速排序是由东尼·霍尔所发展的一种排序算法。在平均状况下，排序n个元素要O(nlogn)次比较。
在最坏状况下则需要O(n^2)次比较，但这种状况并不常见。事实上，快速排序通常明显比其他O(nlogn)算法更快，
因为它的内部循环可以在大部分的架构上很有效率地被实现出来。
快速排序使用分治策略(Divide and Conquer)来把一个序列分为两个子序列。步骤为：
1.从序列中挑出一个元素，作为”基准”(pivot).
2.把所有比基准值小的元素放在基准前面，所有比基准值大的元素放在基准的后面（相同的数可以到任一边），这个称为分区(partition)操作。
3.对每个分区递归地进行步骤1~2，递归的结束条件是序列的大小是0或1，这时整体已经被排好序了。
*/
void QuickSort(int s[], int l, int r)  
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
        //PrintArray(s);
        QuickSort(s, l, i - 1); // 递归调用  
        QuickSort(s, i + 1, r);  
    }  
}  

/*--------选择排序--------------
选择排序也是一种简单直观的排序算法。
它的工作原理很容易理解：初始时在序列中找到最小（大）元素，放到序列的起始位置作为已排序序列；
然后，再从剩余未排序元素中继续寻找最小（大）元素，放到已排序序列的末尾。
以此类推，直到所有元素均排序完毕。
*/
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
    QuickSort(A,0,n-1);
    for (int i = 0 ; i<= n -1; i++)
    {
        cout<< A[i];
    }
    getchar();
    return 0;
}