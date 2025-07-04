#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
double solution(int arr[], size_t arr_len) {
    double answer = 0;
    
    int temp = 0;
    for(int idx = 0; idx < arr_len; idx++){
        temp += arr[idx];
    }
    
    answer = ((double)temp / arr_len);
    return answer;
}