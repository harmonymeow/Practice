#include <iostream>
using namespace std;

template<class T>
class BinarySearchTree
{
public:
  BinarySearchTree()
  {
    size = 0;
    root = NULL;
  }

  void Insert(T value)
  {
    if (size <= 0)
    {
      root = new Node(value, NULL, NULL);
    }
    else
    {
      Node *where = root;
      while (true)
      {
        if (value <= where->value && where->left == NULL)
        {
          where->left  = new Node(value, NULL, NULL);
          return;
        }
        else if (value >= where-> value && where->right == NULL)
        {
          where->right = new Node(value, NULL, NULL);
          return;
        }
        else if (value <= where->value)
        {
          where = where->left;
        }
        else
        {
          where = where->right;
        }
      }
    }
  }

  int getSize()
  {
    return size;
  }

private:
  class Node
  {
  public:
    Node(T value_, Node *left_, Node *right_)
    {
      value = value_;
      left = left_;
      right = right_;
    }

    T value;
    Node *left;
    Node *right;
  };

  int size;
  Node *root;
};