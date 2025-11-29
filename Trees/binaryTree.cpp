#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
	    
	    Node(int d){
	    	data = d;
	    	left = right = 0;
		}
};
Node* createNode(int v){
	return new Node(v);
}

Node* insert(Node* root, int value){
	if(root==0){
		return createNode(value);
	}
	if(value < root->data){
		root->left = insert(root->left, value);
	}
	if(value >root->data){
		root->right = insert(root->right, value);
	}
	return root;
}

Node* search(Node* root, int value){
	if(root==0 || root->data==value){
		return root;
	}
	if(value < root->data){
		return search(root->left, value);
	}
	if(value > root->data){
		return search(root->right, value);
	}
}

Node* findMin(Node* root){
	Node* temp = root;
	while(temp->left != 0){
		temp = temp->left;
	}
	return temp;
}

Node* deleteNode(Node* root, int value){
	if(root==0){
		return root;
	}
	if(value < root->data){
		root->left = deleteNode(root->left, value);
	}
	else if(value > root->data){
		root->right = deleteNode(root->right, value);
	}
	else{
		if(root->left==0){
			Node* temp = root->right;
			delete root;
		    return temp;
		}
		else if(root->right == 0){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = findMin(root);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void inorder(Node* root){
	if(root==0){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node* root){
	if(root==0){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root){
	if(root==0){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main() {
    Node* root = 0;

    // Insert values
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "BST created successfully.\n";

    // Search test
    int key = 40;
    Node* s = search(root, key);
    if(s) cout << key << " found in tree.\n";
    else cout << key << " not found.\n";

    // Delete test
    cout << "Deleting 50...\n";
    root = deleteNode(root, 50);

    cout << "Done.\n";
    inorder(root);
    return 0;
}



