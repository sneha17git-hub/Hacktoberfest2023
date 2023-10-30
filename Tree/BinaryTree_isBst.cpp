//A program to check if a binary tree is BST or not
#include<iostream> 
#include<limits.h> //for INT_MIN and INT_MAX
using namespace std; 
/* A binary tree node has data, pointer to left child 
and a pointer to right child */  
struct Node
{
	int data;
	Node* left;
	Node* right;
	/*For Creating New Node*/
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)  
{  
    if (node==NULL) //if root is NULL 
        return 1;  
    if (node->data < min || node->data > max)  
        return 0;  
    return
        isBSTUtil(node->left, min, node->data-1) &&   
        isBSTUtil(node->right, node->data+1, max); 
} 

/* Returns true if the given  
tree is a binary search tree */
int isBST(Node* rt)  
{  
    return(isBSTUtil(rt, INT_MIN, INT_MAX));  
}  

/* DRIVER FUNCTION */
int main()  
{  
	//Inserting the elements according to the Tree
    Node* root = new Node(10);  
    root->left = new Node(6);  
    root->right = new Node(13);  
    root->left->left = new Node(1);  
    root->left->right = new Node(8);
	root->right->left = new Node(11);  
    root->right->right = new Node(14);  
      
    if(isBST(root))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
}  

//OUTPUT
//Is BST
