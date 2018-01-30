# Problem

you are given with two binary numbers in string form. your task is to add those two binary numbers and print resultant binary number.

# what's my approach.

let's take one example 

`1010`(is 10) and `0101` (is 5) the result should be 
```
  1010
+ 0101
-------
  1111

```
 1111 is 15, basically it 10 + 5 = 15.
Now I think you got me.

step 1: convert binary string into decimal representation.(i.e `0101` to to `10` ... )

step 2: add resultant decimal value. ( ie `10` + `5` = `15` )

step 3: now convert decimal value to binary string.( ie `15` => `1111`)


solution : 
C Lang

```c
#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 100

// since it can be a big number we will take long long int
long long int binaryToInteger(char binary[size]){
    int length = strlen(binary);
    int i;
    long long int twoRaisedToN = 1;
    // i starts from right and goes till left
    // thus i is initialized with length -1
    long long int returnValue = 0;
    for(i=length-1; i>=0; --i){
        if( binary[i] == '1' ) { // if it's a set bit or 1 bit
            // add 2^x to return value
            returnValue += twoRaisedToN;
        }
        twoRaisedToN *= 2;
    }
    // let's return whatever there in returnValue
    return returnValue;
}



void binaryRecursive(long long result){
    if(result == 0)
        return;
    binaryRecursive( result/ 2 );
    printf("%lld", result % 2);
}


void convertToBinary(long long int result){
    if ( result == 0 ){ // if number is already zero then print it right here
        printf("0");
    }else{ // number isn't zero call the recursive convert function
        binaryRecursive(result);
    }
}

int main(){
    // allocate enough memory for storing binary string.
    char binaryInput1[100] = {'\0'}, binaryInput2[100] = {'\0'};
    scanf("%s%s", binaryInput1, binaryInput2);
    

    // convert string to decimal
    long long int decimalInput1, decimalInput2;
    decimalInput1 =  binaryToInteger(binaryInput1);
    decimalInput2 =  binaryToInteger(binaryInput2);

    // add them up.
    long long int result = decimalInput1 + decimalInput2;

    // convert result into binary representation and print
    convertToBinary(result);
    printf("\n");
    return 0;
}


```

python :


```python



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

```
