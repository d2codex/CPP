template <typename T>
class Array {
    T* _array;
    unsigned int _size;

public:
    // Constructor, destructor, etc.

    // Copy constructor
    Array(const Array& other)
        : _array(new T[other._size]), _size(other._size)
    {
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }

    // Swap (C++98 style)
    void swap(Array& other)
    {
        std::swap(_array, other._array);
        std::swap(_size, other._size);
    }

    // Assignment operator (copy-and-swap)
    Array& operator=(Array other)
    {
        swap(other);
        return *this;
    }

    // Destructor
    ~Array() { delete[] _array; }
};

/*
Advantages:

DRY — reuses the copy constructor instead of duplicating deep-copy logic
Exception safety is automatic — if the copy constructor throws, it
happens before the function body even starts, so *this is never touched
Self-assignment safe for free — no if (this != &other) check needed, it
just makes a copy and swaps, slightly wasteful but correct
Less code, fewer places to introduce bugs

One tradeoff:
Version with this != &other guard skips all work on self-assignment.
Copy-and-swap always makes a full copy even on a = a. Self-assignment
is rare enough that this almost never matters, but it's worth knowing.
*/
