
struct node {
	node* next;
	int data;

	// Parametrized Constructor
	node(int data = 0) {
		this->next = NULL;
		this->data = data;
	}
};

class Stack {
	node* top;

public:
	// Default Constructor
	Stack() {
		this->top = NULL;
	}

	// To check if the Linked List is empty is or not.
	bool isEmpty() {
		if (this->top == NULL)
			return true;

		return false;
	}

	// Based on LIFO
	bool push(int data) {
		node* NodeToInsert = new node(data);
		NodeToInsert->next = top;
		top = NodeToInsert;

		return true;
	}

	// To Delete the Starting Node.
	int pop() {

		int n = 0;
		node* temp = top;
		n = top->data;
		top = top->next;
		delete temp;

		return n;
	}

	// Destructor
	~Stack() {
		node* temp = top;

		while (temp != NULL) {
			top = top->next;
			delete temp;
			temp = top;
		}
	}
};