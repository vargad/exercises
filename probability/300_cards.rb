#!/usr/bin/env ruby
# 2019 Daniel Varga (vargad88@gmail.com)

# There are 300 different cards. How many cards I need to buy so that I have 50% chance getting all the 300 different cards.

require 'set'


have300 = []
TOTAL=40000
TOTAL.times {
    missing_cards = Set.new(0..299)
    buys = 0
    until missing_cards.empty?
        missing_cards.delete(rand(300))
        buys += 1
    end
    have300[buys] = have300[buys].to_i + 1
}

have300_so_far = 0.0
prob = have300.map { |count|
    have300_so_far += count.to_i
    have300_so_far / TOTAL
}

prob.each.with_index { |p, i| puts("#{i} #{p*100}") }
