#include <cassert>
#include <string>
#include <iostream>

// Pointer exercises, please use pointers to solve the tasks (avoid using
// indices). Although C-style strings should not be used in C++, it's a good
// exercise for deeper understanding of pointers. Many low level libraries
// and system calls operate on C-style strings, is crucial to understand them.
// Also iterators in C++ has similar schematics to pointers.
// Just remember this is an exercise, generally avoid using pointers in
// this way.

// Return the length of C-style string (ending with zero character)
size_t my_strlen(const char *str)
{
  return 0; // TODO Your code here
}

// Determine if the passed C-style string is a palindrome.
bool is_palindrome(const char *str)
{
  return false; // TODO Your code here
}

// Return the position of the first occurence of the specified character in
// the C-style string, return negative value in case the character is not
// found.
int char_pos(const char *str, char c)
{
    return -1; // TODO Your code here
}

// Reverse the C-style string in place.
void reverse(char *str)
{
    // TODO Your code here
}

// Implement a template function that swaps the values of the arguments.
// We assume the types are copyable and copy constructable.
void my_swap(/* TODO Your code here */)
{
    // TODO Your code here
}

// Implement list_prepend function, which prepends a node to the list.
// Allocate a node for the value and connect it to the list. The function must
// return the head of the list.
// It should also work when the list is empty, so the head is nullptr.
struct MyListNode {
    MyListNode *next_node;
    int num;
};

MyListNode* list_prepend(MyListNode *head, int num)
{
    return nullptr; // TODO Your code here
}

int main()
{
    // my_strlen tests
    assert(my_strlen("mokus") == 5);
    assert(my_strlen("Hello World!") == 12);

    // is_palindrome tests
    assert(is_palindrome("mokus") == false);
    assert(is_palindrome("Hello World") == false);
    assert(is_palindrome("lakkal") == true);
    assert(is_palindrome("gorog") == true);

    // char_pos tests
    assert(char_pos("42", '4') == 0);
    assert(char_pos("Hello World!", '!') == 11);
    assert(char_pos("username;password", ';') == 8);
    assert(char_pos("Hello World!", ';') < 0);

    // reverse test
    std::string str = "a mokus felmaszott a fara";
    // Not very nice to manipulate the string's underlying data this way,
    // the operator[] should only be used to access one character, although
    // from C++11 it's guaranteed to be continuous memory.
    // Also we rely on the fact that in practice all major string
    // implementations have a zero character at the end of the string,
    // although it's not guaranteed by the standard.
    reverse(&(str[0]));
    assert(str == "araf a ttozsamlef sukom a");

    // my_swap test
    std::string apple = "apple", pear = "pear";
    my_swap(apple, pear);
    assert(apple == "pear");
    assert(pear == "apple");

    int a=10, b=42;
    my_swap(a, b);
    assert(a == 42);
    assert(b == 10);

    // list_prepend test
    MyListNode *head = nullptr;
    for (int i=0; i<5; ++i)
    {
        head = list_prepend(head, i);
    }
    int j = 4;
    for (MyListNode *node = head; node->next_node != nullptr; node = node->next_node)
    {
        assert(node->num == j);
        --j;
    }
    // note: we are leaking memory, by not properly freeing the list
}
