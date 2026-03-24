#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

#include "CharStack.h"

class BinaryTree {
	private:
		struct Node;
		Node* root;
		CharStack charStack;
	public:
		// constructor
		BinaryTree();

		// observers
		bool isEmpty();
		void printTreePost();
		void printTreePost(Node* curr);
		void printTreePre();
		void printTreePre(Node* curr);

		// modifiers
		void buildTree(std::string infix);
		Node* buildTreeFromPostfix(std::string postfix[], int& index);
		
		// calculator related functions
		bool isOperator(std::string x);
		int precedence(char x);
		void infixToPostfix(std::string infix, std::string postfix[], int& size);
		int calcTree(Node* curr);
		int evaluate();

		// destructor
		~BinaryTree();
		void deleteTree(Node* curr);
};

#endif