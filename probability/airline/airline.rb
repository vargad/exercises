#!/usr/bin/env ruby
# 2019 Daniel Varga (vargad88@gmail.com)

# There are 100 people to board a plane with 100 seats. First person lost his
# boarding pass taking a random seat. Everyone else takes their assigned seat
# if available, otherwise taking a random unoccupied seat. What is the
# probability that the last passenger ends up in his/her assigned seat?


class Simulation

    def initialize
        @tickets = 0.upto(99).to_a.shuffle
        @seats_free = (0..99).to_a
    end

    def simulate_can_sit_own
        return false unless sit_random_taking_last
        @tickets[1..-2].each { |ticket|
            if @seats_free.delete(ticket).nil?
                return false unless sit_random_taking_last
            end
        }
        return true
    end

private
    def sit_random_taking_last
        s = @seats_free.sample
        return false if s == @tickets[-1]
        @seats_free.delete(s)
        return true
    end

end

SIMULATE_TOTAL = 10000

own_seat = 0
SIMULATE_TOTAL.times {
    s = Simulation.new
    own_seat += 1 if s.simulate_can_sit_own
}

puts(own_seat/SIMULATE_TOTAL.to_f)
