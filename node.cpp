#include <cstddef>
#include <iostream>

class node{
	int data;
	int height;
	int balance;
	node* left;
	node* right;
	node* parent;
public: 
	node();
	node(int);
	void deleteTree();
	void nodeInsert(node*);
	void setData(int);
	int getData();
	void printTree(int);
	void setBalance(int);
	//void createTree();
	void rotate();
	int balanceTree();
	void search(int);
	void search(int, int);
	void traversal(char);
	void deleteNode(int);
	int startCopyRight();
	int copyLeft();
	void startDeleteRight();
	void deleteLeft();
	bool checkNull();

};

//node::node(){
//	//data =  -1;
//	height = -1;
//	left = NULL;
//	right = NULL;
//	parent = NULL;
//}

void node::setData(int value){
	data = value;
}

void node::setBalance(int value){
	balance = value;
}

int node::getData(){
	return data;
}

node::node(int value){
	data =  value;
	height = -1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

void node::deleteTree(){


	if(this->left == NULL && this->right == NULL){
		
		return;
	}
	else if(this->left != NULL){
		this->left->deleteTree();
		delete this->left;
		this->left = NULL;
	}
	else{
		this->right->deleteTree();
		delete this->right;
		this->right = NULL;

	}
}

void node::nodeInsert(node* newNode){
	//if no tree exists
	//if(this == NULL){
	//	this = newNode;
	//	newNode->height = 0;
	//}

	if(this->data >= newNode->data){
		if(this->left == NULL){
			this->left = newNode;
			newNode->parent = this;
			newNode->height = (this->height+1);
			//if(this->right == NULL){
			//	this->balance = 
			//}
			return;

		}else{
			this->left->nodeInsert(newNode);
			return;
		}
	}else{
		if(this->right == NULL){
			this->right = newNode;
			newNode->parent = this;
			newNode->height = (this->height+1);

			//std::cout<<this->right->data;
			//std::cout<<newNode->data;

			return;

		}else{
			this->right->nodeInsert(newNode);
			return;
		}
	}
}

void node::printTree(int count){
	if(this->left == NULL && this->right == NULL){
		for( int i =0; i < count; i++){
			std::cout << "   ";
		}
		std::cout << data << std::endl;
		return;
	}

	if(this->left != NULL){
		this->left->printTree(count+1);
		
	}

	for( int i =0; i < count; i++){
			std::cout << "   ";
		}
	std::cout << data << std::endl;

	if(this->right != NULL){
		this->right->printTree(count+1);
		
	}

	return;
}

int node::balanceTree(){
//	std::cout<<"hitting";
	int right, left;

	if(this->left == NULL && this->right == NULL){
		this->balance = 0;
		this->height = 1;
		return 1;
	}

	//counts left subtree
	if(this->left != NULL){
		left = this->left->balanceTree();
	}else{
		left = 0;
	}

	//counts right subtree
	if(this->right != NULL){
		right = this->right->balanceTree();
	}else{
		right = 0;
	}

	//calculates balance
	this->balance = (left - right);
	//std::cout << left<<"->"<<right << std::endl;
	if(this->balance < -1 || this->balance > 1){
	//std::cout << this->data <<" unbalanced"<< this->balance<<std::endl;
		this->rotate();

		if(left >= right){
			this->height = (left);
			return (left);
		}else{
			this->height = (right);
			return (right);
		}

		//std::cout<<"after call"<<this->data<<std::endl;
	}else{
		if(left >= right){
			this->height = (left + 1);
			return (left+1);
		}else{
			this->height = (right + 1);
			return (right+1);
		}
	}
}

void node::rotate() {
	if (this->balance == 2) {
		if (this->left->balance >= 0) {
			//rotate right once
			//std::cout<<"this begins at:"<<this->data<<std::endl;
			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);

			node1 = this;
			//std::cout<<"node1"<<node1->data<<std::endl;
			node2 = this->left;
			//std::cout<<"node2"<<node2->data<<std::endl;
			
			//new
			node1->left = node2->left;
			node2->left = node2->right;
			node2->right = node1->right;
			node1->right = node2;
			int swap;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	
			


			//if(node2->right == NULL){
			//	node1->left = NULL;
			//}else{
			//	node1->left = node2->right;
			//}
			//node2->right = node1;
			//if(node1->parent == NULL){
			//	this = node2;
			//	node2->parent = NULL;
			//} else {
			//	node2->parent = node1->parent;
			//}
			//node1->parent = node2;

			//std::cout<<"this ends at:"<<this->data<<std::endl;
			//std::cout << "Rotated right" << std::endl;	
		}
		else if(this->left->balance == -1) {
			//rotate left then right

			node* node3;
			node* node4;
			node3 = new node(0);
			node4 = new node(0);

			node3 = this->left;
			node4 = this->left->right;
			
			node3->right = node4->right;
			node4->right = node4->left;
			node4->left = node3->left;
			node3->left = node4;
			
			int swap;
			swap = node3->data;
			node3->data = node4->data;
			node4->data = swap;


			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);

			node1 = this;
			node2 = this->left;
			
			node1->left = node2->left;
			node2->left = node2->right;
			node2->right = node1->right;
			node1->right = node2;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	

		}
		else {
			std::cout << "We have a problem";
		}
	}
	else if (this->balance == -2) {
		//if (this->right->balance == -1) {
		if (this->right->balance <= 0) {
			//rotate left once

			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);

			node1 = this;
			node2 = this->right;
			
			node1->right = node2->right;
			node2->right = node2->left;
			node2->left = node1->left;
			node1->left = node2;
			
			int swap;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	

			//std::cout << "Rotated left" << std::endl;
		}
		else if (this->right->balance == 1) {
			//rotate right then left

			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);

			node1 = this->right;
			node2 = this->right->left;
			
			node1->left = node2->left;
			node2->left = node2->right;
			node2->right = node1->right;
			node1->right = node2;
			int swap;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	


			node* node3;
			node* node4;
			node3 = new node(0);
			node4 = new node(0);

			node3 = this;
			node4 = this->right;
			
			node3->right = node4->right;
			node4->right = node4->left;
			node4->left = node3->left;
			node3->left = node4;
			
			swap = node3->data;
			node3->data = node4->data;
			node4->data = swap;
		}
		else {
			std::cout << "We have a negative problem";
		}
	}
	else {
		std::cout << "We have a big problem";
	}
}

