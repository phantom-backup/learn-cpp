#include <cassert>
#include <iostream>

constexpr int MAX_SIZE{10};

class Stack
{
public:
    bool push(int x)
    {
        if (size == MAX_SIZE)
        {
            return false;
        }

        array[size++] = x;
        return true;
    }

    int pop()
    {
        assert(size > 0 && "Can not pop empty stack");

        return array[--size];
    }

    void reset()
    {
        size = 0;
    }

    void print() const
    {
        std::cout << "( ";

        for (int i{0}; i < size; ++i)
        {
            std::cout << array[i] << " ";
        }

        std::cout << ")" << std::endl;
    }

private:
    int array[MAX_SIZE]{};
    int size{};
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}