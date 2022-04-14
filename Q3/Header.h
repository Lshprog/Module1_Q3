#pragma once
namespace listd {
	struct NodeList {
	private:
		listd::NodeList* arr;
		struct Node {
			Node* next;
			int value;
			Node(int value);
			~Node();
		};
		Node* head = nullptr;
		Node* tail = nullptr;

	public:

		void add_node(int value);
		void print_out_list_of_lists(int n);
		int sum_numbers(Node* k, int n);
		void create_random_list(NodeList list_of_lists,int n);
		bool look_for_node(int n);
		void create_list_of_lists(NodeList list_of_lists,int n);
		void print_out_list();

	};
}