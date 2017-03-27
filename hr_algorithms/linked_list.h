///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT 2017
// Nam Ly, Pullman, WA
//
// Linked list for any data type
///////////////////////////////////////////////////////////////////////////////

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>

///////////////////////////////////////////////////////////////////////////////
// Implement a Node of a linked list
//
///////////////////////////////////////////////////////////////////////////////
template <class DataType>
class Node
{
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
template <class DataType>
class linked_list
{
public:
	///////////////////////////////////////////////////////////////////////////
	// Constructor
	///////////////////////////////////////////////////////////////////////////
	linked_list();

	///////////////////////////////////////////////////////////////////////////
	// Destructor
	///////////////////////////////////////////////////////////////////////////
	virtual ~linked_list();

	///////////////////////////////////////////////////////////////////////////
	// Insert a node at the begin of a linked list
	//
	// @param[in] new_node a new Node to be inserted
	//
	// @remarks the linked list start pointer node is updated to point to the 
	//  new node
	///////////////////////////////////////////////////////////////////////////
	void insert_begin(DataType);

	///////////////////////////////////////////////////////////////////////////
	// Insert a node at the end of a linked list
	//
	// @param[in] new_node a new Node to be inserted
	//
	// @remarks the linked list end pointer node is updated to point to the new 
	//  node
	///////////////////////////////////////////////////////////////////////////
	void insert_end(DataType);

	///////////////////////////////////////////////////////////////////////////
	// Delete a node at the begin of a linked list
	//
	// @remarks the linked list start pointer node is updated to point to the 
	//  next node
	///////////////////////////////////////////////////////////////////////////
	void delete_begin();

	///////////////////////////////////////////////////////////////////////////
	// delete a node at the end of a linked list
	//
	// @remarks the linked list end pointer node is updated to point to the 
	//  next node
	///////////////////////////////////////////////////////////////////////////
	void delete_end();

	///////////////////////////////////////////////////////////////////////////
	// delete linked list and data of each node
	//
	///////////////////////////////////////////////////////////////////////////
	void delete_all();

	///////////////////////////////////////////////////////////////////////////
	// Return size of a linked list
	///////////////////////////////////////////////////////////////////////////
	void size();
	
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
	bool is_empty();
};

#endif LINKED_LIST_H
