#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
node* take_input()
{
	node* head = NULL;
	node* tail = NULL;
	int data;
	cout<<"Enter your linked list: ";
	cin>>data;
	while(data != -1)
	{
		node* newnode = new node(data);
		if(head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin>>data;
	}
	return head;
}
void print(node* head)
{
	node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
node* insert_node(node* head, int data, int i)
{
	node* newnode = new node(data);
	node* temp = head;
	int count = 0;
	if(i == 0)
	{
		newnode->next = head;
		head = newnode;
		return head;
	}
	while(temp != NULL && count < i-1)
	{
		temp = temp->next;
		count++;
	}
	if(temp != NULL)
	{
		newnode->next = temp->next;
		temp->next = newnode;
	}
	return head;
}
node* insert_node_recursively(node* head, int data, int i)
{
	if(head == NULL)
	{
		if(i == 0)
		{
			node* newnode = new node(data);
			head = newnode;
			return head;
		}
		else
		{
			return head;
		}
	}
	if(i == 0)
	{
		node* newnode = new node(data);
		newnode->next = head;
		head = newnode;
		return head;	
	}
// 1->2->3->4->5->null
// if we pass the linked list from node data 2(index 1) to recursion then it will return only that linked list which we have pass..we have to made the connection externally head and newhead return by recursion. 
	else
	{
		node* newhead = insert_node_recursively(head->next, data, i-1);
		head->next = newhead;
		return head;
	}
}
node* delete_node(node* head, int i)
{
	node* temp = head;
	int count = 0;
	if(i == 0)
	{
		head = head->next;
		temp->next = NULL;
		delete temp;
		return head;
	}
	while(temp != NULL && count < i-1)
	{
		temp = temp->next;
		count++;
	}
	if(temp != NULL)
	{
		node* del_node = temp->next;
		temp->next = del_node->next;
		del_node->next = NULL;
		delete del_node;
	}
	return head;
}
node* delete_node_recursively(node* head, int i)
{
	if(head == NULL)
	{
		return head;
	}
	if(i == 0)
	{
		node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		node* newhead = delete_node_recursively(head->next, i-1);
		head->next = newhead;
	}
	return head;
}
int main()
{
	node* head = take_input();
	print(head);
	int data, i, j = 1, choice;
	while(j == 1)
	{
		printf("\nPress 1 to insert an element into linked list");
		printf("\nPress 2 to insert an element recursively into linkd list");
		printf("\nPress 3 to delete an element from linked list");
		printf("\nPress 4 to delete an element recursively from linkd list");
		printf("\nPress 5 to display elements");
		printf("\nPress any key to exit");
		printf("\nEnter your choice: ");
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the data you want to insert in linked list: ";
					cin>>data;
					cout<<"Enter the position at which you want to insert the node: ";
					cin>>i;
					head = insert_node(head, data, i);
					break;
			case 2:	cout<<"Enter the data you want to insert in linked list: ";
					cin>>data;
					cout<<"Enter the position at which you want to insert the node: ";
					cin>>i;
					head = insert_node_recursively(head, data, i);
					break;
			case 3: cout<<"Enter the position at which you want to delete an element: ";
					cin>>i;
					head = delete_node(head, i);
					break;
			case 4: cout<<"Enter the position at which you want to delete an element: ";
					cin>>i;
					head = delete_node_recursively(head, i);
					break;
			case 5: print(head);
					break;
			default: j++;
					 break;
		}
	}
}
