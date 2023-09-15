t = int(input())
for _ in range(t):
    cat = ['m', 'e', 'o', 'w', 'M', 'E', 'O', 'W']
    n = int(input())
    s = input()
    for i in s:
        if(i not in cat):
            print("NO")
            break
    print("YES")