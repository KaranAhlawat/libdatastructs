#pragma once

template<typename T>
class BST
{
private:
	struct Node
	{
		T data = T();
		Node* lchild = nullptr;
		Node* rchild = nullptr;
	};
	Node* root = nullptr;
	int node_count = 0;

	Node* createNode(T& element)
	{
		Node* temp = new Node;
		temp->data = element;
		temp->lchild = temp->rchild = nullptr;
		return temp;
	}
	 Node* inSucc(Node* node);
	 Node* inPre(Node* node);

public:
	void insertNode(T element);
	Node* deleteNode(T key, Node* p);
	bool search(T key);
	int height(Node* node);
	void inorder(Node* p);
	Node* getRoot();
	
};

