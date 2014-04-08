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
        IntArray(const IntArray& rhs);
        int& operator[](size_t index);

        ~IntArray();

        friend std::ostream& operator<< (std::ostream& out, IntArray& iArr);

    private:
        int* _arr;
        size_t _size;
    };
}

#endif