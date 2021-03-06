#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* createTree(vector<int> nodeList)
{
    int len = nodeList.size();
    if(len==0 || !nodeList[0])
        return nullptr;
    TreeNode* root = new TreeNode(nodeList[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i=1;
    while (i<len)
    {
        TreeNode* node = que.front();
        que.pop();
        if(nodeList[i])
        {
            TreeNode* n = new TreeNode(nodeList[i]);
            node->left = n;
            que.push(n);
        }
        if(++i==len) break;
        if(nodeList[i])
        {
            TreeNode* n = new TreeNode(nodeList[i]);
            node->right = n;
            que.push(n);
        }
        if(++i==len) break;
    }
    return root;
}

class Solution
{
    public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& res)
    {
        if(!root)
            return;
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }
    
};

int main()
{
    vector<int> treelist = {1, NULL, 2, 3};
    TreeNode* root = createTree(treelist);
    Solution solution = Solution();
    vector<int> res = solution.inorderTraversal(root);

    cout << '[';
    for(int x:res)
    {
        cout << x <<' ';
    }
    cout << ']' << endl;
    system("pause");
    return 0;
}