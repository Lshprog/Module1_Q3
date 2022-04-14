#include <iostream>
#include "Header.h"

int main() {
	listd::NodeList startlist = listd::NodeList();
	listd::NodeList list_of_lists = listd::NodeList();
	int n;
	std::cout << "Enter N: ";
	std::cin >> n;
	std::cout << '\n';
	startlist.create_random_list(list_of_lists,n);
	
}