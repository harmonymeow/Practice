#include <iostream>
#include <vector>
using namespace std;

template <class T>
class SortedList
{
public:
    SortedList(T value)
    {
        array.resize(10);
        array[1] = value;
        //m_head = new Node(value_, NULL);
        size = 1;
    }

    void Push(T value)
    {
        if (size == array.size() -1)
            array.resize(array.size() * 2);
        int hole = ++size;
        for (; hole > 1 && value < array[hole/2]; hole /=2)
            array[hole] = array[hole/2];
        array[hole] = value;

        /*
        size++;
        if (Size() <= 0)
        {
            m_head = new Node(value, NULL);
            return;
        }
        Node **where = &m_head;
        while (*where && (*where)->value < value) {
            where = &((*where)->next);
        }
        *where = new Node(value,*where);
        */
    }

    T Pop()
    {
        if (Size() <= 0)
        {
            cout << "ERROR: The SortedList is empty.";
            return NULL;
        }
        array[1] = array[]
        /*
        Node* pResult = m_head;
        m_head = m_head->next;
        T result = pResult->value;
        delete(pResult);
        */

        size--;
        return result;
    }

    int Size()
    {
        return size;
    }

private:
    /*
    class Node
    {
    public: 
        Node(T value_, Node* next_)
        {
            value = value_;
            next = next_;
        }
        T value;
        Node* next;
    };

    Node *m_head;
    */
    int size;
    vector<T> array;
};

int main()
    {
        SortedList<char> list = SortedList<char>('a');
        list.Push('b');
        //list.Pop();
        //list.Pop();
        //list.Pop();
        //list.Push('c');
        cout << list.Size();
        return 0;
    }