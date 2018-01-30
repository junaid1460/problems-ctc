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