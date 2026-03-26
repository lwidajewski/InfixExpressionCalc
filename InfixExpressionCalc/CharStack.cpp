#include <iostream>

#include "CharStack.h"

using namespace std;


struct CharStack::Node {
	char data;
	Node* next;
};

// constructor
CharStack::CharStack() {
	top = nullptr;
};

// check if stack is empty or not
bool CharStack::isEmpty() {
	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	};
};

// get the char fromt the top of the stack
char CharStack::peek() {
	if (top == nullptr) {
		return '\0';
	}
	else {
		return top->data;
	};
};

// put a char at the top of the stack
void CharStack::push(char x) {
	Node* temp = new Node;
	temp->data = x;
	temp->next = top;
	top = temp;
};

// remove a char from the top of the stack
void CharStack::pop() {
	if (isEmpty()) {
		cout << "Char stack empty" << endl;
		return;
	}
	else {
		Node* temp = top;
		top = top->next;
		delete temp;
	};
};

// destructor
CharStack::~CharStack() {
	while (!isEmpty()) {
		Node* temp = top;
		top = top->next;
		delete temp;
	};
};