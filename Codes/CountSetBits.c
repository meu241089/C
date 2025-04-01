#include<stdio.h>
#include<conio.h>

int rem, binary = 0;
unsigned int

countSetBits (unsigned int n){

    unsigned int count = 0;

    while (n){
        count += n & 1;
        n >>= 1;
    }

    printf ("\n\t Number of  1's  in the binary number is : %d",count);
}

int dec_bin (int n){

    int i=1;

    while (n != 0){
        rem = n % 2;
        n = n / 2;
        binary = binary + (rem * i);
        i = i * 10;
    }

    printf("\n\t The converted Binary Equivalent is : %d",binary);
}

int main(){  
    int i = 0;

    printf ("\n\t Enter the Decimal Nummber: ");

    scanf ("%d", &i);

    int n= i;
    dec_bin(n);
    countSetBits (i);
    return 0;
}