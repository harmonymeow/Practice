#include <iostream>
using namespace std;

template <class T>
class SortedList
{
public:
    SortedList(T value_)
    {
        m_head = new Node(value_, NULL);
        size++;
    }

    void Push(T value)
    {
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
    }

    T Pop()
    {
        if (Size() <= 0)
        {
            cout << "ERROR: The SortedList is empty.";
            return NULL;
        }
        Node* pResult = m_head;
        m_head = m_head->next;
        T result = pResult->value;
        delete(pResult);
        size--;
        return result;
    }

    int Size()
    {
        return size;
    }

private:
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
    size = 0;
};

int main()
    {
        SortedList<char> list = SortedList<char>('a');
        list.Push('b');
        list.Pop();
        list.Pop();
        list.Pop();
        list.Push('c');
        cout << list.Size();
        return 0;
    }