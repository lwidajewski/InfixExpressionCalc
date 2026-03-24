#ifndef CHARSTACK_H
#define CHARSTACK_H

struct Node {
	char data;
	Node* next;
};

class CharStack {
	private:
		Node* top;
	public:
		// constructor
		CharStack();

		// observers
		bool isEmpty();
		char peek();

		// modifiers
		void push(char x);
		void pop();

		// destructor
		~CharStack();
};

#endif