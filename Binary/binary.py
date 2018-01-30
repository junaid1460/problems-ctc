

# define a function which converts string into number
def toNumber(binary):
    twoRaisedToN = 1
    result = 0
    binary = reversed(binary)
    for bit in binary:
        if bit == '1':
            result += twoRaisedToN
        twoRaisedToN *= 2
    return result


def answer():
    binary1 = input().strip()
    binary2 = input().strip()

    # binary1 = "1010"
    # binary2 = "0101"
    
    decimal1 = toNumber(binary1)
    decimal2 = toNumber(binary2)

    result = decimal1 + decimal2
    result = str(bin(result))
    result = result[2:]
    print(result)


# make unsafe call to function answer() to start

answer()