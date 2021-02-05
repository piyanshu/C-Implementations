#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreenode
{
public:
	T data;
	BinaryTreenode* left;
	BinaryTreenode* right;
	BinaryTreenode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL; 
	}
	~BinaryTreenode()
	{
		delete left;
		delete right;
	}
};
BinaryTreenode<int>* helper(int *pre, int *in, int ins, int ine, int pres, int pree)
{
    if(ins > ine)
    {
        return NULL;
    }
    int rootdata = pre[pres];
    int lpres = pres+1;
    int lins = ins;
    int rootindex = -1;
    for(int i=ins; i<=ine; i++)
    {
        if(rootdata == in[i])
        {
            rootindex = i;
            break;
        }
    }
    int line = rootindex-1;
    int lpree = (line - lins) + lpres;
    int rpres = lpree+1;
    int rpree = pree;
    int rins = rootindex+1;
    int rine = ine;
    BinaryTreenode<int>* root = new BinaryTreenode<int>(rootdata);
/* Hume left subtree par recursive call karni hai 
   to hume batana padega ki left kaha se kaha tak hai 
   aur hume preorder aur inorder dono mein batana padega kyunki hume unique tree banana hai
*/
    root->left = helper(pre, in, lins, line, lpres, lpree);
    root->right = helper(pre, in, rins, rine, rpres, rpree);
	return root;
/*
Concept = Jab kabhi bhi hum kisi bhi part par recursive call karte hain 
	to hume batana padta hai ki vo part kaha se kaha tak hai 
	Hum arrays mein bhi recursion use karte hain to batate hain recursion ko arr+1
*/
}
BinaryTreenode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return helper(preorder, inorder, 0, inLength-1, 0, preLength-1);
}
void printTreelevelwise(BinaryTreenode<int>* root)
{
	queue<BinaryTreenode<int>*>pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0)
	{
		BinaryTreenode<int>* front = pendingNodes.front();
		cout<<front->data<<":";
		pendingNodes.pop();
		if(front->left != NULL)
		{
			cout<<"L"<<front->left->data;
			pendingNodes.push(front->left);
		}
		if(front->right != NULL)
		{
			cout<<"R"<<front->right->data;
			pendingNodes.push(front->right);
		}
		cout<<endl;
	}
}
int main()
{
	int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
	int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
	BinaryTreenode<int>* root = buildTree(pre, 9, in, 9);
	printTreelevelwise(root);
}
