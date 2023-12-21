V = int(input())
str = input()
voteA = 0
voteB = 0

for vote in str:
    if vote=="A":
        voteA+=1
    elif vote=="B":
        voteB+=1

if voteA>voteB:
    print("A")
elif voteA==voteB:
    print("Tie")
elif voteA<voteB:
    print("B")