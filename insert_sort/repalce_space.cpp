#include <stdio.h>  
#include <iostream>
#include <stdlib.h>
using namespace std;

/*
��Ŀ����
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/
void replaceSpace(char *str,int length) 
{
    for(int i = 0; i < length; i ++)
    {
        //��ǰ�ַ�Ϊ�ո�ʱ
        cout << *(str + i) << endl;
        if(*(str+i) == ' ')
        {
            //1.0����str�Ĵ�С
            length = length + 2;
            //2.0���ո������ַ�����������ƶ�
            int j = length -1;
            while(j-2 > i)
            {
                *(str+j) = *(str+j-2);
                j--;
            }
            //3.0��Ӧ�ĵط��滻�ɿո�
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