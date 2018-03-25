#!/usr/bin/env ruby

def popular_words(text, words)
    counter = words.map{ |word| [word, 0] }.to_h
    text.downcase.split(/[^a-z']/).each { |word|
        counter[word] += 1 if counter.include? word
    }
    return counter
end

if __FILE__ == $0
    poem = '''Tuzesen sut le a nyari nap sugara\n
           Az eg tetejerol a juhaszbojtarra.\n
           Folosleges dolog sutnie oly nagyon,\n
           A juhasznak ugyis nagy melege vagyon\n'''

    puts(popular_words(poem, ["a", "nagy", "macska"]))
    raise unless popular_words(poem, ["a", "nagy", "macska"]) == { "a" => 3, "nagy" => 1, "macska" => 0 }
end
