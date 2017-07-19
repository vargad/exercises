#!/usr/bin/env ruby
# 2017 Daniel Varga (vargad88@gmail.com)

class LinkedList
    attr_reader :data
    attr_reader :next

    def initialize(data, rest=nil)
        @data = data
        @next = rest
    end

    def to_s
        return "%d, %s" % [self.data, self.next]
    end
end

def make_list(*elements)
    # alternate solution
    #return elements.reverse.inject(nil) { |c, e| LinkedList.new(e, c) }
    list = nil
    elements.reverse.each { |e| list = LinkedList(e, list) }
    return list
end

def reverse(list, rest=nil)
    return rest if list.nil?
    return reverse(list.next, LinkedList.new(list.data, rest))
end

l = make_list(1,2,3,4,5,6,7)
puts(l)
l2 = reverse(l)
puts(l2)
