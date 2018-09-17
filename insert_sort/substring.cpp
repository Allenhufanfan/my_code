
/*
	scanf("%s" ,str1);	   //"asdfabc11abcd"
	scanf("%s" ,str2);	   // "abcde"

	得到最大子串为abcd
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
	//比较直接一个为空，直接返回为空
	if(NULL == str1||NULL == str2)
	{
		return NULL;
	}
	//将长度较短的串作为子串
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
	//采用strstr比较：若str2是str1的子串，则返回str2在str1的首次出现的地址；如果str2不是str1的子串，则返回NULL。
	if(strstr(longstr ,shortstr) !=NULL)
	{
		return shortstr;
	}
	//申请一个shortstr-1长度的子串
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