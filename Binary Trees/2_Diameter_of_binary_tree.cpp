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
// pair is an inbuilt class which is a template and having two data members first and second
pair<int, int> diameter_betterapproach(BinaryTreenode<int>* root)
{
	if(root == NULL)
	{
		pair<int, int>p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> left = diameter_betterapproach(root->left);
	pair<int, int> right = diameter_betterapproach(root->right);
	int lh = left.first;
	int ld = left.second;
	int rh = right.first;
	int rd = right.second;
	int height = 1+max(lh, rh);
	int diameter = max(lh+rh, max(ld, rd));
	pair<int, int>p;
	p.first = height;
	p.second = diameter;
	return p;
}
int height(BinaryTreenode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1+max(height(root->left), height(root->right));
}
int diameter(BinaryTreenode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
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
// 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
	BinaryTreenode<int>* root = takeInputlevelwise();
	printTreelevelwise(root);
	cout<<"Diameter: "<<diameter(root)<<endl;
	pair<int, int>ans = diameter_betterapproach(root);
	cout<<"Height: "<<ans.first<<" "<<"Diameter: "<<ans.second;
}