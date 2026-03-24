#include <iostream>

#include "CharStack.h"

using namespace std;


CharStack::CharStack() {
	top = nullptr;
};

bool CharStack::isEmpty() {
	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	};
};

char CharStack::peek() {
	if (top == nullptr) {
		return '\0';
	}
	else {
		return top->data;
	};
};

void CharStack::push(char x) {
	Node* temp = new Node;
	temp->data = x;
	temp->next = top;
	top = temp;
};

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

CharStack::~CharStack() {
	while (!isEmpty()) {
		Node* temp = top;
		top = top->next;
		delete temp;
	};
};