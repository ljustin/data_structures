#include "IntArray.h"

namespace JDS
{
    IntArray::IntArray(size_t size, int init_value) : _size(size)
    {
        _arr = new int[_size];

        for (size_t i = 0; i < size; i++)
            _arr[i] = init_value;
    }

    IntArray::IntArray(const JDS::IntArray& rhs)
    {
        delete[] _arr;
        _arr = new int[rhs._size];
        _size = rhs._size;

        for (size_t i = 0; i < _size; i++)
        {
            _arr[i] = rhs._arr[i];
        }
    }

    int& IntArray::operator[] (size_t index)
    {
        assert(index < _size);
        return _arr[index];
    }

    IntArray::~IntArray()
    {
        delete[] _arr;
    }


    std::ostream& operator<< (std::ostream& out, IntArray& iArr)
    {
        out << "[ ";

        for (size_t i = 0; i < iArr._size - 1; i++)
        {
            out << iArr[i] << ", ";
        }

        out << iArr[iArr._size - 1] << " ] " << std::endl;

        return out;
    }

}
