#!/usr/bin/env python3

def left_join(phrases):
    return ','.join(phrases).replace("right", "left")

if __name__ == '__main__':
    print(left_join(["right", "right", "left", "left", "forward"]))
    assert left_join(["right", "right", "left", "left", "forward"]) == "left,left,left,left,forward"
    assert left_join(["alright outright", "squirrel"]) == "alleft outleft,squirrel"
    assert left_join(["frightened", "eyebright"]) == "fleftened,eyebleft"
    assert left_join(["little", "squirrel"]) == "little,squirrel"
