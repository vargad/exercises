#!/usr/bin/env ruby

def second_index(text, symbol)
    pos=text.index(symbol)
    return pos.nil? ? nil : text.index(symbol, pos+1)
end

if __FILE__ == $0
    puts(second_index("Hello World", 'o'))

    raise unless second_index("Hello World", 'o') == 7
    raise unless second_index(" more spaces ", 'e') == 10
    raise unless second_index("hello, world", ' ').nil?
    raise unless second_index("... very long sentence ...", ' ') == 8
end
