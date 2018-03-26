#!/usr/bin/env ruby

def absolute_sort(numbers_array)
    return numbers_array.sort_by{ |e| e.abs }
end

if __FILE__ == $0
    p(absolute_sort([-13, 3, -18, 24]))
    raise unless absolute_sort([-13, 3, -18, 24]) == [3, -13, -18, 24]
    raise unless absolute_sort([1, 2, 3, 0]) == [0, 1, 2, 3]
    raise unless absolute_sort([-42, -43, -44, 0]) == [0, -42, -43, -44]
end
