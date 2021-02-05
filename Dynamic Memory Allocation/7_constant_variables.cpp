// In case of const variables we have to initialise at the time of declaration
#include<iostream>
using namespace std;
int main()
{
	const int i = 10;	// rewrite as int const i = 10
	// i = 12;			// gives an error
	// const int i;		// gives error doesn't allow to store garbage

/* 
ek memory pe jane ke do raaste hain j and k, humne k vale path ko constant kar diya
to main us memory pe k vale path ke through changes nahi kara sakta
but j ke through kara sakta hoon 
*/

// 1. const reference from a non const int
	int j = 12;				// path of j has both read and write access
	const int & k = j;		// path of k has read only access
	// k++;					// k doesn't have any access to write
	j++;
	cout<<k<<endl;

// 2. constant reference from a const int 
	int const j2 = 12;		// path of j2 has read only access
	int const & k2 = j2;	// path of k2 has read only access 
	// j2++;				// j2 doesn't has any access to write
	// k2++;				// k2 doesn't has any access to write

// 3. reference from a const int
	int const j3 = 123;		// path of j3 has read only access
	// int & k3 = j3;		// if j3 has read only access then 
							// how can i create k3 which has both read and write access

}