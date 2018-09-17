#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) 
{
    //获取向量的行数
    int n = array.size();
    //获取向量的列数
    int m = array[0].size();

    /* 思路
     * 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
     * 因此从左下角开始查找，当要查找数字比左下角数字大时。右移
     * 要查找数字比左下角数字小时，上移{}
    */
   int i = n -1,j = 0;
    while(i >=0 && j < m )
    {
        if(array[i][j] < target)
        {
            ++j;
        }
        else if (array[i][j] < target)
        {
            --i;
        }
        else
          return true;
    }
    return false;
}

int main()
{
    vector<vector<int> > vec(4);
    vec[0] = {1,3,5,7};
    vec[1] = {2,8,10,14};  
    vec[2] = {4,9,12,15}; 
    vec[3] = {6,11,13,16}; 
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    cout << "向量的行数为:"<< vec[0].size()<<endl;
    cout << "向量的列数为:"<< vec.size()<<endl;;
    if(Find(7,vec))
      cout << "7";
    getchar();
    return 0;
}

