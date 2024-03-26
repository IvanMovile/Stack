#pragma once

#include <stdexcept>
#include <utility>

template<class T> class stack
{
public:
    int size;

    stack() noexcept
    {
        size = 0;
        capacity = 1;
        stack_pointer = new T[capacity];
    }

    stack(const stack<T>& src)
    {
        size = src.size;
        capacity = src.capacity;
        stack_pointer = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            stack_pointer[i] = src.stack_pointer[i];
        }
    }

    stack(stack<T>&& src) noexcept
    {
        size = src.size;
        capacity = src.capacity;
        stack_pointer = src.stack_pointer;
        src.size = 0;
        src.capacity = 0;
        src.stack_pointer = nullptr;
    }

    stack<T>& operator=(const stack<T>& other)
    {
        if (this != &other)
        {
            size = other.size;
            capacity = other.capacity;
            delete[] stack_pointer;
            stack_pointer = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                stack_pointer[i] = other.stack_pointer[i];
            }
        }

        return *this;
    }

    stack<T>& operator=(stack<T>&& other) noexcept
    {
        size = other.size;
        capacity = other.capacity;
        delete[] stack_pointer;
        stack_pointer = other.stack_pointer;
        other.size = 0;
        other.capacity = 0;
        other.stack_pointer = nullptr;

        return *this;
    }

    ~stack() noexcept
    {
        delete[] stack_pointer;
    }

    void push(T& element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* new_stack_pointer = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                new_stack_pointer[i] = stack_pointer[i];
            }

            delete[] stack_pointer;
            stack_pointer = new_stack_pointer;
        }

        stack_pointer[size++] = element;
    }

    void push(const T& element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* new_stack_pointer = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                new_stack_pointer[i] = stack_pointer[i];
            }

            delete[] stack_pointer;
            stack_pointer = new_stack_pointer;
        }

        stack_pointer[size++] = element;
    }


    void push(T&& element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* new_stack_pointer = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                new_stack_pointer[i] = stack_pointer[i];
            }

            delete[] stack_pointer;
            stack_pointer = new_stack_pointer;
        }

        stack_pointer[size++] = std::move(element);
    }

    void push(const T&& element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* new_stack_pointer = new T[capacity];

            for (int i = 0; i < size; i++)
            {
                new_stack_pointer[i] = stack_pointer[i];
            }

            delete[] stack_pointer;
            stack_pointer = new_stack_pointer;
        }

        stack_pointer[size++] = element;
    }

    void pop()
    {
        if (size == 0)
        {
            throw std::runtime_error("Cannot pop from empty stack.\n");
        }

        stack_pointer[--size].~T();
    }

    T top() const
    {
        if (size == 0)
        {
            throw std::runtime_error("Cannot top from empty stack.\n");
        }

        return stack_pointer[size - 1];
    }

private:
    int capacity;
    T* stack_pointer;
};