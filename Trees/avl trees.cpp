#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		int height;
		Node* left;
		Node* right;
		Node(int v){
			data = v;
			height = 1;
			left = 0;
			right = 0;
		}
};
int getHeight(Node* root){
	return n->height;
}
int updateHeight(Node *root){
	return 1+max((getHeight(root->left)), getHeight(root->right));
}

int balance(Node* root){
	return getHeight(root->left) - getHeight(root->right);
}

Node* leftRotate(Node* x){
	Node* y = x->right;
	Node* T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	updateHeight(x);
	updateHeight(y);
	return y;
}

Node* rightRotate(Node* y){
	Node* x = y->left;
	Node* T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	updateHeight(x);
	updateHeight(y);
	return x;
}

Node* balanceAvl(Node* root, int value){
	updateHeight(root);
	int balance = balance(root);
	
	if(balance > 1 && value < root->left->data){
		return rightRotate(root);
	}
	else if(balance < -1 && value > root->right->data){
		return leftRotate(root);
	}
	else if(balance > 1 && value > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	else if(balance < -1 && value < root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

Node* insert(Node *root, int val){
	if(root==0){
		return new Node(val);
	}
	if(val < root->data){
		root->left = insert(root->left, val);
	}
	else if(val > root->data){
		root->right = insert(root->right, val);
	}
	else{
		return root;
	}
	return balanceAvl(root, val);
}

Node* deleteNode(Node* root, int val){
	if(root==0){
		return 0;
	}
	if(val < root->data){
		root->left = deleteNode(root->left, val);
	}
	else if(val > root->data){
		root->right = deleteNode(root->right, val);
	}
	else{
		//no child
		if(root->left == 0 && root->right == 0){
			delete root;
			return 0;
		}
		//one child exists
		else if(root->left == 0){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == 0){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else{ //both child exists
			Node* succ = findMin(root);
		    root->data = succ->data;
		    root->right = deleteNode(root->right, succ->data);
		}
	}
	return balanceAvl(root, value);
}

Node* findMin(Node* root){
	Node* temp = root;
	while(temp->left != 0){
		temp = temp->left;
	}
	return temp;
}


