#include "Header.h"
#include <iostream>


listd::NodeList::Node::Node(int value) {
	this->value = value;
	this->next = nullptr;
}

listd::NodeList::Node::~Node()
{
	delete next;
}

void listd::NodeList::create_random_list(NodeList list_of_lists,int n)
{
	int v = rand() % 1000 + 1;
	Node* z = new Node(v);
	head = z;
	tail = head;
	int i = 1;
	while (i < 100) {
		Node* temp = new Node(rand() % 1000 + 1);
		tail->next = temp;
		tail = temp;
		i++;
	}
	print_out_list();
	create_list_of_lists(list_of_lists,n);
}



bool listd::NodeList::look_for_node(int n)
{
	int value = 0;
	std::cout << "What value do you want to look for? ";
	std::cin >> value;

	Node* node = new Node(value);
	int num = sum_numbers(node, n);

	if (arr[num].head != nullptr) {
		Node* temp = arr[num].head;
		while (temp != nullptr) {
			if (temp->value == node->value) {
				std::cout << "Such value exists";
				delete node;
				return true;
			}
			else temp = temp->next;
		}
	}
	std::cout << "Such value doesnt exist";
	delete node;
	return false;
	
}

int listd::NodeList::sum_numbers(Node* k,int n)
{
	int sum = 0;
	int temp_value = k->value;

	while (temp_value > 9) {
		sum += temp_value % 10;
		temp_value /= 10;
	}
	sum += temp_value;
	return sum%n;
}

void listd::NodeList::add_node(int value)
{
	Node* temp = new Node(value);
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}

	return;
}

void listd::NodeList::print_out_list_of_lists(int n)
{
	for (int i = 0; i < n; i++) {
		if (arr[i].head == nullptr)
			continue;
		std::cout << i << ": ";
		arr[i].print_out_list();
		std::cout << '\n';
	}
}
void listd::NodeList::create_list_of_lists(NodeList list_of_lists,int n)
{
	
	Node* temp = head;
	
	list_of_lists.arr = new NodeList[100];
	
	while (true) {
		
		int temp_num =sum_numbers(temp,n);
		list_of_lists.arr[temp_num].add_node(temp->value);
		if (temp == tail)
			break;
		temp = temp->next;
	}
	std::cout << '\n';
	list_of_lists.print_out_list_of_lists(n);
	list_of_lists.look_for_node(n);

}

void listd::NodeList::print_out_list() {
	Node* temp = head;
	while (true) {
		std::cout << temp->value<<"  ";
		if (temp == tail)
			return;
		temp = temp->next;
	}
}
