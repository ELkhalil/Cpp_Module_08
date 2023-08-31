#include <iostream>

// Iterator class for MyVectorContainer
template <typename T>
class MyVectorIterator
{
private:
    T* ptr;

public:
    MyVectorIterator(T* p) : ptr(p) {}

    T& operator*()
    {
        return *ptr;
    }

    MyVectorIterator& operator++() {
        ++ptr;
        return *this;
    }

    bool operator!=(const MyVectorIterator& other) const {
        return ptr != other.ptr;
    }
};

// Container class
template <typename T>
class MyVectorContainer
{
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    typedef MyVectorIterator<T> iterator;
    MyVectorContainer() : data(NULL), size(0), capacity(0) {}

    ~MyVectorContainer() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            reserve(capacity * 2 + 1);
        }
        data[size++] = value;
    }

    void reserve(size_t newCapacity) {
        if (newCapacity > capacity) {
            T* newData = new T[newCapacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
    }

    // Begin iterator
    iterator begin()
    {
        return MyVectorIterator<T>(data);
    }

    // End iterator
    iterator end() {
        return MyVectorIterator<T>(data + size);
    }
};

/* Using it separatly */
// int main() {
//     MyVectorContainer<int> myVector;

//     for (int i = 0; i < 5; ++i) {
//         myVector.push_back(i);
//     }

//     for (MyVectorIterator<int> it = myVector.begin(); its != myVector.end(); ++it)
//     {
//         std::cout << *it << " ";
//     }

//     return 0;
// }

/* using linked iterator */
int main()
{
    MyVectorContainer<int> myVector;

    for (int i = 0; i < 5; ++i) {
        myVector.push_back(i);
    }

    MyVectorContainer<int>::iterator it = myVector.begin();
    MyVectorContainer<int>::iterator itEnd = myVector.end();
    for (it ; it != itEnd; ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
