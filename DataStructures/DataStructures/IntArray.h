#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <iostream>
#include <cassert>

namespace JDS
{
    // array
    class IntArray
    {
    public:
        IntArray(size_t size, int init_value = 0);

        int& operator[](size_t index);

        ~IntArray();

        friend std::ostream& operator<< (std::ostream& out, JDS::IntArray& iArr)
        {
            out << "[ ";

            for (int i = 0; i < iArr._size - 1; i++)
            {
                out << iArr[i] << ", ";
            }

            out << iArr[iArr._size - 1] << " ] " << std::endl;

            return out;
        }

    private:
        int* _arr;
        size_t _size;
    };
}

#endif