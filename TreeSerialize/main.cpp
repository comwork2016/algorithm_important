#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
        public:
                char val;
                TreeNode* left;
                TreeNode* right;

                TreeNode(char val):val(val),left(NULL),right(NULL){}
};

/**
 * create tree from serialized string
 * TreeNode* is not correct, cause function can only modify the content that the pointer points to,
 * but can't modify the value of pointer
 */
void readTreeFromString(TreeNode** root,string str,int& count)
{
        if (str[count++] == '#') {
                *root = NULL;
        } else {
                *root = new TreeNode(str[count-1]);
                readTreeFromString(&((*root)->left),str,count);
                readTreeFromString(&((*root)->right),str,count);
        }
}

/*
   write tree to serialized string
 */
void writeTreeToString(TreeNode* root,string& str)
{
        if(!root)
        {
                str.append(1,'#');
        }else
        {
                str.append(1,root->val);
                writeTreeToString(root->left,str);
                writeTreeToString(root->right,str);
        }
}

int main()
{
        string str = "abc##de#g##f###";
        TreeNode* tree;
        int count = 0;
        readTreeFromString(&tree,str,count);
        string str_Serialized;
        writeTreeToString(tree,str_Serialized);
        cout<<"Read from string: "<<str<<endl;
        cout<<"Write to string: "<<str_Serialized<<endl;
        return 0;
}

