#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) 
{
    //��ȡ����������
    int n = array.size();
    //��ȡ����������
    int m = array[0].size();

    /* ˼·
     * ����������ģ������½��������������ֵݼ����������ֵ�����
     * ��˴����½ǿ�ʼ���ң���Ҫ�������ֱ����½����ִ�ʱ������
     * Ҫ�������ֱ����½�����Сʱ������{}
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
    cout << "����������Ϊ:"<< vec[0].size()<<endl;
    cout << "����������Ϊ:"<< vec.size()<<endl;;
    if(Find(7,vec))
      cout << "7";
    getchar();
    return 0;
}

