import random
import string
import time

target = input("비밀 문구 입력: ")

chars = string.ascii_letters + string.digits + "!@#$%^&*"

current = [" "] * len(target)

while "".join(current) != target:
    for i in range(len(target)):
        if current[i] != target[i]:
            current[i] = random.choice(chars)

    print("\r" + "".join(current), end="")
    time.sleep(0.03)

    for i in range(len(target)):
        if random.random() < 0.1:
            current[i] = target[i]

print("\r" + target)
print("\n접속 완료 😎")

print("dho안돼")