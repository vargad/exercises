#!/usr/bin/env ruby

def fizz_buzz(number)
    return "Fizz Buzz" if number%15==0
    return "Fizz" if number%3==0
    return "Buzz" if number%5==0
    return number.to_s
end

if __FILE__ == $0
    raise unless fizz_buzz(30) == "Fizz Buzz"
    raise unless fizz_buzz(12) == "Fizz"
    raise unless fizz_buzz(5) == "Buzz"
    raise unless fizz_buzz(13) == "13"
end
