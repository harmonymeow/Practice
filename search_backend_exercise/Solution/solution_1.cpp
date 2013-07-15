#include <iostream>
#include <vector>
using namespace std;

template <class T>
class SortedList
{
public:
    SortedList()
    {
        array.resize(10);
        size = 0;
    }

    SortedList(T value)
    {
        array.resize(10);
        array[1] = value;
        size = 1;
    }

    void Push(T value)
    {
        if (size == array.size() - 1)
            array.resize(array.size() * 2);
        int hole = ++size;
        for (; hole > 1 && value < array[hole / 2]; hole /= 2)
            array[hole] = array[hole / 2];
        array[hole] = value;
    }

    T Pop()
    {
        if (Size() <= 0)
        {
            cout << "ERROR: The SortedList is empty.";
            return NULL;
        }

        T min = array[1];
        T temp = array[size];
        array[1] = temp;
        
        int child;
        int hole = 1;
        for (; hole * 2 <= size; hole = child)
        {
            child = hole * 2;
            if (child != size && array[child + 1] < array[child])
                child++;
            if (array[child] < temp)
                array[hole] = array[child];
            else
                break;
        }

        array[hole] = temp;
        array[size] = NULL;
        size--;
        return min;
    }

    int Size()
    {
        return size;
    }

private:
    int size;
    vector<T> array;
};

int main()
    {
        SortedList<int> list = SortedList<int>();
        list.Push(13);
        list.Push(14);
        list.Push(16);
        list.Push(19);
        list.Push(21);
        list.Push(1);
        list.Push(68);
        list.Push(65);
        list.Push(26);
        list.Push(32);
        list.Push(31);
        cout << list.Pop() << endl;
        cout << list.Pop() << endl;
        //cout << list.Size() << endl;
        return 0;
    }