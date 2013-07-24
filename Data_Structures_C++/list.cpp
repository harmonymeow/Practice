#include <iostream>
#include <string>
//#include <unordered_map> //Hash Table
#include "SinglyLinkedList.cpp"
//#include "BinarySearchTree.cpp"

using namespace std;

int main()
{
  /*
  // Tests for Singly Linked List
  SinglyLinkedList<int> list = SinglyLinkedList<int>();
  list.Push(1);
  list.Push(2);
  list.Push(3);
  list.Remove(2);
  list.Remove(4);
  cout << list.Pop() << " | " << list.Size() << endl;
  cout << list.Pop() << " | " << list.Size() << endl;
  cout << list.Pop() << " | " << list.Size() << endl;
  cout << list.Pop() << " | " << list.Size() << endl;


  // Tests for Binary Search Tree
  BinarySearchTree<int> list2 = BinarySearchTree<int>();
  list2.Insert(1);
  list2.Insert(2);
  list2.Insert(3);
  */

  unordered_map<string,int> hashtable;
  hashtable.emplace("one", 1);
  cout << hashtable["one"] << endl;
  return 0;
};