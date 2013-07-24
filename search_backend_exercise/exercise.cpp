template <class T>
class SortedList
{
public:
    void Push(T value)
    {
        Node ** where = &m_head;
        while (*where && (*where)->value < value) {
            where = &((*where)->next);
        }
        *where = new Node(value,*where);
    }

    T Pop()
    {
        Node* pResult = m_head;
        m_head = m_head->next;
        T result = pResult->value;
        free(pResult);
        return result;
    }

    int Size()
    {
        Node * p = m_head;
        int size = 0;
        while (p)
            ++size;
            p = p->next;
        return size;
    }

private:
    class Node
    {
        Node(T value_, Node* next_)
        {
            value = value_;
            next = next_;
        }
        T value;
        Node* next;
    };

    Node* m_head;
};