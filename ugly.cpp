#include <stdio.h>
#include <algorithm>

using namespace std;

int nth_ugly_number(int n){
    int ugly_numbers[n];
    ugly_numbers[0] = 1;
    int ugly_index = 1;
    int index2, index3, index5 = 0;
    index2 = index3 = index5;

    while(ugly_index < n){
        int min_1 = min(ugly_numbers[index2]*2, ugly_numbers[index3]*3);
        int minimum = min(min_1, ugly_numbers[index5] * 5);
        ugly_numbers[ugly_index] = minimum;

        while(ugly_numbers[index2] * 2 <= ugly_numbers[ugly_index])
            index2++;
        while(ugly_numbers[index3] * 3 <= ugly_numbers[ugly_index])
            index3++;
        while(ugly_numbers[index5] * 5 <= ugly_numbers[ugly_index])
            index5++;
        ugly_index++;
    }
    return ugly_numbers[ugly_index-1];
}

int main(){
    int n = 1500;
    int nth_ugly = 0;
    nth_ugly = nth_ugly_number(n);

    printf("The %d\'th ugly number is %d.\n", n, nth_ugly);
    return 0;
}
