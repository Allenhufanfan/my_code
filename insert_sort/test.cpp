/*
�ַ�����ת
����: hello xiao mi
�����mi xiao hello
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct Node
{
    int value;
    Node *next;
};

class Test
{
    public:
        void f(const int& arg);
    private:
       int value;
};

void Test::f(const int& arg)
{
    //arg = 10;
    cout << "arg = " << arg << endl;
    value = 20;
    cout << "value = "<< value << endl;
}

//p1 -> p2 -> p3  ��ת p3 -> p2 -> p1
Node * reverseLinkedList(Node* head)
{
    Node *pre = NULL;
    Node *reverseNode = NULL;
    Node *pNode = head;

    while(pNode != NULL)
    {
        //nextΪ�գ���ʾ�Ѿ������Ե���β��ֱ�Ӹ�ֵ
        if (pNode->next==NULL) 
        {
            reverseNode = pNode;
        }
        Node* nxt = pNode->next;
        pNode->next = pre;
        pre = pNode;
        pNode = nxt;
    }
    return reverseNode;
}

int main()
{
    Node *head = NULL;
    Node *preNode = head;
    for(int i = 0; i < 6 ; i++)
    {
        Node *tt = (Node*)malloc(sizeof(Node));
        tt->value = i;
        tt->next = NULL;
        if(preNode == NULL)
        {
            head = tt;
            preNode = head;
        }
        else
        {
            preNode->next =tt;
            preNode = tt;
        }
    }

/*
    while(head != NULL)
    {
        printf("%d\t",head ->value);
        head = head ->next;
    }
*/
    
    head = reverseLinkedList(head);
    while(head != NULL)
    {
        printf("%d\t",head ->value);
        head = head ->next;
    }   

    /*
    char *str[] = {"welcome","to","Fortemedia","Najing"};
    char **p = str + 1;
    printf("%s\n",p[0]);
    printf("%s\n",p[1]);  
    str[0] = (*p++) + 2;
    str[1] = *(p +1);
    printf("%s\n",p[0]);
    printf("%s\n",p[1]);
    printf("------------\n");  
    str[2] = p[1] + 2;
    str[3] = p[0] + (str[2] - str[1]);
    printf("%s\n",p[0]);
    printf("%s\n",p[1]);  
    printf("------------\n");  
    printf("%s\n",str[0]);
    printf("%s\n",str[1]);
    printf("%s\n",str[2]);
    printf("%s\n",str[3]); 
    */
    /*
    string words;
    while(getline(cin, words))
    {
        //1.0 ֱ�ӽ��ַ�����ת
        reverse(words.begin(), words.end());
        
        //2.0 ����ȡ��Ӧ�ո�֮ǰ���ַ������з�ת
        unsigned int i = 0;
        unsigned int j = 0;
        while(i < words.size())
        {
            while(i < words.size() && words[i] != ' ')
                i++;
            reverse(words.begin() + j, words.begin() + i);
            j = ++i;
        }
        cout << words << endl;
    }
    */

   string strnum = "1sdf2";
   int num1=atoi(strnum.c_str());
   cout<<"atoi�Ľ��Ϊ:"<<num1<<endl;

    getchar();
    return 0;
}