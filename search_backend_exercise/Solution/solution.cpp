#include <iostream>
using namespace std;

template <class T>
class SortedList
{
public:
    SortedList(T value_)
    {
        m_head = new Node(value_, NULL);
        size = 1;
    }

    void Push(T value)
    {
        size++;
        if (Size() <= 0)
        {
            m_head = new Node(value, NULL);
            return;
        }
        else
        {
            Node **where = &m_head;
            while (*where && (*where)->value < value) {
                where = &((*where)->next);
            }
            *where = new Node(value,*where);
        }
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
        /*
        Node * p = m_head;
        int size = 0;
        while (p)
        {
            ++size;
            p = p->next;
        }*/
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
    int size;
};

int main()
    {
        SortedList<int> list = SortedList<int>(3);
        list.Push(5);
        cout << list.Pop() << endl;
        cout << list.Pop() << endl;
        list.Push(3);
        cout << list.Size();
        return 0;
    }