str = input()
for i in str:
    new = ord(i)
    if 65<=new<=77 or 97<=new<=109:
        new+=13
    elif 78<=new<=90 or 110<=new<=122:
        new-=13
    print(chr(new), end='')