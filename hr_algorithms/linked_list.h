///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT 2017
// Nam Ly, Pullman, WA
//
// Linked list for any data type
///////////////////////////////////////////////////////////////////////////////

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>
#include <memory>

///////////////////////////////////////////////////////////////////////////////
// Implement a Node of a linked list
//
///////////////////////////////////////////////////////////////////////////////
template <class DataType>
class linked_list;

template <class DataType>
class Node
{
	friend class linked_list<DataType>;
public:
	///////////////////////////////////////////////////////////////////////////
	// Constructor
	///////////////////////////////////////////////////////////////////////////
	Node(DataType dataIn)
	{
		data = dataIn;
		next_ptr = nullptr;
	}

	///////////////////////////////////////////////////////////////////////////
	// Destructor
	///////////////////////////////////////////////////////////////////////////
	virtual ~Node()
	{}
private:
	DataType data;
	Node *next_ptr;
};


///////////////////////////////////////////////////////////////////////////////
// linked list interfaces
//   
///////////////////////////////////////////////////////////////////////////////
template <typename DataType>
class linked_list
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Constructor
	///////////////////////////////////////////////////////////////////////////
	linked_list() : m_start_ptr(nullptr), m_end_ptr(nullptr)
	{}

	///////////////////////////////////////////////////////////////////////////
	// Destructor
	///////////////////////////////////////////////////////////////////////////
	virtual ~linked_list()
	{
		delete_all();
	}

	///////////////////////////////////////////////////////////////////////////
	// Insert a node at the begin of a linked list
	//
	// @param[in] new_node a new Node to be inserted
	//
	// @remarks the linked list start pointer node is updated to point to the 
	//  new node
	///////////////////////////////////////////////////////////////////////////
	void insert_begin(const DataType data_in)
	{
		Node<DataType> *new_ptr = new Node<DataType>(data_in);

		// List is empty, insert first node to the list
		if (is_empty())
		{
			m_start_ptr = new_ptr;
			m_end_ptr = new_ptr;
		}
		else
		{
			new_ptr->next_ptr = m_start_ptr;
			m_start_ptr = new_ptr;
		}
	}

	///////////////////////////////////////////////////////////////////////////
	// Insert a node at the end of a linked list
	//
	// @param[in] new_node a new Node to be inserted
	//
	// @remarks the linked list end pointer node is updated to point to the new 
	//  node
	///////////////////////////////////////////////////////////////////////////
	void insert_end(const DataType data_in)
	{
		Node<DataType> *new_ptr = new Node<DataType>(data_in);

		// List is empty, insert first node to the list
		if (is_empty())
		{
			m_start_ptr = new_ptr;
			m_end_ptr = new_ptr;
		}
		else
		{
			m_end_ptr->next_ptr = new_ptr;
			m_end_ptr = new_ptr;
		}
	}

	///////////////////////////////////////////////////////////////////////////
	// Delete a node at the begin of a linked list
	//
	// @remarks the linked list start pointer node is updated to point to the 
	//  next node
	///////////////////////////////////////////////////////////////////////////
	void delete_begin(void)
	{
		if (!is_empty())
		{
			Node<DataType> *temp_ptr = m_start_ptr->next_ptr;
			delete m_start_ptr;
			m_start_ptr = temp_ptr;
		}
	}

	///////////////////////////////////////////////////////////////////////////
	// Delete a node at the end of a linked list
	//
	// @remarks the linked list end pointer node is updated to point to the 
	//  next node
	///////////////////////////////////////////////////////////////////////////
	void delete_end(void)
	{
		Node<DataType> *temp_ptr = m_start_ptr;
		while (temp_ptr && (temp_ptr->next_ptr != m_end_ptr))
		{
			temp_ptr = temp_ptr->next_ptr;
		}
		delete m_end_ptr;
		m_end_ptr = temp_ptr;
		m_end_ptr->next_ptr = nullptr;
	}

	///////////////////////////////////////////////////////////////////////////
	// Delete linked list and data of each node
	//
	///////////////////////////////////////////////////////////////////////////
	void delete_all(void)
	{
		while (m_start_ptr)
		{
			delete_begin();
		}
		m_start_ptr = nullptr;
		m_end_ptr = nullptr;
	}

	///////////////////////////////////////////////////////////////////////////
	// Print all data of a linked list
	//
	///////////////////////////////////////////////////////////////////////////
	void print_all(void)
	{
		Node<DataType> *temp_ptr = m_start_ptr;
		while (temp_ptr)
		{
			std::cout << temp_ptr->data << std::endl;
			temp_ptr = temp_ptr->next_ptr;
		}
	}

	///////////////////////////////////////////////////////////////////////////
	// Calculate size of a linked list
	//
	// @return size of linked list
	///////////////////////////////////////////////////////////////////////////
	unsigned int size(void)
	{
		Node<DataType> *temp_ptr = m_start_ptr;
		unsigned int count = 0;
		while (temp_ptr)
		{
			count++;
			temp_ptr = temp_ptr->next_ptr;
		}
		return count;
	}

	///////////////////////////////////////////////////////////////////////////
	// Remove duplicate nodes of a linked list
	///////////////////////////////////////////////////////////////////////////
	void remove_duplicates(void)
	{
		Node<DataType> *cur_ptr = m_start_ptr;
		while (cur_ptr)
		{
			Node<DataType> *runner_ptr = cur_ptr;
			while (runner_ptr->next_ptr)
			{
				if (runner_ptr->next_ptr->data == cur_ptr->data)
				{
					Node<DataType> *temp_ptr = runner_ptr->next_ptr->next_ptr;
					delete runner_ptr->next_ptr;
					runner_ptr->next_ptr = temp_ptr;
				}
				else
				{
					runner_ptr = runner_ptr->next_ptr;
				}
			}
			cur_ptr = cur_ptr->next_ptr;
		}
	}

	///////////////////////////////////////////////////////////////////////////
	// Return kth from last of a linked list
	///////////////////////////////////////////////////////////////////////////
	DataType get_kth_from_last_node(const unsigned int k)
	{
		Node<DataType> *fast_ptr = m_start_ptr;
		Node<DataType> *slow_ptr = m_start_ptr;
		
		// Let fast pointer advance k nodes
		for (unsigned int i = 0; i < k; i++)
		{
			if (!fast_ptr)
			{
				return NULL;
			}
			fast_ptr = fast_ptr->next_ptr;
		}

		// Let slow pointer move k nodes after fast pointer
		while (fast_ptr)
		{
			fast_ptr = fast_ptr->next_ptr;
			slow_ptr = slow_ptr->next_ptr;
		}
		return slow_ptr->data;
	}

	///////////////////////////////////////////////////////////////////////////
	// Partition a list around a value
	///////////////////////////////////////////////////////////////////////////
	void partition_list(const DataType pivot,
		std::shared_ptr<linked_list<DataType>> partitioned_list)
	{
		Node<DataType> *runner_ptr = m_start_ptr;
		while (runner_ptr)
		{
			if (runner_ptr->data < pivot)
			{
				partitioned_list->insert_begin(runner_ptr->data);
			}
			else
			{
				partitioned_list->insert_end(runner_ptr->data);
			}
			runner_ptr = runner_ptr->next_ptr;
		}
	}

private:
	/// Pointer points to the 1st node of a linked list
	Node<DataType> *m_start_ptr;

	/// Pointer points to the last node of a linked list
	Node<DataType> *m_end_ptr;

	///////////////////////////////////////////////////////////////////////////
	// Check if linked list is empty
	//
	// @return True if list is empty, False otherwise
	///////////////////////////////////////////////////////////////////////////
	bool is_empty()
	{
		return (m_start_ptr == nullptr);
	}
};

#endif 