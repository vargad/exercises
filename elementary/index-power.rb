#!/usr/bin/env ruby

def index_power(array, n)
    return array.size<n ? -1 : array[n]**n
end

if __FILE__ == $0
    raise unless index_power([7, 2, 4, 8], 1) == 2
    raise unless index_power([7, 2, 10, 20, 9], 2) == 100
    raise unless index_power([20, 1], 0) == 1
    raise unless index_power([1], 4) == -1
end
