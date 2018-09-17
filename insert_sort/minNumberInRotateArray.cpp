#include <stdio.h>
#include <iostream>
#include <vector>  
using namespace std;


//旋转数组中找到最小的元素
//采用二分法查找，数组中最小元素
/*
依次取最左、最右、中间的元素进行比较
当左边元素 > 中间元素 ，则
*/

//数组长度为0时，直接返回为0
int minNumberInRotateArray(vector<int> rotateArray)
{
    int size = rotateArray.size();
    if (size == 0)
      return 0;
    int left = 0;
    int right = size - 1;
    int mid = 0;
    while(rotateArray[left] >= rotateArray[right])
    {  
        if (left == right - 1) {   //如果最左和最右元素相邻，则取最右元素
            mid = right;
            break;
        }
        mid = left + (right - left)/2;
        if (rotateArray[left] <= rotateArray[mid]) {  //如果中间元素小于等于中间元素，则left = mid 
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return rotateArray[mid]; 
}

int main()
{
    vector<int> vec;
    int n = 0;
    cout << "请输入向量元素的个数:";
    cin >> n;
    cout << "请依次输入每一项数" << endl;
    for(int i = 1; i <= n ; i++)
    {
        int j;
        cin >> j;
        vec.push_back(j);
    }
    cout <<"旋转向量的最小元素为:"<< minNumberInRotateArray(vec) << endl;
    system("pause");
    return 0;
}