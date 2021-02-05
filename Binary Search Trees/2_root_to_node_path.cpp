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
vector<int>* root_to_node_path(BinaryTreenode<int>*root, int data)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(root->data == data)
	{
		vector<int>* v = new vector<int>();
		v->push_back(root->data);
		return v;
	}
	vector<int>* left = root_to_node_path(root->left, data);
	if(left != NULL)
	{
		left->push_back(root->data);
		return left;
	}
	vector<int>* right = root_to_node_path(root->right, data);
	if(right != NULL)
	{
		right->push_back(root->data);
		return right;
	}
	else
	{
		return NULL;
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
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
	BinaryTreenode<int>*root = takeInputlevelwise();
	printTreelevelwise(root);
	vector<int>* ans = root_to_node_path(root, 8);
	cout<<"Root to node path is"<<endl;
	for(int i=0; i<ans->size(); i++)
	{
		cout<<ans->at(i)<<endl;
	}
}