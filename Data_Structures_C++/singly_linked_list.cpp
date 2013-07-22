#include <iostream>
using namespace std;

template <class T>
class SinglyLinkedList
{
public:
  SinglyLinkedList(T value_)
  {
    head = new Node(value_, NULL);
    size = 1;
  }

  void Push(T value)
  {
    // O(1)
    size++;
    if (Size() <= 0)
    {
      head = new Node(value, NULL);
    }
    else
    {
      head = new Node(value, head);
    }
  }

  T Pop()
  {
    // O(1)
    if (Size() <= 0)
    {
      cout << "ERROR: The SinglyLinkedList is empty." << endl;
      return NULL;
    }
    else
    {
      size--;
      Node *resultNode = head;
      head = head->next;
      T result = resultNode->value;
      delete(resultNode);
      return result;
    }
  }

  void Remove(T value)
  {
    // Linear Search, O(n)
    if (Size() <= 0)
    {
      cout << "ERROR: The SinglyLinkedList is empty." << endl;
    }
    else
    {
      Node *where = head;
      Node *prev = NULL;
      while (where->next != NULL && where->value != value)
      {
        prev = where;
        where = where->next;
      }
      if (where->value == value)
      {
        prev->next = where->next;
        delete(where);
        size--;
      }
    }
  }

  int Size()
  {
    // O(1)
    return size;
  }

private:
  class Node
  {
  public:
    Node(T value_, Node *next_)
    {
      value = value_;
      next = next_;
    }

    T value;
    Node *next;
  };

private:
  Node *head;
  int size;
};

int main()
{
  SinglyLinkedList<int> list = SinglyLinkedList<int>(1);
  list.Push(2);
  list.Push(3);
  list.Remove(2);
  list.Remove(4);
  cout << list.Pop() << " | " << list.Size() << endl;
  cout << list.Pop() << " | " << list.Size() << endl;
  cout << list.Pop() << " | " << list.Size() << endl;
  cout << list.Pop() << " | " << list.Size() << endl;
  return 0;
};