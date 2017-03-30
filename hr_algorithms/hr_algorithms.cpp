///////////////////////////////////////////////////////////////////////////////
// Solve Cracking the code interview
//
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "linked_list.h"
#include <memory>

///////////////////////////////////////////////////////////////////////////////
// Chapter 2: linked list
//   
///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<linked_list<int>> single_list;
void construct_linked_list(void)
{
	single_list.reset(new linked_list<int>);
	// Construct a linked list
	single_list->insert_begin(10);
	single_list->insert_begin(10);
	single_list->insert_begin(1);
	single_list->insert_begin(5);
	single_list->insert_begin(80);
	single_list->insert_begin(120);
	single_list->insert_begin(9);
	single_list->insert_begin(7);
	single_list->insert_begin(10);
	single_list->insert_begin(7);
	single_list->insert_begin(20);
	single_list->insert_begin(200);
}

void prob_2_1_remove_duplicate(void)
{
	construct_linked_list();
	std::cout << "Original list" << std::endl;
	single_list->print_all();
	
	// Remove duplicates
	single_list->remove_duplicates();
	std::cout << "Shortened list" << std::endl;
	single_list->print_all();
}

void prob_2_2_return_kth_item(void)
{
	construct_linked_list();
	std::cout << "Original list" << std::endl;
	single_list->print_all();

	// 3rd item from last
	std::cout << "3rd item from last " << (int)single_list->get_kth_from_last_node(3) << std::endl;

}
int main()
{
	prob_2_1_remove_duplicate();
	prob_2_2_return_kth_item();
    return 1;
}

