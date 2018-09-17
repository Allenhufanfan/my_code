#include <stdio.h>  
#include <iostream>
#include <stdlib.h>
using namespace std;

/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
void replaceSpace(char *str,int length) 
{
    for(int i = 0; i < length; i ++)
    {
        //当前字符为空格时
        cout << *(str + i) << endl;
        if(*(str+i) == ' ')
        {
            //1.0扩充str的大小
            length = length + 2;
            //2.0将空格后面的字符串整体向后移动
            int j = length -1;
            while(j-2 > i)
            {
                *(str+j) = *(str+j-2);
                j--;
            }
            //3.0对应的地方替换成空格
            *(str + i) = '%';
            *(str + i + 1) = '2';
            *(str + i + 2) = '0';
        }
    }
}

int main()
{
   	//char *str1[10] = (char*)malloc(10);
	//scanf("%s" ,str1);	   //"asdfabc11abcd"
    char str1[20] = "he xiao mi";
    replaceSpace(str1,20);
    cout << str1 << endl;
    system("pause");
    getchar();
    return 0;
}