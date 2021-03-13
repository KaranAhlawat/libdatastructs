#include <iostream>
#include "BinarySearchTree.h"

template<typename T>
void BST<T>::insertNode(T element)
{
	if (root == nullptr)
	{
		root = createNode(element);
		return;
		node_count++;
	}
	Node* temp = root;
	Node* tail = nullptr;
	while (temp != nullptr)
	{
		tail = temp;
		if (element < temp->data)
		{
			temp = temp->lchild;
		}
		else if (element > temp->data)
		{
			temp = temp->rchild;
		}
		else
			return;
	}

	if (element > tail->data)
	{
		tail->rchild = createNode(element);
		node_count++;
	}
	else
	{
		tail->lchild = createNode(element);
		node_count++;
	}
}

template<typename T>
bool BST<T>::search(T key)
{
	Node* temp = root;
	if (root == nullptr)
	{
		return false;
	}
	while (temp != nullptr)
	{
		if (temp->data == key)
			return true;
		else if (temp->data > key)
			temp = temp->lchild;
		else
			temp = temp->rchild;
	}
	return false;
}

template<typename T>
typename BST<T>::Node* BST<T>::getRoot()
{
	return root;
}

template<typename T>
typename BST<T>::Node* BST<T>::inSucc(Node* node)
{
	Node* temp = node;
	while (temp && temp->lchild != nullptr)
	{
		temp = temp->lchild;
	}
	return temp;
}

template<typename T>
typename BST<T>::Node* BST<T>::inPre(Node* node)
{
	Node* temp = node;
	while (temp && temp->rchild != nullptr)
	{
		temp = temp->rchild;
	}
	return temp;
}

template<typename T>
int BST<T>::height(Node* node)
{
	int x, y;
	if (node == nullptr)
		return 0;
	x = height(node->lchild);
	y = height(node->rchild);
	return x > y ? x + 1 : y + 1;
}

template<typename T>
typename BST<T>::Node* BST<T>::deleteNode(T key, Node* p)
{
	Node* temp = nullptr;
	if (!search(key))
	{
		std::cout << "Key not found in tree. " << std::endl;
		return nullptr;
	}
	if (p == nullptr)
	{
		return nullptr;
	}
	if (p->lchild == nullptr && p->rchild == nullptr)
	{
		if (p == root)
			root = nullptr;
		delete p;
		return nullptr;
	}

	if (key < p->data)
	{
		p->lchild = deleteNode(key, p->lchild);
	}
	else if (key > p->data)
	{
		p->rchild = deleteNode(key, p->rchild);
	}
	else
	{
		if (height(p->lchild) > height(p->rchild))
		{
			temp = inPre(p->lchild);
			p->data = temp->data;
			p->lchild = deleteNode(temp->data, p->lchild);
		}
		else
		{

			temp = inSucc(p->rchild);
			p->data = temp->data;
			p->rchild = deleteNode(temp->data, p->rchild);
		}
	}
	return p; 
}

template<typename T>
void BST<T>::inorder(Node* p)
{
	if (p)
	{
		inorder(p->lchild);
		std::cout << p->data << " ";
		inorder(p->rchild);
	}
}
