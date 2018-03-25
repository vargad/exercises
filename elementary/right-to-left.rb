#!/usr/bin/env ruby

def left_join(phrases)
    return phrases.join(',').gsub("right", "left")
end

if __FILE__ == $0
    puts(left_join(["right", "right", "left", "left", "forward"]))
    raise unless left_join(["right", "right", "left", "left", "forward"]) == "left,left,left,left,forward"
    raise unless left_join(["alright outright", "squirrel"]) == "alleft outleft,squirrel"
    raise unless left_join(["frightened", "eyebright"]) == "fleftened,eyebleft"
    raise unless left_join(["little", "squirrel"]) == "little,squirrel"
end
