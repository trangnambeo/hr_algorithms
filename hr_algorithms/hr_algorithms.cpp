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



	std::cout << "Original list" << std::endl;
	single_list->print_all();
}

void prob_2_1_remove_duplicate(void)
{
	std::cout << "Problem 2.1: remove duplicates from a linked list" << std::endl;
	construct_linked_list();
	
	// Remove duplicates
	single_list->remove_duplicates();
	std::cout << "Shortened list" << std::endl;
	single_list->print_all();
}

void prob_2_2_return_kth_item(void)
{
	std::cout << "Problem 2.1: return kth item from last of a linked list" << std::endl;
	construct_linked_list();

	// 3rd item from last
	std::cout << "3rd item from last " << (int)single_list->get_kth_from_last_node(3) << std::endl;

}

void prob_2_4_partition(void)
{
	std::cout << "Problem 2.4: partition a linked list" << std::endl;
	construct_linked_list();
	
	std::shared_ptr<linked_list<int>> partitioned_list(new linked_list<int>);
	single_list->partition_list(40, partitioned_list);

	std::cout << "Partitioned list" << std::endl;
	partitioned_list->print_all();
}

void prob_2_5_sum_list(void)
{
	std::shared_ptr<linked_list<int>> first_number(new linked_list<int>);
	first_number->insert_begin(7);
	first_number->insert_begin(1);
	first_number->insert_begin(6);
	
	std::shared_ptr<linked_list<int>> second_number(new linked_list<int>);
	second_number->insert_begin(5);
	second_number->insert_begin(9);
	second_number->insert_begin(2);
	second_number->insert_begin(9);
	second_number->insert_begin(8);

	std::shared_ptr<linked_list<int>> result_number(new linked_list<int>);
	
	Node<int> *first_ptr = first_number->get_head();
	Node<int> *second_ptr = second_number->get_head();
	int carrier = 0;
	int sum = 0;

	// Go through 2 lists, stop at shorter one
	while (first_ptr && second_ptr)
	{
		sum = first_ptr->data + second_ptr->data + carrier;
		result_number->insert_begin(sum % 10);
		carrier = sum / 10;

		first_ptr = first_ptr->next_ptr;
		second_ptr = second_ptr->next_ptr;
	}
	if (!first_ptr)
	{
		while (second_ptr)
		{
			sum = second_ptr->data + carrier;
			result_number->insert_begin(sum % 10);
			carrier = sum / 10;

			second_ptr = second_ptr->next_ptr;
		}
	}
	else if (!second_ptr)
	{
		while (first_ptr)
		{
			sum = first_ptr->data + carrier;
			result_number->insert_begin(sum % 10);
			carrier = sum / 10;

			first_ptr = first_ptr->next_ptr;
		}
	}

	if (carrier)
	{
		result_number->insert_begin(carrier);
	}
	std::cout << "Result is: " << std::endl;
	result_number->print_all();
}

void check_exit(void)
{
	char c;
	while (1)
	{
		std::cin >> c;
		if (c = 'q')
			break;
	}
}
int main()
{
	prob_2_1_remove_duplicate();

	prob_2_2_return_kth_item();

	prob_2_4_partition();
	
	prob_2_5_sum_list();

    return 1;
}

