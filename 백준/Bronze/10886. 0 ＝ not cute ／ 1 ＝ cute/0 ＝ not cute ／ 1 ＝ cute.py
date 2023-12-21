N = int(input())
voteNot = 0
voteCute = 0
for i in range(N):
    getVote = int(input())
    if getVote==0:
        voteNot+=1
    elif getVote==1:
        voteCute+=1

if voteNot>voteCute:
    print("Junhee is not cute!")
elif voteNot<voteCute:
    print("Junhee is cute!")