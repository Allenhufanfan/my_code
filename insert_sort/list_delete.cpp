/*ɾ���������ظ��Ľ��
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5��

˼·
ɾ���ظ���㣬ֻ��Ҫ��¼��ǰ���ǰ��������ʹ��Ĳ��ظ����pPre����ǰ���pCur��ָ��ǰ������Ľ��pNext������ָ�뼴�ɡ������ǰ�ڵ��������ļ��������ֵ��ͬ����ô��Щ��㶼Ҫ���޳���Ȼ�����pPre��pCur���������ͬ����ֱ�Ӹ���pPre��pCur��
��Ҫ���ǵ��ǣ������һ��������ظ�������Ǹ���ô�죿�������Ƿֱ���һ�¾ͺã������һ��������ظ���㣬��ô�Ͱ�ͷָ��pHeadҲ����һ�¡�
*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

//��ת����
ListNode* reverseList(ListNode* pHead)
{
    ListNode* pPre = NULL;
    ListNode* pRevserNode = NULL;
    while(pHead != NULL)
    {
        if(pHead ->next == NULL)
        {
            pRevserNode = pHead;   
        }
        ListNode* node = pHead ->next;
        pHead ->next = pPre;
        pPre = pHead;
        pHead = node;
    }
    return pRevserNode;
}

ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead == NULL)
    {
        return NULL;
    }
    // ָ��ǰ���ǰ������ʹ��Ĳ��ظ����
    ListNode* pPre = NULL;
    // ָ��ǰ����Ľ��
    ListNode* pCur = pHead;
    // ָ��ǰ������Ľ��
    ListNode* pNext = NULL;
    
    while(pCur != NULL)
    {
        // �����ǰ�������һ�������ͬ
        if(pCur->next != NULL && pCur->val == pCur->next->val)
        {
            pNext = pCur->next;
            // �ҵ����ظ������һ�����λ��
            while(pNext->next != NULL && pNext->next->val == pCur->val)
            {
                pNext = pNext->next;
            }
            // ���pCurָ�������е�һ��Ԫ�أ�pCur -> ... -> pNext ->... 
            // Ҫɾ��pCur��pNext, ��ָ�������һ��Ԫ�ص�ָ��pHeadָ��pNext->next��
            if(pCur == pHead)
            {
                pHead = pNext->next;
            }
            // ���pCur��ָ�������е�һ��Ԫ�أ�pPre -> pCur ->...->pNext ->... 
            // Ҫɾ��pCur��pNext����pPre->next = pNext->next
            else
            {
                pPre->next = pNext->next;
            }
            // ��ǰ�ƶ�
            pCur = pNext->next;
        }
        // �����ǰ�������һ����㲻��ͬ
        else
        {
            pPre = pCur;
            pCur = pCur->next;
        }
    }
    return pHead;
};

int main()
{
    ListNode *head = NULL;
    ListNode *preNode = head;
    int n = 0;
    cout << "����������ĳ���:";
    cin >> n;
    cout << "����������ÿһ����" << endl;
    for(int i = 1; i <= n ; i++)
    {
        int j;
        ListNode *tt = (ListNode*)malloc(sizeof(ListNode));
        cin >> j;
        tt -> val = j;
        tt->next = NULL;
        if(preNode == NULL)
        {
            head = tt;
            preNode = head;
        }
        else
        {
            preNode->next = tt;
            preNode = tt;
        }
    }

    ListNode *head1 = head;

    while(head != NULL)
    {
        printf("%d\t",head ->val);
        head = head ->next;
    }
    printf("\n");

    head = deleteDuplication(head1);
    //head = reverseList(head1);
    while(head != NULL)
    {
        printf("%d\t",head ->val);
        head = head ->next;
    }  
    system("pause");
    return 0;
}