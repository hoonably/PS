import sys

t = int(sys.stdin.readline())

for _ in range(t):
    sound = list(map(str, sys.stdin.readline().split()))

    while True:
        animal = list(map(str, sys.stdin.readline().split()))

        # what does the fox say?
        if animal[0] == "what":
            print(" ".join(sound))
            break

        # ??? goes ???
        while animal[2] in sound:
            sound.remove(animal[2])