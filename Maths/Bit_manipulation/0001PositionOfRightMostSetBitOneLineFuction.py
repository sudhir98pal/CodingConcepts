# step 1: Find two's complement 
# step 2: Bitwise and(&) with original number
# step 3:Take log2


import math
def PositionOfRightMostSetBit(n):
    return math.log2(n&(-n))+1



for i in range(10):
    x=int(input())
    print(PositionOfRightMostSetBit(x))
