#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <string>


class BinarySearchTree {
	private:
		struct Node;
		Node* root;
	public:
		// constructor
		BinarySearchTree();

		// observers
		bool isEmpty();
		void printTreePost();
		void printTreePre();
		int calcTreeIn();

		// modifiers
		void insert(std::string x);
		void deleteNode(std::string x);

		// destructor
		~BinarySearchTree();
};

#endif