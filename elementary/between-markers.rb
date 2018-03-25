#!/usr/bin/env ruby

def between_markers(text, beginTok, endTok)
    b=text.index(beginTok)
    e=text.index(endTok)
    return text[Range.new(b.nil? ? 0 : b+beginTok.size, e.nil? ? -1 : e-1)]
end

if __FILE__ == $0
    puts(between_markers("What is >love<", ">", "<"))
    puts(between_markers("<body><h1>My Little Phony</h1></body>", "<h1>", "</h1>"))

    raise unless between_markers("What is >love<", ">", "<") == "love"
    raise unless between_markers("<body><h1>My Little Phony</h1></body>", "<h1>", "</h1>") == "My Little Phony"
    raise unless between_markers("<body><h1>My Little Phony", "<h1>", "</h1>") == "My Little Phony"
    raise unless between_markers("My Little Phony", "<h1>", "</h1>") == "My Little Phony"
    raise unless between_markers("What is <love>", ">", "<") == ""
end
