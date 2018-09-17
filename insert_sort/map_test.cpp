#include <iostream>
#include <string>  
#include <map>
using namespace std;

typedef struct tagStudentinfo  
{  
    int      niD;  
    string   strName; 

    //operator操作运算符  
    bool operator < (tagStudentinfo const& _A) const  
    {     
        //这个函数指定排序策略，按niD排序，如果niD相等的话，按strName排序  
        if(niD < _A.niD) return true;  
        if(niD == _A.niD)  
            return strName.compare(_A.strName) < 0;  
        return false;  
    }  

}Studentinfo, *PStudentinfo; //学生信息  


int main()  
{  
    int nSize;   //用学生信息映射分数  

    map<Studentinfo, int>mapStudent;  

    map<Studentinfo, int>::iterator iter;  

    Studentinfo studentinfo;  

    studentinfo.niD = 1;  

    studentinfo.strName = "student_one";  

    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));  

    studentinfo.niD = 2;  

    studentinfo.strName = "student_two";  

    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));  

    for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)  
        cout<<iter->first.niD<<' '<<iter->first.strName<<' '<<iter->second<<endl;  


    map<int,string>maptest;
    maptest.insert(pair<int,string>(1,"test1"));
    maptest.insert(pair<int,string>(2,"test2"));
    for (auto iter2 = maptest.begin(); iter2 != maptest.end(); iter2 ++)
    {
       cout<<iter2->first<<' '<<(*iter2).second<<endl;  
    }

    system("pause");  
    return 0;  
}  
