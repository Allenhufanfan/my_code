
/*
	scanf("%s" ,str1);	   //"asdfabc11abcd"
	scanf("%s" ,str2);	   // "abcde"

	�õ�����Ӵ�Ϊabcd
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
using namespace std;
char *commonstring(char *str1, char *str2)
{
	char *shortstr;
	char *longstr;
	char *substr;
	int i,j;
	//�Ƚ�ֱ��һ��Ϊ�գ�ֱ�ӷ���Ϊ��
	if(NULL == str1||NULL == str2)
	{
		return NULL;
	}
	//�����Ƚ϶̵Ĵ���Ϊ�Ӵ�
	if(strlen(str1) <= strlen(str2))
	{
		longstr = str2;
	    shortstr = str1;
	}
	else
	{
		longstr = str1;
		shortstr = str2;
	}
	//����strstr�Ƚϣ���str2��str1���Ӵ����򷵻�str2��str1���״γ��ֵĵ�ַ�����str2����str1���Ӵ����򷵻�NULL��
	if(strstr(longstr ,shortstr) !=NULL)
	{
		return shortstr;
	}
	//����һ��shortstr-1���ȵ��Ӵ�
	substr = (char *)malloc(sizeof(char)*strlen(shortstr)-1);
	//(char *)malloc(sizeof(char)*strlen(shortstr)-1);
	for(i=strlen(shortstr)-1;i>0 ;i--)
	{
		for(j=0; j <= strlen(shortstr)-i; j++)
		{
			memcpy(substr ,&shortstr[j] , i);
		    substr[i] = '\0';
			if(strstr(longstr ,substr)!=NULL)
			return substr;
		}	
	}
	return NULL;
} 
int main()
{
	char *str1 = (char*)malloc(256);
	char *str2 = (char*)malloc(256);
	scanf("%s" ,str1);	   //"asdfabc11abcd"
	scanf("%s" ,str2);	   // "abcde"
	cout<<"the common string is:"<<commonstring(str1, str2)<<endl;
    getchar();
    return 0;	
}