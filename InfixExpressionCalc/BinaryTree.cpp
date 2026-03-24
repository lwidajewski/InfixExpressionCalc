#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace std;

// data stored in each node
struct BinaryTree::Node {
	string data;
	Node* left;
	Node* right;
};


// constructor
BinaryTree::BinaryTree() {
	root = nullptr;
};


// observers
bool BinaryTree::isEmpty() {
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	};
};

// prints the tree in postfix order using recursion
void BinaryTree::printTreePost() {
	if (isEmpty()) {
		cout << "Tree Empty!" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	};
};
void BinaryTree::printTreePost(Node* curr) {
	if (curr == nullptr) {
		return;
	}
	else {
		printTreePost(curr->left);
		printTreePost(curr->right);
		cout << curr->data << " ";
	};
};

// prints the tree in prefix order using recursion
void BinaryTree::printTreePre() {
	if (isEmpty()) {
		cout << "Tree Empty!" << endl;
	}
	else {
		printTreePre(root);
		cout << endl;
	};
};
void BinaryTree::printTreePre(Node* curr) {
	if (curr == nullptr) {
		return;
	}
	else {
		cout << curr->data << " ";
		printTreePre(curr->left);
		printTreePre(curr->right);
	};
};


// modifiers
void BinaryTree::buildTree(string infix) {
	// to hold infixToPostfix conversion string --> this could probably be updated to be dynamic but for now this is plenty of space
	string postfix[100];
	int size;

	infixToPostfix(infix, postfix, size);

	int index = size - 1;
	root = buildTreeFromPostfix(postfix, index);
}

BinaryTree::Node* BinaryTree::buildTreeFromPostfix(string postfix[], int& index) {
	if (index < 0) {
		return nullptr;
	}
	else {
		Node* node = new Node;
		node->data = postfix[index];
		node->left = nullptr;
		node->right = nullptr;

		index--;

		if (isOperator(node->data)) {
			node->right = buildTreeFromPostfix(postfix, index);
			node->left = buildTreeFromPostfix(postfix, index);
		}

		return node;
	};
};

void BinaryTree::deleteNode(string x) {

};


// calculation related functions
// Goes through the tree and calculates everything
int BinaryTree::calcTree(Node* curr) {
	if (curr == nullptr) {
		return 0;
	}
	else {
		if (!isOperator(curr->data)) {
			return stoi(curr->data); // convert data to an integer
		}

		int left = calcTree(curr->left);
		int right = calcTree(curr->right);

		if (curr->data == "+") return left + right;
		if (curr->data == "-") return left - right;
		if (curr->data == "*") return left * right;
		if (curr->data == "/") return left / right;

		return 0;
	}
};

bool BinaryTree::isOperator(string x) {
	if (x == "+" || x == "-" || x == "*" || x == "/") {
		return true;
	}
	else {
		return false;
	};
};

// used by infixToPostfix function | makes it so multiplicatin or division come before addition or subtraction (unless there are parentheses)
int BinaryTree::precedence(char x) {
	if (x == '+' || x == '-') {
		return 1;
	}
	else if (x == '*' || x == '/') {
		return 2;
	}
	else {
		return 0;
	};
};

// take the user string 'infix' fromt their input and convert to postfix to put the expression into the tree
void BinaryTree::infixToPostfix(string infix, string postfix[], int& size) {
	size = 0;

	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		// skip whitespace
		if (c == ' ') {
			continue;
		}
		// if it's a digit add it to the string
		if (isdigit(c)) {
			string digit = "";
			
			// check for multi-digit numbers
			while (i < infix.length() && isdigit(infix[i])) {
				digit += infix[i];
				i++;
			};

			postfix[size++] = digit;
			i--; // decrement for later since the for loop would increment it and that would skip over an index
		}
		// if it's a '(' push it to the stack
		else if (c == '(') {
			charStack.push(c);
		}
		// if it's a ')' pop until you find '(' and then remove '('
		else if (c == ')') {
			while (charStack.peek() != '(') {
				// basically goes through adding operators onto the postfix expression until you find '('
				postfix[size++] = string(1, charStack.peek());
				charStack.pop();
			}
			charStack.pop();
		}
		// operator: +, -, *, /
		else {
			while (!charStack.isEmpty() && precedence(c) <= precedence(charStack.peek())) {
				postfix[size++] = string(1,charStack.peek());
				charStack.pop();
			};
			charStack.push(c);
		};
	};
	// pop remaining elements off stack and into string
	while (!charStack.isEmpty()) {
		postfix[size++] = string(1, charStack.peek());
		charStack.pop();
	};
};






// destructor
BinaryTree::~BinaryTree() {
	
};
