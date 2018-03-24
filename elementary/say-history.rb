#!/usr/bin/env ruby

def say_hi(name, age)
    return "Hi. My name is #{name} and I'm #{age} years old"
end

if __FILE__ == $0
    raise unless say_hi("Kitty", 28) == "Hi. My name is Kitty and I'm 28 years old"
    raise unless say_hi("Peter", 42) == "Hi. My name is Peter and I'm 42 years old"
end
