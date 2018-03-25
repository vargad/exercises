#!/usr/bin/env ruby

def even_last(array)
    return array.select.with_index{ |v, i| i%2==0 }.sum * array[-1].to_i
end

if __FILE__ == $0
    puts(even_last([1,2,3,4,5]))
    raise unless even_last([1,2,3,4,5]) == 45
    raise unless even_last([1,2,3,4,5]) == 45
    raise unless even_last([1.5,2,3.5,4,5,6]) == 60
    raise unless even_last([1,2,3,4,5,6]) == 54
end
