import hashlib

str = input()
result = hashlib.sha256(str.encode())
print(result.hexdigest())
