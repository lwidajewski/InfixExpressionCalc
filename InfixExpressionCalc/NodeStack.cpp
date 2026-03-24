#include <iostream>

#include "NodeStack.h"

using namespace std;

// constructor
NodeStack::NodeStack() {
	top = nullptr;
};


// observers
Node* NodeStack::peek() {
	if (isEmpty) {
		return nullptr;
	}
	else {
		return top;
	}
};

bool NodeStack::isEmpty() {
	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	};
};


// modifiers
void NodeStack::push(Node* x) {
	x->next = top;
	top = x;
};

Node* NodeStack::pop() {
	if (isEmpty()) {
		cout << "Node stack empty" << endl;
		return nullptr;
	}
	else {
		Node* temp = top;
		top = top->next;
		temp->next = nullptr; // disconnect it from the stack
		return temp; // returns what was the top value (makes it so I don't have to call peek then pop multiple times)
	};
};


// destructor
NodeStack::~NodeStack() {
	while (!isEmpty()) {
		Node* temp = top;
		top = top->next;
		delete temp;
	};
};