void node::search(int input){
	if(this->data == input){
		std::cout << input <<" is at the root of the tree." << std::endl;
		return;
	}
	
	if(input < this->data){
		this->left->search(input, 1);
	} else if(input > this->data){
		this->right->search(input, 1);
	} else {
		std::cout << "We have a problem searching";
	}
	
}

void node::search(int input, int count){
	if(this->data == input){
		std::cout << input <<" is at height " << count;
		std::cout << " in the tree." << std::endl;
		return;
	}

	if(input < this->data){
		this->left->search(input, count+1);
	} else if(input > this->data){
		this->right->search(input, count+1);
	} else {
		std::cout << "We have a problem searching at the end";
	}
	return;
}

void node::traversal(char order){
	if(order == 'a'){
		//std::cout << this->data << std::endl;
		std::cout << this->data << "  ";
	}

//	if(this->left == NULL && this->right == NULL){
//		return;
//	}

	if(this->left !=NULL){
		this->left->traversal(order);
	}

	if(order == 'b'){
		//std::cout << this->data << std::endl;
		std::cout << this->data << "  ";	
	}

	if(this->right !=NULL){
		this->right->traversal(order);
	}

	if(order == 'c'){
		//std::cout << this->data << std::endl;
		std::cout << this->data << "  ";	
	}
	return;	
}

void node::deleteNode(int value){
	if(value == this->data){
		//delete this node

		if(this->left == NULL && this->right != NULL){
			this->data = this->right->data;
			delete this->right;
			this->right = NULL;
		}
		else if(this->right == NULL && this->left != NULL){
			this->data = this->left->data;
			delete this->left;
			this->left = NULL;
		}else{
			this->data = this->startCopyRight();
			this->startDeleteRight();
		}
		return;	
	}

	if(value < this->data){
		if(this->left != NULL){
			if(this->left->data == value && this->left->left == NULL && this->left->right == NULL){
				delete this->left;
				this->left = NULL;
				return;
			}
			this->left->deleteNode(value);
		}else{
			std::cout << "Node cannot be found. Deletion cannot be performed" << std::endl;
		}
	}else if (value > this->data){
		if(this->right !=NULL){
			if(this->right->data == value && this->right->left == NULL && this->right->right == NULL){
				delete this->right;
				this->right = NULL;
				return;
			}
			this->right->deleteNode(value);
		}else{
			std::cout << "Node cannot be found. Deletion cannot be performed" << std::endl;
		}
	}else{
		std::cout << "we have a problem";
	}
}

int node::startCopyRight(){
	if(this->right->left == NULL){
		return this->right->data;
	}else{
		return this->right->copyLeft();
	}
}

int node::copyLeft(){
	if(this->left->left == NULL){
		return this->left->data;
	}else{
		return this->left->copyLeft();
	}
}

void node::startDeleteRight(){
	if(this->right->left == NULL && this->right->right == NULL){
		delete this->right;
		this->right = NULL;
	}else if(this->right->left == NULL){
		//copy children
		node* node1;
		node1 = new node(0);

		node1 = this->right->right;
		delete this->right;
		this->right = node1;
		//std::cout << "Made it here" << std::endl;
	}else{
		this->right->deleteLeft();
	}
	return;
}

void node::deleteLeft(){
	if(this->left->left == NULL && this->right->right == NULL){
		delete this->left;
		this->left = NULL;
	}else if(this->left->left == NULL){
		//copy children
		node* node2;
		node2 = new node(0);

		node2 = this->left->right;
		delete this->left;
		this->left = node2;
		//std::cout << "Made it here again" << std::endl;
	}else{
		this->left->deleteLeft();
	}
}

bool node::checkNull(){
	if(this->left == NULL && this->right == NULL){
		return true;
	}else{
		return false;
	}
}
