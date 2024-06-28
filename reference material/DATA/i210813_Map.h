
#pragma once
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////   Node   ////////////////////////////////////////////////////////////////////////////
struct Node {
	Node* next;
	string data;

	// Default Constructor
	Node() {
		this->next = NULL;
		this->data = "";
	}

	// Parametrized Constructor
	Node(string data) {
		this->next = NULL;
		this->data = data;
	}

	// Setters
	void SetData(string data) {
		this->data = data;
	}

	void SetNext(Node* next) {
		this->next = next;
	}

	// Getters
	string GetData() {
		return this->data;
	}

	Node* GetNext() {
		return this->next;
	}
};



///////////////////////////////////////////////////////////////   Linked List   ////////////////////////////////////////////////////////////////////////////
class SingleLinkedList {
	Node* head;

public:
	// Default Constructor
	SingleLinkedList() {
		this->head = NULL;
	}

	// To check if the Linked List is empty is or not.
	bool isEmpty() {
		if (this->head == NULL)
			return true;

		return false;
	}

	// Getters
	Node* GetHead() {
		return this->head;
	}

	void SetHead(Node* head) {
		this->head = head;
	}

	// For printing all the values of the node.
	void Traverse() {
		Node* trav = head;

		cout << "\n\n\n\n";
		while (trav != NULL) {
			cout << "|" << trav->data << "| -> ";
			trav = trav->next;
		}
		cout << "|NULL|" << endl;
		cout << "\n\n\n\n";
	}

	// Gives the number of attached nodes.
	int No_of_Nodes() {
		Node* trav = head;
		int count = 0;

		while (trav != NULL) {
			count++;
			trav = trav->next;
		}
		return count;
	}

	// To update the value at the certain index.
	bool Update(string data, int index) {

		Node* ptr = head;
		for (int i = 0; i < index; i++) {
			ptr = ptr->next;
		}
		ptr->data = data;

		return true;
	}

	// To Check if the passed data is present is in the list or not.
	int Search(string data) {

		if (isEmpty() == 0) {
			Node* ptr = head;
			int index = 0;

			while (ptr != NULL) {
				if (ptr->data == data)
					return index;

				index++;
				ptr = ptr->next;
			}
		}
		return -1;
	}

	// Search for the city in the list with the help of provided index.
	string City(int index) {
		Node* trav = head;
		for (int i = 0; i < index; i++) {
			trav = trav->next;
		}
		return trav->data;
	}

	// To insert the node at the starting position.
	bool InsertAtStart(string data) {

		Node* NodeToInsert = new Node(data);
		if (head == NULL) {
			head = NodeToInsert;
			return true;
		}
		NodeToInsert->next = head;
		head = NodeToInsert;

		return true;
	}

	// To insert the node at a specified index.
	bool InsertAtIndex(string data, int index = 0) {

		if (index == 0)
			InsertAtStart(data);

		else {
			Node* trav = head;
			for (int i = 0; i < (index - 1); i++) {
				trav = trav->next;
			}

			Node* NodeToInsert = new Node(data);

			NodeToInsert->next = trav->next;
			trav->next = NodeToInsert;
		}

		return true;
	}

	// To insert the node at the Last position.
	bool InsertAtEnd(string data) {

		if (head == NULL) {
			InsertAtStart(data);
			return true;
		}

		Node* ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}

		Node* NodeToInsert = new Node(data);
		ptr->next = NodeToInsert;

		return true;
	}

	// To Delete the Starting Node.
	string DeleteAtStart() {
		Node* temp = head;
		head = head->next;
		string n = temp->data;
		delete temp;

		return n;
	}


	// To Delte the node at the specified index.
	bool Delete(int index = 0) {

		if (index == 0)
			DeleteAtStart();

		else {
			Node* prev = head;
			Node* curr = head;

			for (int i = 0; i < index; i++) {
				prev = curr;
				curr = curr->next;
			}

			prev->next = curr->next;
			delete curr;
		}

		return true;
	}

	// To delete the last node.
	bool DeleteAtEnd() {

		Node* curr = head;
		Node* prev = head;

		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}

		// curr will be at the last node.
		prev->next = NULL;
		delete curr;

		return true;
	}

	// To find the middle Node.
	Node* FindMid() {
		Node* fast = head;
		Node* slow = head;

		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}

	// To Reverse a Linked List
	bool Reverse() {
		Node* curr = head;
		Node* prev = NULL;

		while (curr != NULL) {
			Node* nextptr = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextptr;
		}

		head = prev;

		return true;
	}

	// Destructor
	~SingleLinkedList() {
		Node* temp = head;

		while (temp != NULL) {
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};
