#include "stack.h"
#include "gtest/gtest.h"

TEST(stack, default_constructor)
{
    stack<int> s;

    EXPECT_EQ(s.size, 0);
    EXPECT_THROW(s.top(), std::runtime_error);
    EXPECT_THROW(s.pop(), std::runtime_error);
}

TEST(stack, copy_constructor)
{
    stack<int> s1;

    s1.push(0);
    s1.push(1);

    stack<int> s2(s1);

    EXPECT_EQ(s2.size, 2);
    EXPECT_EQ(s2.top(), 1);
}

TEST(stack, copy_assignment_operator)
{
    stack<int> s1;
    stack<int> s2;

    s1.push(0);
    s1.push(1);

    s2 = s1;

    EXPECT_EQ(s2.size, s1.size);
    EXPECT_EQ(s2.top(), s1.top());
}

TEST(stack, move_constructor)
{
    stack<int> s1;

    s1.push(0);
    s1.push(1);

    stack<int> s2(std::move(s1));

    EXPECT_EQ(s1.size, 0);
    EXPECT_EQ(s2.size, 2);
    EXPECT_EQ(s2.top(), 1);
    EXPECT_THROW(s1.top(), std::runtime_error);
}

TEST(stack, move_assignment_operator)
{
    stack<int> s1;
    stack<int> s2;

    s1.push(0);
    s1.push(1);

    s2 = std::move(s1);

    EXPECT_EQ(s1.size, 0);
    EXPECT_EQ(s2.size, 2);
    EXPECT_EQ(s2.top(), 1);
    EXPECT_THROW(s1.top(), std::runtime_error);
}

TEST(stack, floating)
{
    stack<double> s;

    s.push(0.5);

    EXPECT_EQ(s.size, 1);
    EXPECT_EQ(s.top(), 0.5);

    s.pop();

    EXPECT_THROW(s.top(), std::runtime_error);
}

TEST(stack, string)
{
    stack<std::string> s;

    s.push("Hello, world!\n");

    EXPECT_EQ(s.size, 1);
    EXPECT_EQ(s.top(), "Hello, world!\n");

    s.pop();

    EXPECT_THROW(s.top(), std::runtime_error);
}

TEST(stack, destructor)
{
    auto* s = new stack<int>();

    s->push(0);

    EXPECT_EQ(s->top(), 0);

    delete s;
}

TEST(stack, lvalue_reference_push)
{
    std::string str1 = "Hello";
    std::string str2 = "World";

    stack<std::string> s;

    s.push(str1);
    s.push(str2);

    EXPECT_EQ(s.top(), "World");
}

TEST(stack, const_lvalue_reference_push)
{
    const std::string str1 = "Hello";
    const std::string str2 = "World";

    stack<std::string> s;

    s.push(str1);
    s.push(str2);

    EXPECT_EQ(s.top(), "World");
}

TEST(stack, rvalue_reference_push)
{
    stack<std::string> s;

    s.push("Hello");
    s.push("World");

    EXPECT_EQ(s.top(), "World");
}

TEST(stack, const_rvalue_reference_push)
{
    stack<stack<int>> s;

    s.push(stack<int>());

    EXPECT_EQ(s.top().size, 0);
}

TEST(stack, pop)
{
    stack<int> s;

    s.push(1);
    s.pop();

    EXPECT_EQ(s.size, 0);
    EXPECT_THROW(s.pop(), std::runtime_error);
}

TEST(stack, top)
{
    stack<int> s;

    s.push(1);

    EXPECT_EQ(s.size, 1);
    EXPECT_EQ(s.top(), 1);
}