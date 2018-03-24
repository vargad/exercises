#include <cassert>
#include <string>
#include <iostream>

std::string say_hi(const std::string &name, int age) {
    return "Hi. My name is "+name+" and I'm "+std::to_string(age)+" years old";
}

int main()
{
    assert(say_hi("Kitty", 28) == "Hi. My name is Kitty and I'm 28 years old");
    assert(say_hi("Peter", 42) == "Hi. My name is Peter and I'm 42 years old");
}

