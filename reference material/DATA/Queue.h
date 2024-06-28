#pragma once
////////////////////////////////////////////////////////////////////   Node   ////////////////////////////////////////////////////////////////////////////
struct nodes {
	nodes* next;
	int data;

	// Default Constructor
	nodes() {
		this->next = NULL;
		this->data = 0;
	}

	// Parametrized Constructor
	nodes(int data) {
		this->next = NULL;
		this->data = data;
	}

	// Setters
	void SetData(int data) {
		this->data = data;
	}

	void SetNext(nodes* next) {
		this->next = next;
	}

	// Getters
	int GetData() {
		return this->data;
	}

	nodes* GetNext() {
		return this->next;
	}
};


///////////////////////////////////////////////////////////////   Queue   ////////////////////////////////////////////////////////////////////////////
class Queue {
	nodes* front;
	nodes* rear;

public:
	// Default Constructor
	Queue() {
		this->front = NULL;
		this->rear = NULL;
	}

	// To check if the Linked List is empty is or not.
	bool isEmpty() {
		if (this->front == NULL)
			return true;

		return false;
	}



	// To insert the node.
	bool Enqueue(int data) {
		nodes* NodeToInsert = new nodes(data);

		if (front == NULL && rear == NULL) {
			front = rear = NodeToInsert;
		}

		else {
			rear->next = NodeToInsert;
			rear = NodeToInsert;
		}

		return true;
	}


	// To delete the node.
	int Dequeue() {
		double n;
		nodes* temp = front;
		front = front->next;
		n = temp->data;
		delete temp;
		if (front == NULL)
			rear = NULL;
		return n;
	}

	// Destructor
	~Queue() {
		nodes* temp = front;

		while (temp != NULL) {
			front = front->next;
			delete temp;
			temp = front;
		}
	}

};