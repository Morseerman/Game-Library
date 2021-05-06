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

    List() {};

    List(const List<T>& n) {
        head = n.head;
        tail = n.tail;
    }

    List(const T& n) {
        Node<T>* temp = new Node<T>(n);
        temp->next = head;
        head = temp;
    }


    bool List<T>::isEmpty() const {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    List<T>& operator = (const List<T>& n) {

        head = other.head;
        tail = other.tail;
    }

    bool operator == (const List<T>& n) const {
        if (head == n.head && tail == n.tail) {
            return true;
        }
        else {
            return false;
        }
    }

    void addInFront(const T& n) {
        Node<T>* temp = new Node<T>(n);
        if (head != NULL) {
            temp->next = head;
            head = temp;
        }
        else {
            return;
        }

    }

    T first() const {
        if (head != NULL) {
            return head->item;

        }
    }

    T last() const {
        if (head != NULL) {
            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            return temp->item;
        }
    }

    void deleteFirst() {
        if (head != NULL) {
            Node<T>* temp;
            temp = head;
            head = head->next;
        }
    }

    void deleteOne(const T& n) {

    }

    void addAtEnd(const T& n) {
        Node<T>* temp = new Node<T>(n);

        if (head == NULL) {
            head = new Node<T>(n);
            return;
        }

        temp->next = NULL;

        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = temp;
        return;

    }

    int length() const {
        Node<T>* temp;
        temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node<T>* temp;
        temp = head;
        int counter = 1;
        while (temp != NULL) {
            std::cout << counter << ": " << temp->item << std::endl;
            counter++;
            temp = temp->next;
        }
    }
  


    bool contains(const T& n) const {
        Node<T>* temp;
        temp = head;
        while (temp != NULL) {
            if (temp->item == n) {
                return true;
            } 
            if (temp == NULL) {
                return false;
            }
            temp = temp->next;
        }

    }    

private:
    Node<T>* head = nullptr;                           // point onto first item (nullptr if empty)
    Node<T>* tail = nullptr;
    Node<T>* end() const;                    // return address of last item (nullptr if empty)
    void destroy();                          // delete all items in list
    void copy(const List<T>&);               // make a deep copy of the list
};

