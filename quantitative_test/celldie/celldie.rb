#!/usr/bin/env ruby
# 2018 Daniel Varga (vargad88@gmail.com)

def simulate_colony
    size = 1
    while size > 0 && size < 2000
        new_size = 0
        size.times { new_size += rand(0..3) }
        size = new_size
    end
    return size > 0
end

ITERATIONS=10000
dieout = 0
ITERATIONS.times {
    dieout += 1 if not simulate_colony
}

puts "chance of never die: #{100-dieout.to_f/ITERATIONS*100}"
