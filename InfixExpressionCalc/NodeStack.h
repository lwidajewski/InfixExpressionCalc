#ifndef NODESTACK_H
#define NODESTACK_H

#include <string>

#include "BinaryTree.h"

class NodeStack {
	private:
		BinaryTree::Node* top;
	public:
		// constructor
		NodeStack();

		// observers
		Node* peek();
		bool isEmpty();

		// modifiers
		void push(Node* x);
		Node* pop();

		// destructor
		~NodeStack();
};

#endif