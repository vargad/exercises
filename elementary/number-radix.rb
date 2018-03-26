#!/usr/bin/env ruby

def number_radix(str_number, radix)
    begin
        return Integer(str_number, radix)
    rescue
        return -1
    end
end

if __FILE__ == $0
    raise unless number_radix("1234", 10) == 1234
    raise unless number_radix("FF", 16) == 255
    raise unless number_radix("FF", 10) == -1
end
