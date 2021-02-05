/*
For every node n, everything in n's left subtree is less than n's data
For every node n, everything in n's right subtree is greater than n's data
*/
#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreenode
{
public:
	T data;
	BinaryTreenode<int>* left;
	BinaryTreenode<int>*right;
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
class BST
{
private:
	BinaryTreenode<int>* root;
public:
	BST()
	{
		root = NULL;
	}
	~BST()
	{
		delete root;
	}
private:
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
public:
	void printTreelevelwise()
	{
		printTreelevelwise(root);
	}
private:
	BinaryTreenode<int>* deletedata(int data, BinaryTreenode<int>* node)
	{
		if(node == NULL)
		{
			return NULL;
		}
		if(data < node->data)
		{
			node->left = deletedata(data, node->left);
			return node;
		}
		if(data > node->data)
		{
			node->right = deletedata(data, node->right);
			return node;
		}
		else
		{
			if(node->left == NULL && node->right == NULL)
			{
				delete node;
				return NULL;
			}
			if(node->right == NULL)
			{
				BinaryTreenode<int>* temp = node->left;
				node->left = NULL;
				delete node;
				return temp;
			}
			if(node->left == NULL)
			{
				BinaryTreenode<int>* temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			}
			else
			{
				BinaryTreenode<int>* minnode = node->right;
				while(minnode->left != NULL)
				{
					minnode = minnode->left;
				}
				int rightmin = minnode->data;
				node->data = rightmin;
				node->right = deletedata(rightmin, node->right);
				return node;
			}
		}
	}
public:
	void deletedata(int data)
	{
		root = deletedata(data, root);
	} 
private:
	BinaryTreenode<int>* insert(int data, BinaryTreenode<int>* node)
	{
		if(node == NULL)
		{
			BinaryTreenode<int>* newnode = new BinaryTreenode<int>(data);
			return newnode;
		}
		if(data < node->data)
		{
			node->left = insert(data, node->left);
		}
		else
		{
			node->right = insert(data, node->right);
		}
		return node;
	}
public:
	void insert(int data)
	{
		root = insert(data, root);
	}
private:
	bool hasData(int data, BinaryTreenode<int>* node)
	{
		if(node == NULL)
		{
			return false;
		}
		if(node->data == data)
		{
			return true;
		}
		if(data < node->data)
		{
			return hasData(data, node->left);
		}
		else
		{
			return hasData(data, node->right);
		}
	}
public:
	bool hasData(int data)
	{
		return hasData(data, root);
	}
};
int main()
{
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.printTreelevelwise();
	cout<<endl;
	b.deletedata(10);
	b.deletedata(100);
	b.printTreelevelwise();
}