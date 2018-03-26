#!/usr/bin/env ruby

def digits_multiplication(number)
    return 1 if number == 0
    return [number%10,1].max*digits_multiplication(number/10)
end

if __FILE__ == $0
    raise unless digits_multiplication(102345) == 120
    raise unless digits_multiplication(555) == 125
    raise unless digits_multiplication(2000) == 2
    raise unless digits_multiplication(1111111) == 1
end
