#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): data(x), left(NULL), right(NULL){}
};


/* 树的递归遍历 */

void pre(TreeNode* root){
    if(root==nullptr)
        return;
    cout<<root->data<<endl;

    pre(root->left);
    pre(root->right);
}

void In(TreeNode* root){
    if(root==nullptr)
        return;
    
    In(root->left);
    cout<<root->data<<endl;
    In(root->right);
}

void post(TreeNode* root){
    if(root == nullptr)
        return;
    
    post(root->left);
    post(root->right);
    cout<<root->data<<endl;
}


/* 栈 后序遍历 */
vector<int> post(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> s;
    // p正在访问的节点，q刚刚访问的节点
    TreeNode* p, q;
    p = root;
    do{
        // 首先从根节点开始不断压入左节点。
        while(p!=nullptr){
            s.push(p);
            p = p->left;
        }
        q = nullptr;
        while(!s.empty()){
            //只要栈不为空，记录当前访问的栈顶节点，并出战
            p = s.top();
            s.pop();

            // 判断出战的节点，如果右孩子不存在，或者已经访问
            if(p->right == q){
                result.push_back(p->data);
                q = p;
            }
            // 否则， 刚刚出战的还不能出战，重新压栈。当前访问的节点设为p
            else{
                s.push(p);
                p = p->right;
                break;
            }
        }
    }while(!s.empty());
    return result;
}


/* 栈 中序遍历 */

vector<int> In(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(s!empty() || p!=nullptr){
        if(p!=nullptr){
            s.push(p);
            p = p->left;
        }
        else{
            p = s.top();
            s.pop();
            result.push_back(p->data);
            p = p->right;
        }
    }
    return result;
}

/* 栈 前序遍历 */
vector<int> pre(TreeNode* root){
    vector<int> result;
    TreeNode* p;
    stack<TreeNode*> s;
    if(p!=nullptr){
        s.push(p);
    }

    while(s!=empty()){
        p = s.top();
        s.pop();
        result.push_back(p->data);
        if(p->right!=nullptr)
            s.push(p->right);
        if(p->left!=nullptr)
            s.push(p->left);
    }
    return result;
}

/*  二叉树层序遍历 */

// 层序遍历 广度优先，队列模拟
vector<vector<int>> levelO(TreeNode* root){
    vector<vector<int>> result;
    TreeNode* p = root;
    queue<TreeNode*> q;
    q.push(p);
    while(q!=empty()){
        vector<int> thislevel;
        for(int i=0;i<q.size();i++){
            TreeNode* tmp = q.front();
            q.pop();
            thislevel.push_back(tmp->data);
            if(tmp->left!=nullptr)
                q.push(tmp->left);
            if(tmp->right!=nullptr)
                q.push(tmp->right);
        }
        result.push_back(oneleve);
    }
    return result;
}


/* 判断两颗二叉树是否一样 */

bool isSame(TreeNode* p, TreeNode* q){
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    
    return (p->data == q->data) &&(isSame(p->left, q->left)) 
            &&(isSame(p->right, q->right));
}

/* 判断一颗二叉树是否对称 */

bool isSy(TreeNode* root){
    if(root==nullptr)
        return true;
    else{
        isSy(root->left, root->right);
    }
}

isSy(TreeNode* left, TreeNode* right){
    if(!left && !right)
        return true;
    if(!left || !right)
        return false;
    
    return (left->data == right->data) && (isSy(left->left, right->right))
            && (left->right, right->left);
}


/* 二叉树的翻转 */

TreeNode* inverttree(TreeNode* root){
    if(root==nullptr)
        return nullptr;
    
    TreeNode* tmp = root->left;
    root->left = inverttree(root->right);
    root->right = inverttree(tmp);

    return root;
}

/* 二叉树的最大深度 */
int TreeDepth(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)    
        return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

/* 二叉树最小深度 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 直接递归，初始根节点是没有brother
        return minDepth(root, false);
    }
    
    int minDepth(TreeNode* p, bool hasbrother)
    {
        // 当前节点是空节点
        if(!p)
            return hasbrother?INT_MAX:0;
        // 递归
        // 分别考虑左右子树
        return 1+min(minDepth(p->left, p->right!=NULL), 
                    minDepth(p->right, p->left!=NULL));
        
    }
};

