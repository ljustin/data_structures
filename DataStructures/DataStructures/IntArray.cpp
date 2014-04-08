#include "IntArray.h"

JDS::IntArray::IntArray(size_t size, int init_value) : _size(size)
{
    _arr = new int[_size];

    for (int i = 0; i < size; i++)
        _arr[i] = init_value;
}

int& JDS::IntArray::operator[](size_t index)
{
    assert(index < _size);
    return _arr[index];
}

JDS::IntArray::~IntArray()
{
    delete[] _arr;
}

namespace JDS
{
    std::ostream& operator<< (std::ostream& out, JDS::IntArray& iArr)
    {
        out << "[ ";

        for (int i = 0; i < iArr._size - 1; i++)
        {
            out << iArr[i] << ", ";
        }

        out << iArr[iArr._size - 1] << " ] " << std::endl;

        return out;
    }
}