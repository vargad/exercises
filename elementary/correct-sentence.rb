#!/usr/bin/env ruby
#
def correct_sentence(text)
    return (text.end_with?('.') ? text : text+".").capitalize
end

if __FILE__ == $0
    puts(correct_sentence("hello, world"))
    raise unless correct_sentence("hello, world") == "Hello, world."
    raise unless correct_sentence("kis mokus felmaszott a fara.") == "Kis mokus felmaszott a fara."
end
