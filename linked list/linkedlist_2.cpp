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
node* midpoint_ll(node* head)
{
	node* slow = head;
	node* fast = head->next;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
node* merge_two_sorted_ll(node* head1, node* head2)
{
	node* newhead = NULL;
	node* temp = NULL;
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->data < head2->data)
		{
			if(newhead == NULL)
			{
				newhead = head1;
				temp = head1;
			}
			else
			{
				temp->next = head1;
				temp = head1;
			}
			head1 = head1->next;
		}
		else
		{
			if(newhead == NULL)
			{
				newhead = head2;
				temp = head2;
			}
			else
			{
				temp->next = head2;
				temp = head2;
			}
			head2 = head2->next;
		}
	}
	while(head1 != NULL)
	{
		temp->next = head1;
		temp = head1;
		head1 = head1->next;
	}
	while(head2 != NULL)
	{
		temp->next = head2;
		temp = head2;
		head2 = head2->next;
	}
	return newhead;
}
node* reverse_ll_rec_1(node* head)
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	node* newhead = reverse_ll_rec_1(head->next);
	node* temp = newhead;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return newhead;
}
node* reverse_ll_rec_2(node* head)
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	node* newhead = reverse_ll_rec_2(head->next);
	node* temp = head->next;
	temp->next = head;
	head->next = NULL;
	return newhead;
}
class pair1
{
public:
	node* head;
	node* tail;
};
pair1 helper(node* head)
{
	if(head == NULL || head->next == NULL)
	{
		pair1 ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}
	pair1 smallans = helper(head->next);
	smallans.tail->next = head;
	head->next = NULL;
	pair1 ans;
	ans.head = smallans.head;
	ans.tail = head;
	return ans;
}
node* reverse_ll_rec_3(node* head)
{
	return helper(head).head;
}
int main()
{
	node* head = take_input();
	print(head);
	int data, i, j = 1, choice;
	while(j == 1)
	{
		printf("\nPress 1 to find mid point of linked list");
		printf("\nPress 2 to merge two sorted linked list");
		printf("\nPress 3 to reverse linked list");
		// printf("\nPress 4 to reverse linked list recursive 2");
		printf("\nPress 4 to display elements");
		printf("\nPress any key to exit");
		printf("\nEnter your choice: ");
		cin>>choice;
		switch(choice)
		{
			case 1:	{ 
						node* ans = midpoint_ll(head);
						cout<<"\nMidpoint is: "<<ans->data<<endl;
						break;
					}
			case 2: {
						node* head1 = take_input();
						node* head2 = take_input();
						node* ans= merge_two_sorted_ll(head1, head2);
						print(ans);
						break;
					}
			case 3:	{
						node* ans = reverse_ll_rec_1(head);
						print(ans);
						ans = reverse_ll_rec_2(ans);
						print(ans);
						ans = reverse_ll_rec_3(ans);
						print(ans);
						break;
					}
			case 4: {
						print(head);
						break;
					}
			default:{ 	
						j++;
					 	break;
					}
		}
	}
}