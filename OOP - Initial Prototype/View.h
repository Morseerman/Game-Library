//-------------------------------------------------
// List and Node: using singly linked list of Nodes
//-------------------------------------------------

#pragma once

#include <assert.h> // for assert

//------------------------------------------------------------------------------
// Node
//
//   T is the type parameter, it is the type that will be stored in the Node.
//
//   This is stored in the same file as List because List directly accesses its
//   private attributes. It could be rewritten using public functions to access
//   private data, using a nested class, or by making Node a "friend" of List.
//
//   This is fine for this implementation though!
//
//------------------------------------------------------------------------------

template <class T>
class Node
{
public:
    Node(const T& item); // Node constructor
    T item;              // the data item in the node
    Node<T>* next;       // pointer to the next node (initialised to nullptr)
};

// Node implementation
// -------------------
template <class T>
Node<T>::Node(const T& item) : item(item), next(nullptr)
{
}

//-----------------------------------------------------------------------------
// List
//
//   T is the type parameter, it is the type that will be managed by the List.
//
//-----------------------------------------------------------------------------

template <class T>
class List
{
public:
    void deleteOne(const T&);                // delete first occurrence of item
};

