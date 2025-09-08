#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 선택 정렬 함수
void selection_sort(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int maxI = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] > arr[maxI]) {
                maxI = j;
            }
        }
        if (maxI != i) {
            int temp = arr[i];
            arr[i] = arr[maxI];
            arr[maxI] = temp;
        }
    }
}

// 삽입 정렬 함수
void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int element = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > element) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }
}

// 배열 복사 함수
void copy_array(int *source, int *dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 동적 배열 할당
    int *arr = (int*)malloc(n * sizeof(int));
    int *arrA = (int*)malloc(n * sizeof(int));
    int *arrB = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL || arrA == NULL || arrB == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    // 배열 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 동일한 데이터로 두 배열 초기화
    copy_array(arr, arrA, n);
    copy_array(arr, arrB, n);
    
    // 선택 정렬 시간 측정
    clock_t start = clock();
    selection_sort(arrA, n);
    clock_t end = clock();
    double selection_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; // ms 단위
    
    // 삽입 정렬 시간 측정
    start = clock();
    insertion_sort(arrB, n);
    end = clock();
    double insertion_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; // ms 단위
    
    // 결과 출력
    printf("%d\n", n);
    printf("%.9fms\n", selection_time);
    printf("%.9fms\n", insertion_time);
    
    // 메모리 해제
    free(arr);
    free(arrA);
    free(arrB);
    
    return 0;
}
