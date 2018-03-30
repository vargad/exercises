#!/usr/bin/env ruby

def most_frequent(data)
    counter = Hash.new(0)
    data.each { |x| counter[x] += 1 }
    return counter.max_by { |k,v| v }[0]
end

if __FILE__ == $0
    puts(most_frequent([1,1,3,1,1,1,2]))
    raise unless most_frequent([1,1,3,1,1,1,2]) == 1
    raise unless most_frequent([2,2,2,3,4,5,6]) == 2
    raise unless most_frequent(["mokus","mokus","abc","ghj","koala","qwerty"]) == "mokus"
end
