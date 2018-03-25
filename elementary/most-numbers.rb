#!/usr/bin/env ruby

def most_numbers(*args)
    return args.empty? ? 0 : args.max-args.min
end

if __FILE__ == $0
    puts(most_numbers(2,5,3,7,5,8))
    raise unless most_numbers(2,5,3,7,5,8) == 6
    raise unless most_numbers(2.5,5,3,7,5,8.5) == 6
    raise unless most_numbers() == 0
    raise unless most_numbers(2,5,7,6,4) == 5
end
