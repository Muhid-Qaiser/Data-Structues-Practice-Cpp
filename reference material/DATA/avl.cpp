#include<iostream>
#include<fstream>
using namespace std;
class node {
public:
	node* right;
	node* left;
	int data;
	int h;

	node(int data)
	{
		this->data = data;
		right = nullptr;
		left = nullptr;
		h = 1;
	}

};
class bst {
public:
	node* Root;
	bst()
	{
		Root = nullptr;
	}
	node* getroot()
	{
		return Root;
	}
	node* insert(int d,node *root)
	{
		node* temp = new node(d);
		node* cur = root;
		node* par = nullptr;
		
		while (cur != nullptr)
		{
			par = cur;
			if (d < cur->data)
			{
				cur = cur->left;
			}
			else if (d > cur->data)
			{
				cur = cur->right;
			}
		}
		if (par == nullptr)
			{
				//par = temp;
				return temp;
			}

		else if (d<par->data )
		{
			par->left = temp;
		}
		else if (d>par->data)
		{
			par->right = temp;
		}
		root = avlb(root, d);
		//AVL
		//cout << par->data << endl;
		Root = root;
		return root;
	}
	node* avlb(node* root, int key)
	{
		root->h = height(root);
		int b = gelbalance(root);

		if (b > 1 && key < root->left->data)
		{
			cout << "b1" << endl;
			return rightrotate(root);
		}
		 if (b<-1 && key>root->right->data)
		{
			 cout << "b2" << endl;
			return leftrotate(root);
		}
		 if (b > 1 && key > root->left->data)
		 {
			 cout << "b3" << endl;
			 root->left = leftrotate(root->left);
			 return rightrotate(root);
		 }
		 if (b < -1 && key < root->right->data)
		 {
			 cout << "b4" << endl;
			 root->right = rightrotate(root->right);
			 return leftrotate(root);
		 }

		 return root;
	}
	node* rightrotate(node* x)
	{
		node* y = x->left;
		node* T2 = y->right;

		// Perform rotation
		y->right = x;
		x->left = T2;

		// Update heights
		y->h = max(height(y->left),
			height(y->right)) + 1;
		x->h = max(height(x->left),
			height(x->right)) + 1;

		// Return new root
		return x;
	}

	// A utility function to left
	// rotate subtree rooted with x
	// See the diagram given above.
	node* leftrotate(node* x)
	{
		node* y = x->right;
		node* T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		// Update heights
		x->h = max(height(x->left),
			height(x->right)) + 1;
		y->h = max(height(y->left),
			height(y->right)) + 1;

		// Return new root
		return y;
	}
	int gelbalance(node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return height(root->left) - height(root->right);
	}
	void inorder(node* root)
	{

		if (root == nullptr)
		{
			return;
		}
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}

	void postorder(node* root)
	{

		if (root == nullptr)
		{
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
	void preorder(node* root)
	{

		if (root == nullptr)
		{
			return;
		}
		cout << root->data;
		postorder(root->left);
		postorder(root->right);
		
	}

	bool search(node* root, int key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (key == root->data)
		{
			return true;
		}

		else if (root->data > key)
		{
			search(root->left, key);
		}
		else
		{
			search(root->right, key);
		}
	}

	int size(node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		return size(root->left)+ size(root->right) + 1;
	}
	int height(node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		return max(height(root->left), height(root->right)) + 1;
	}

	node* deletenode(node* root, int key)
	{
		if (root == nullptr)
		{
			return root;
		}
		if (key < root->data)
		{
			root->left = deletenode(root->left, key);
		}
		else if (key > root->data)
		{
			root->right = deletenode(root->right, key);
		}
		else
		{
			if (root->left == nullptr)
			{
				return root->right;
			}
			else if (root->right==nullptr)
			{
				return root->left;
			}
			root->data = minv(root->right);
			root->right = deletenode(root->right, root->data);
		}
		Root = root;
		return root;
	}

	int minv(node* root)
	{
		int Min = root->data;
		while(root->left != nullptr)
		{
			Min = root->left->data;
			root = root->left;
		}
		return Min;
	}
	
};
int main()
{
	int c = 0;
	bst b1;
	node* ptr= b1.getroot();
	int j = 0;
	int arr[6] = { 25,10,15,30,40,5 };
	ifstream myfile("Numbers.txt");
	while (!myfile.eof())
	{
		myfile >> c;
		cout << c << endl;
	}

	for (int i = 0; i < 6; i++)
	{
		ptr = b1.insert(arr[i], ptr);
	}

	ptr = b1.getroot();;
	// cout <<ptr->data;
	//b1.inorder(ptr);
	//b1.postorder(ptr);
	//cout << b1.search(ptr, 25);
	//cout << b1.size(ptr);
	//cout << b1.height(ptr);
	//ptr=b1.deletenode(ptr, 10);
	b1.inorder(ptr);
	//int arr[3] = { 15,10,7 };
	//ofstream myfile;
//myfile.open("example.pgm", ios::trunc);

}
