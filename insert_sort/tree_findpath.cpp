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

//二叉树前序遍历
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
      输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
      路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    */
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber){
        if(root == NULL){
            return result;
        }
        
        tmp.push_back(root->value);
        if((expectNumber - root->value ) == 0 && root->lchild == NULL && root->rchild == NULL){
            result.push_back(tmp);
        }
        
        //遍历左子树
        FindPath(root->lchild, expectNumber - root->value);
        //遍历右子树
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
      把二叉树打印成多行
      从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
            // 偶数行
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
            // 奇数行
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
        //打印显示路径
        int row = 0; //行数
        int col=0;//获取列数
        
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
      获取树的深度
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

    //初始化插入二叉树
    for(int i = 0; i < 8; i++)
    {
        int key = sTemp[i];
        TreeNode* pparent = nullptr;
        TreeNode* pnode = testTree;
 
        while (pnode != nullptr)        //寻找合适的插入位置
        {
            pparent = pnode;
            if (key > pnode->value)
                pnode = pnode->rchild;
            else if (key < pnode->value)
                pnode = pnode->lchild;
            else
                break;
        }
 
        pnode = new TreeNode(key); //以元素的值构建新节点

        if (pparent == nullptr)            //如果是空树
        {
            testTree = pnode;              //则新节点为根
        }
        else                            
        {
            if (key  > pparent->value)   
            {
                pparent->rchild = pnode;//否则新节点为其父节点的左子树
            }
            else
                pparent->lchild = pnode; //或右子树
        }
    }

    //前序遍历显示二叉树
    cout << "前序遍历:";
    preOrder(testTree);
    cout << endl;
    
    Solution sSo;
    //sSo.FindPath(testTree,22);   //获取二叉树路径
    //sSo.PrintTreebyOrder(testTree);//按层从左往右打印出二叉树
    sSo.PrintTreebyZhi(testTree);//奇数层从左往右打印，偶数层从右往左打印出二叉树
    sSo.printResult();
    cout << "节点的度为:" << sSo.TreeDepth(testTree);
    system("pause");
    return 0;
}