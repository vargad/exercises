#!/usr/bin/env ruby

def first_word(text)
    return text.scan(/([a-zA-Z']+)/)[0][0]
end

if __FILE__ == $0
    puts(first_word("Hello World"))

    raise unless first_word("Hello World") == "Hello"
    raise unless first_word(" more spaces ") == "more"
    raise unless first_word("don't split it") == "don't"
    raise unless first_word("hello, world") == "hello"
    raise unless first_word("... very long sentence ...") == "very"
    raise unless first_word("mokus") == "mokus"
end
