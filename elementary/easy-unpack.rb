#!/usr/bin/env ruby

def easy_unpack(elements)
    return [elements[0], elements[2], elements[-2]]
end

if __FILE__ == $0
    a, b, c = easy_unpack([1, "Macska", "Mokus", 2, 3, 4 , 6, "Cica", 10]);
    puts(a, b, c)

    raise unless easy_unpack([1, "Macska", "Mokus", 2, 3, 4 , 6, "Cica", 10]) == [1, "Mokus", "Cica"]
    raise unless easy_unpack([1, "Macska", 2]) == [1, 2, "Macska"]
end
