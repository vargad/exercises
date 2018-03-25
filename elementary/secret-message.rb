#!/usr/bin/env ruby

def secret_message(text)
    return text.gsub(/[^A-Z]/, "")
end

def secret_message2(text)
    return text.each_char.select{ |c| ('A'..'Z').include?(c) }.join
end


if __FILE__ == $0
    puts(secret_message("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten."))
    raise unless secret_message("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten.") == "MACSKA"
    raise unless secret_message("hello world!") == ""
    raise unless secret_message("HELLO WORLD!") == "HELLOWORLD"

    puts(secret_message2("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten."))
    raise unless secret_message2("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten.") == "MACSKA"
    raise unless secret_message2("hello world!") == ""
    raise unless secret_message2("HELLO WORLD!") == "HELLOWORLD"
end
