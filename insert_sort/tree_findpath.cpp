#include <stdio.h>  
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int value;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
	TreeNode(int x) :
			value(x), lchild(NULL), rchild(NULL) {
	}
};

//������ǰ�����
void preOrder(TreeNode *p)
{
    if (p != nullptr)
    {
        cout << p->value << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
};

class Solution {
public:
    /*
      ����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
      ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
    */
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber){
        if(root == NULL){
            return result;
        }
        
        tmp.push_back(root->value);
        if((expectNumber - root->value ) == 0 && root->lchild == NULL && root->rchild == NULL){
            result.push_back(tmp);
        }
        
        //����������
        FindPath(root->lchild, expectNumber - root->value);
        //����������
        FindPath(root->rchild, expectNumber - root->value);

        
        for(auto it = tmp.begin(); it < tmp.end(); it++)
        {
            cout << *it<< " ";
        }
        cout << endl;
        tmp.pop_back();   
        return result;
    }

    /*
      �Ѷ�������ӡ�ɶ���
      ���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
    */
    vector<vector<int> > PrintTreebyOrder(TreeNode* pRoot) 
    {
        //vector<vector<int> > result;
        if(pRoot == NULL)
        {
            return result;
        }
        queue<TreeNode* > nodes[2];
        nodes[0].push(pRoot);
        while(!nodes[0].empty() || !nodes[1].empty())
        {
            vector<int> v[2];
            while(!nodes[0].empty())
            {
                v[0].push_back(nodes[0].front()->value);
                if(nodes[0].front()->lchild != NULL)
                {
                    nodes[1].push(nodes[0].front()->lchild);
                }
                if(nodes[0].front()->rchild != NULL)
                {
                    nodes[1].push(nodes[0].front()->rchild);
                }
                nodes[0].pop();
            }
            if(!v[0].empty())
            {
                result.push_back(v[0]);
            }
            while(!nodes[1].empty())
            {
                v[1].push_back(nodes[1].front()->value);
                if(nodes[1].front()->lchild != NULL)
                {
                    nodes[0].push(nodes[1].front()->lchild);
                }
                if(nodes[1].front()->rchild != NULL)
                {
                    nodes[0].push(nodes[1].front()->rchild);
                }
                nodes[1].pop();
            }
            if(!v[1].empty())
            {
                result.push_back(v[1]);
            }
        }
        return result;
    }

    vector<vector<int> > PrintTreebyZhi(TreeNode* pRoot) 
    {
        if(pRoot == NULL)
        {
            return result;
        }
        stack<TreeNode* > s[2];
        s[0].push(pRoot);
        while(!s[0].empty() || !s[1].empty())
        {
            vector<int> v[2];
            // ż����
            while(!s[0].empty())
            {
                v[0].push_back(s[0].top()->value);
                if(s[0].top()->lchild != NULL)
                {
                    s[1].push(s[0].top()->lchild);
                }
                if(s[0].top()->rchild != NULL)
                {
                    s[1].push(s[0].top()->rchild);
                }
                s[0].pop();
            }
            if(!v[0].empty())
            {
                result.push_back(v[0]);
            }
            // ������
            while(!s[1].empty())
            {
                v[1].push_back(s[1].top()->value);
                if(s[1].top()->rchild != NULL)
                {
                    s[0].push(s[1].top()->rchild);
                }
                if(s[1].top()->lchild != NULL)
                {
                    s[0].push(s[1].top()->lchild);
                }
                s[1].pop();
            }
            if(!v[1].empty())
            {
                result.push_back(v[1]);
            }
        }
        return result;
    }

    void printResult(){
        //��ӡ��ʾ·��
        int row = 0; //����
        int col=0;//��ȡ����
        
        for(row = 0; row < result.size() ; row++)
        {
            for(col = 0; col < result[row].size(); col++)
            {
                cout << result[row][col] << " ";
            } 
            cout << endl;   
        }
    }
    /*
      ��ȡ�������
    */
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL){
            return 0;
        }
        int left = TreeDepth(pRoot->lchild);
        int right = TreeDepth(pRoot->rchild);
        return (left > right) ? (left + 1) : (right + 1);
    }
private:
    vector<vector<int> > result;
    vector<int> tmp;
};

int main()
{
    int sTemp[8] = {10,5,4,3,6,15,16,8};
    TreeNode *testTree = nullptr;

    //��ʼ�����������
    for(int i = 0; i < 8; i++)
    {
        int key = sTemp[i];
        TreeNode* pparent = nullptr;
        TreeNode* pnode = testTree;
 
        while (pnode != nullptr)        //Ѱ�Һ��ʵĲ���λ��
        {
            pparent = pnode;
            if (key > pnode->value)
                pnode = pnode->rchild;
            else if (key < pnode->value)
                pnode = pnode->lchild;
            else
                break;
        }
 
        pnode = new TreeNode(key); //��Ԫ�ص�ֵ�����½ڵ�

        if (pparent == nullptr)            //����ǿ���
        {
            testTree = pnode;              //���½ڵ�Ϊ��
        }
        else                            
        {
            if (key  > pparent->value)   
            {
                pparent->rchild = pnode;//�����½ڵ�Ϊ�丸�ڵ��������
            }
            else
                pparent->lchild = pnode; //��������
        }
    }

    //ǰ�������ʾ������
    cout << "ǰ�����:";
    preOrder(testTree);
    cout << endl;
    
    Solution sSo;
    //sSo.FindPath(testTree,22);   //��ȡ������·��
    //sSo.PrintTreebyOrder(testTree);//����������Ҵ�ӡ��������
    sSo.PrintTreebyZhi(testTree);//������������Ҵ�ӡ��ż������������ӡ��������
    sSo.printResult();
    cout << "�ڵ�Ķ�Ϊ:" << sSo.TreeDepth(testTree);
    system("pause");
    return 0;
}