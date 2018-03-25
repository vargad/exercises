#!/usr/bin/env ruby

def three_words(words)
    return (/[a-zA-Z]+ [a-zA-Z]+ [a-zA-Z]+/ =~ words) != nil
end

if __FILE__ == $0
    raise unless three_words("Mokus felmaszott fara") == true
    raise unless three_words("This squirrel 999 apple") == false
    raise unless three_words("9 8 7 6") == false
    raise unless three_words("little little little") == true
    raise unless three_words("Wow") == false
end
