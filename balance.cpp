#include <stdio.h>
#include <iostream>

using namespace std;
class Node
{
public:
	Node(int x )
	{	  data = x;
	      this -> left = NULL;
	      this -> right = NULL;
	    }

	int data;
	Node* left;
	Node* right;
};


class BST
{
public:
	bool isEmpty()
	{
		return rootptr == NULL;
	}

	BST(Node *rootPtr)
		{
			this->rootptr = rootPtr;
		}
	Node *	getRoot() {
		return rootptr;
	}
bool insert(int x) {
  if (isEmpty())
    {
	  rootptr = new Node(x);
	   return true;
		}

		Node *p = rootptr;
		while (p != NULL) {
			int	a = p->data;
			if (a == x) return false;
			else if (x < a) {
				if (p->left == NULL) {
					Node *newNodePtr = new Node(x);
					p->left=newNodePtr; return true;
				}
				else p = p->left;
			}
			else {
				if (p->right == NULL) {
					Node	*newNodePtr = new Node(x);
					p->right=newNodePtr; return true;
				}
				else p = p->right;
			}
		}
	}

private:
	Node * rootptr;
};

int height(Node*  root)
{
	if (root==NULL)
	{
		return 0;
	}
	
	int left_height = height(root->left);	
    int right_height = height(root->right);

		if (left_height >= right_height)
		{
			return 1+left_height;
		}
		else 
		{ 
			return 1+right_height;
		}
}


bool checkbalance(Node *root) {

	int LeftSubTreeHeight;
	int RightSubTreeHeight;

	if (root == NULL) {
		return 1;	}
	LeftSubTreeHeight = height(root->left);
	RightSubTreeHeight = height(root->right);
	if (abs(LeftSubTreeHeight - RightSubTreeHeight) <= 1 && checkbalance(root->left) && checkbalance(root->right)) {
		return 1;
	}
	return 0;
}

int main()
{
	int num;
	cin >> num;
	int *arr = new int[num];

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];

	}

	Node *root = new Node(arr[0]);

	BST	tree = BST(root);

	for (int i = 1; i < num; i++)
	{
		bool insert = tree.insert(arr[i]);
     }

	if (checkbalance(root) == 1) { cout << "YES"; }
	else { cout << "NO"; }

	//system("pause");
	return 0;
	}

