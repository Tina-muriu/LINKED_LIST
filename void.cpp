#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class LinkedList {
	node* head;
	node* tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void getData(int item) {
		node* newNode = new node();
		newNode->data = item;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	// Insert in between nodes
	void insertNewNode(int item) {
		node* newNode = new node();
		newNode->data = item;
		newNode->next = NULL;

		int pos;
		cout << "Enter the position where you want to insert the new node: ";
		cin >> pos;

		node* current = head;
		node* previous = NULL;

		// Search for position
		for (int i = 1; i < pos; i++) {
			previous = current;
			current = current->next;
		}

		if (current == head) {
			newNode->next = current;
			head = newNode;
		}
		else {
			previous->next = newNode;
			newNode->next = current;
		}
	}

	// Delete node at a given position
	void deleteNode() {
		int pos;
		cout << "Enter the position of the node you want to delete: ";
		cin >> pos;

		node* current = head;
		node* previous = NULL;

		// Search for position
		for (int i = 1; i < pos; i++) {
			previous = current;
			current = current->next;
		}

		if (current == head) {
			head = head->next;
			delete current;
		}
		else if (current == tail) {
			previous->next = NULL;
			tail = previous;
			delete current;
		}
		else {
			previous->next = current->next;
			delete current;
		}
	}

	// Linear search
	void linearSearch() {
		int searchKey;
		cout << "Enter a value to search: ";
		cin >> searchKey;

		node* temp = head;
		bool found = false;
		while (temp != NULL) {
			if (searchKey == temp->data) {
				cout << searchKey << " found." << endl;
				found = true;
				break;
			}
			temp = temp->next;
		}

		if (!found) {
			cout << searchKey << " was not found." << endl;
		}
	}

	void display() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " <--> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main() {
	LinkedList tina;
	int n, item;

	cout << "How many values do you want to enter? ";
	cin >> n;

	cout << "Enter the values:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> item;
		tina.getData(item);
	}

	cout << "Current Linked List: ";
	tina.display();

	cout << "Enter a new value: ";
	cin >> item;
	tina.insertNewNode(item);

	cout << "Updated Linked List: ";
	tina.display();

	tina.deleteNode();


