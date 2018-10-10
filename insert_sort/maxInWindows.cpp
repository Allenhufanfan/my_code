#include<stdio.h>  
#include<algorithm>  
#include<vector>  
#include<deque>
#include<iostream>  
using namespace std; 

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxInWindows;
    // 数组大小要大于等于窗口大小，并且窗口大小大于等于1
    if(num.size() >= size && size >= 1)
    {
        deque<int> index;
        for(unsigned int i = 0; i < size; i++)
        {
            // 如果index非空，并且新添加的数字大于等于队列中最小的数字，则删除队列中最小的数字
            while(!index.empty() && num[i] >= num[index.back()])
            {
                index.pop_back();
            }
            index.push_back(i);
        }
        for(unsigned int i = size; i < num.size(); i++)
        {
            maxInWindows.push_back(num[index.front()]);
            while(!index.empty() && num[i] >= num[index.back()])
            {
                index.pop_back();
            }
            // 控制窗口大小为size
            if(!index.empty() && index.front() <= int(i - size))
            {
                index.pop_front();
            }
            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }
    return maxInWindows;
}

int main(int argc, char const *argv[])
{
    vector<int> vec;  
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(1);
    
    vector<vector<int> >max_window;
    max_window.push_back(maxInWindows(vec,3));
    
    int row = 0; //行数
    int col=0;//获取列数
    for(row = 0; row < max_window.size() ; row++)
    {
        for(col = 0; col < max_window[row].size(); col++)
        {
            cout << max_window[row][col] << " ";
        } 
        cout << endl;   
    }
    
    system("pause");
    return 0;
}
