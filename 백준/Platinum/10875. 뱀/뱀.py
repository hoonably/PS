l = int(input())
n = int(input())
live = 1
time = 0
snake = []
snake.append([[-l, l + 1], [l + 1, l + 1]])
snake.append([[l + 1, l], [l + 1, -l - 1]])
snake.append([[l, -l - 1], [-l - 1, -l - 1]])
snake.append([[-l - 1, -l], [-l - 1, l + 1]])
start = [0, 0]
way = [1, 0]
tArray = []
dirArray = []
for i in range(n) :
    str = input().split()
    tArray.append(int(str[0]))
    dirArray.append(str[1])
wayNum = 0
while live > 0 :
    if wayNum >= n :
        t = max(l - start[0] + 2, l - start[1] + 2, start[0] - (-l) + 2, start[1] - (-l) + 2)
    else :
        t = tArray[wayNum]
        diri = dirArray[wayNum]
    if wayNum == 0 :
        start[0] += 1
    end = [start[0] + (way[0] * (t - 1)), start[1] + (way[1] * (t - 1))]
    tempTime = []
    for i in range(len(snake)) :
        if min(start[0], end[0]) <= max(snake[i][0][0], snake[i][1][0]) \
        and max(start[0], end[0]) >= min(snake[i][0][0], snake[i][1][0]) \
        and min(start[1], end[1]) <= max(snake[i][0][1], snake[i][1][1]) \
        and max(start[1], end[1]) >= min(snake[i][0][1], snake[i][1][1]) :
            if way == [1, 0] :
                tempTime.append(min(snake[i][0][0], snake[i][1][0]) - start[0] + 1)
            elif way == [0, 1] :
                tempTime.append(min(snake[i][0][1], snake[i][1][1]) - start[1] + 1)
            elif way == [-1, 0] :
                tempTime.append(start[0] - max(snake[i][0][0], snake[i][1][0]) + 1)
            elif way == [0, -1] :
                tempTime.append(start[1] - max(snake[i][0][1], snake[i][1][1]) + 1)
            live = 0
    if live == 0 :
        time += min(tempTime)
        break
    if wayNum == 0 :
        start[0] -= 1
    snake.append([[start[0], start[1]], [end[0], end[1]]])
    time += t
    if diri == "L" :
        if way == [1, 0] :
            way = [0, 1]
        elif way == [0, 1] :
            way = [-1, 0]
        elif way == [-1, 0] :
            way = [0, -1]
        elif way == [0, -1] :
            way = [1, 0]
    if diri == "R" :
        if way == [1, 0] :
            way = [0, -1]
        elif way == [0, 1] :
            way = [1, 0]
        elif way == [-1, 0] :
            way = [0, 1]
        elif way == [0, -1] :
            way = [-1, 0]
    start[0] = end[0] + way[0]
    start[1] = end[1] + way[1]
    wayNum += 1
print(time)