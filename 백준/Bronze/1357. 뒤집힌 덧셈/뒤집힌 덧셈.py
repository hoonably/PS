x, y =map(int, input().split())

def Rev(X):
    X = str(X)
    X = X[::-1]
    X = int(X)
    return X

print(Rev(Rev(x)+Rev(y)))