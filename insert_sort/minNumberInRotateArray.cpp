#include <stdio.h>
#include <iostream>
#include <vector>  
using namespace std;


//��ת�������ҵ���С��Ԫ��
//���ö��ַ����ң���������СԪ��
/*
����ȡ�������ҡ��м��Ԫ�ؽ��бȽ�
�����Ԫ�� > �м�Ԫ�� ����
*/

//���鳤��Ϊ0ʱ��ֱ�ӷ���Ϊ0
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
        if (left == right - 1) {   //������������Ԫ�����ڣ���ȡ����Ԫ��
            mid = right;
            break;
        }
        mid = left + (right - left)/2;
        if (rotateArray[left] <= rotateArray[mid]) {  //����м�Ԫ��С�ڵ����м�Ԫ�أ���left = mid 
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
    cout << "����������Ԫ�صĸ���:";
    cin >> n;
    cout << "����������ÿһ����" << endl;
    for(int i = 1; i <= n ; i++)
    {
        int j;
        cin >> j;
        vec.push_back(j);
    }
    cout <<"��ת��������СԪ��Ϊ:"<< minNumberInRotateArray(vec) << endl;
    system("pause");
    return 0;
}