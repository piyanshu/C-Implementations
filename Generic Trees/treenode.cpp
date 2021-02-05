#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename t>
class treenode
{
public:
	t data;
	vector<treenode*>children;
	treenode(t data)
	{
		this->data = data;
	}
	~treenode()
	{
		for(int i=0; i<children.size(); i++)
		{
			delete(children[i]);
		}
	}
};
treenode<int>* takeinput()
{
	int rootdata;
	cout<<"Enter data: ";
	cin>>rootdata;
	treenode<int>* root = new treenode<int>(rootdata);
	int n;
	cout<<"Enter the number of children "<<root->data<<": ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		treenode<int>* child = takeinput();
		root->children.push_back(child);
	}
	return root;
}
void printtree(treenode<int>* root)
{
	cout<<root->data<<":";
	for(int i=0; i<root->children.size(); i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0; i<root->children.size(); i++)
	{
		printtree(root->children[i]);
	}
}
treenode<int>* takeinput_levelwise()
{
	int rootdata;
	cout<<"Enter root data: ";
	cin>>rootdata;
	treenode<int>* root = new treenode<int>(rootdata);
	queue<treenode<int>*>pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size() != 0)
	{
		treenode<int>* front = pendingnodes.front();
		pendingnodes.pop();
		int numchild;
		cout<<"Enter the num of child "<<front->data<<": ";
		cin>>numchild;
		for(int i=0; i<numchild; i++)
		{
			int numdata;
			cout<<"Enter the data of "<<i+1<<"th child of "<<front->data<<": ";
			cin>>numdata;
			treenode<int>* child = new treenode<int>(numdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	cout<<endl;
	return root;
}
void printtree_levelwise(treenode<int>* root)
{
	queue<treenode<int>*>pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size() != 0)
	{
		treenode<int>* front = pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		for(int i=0; i<front->children.size(); i++)
		{
			cout<<front->children[i]->data<<",";
			pendingnodes.push(front->children[i]);
		}
		cout<<endl;
	}
}
int count_nodes(treenode<int>* root)
{
	int sum = 1;
	for(int i=0; i<root->children.size(); i++)
	{
		sum = sum + count_nodes(root->children[i]);
	}
	return sum;
}
int height(treenode<int>* root)
{
	int h = 0;
	for(int i=0; i<root->children.size(); i++)
	{
		int nh = height(root->children[i]);
		if(nh > h)
		{
			h = nh;
		}
	}
	return h+1;
}
void depth_nodes(treenode<int>* root, int d)
{
	if(d == 0)
	{
		cout<<root->data<<" ";
		return;
	}
	for(int i=0; i<root->children.size(); i++)
	{
		depth_nodes(root->children[i], d-1);
	}
}
int leaf_nodes(treenode<int>* root)
{
	int ans = 0;
	if(root->children.size() == 0)
	{
		ans = 1;
	}
	for(int i=0; i<root->children.size(); i++)
	{
		ans = ans + leaf_nodes(root->children[i]);
	}
	return ans;
}
void deletetree(treenode<int>* root)
{
	for(int i=0; i<root->children.size(); i++)
	{
		deletetree(root->children[i]);
	}
	delete root;
}
// 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0
int main()
{
	// treenode<int>* root = new treenode<int>(1);
	// treenode<int>* node1 = new treenode<int>(2);
	// treenode<int>* node2 = new treenode<int>(3);
	// root->children.push_back(node1);
	// root->children.push_back(node2);
	treenode<int>* root = takeinput_levelwise();
	printtree_levelwise(root);
	int ans = count_nodes(root);
	cout<<"Total nodes: "<<ans<<endl;
	ans = height(root);
	cout<<"height: "<<ans<<endl;
	int depth;
	cout<<"Enter the depth at which you want to print the nodes: ";
	cin>>depth;
	cout<<"nodes at depth "<<depth<<": ";
	depth_nodes(root, depth);
	ans = leaf_nodes(root);
	cout<<"\nLeaf nodes: "<<ans<<endl;
	// two ways to delete a tree

	 // deletetree(root);
	delete root;
}