#include<iostream>
#include<queue>
#include<climits>
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
bool helper(BinaryTreenode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data < min || root->data > max)
    {
        return false;
    }
    bool leftans = helper(root->left, min, root->data-1);
    bool rightans = helper(root->right, root->data, max);
	return leftans && rightans;
}
bool isBST3(BinaryTreenode<int> *root) {
    return helper(root);
}
class pair1
{
    public:
    int min;
    int max;
    bool isBST;  
};
pair1 minmaxisBST(BinaryTreenode<int> *root)
{
    if(root == NULL)
    {
        pair1 p;
        p.min = INT_MAX;
        p.max = INT_MIN;
        p.isBST = true;
        return p;
    }
    pair1 leftans = minmaxisBST(root->left);
    pair1 rightans = minmaxisBST(root->right);
	int lmin = leftans.min;
    int lmax = leftans.max;
    int lisBST = leftans.isBST;
    int rmin = rightans.min;
    int rmax = rightans.max;
    int risBST = rightans.isBST;
    pair1 p;
    p.min = min(root->data, min(lmin, rmin));
    p.max = max(root->data, max(lmax, rmax));
    p.isBST = root->data > lmax && root->data <= rmin && lisBST && risBST;
	return p;
}
bool isBST2(BinaryTreenode<int> *root) {
    return minmaxisBST(root).isBST;
}
int minimum(BinaryTreenode<int> *root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }
    int min = root->data;
    int lmin = minimum(root->left);
    if(lmin < min)
    {
        min = lmin;
    }
	int rmin = minimum(root->right);
    if(rmin < min)
    {
        min = rmin;
    }
    return min;
}
int maximum(BinaryTreenode<int> *root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
bool isBST1(BinaryTreenode<int> *root) {
    if(root == NULL)
    {
        return true;
    }
    int lmax = maximum(root->left);
	int rmin = minimum(root->right);
    if(root->data <= lmax || root->data > rmin)
    {
        return false;
    }
    return isBST1(root->left) && isBST1(root->right);
}
BinaryTreenode<int>* takeInputlevelwise()
{
	int rootData;
	cout<<"Enter root data: ";
	cin>>rootData;
	BinaryTreenode<int>* root = new BinaryTreenode<int>(rootData);
	queue<BinaryTreenode<int>*>pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0)
	{
		BinaryTreenode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int leftChild;
		cout<<"Enter the left child of "<<front->data<<": ";
		cin>>leftChild;
		if(leftChild != -1)
		{
			BinaryTreenode<int>*child = new BinaryTreenode<int>(leftChild);
			front->left = child;
			pendingNodes.push(child);
		}
		int rightChild;
		cout<<"Enter the right child of "<<front->data<<": ";
		cin>>rightChild;
		if(rightChild != -1)
		{
			BinaryTreenode<int>* child = new BinaryTreenode<int>(rightChild);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
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
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
	BinaryTreenode<int>*root = takeInputlevelwise();
	printTreelevelwise(root);
	bool ans1 = isBST1(root);
	if(ans1 == false)
	{
		cout<<"False"<<endl;
	}
	else
	{
		cout<<"True"<<endl;
	}
	bool ans2 = isBST2(root);
	if(ans1 == false)
	{
		cout<<"False"<<endl;
	}
	else
	{
		cout<<"True"<<endl;
	}
	bool ans3 = isBST3(root);
	if(ans1 == false)
	{
		cout<<"False"<<endl;
	}
	else
	{
		cout<<"True"<<endl;
	}
}