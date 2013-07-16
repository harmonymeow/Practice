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

    // Inserts an element and rearranges the list
    void Push(T value)
    {
        if (size == array.size() - 1)
            array.resize(array.size() * 2);
        int hole = ++size;
        for (; hole > 1 && value < array[hole / 2]; hole /= 2)
            array[hole] = array[hole / 2];
        array[hole] = value;
    }

    // Returns and removes the minimum element, and restore the heap property
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

    // returns the size of the element
    int Size()
    {
        return size;
    }

    // returns the index of the first matching element
    int Find(T value)
    {
        int pos = 1;
        return Find(value, pos);
        // returns 0 if the value is not found
    }

    
    // Remove will remove the first matching element and restore the 
    //heap property
    void Remove(T value)
    {
        int hole = Find(value);
        if (hole != 0)
        {
            T temp = array[size];
            int child;
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
        }
    }
        

private:
    int size;
    vector<T> array;

    // Recursive depth-first pre-order search
    int Find(T value, int pos)
    {
        int index;
        if (array[pos] == value)
            return pos;
        // Searches left child
        if (array[pos * 2] <= value && pos * 2 <= size)
        {
            index = Find(value, pos *2);
            if (index != 0)
                return index;
        }
        // searches right child
        if (array[pos * 2 + 1] <= value && pos * 2 + 1 <= size)
        {
            index = Find(value, pos * 2 + 1);
            if (index != 0)
                return index;
        }
        return 0;
    }
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
    
        cout << list.Find(1) << endl;
        cout << list.Find(13) << endl;
        cout << list.Find(68) << endl;
        list.Remove(13);
        list.Remove(68);
        cout << list.Find(13) << endl;
        cout << list.Find(68) << endl;
        return 0;
    }