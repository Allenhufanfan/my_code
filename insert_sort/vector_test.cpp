#include<stdio.h>  
#include<algorithm>  
#include<vector>  
#include<iostream>  
using namespace std;  

typedef struct rect  
{  
    int id;  
    int length;  
    int width;   
}Rect;  

int main()  
{  
    vector<Rect> vec;  
    Rect rect;  
    rect.id = 1;  
    rect.length = 2;  
    rect.width = 3;  
    vec.push_back(rect); 
    cout << "rect.id:" << rect.id << endl;
    vector<Rect>::iterator it = vec.begin();  
    cout<<(*it).id<<' '<< (*it).length <<' '<<(*it).width<<endl;   
    cout<<it->id<<' '<<it->length<<' '<<it->width<<endl;   

    int out[3][2] = { 1, 2,   
                      3, 4,  
                      5, 6 };  
    vector <int*> v1; 
    v1.push_back(out[0]);  
    v1.push_back(out[1]);  
    v1.push_back(out[2]);

    cout << "v1�Ĵ�СΪ:"  << v1.size() << endl;
    //cout << "��һ�еĴ�СΪ:" << v1[0].size() <<endl;
    int i = 0;
    for (vector <int*>::iterator it1 = v1.begin(); it1 != v1.end(); it1++, i++ )
    {
        //��ӡ��һ������
        cout << *(*it1) << endl;       
        //��ӡ�ڶ�������
        cout << *(*it1 + 1) << endl;
    }
    /*���δ�ӡ��������
    cout << v1[0][0] << endl;//1  
    cout << v1[0][1] << endl;//2  
    cout << v1[1][0] << endl;//3  
    cout << v1[1][1] << endl;//4  
    cout << v1[2][0] << endl;//5  
    cout << v1[2][1] << endl;//6  
    */
    system("pause");
    return 0;  

}  