#!/usr/bin/env ruby
# 2018 Daniel Varga (vargad88@gmail.com)

$prng = Random.new


class BiasedCoin

    def initialize(head_prob=nil)
        head_prob = $prng.rand(1.0) while head_prob.to_f == 0
        puts "head prob: #{head_prob}"
        @head_prob = head_prob
    end

    def call
        return @head_prob < $prng.rand(1.0)
    end

end

class Game
    attr_reader :money
    attr_reader :total_turn
    attr_reader :head_count

    def initialize(head_prob=nil)
        @money = 1000
        @coin = BiasedCoin.new(head_prob)
        @head_count = 0
        @total_turn = 0
    end

    def turn(bet_amount, bet_head)
        raise "betting more than available" if bet_amount > @money
        raise "not a positive integer bet" if bet_amount < 0 || bet_amount.to_i != bet_amount
        is_head = @coin.call
        @total_turn += 1
        @head_count += 1 if is_head
        if is_head == bet_head
            @money += bet_amount.to_i
            return true
        else
            @money -= bet_amount.to_i
            return false
        end
    end
end

game = Game.new()

confidence = 0
while game.money > 0 && game.money < 2**64
    if game.total_turn > 0
        confidence = [(0.5-game.head_count/game.total_turn.to_f).abs - (1.0-(game.total_turn/(game.total_turn+1.0))), 0.0].max
    end
    #puts "confidence: #{confidence}"
    bet_head = game.head_count > game.total_turn/2.0
    #puts "#{bet_head ? "bet head" : "bet tail"} history: #{game.head_count}/#{game.total_turn} #{game.head_count/game.total_turn.to_f}"
    game.turn([(game.money*confidence).to_i,1].max, bet_head)
    puts "#{game.money}"
end
