// Binary Trees = which have max two child
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
// Jab kabhi bhi tree ko print karana ho to sirf nodes print karo unke children print mat karo
// Base case generic trees me nahi likhna kyunki vaha for loop tha 
// Base case binary trees me compulsory hai kyunki vaha uske children pe call hoti hai
BinaryTreenode<int>* takeInput()
{
	int rootData;
	cout<<"Enter root data: ";
	cin>>rootData;
	if(rootData == -1)
	{
		return NULL;
	}
	BinaryTreenode<int>*root = new BinaryTreenode<int>(rootData);
	BinaryTreenode<int>*leftChild = takeInput();
	BinaryTreenode<int>*rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
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
void printTree(BinaryTreenode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<":";
	if(root->left != NULL)
	{
		cout<<"L"<<root->left->data;
	}
	if(root->right != NULL)
	{
		cout<<"R"<<root->right->data;
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
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
int count_nodes(BinaryTreenode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	int count = 1;
	int leftcount = count_nodes(root->left);
	int rightcount = count_nodes(root->right);
	return 1+leftcount+rightcount;
	// return 1+count_nodes(root->left)+count_nodes(root->right);
}
void Preorder(BinaryTreenode<int>*root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(BinaryTreenode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}
void Inorder(BinaryTreenode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
// 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
int main()
{
	// BinaryTreenode<int>*root = new BinaryTreenode<int>(1);
	// BinaryTreenode<int>*node1 = new BinaryTreenode<int>(2);
	// BinaryTreenode<int>*node2 = new BinaryTreenode<int>(3);
	// root->left = node1;
	// root->right = node2;
	BinaryTreenode<int>*root = takeInputlevelwise();
	printTreelevelwise(root);
	int count = count_nodes(root);
	cout<<"Total nodes are: "<<count<<endl;
	cout<<"Preorder: ";
	Preorder(root);
	cout<<endl;
	cout<<"Postorder: ";
	Postorder(root);
	cout<<endl;
	cout<<"Inorder: ";
	Inorder(root);
	cout<<endl;
}