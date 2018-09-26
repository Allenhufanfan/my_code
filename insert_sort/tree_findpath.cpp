#include <stdio.h>  
#include <iostream>
#include <vector>
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
        cout << p->value << endl;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
};

class Solution {
public:
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
            testTree = pnode;                  //则新节点为根
        }
        else                            
        {
            if (key  > pparent->value)   
            {
                pparent->rchild = pnode;//否则新节点为其父节点的左孩
            }
            else
                pparent->lchild = pnode; //或右孩
        }
    }
    //前序遍历显示二叉树
    preOrder(testTree);
    
    Solution sSo;
    sSo.FindPath(testTree,22);
    system("pause");
    return 0;
}