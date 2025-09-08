#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n) {
    //앞부분을 정렬 상태로 유지
    for (int i = 1; i < n; i++) {
        int element = arr[i];
        int j = i - 1;    // 앞에 원소들
        
        // 정렬된 부분에서 앞보다 큰 원소들을 오른쪽으로 이동
        while (j >= 0 && arr[j] > element) {
            arr[j + 1] = arr[j]; // 제자리 정렬(1)
            j--;
        }
        
        // element를 삽입
        arr[j + 1] = element; // 제자리 정렬(2)
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 동적 배열 할당
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    // 배열 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 삽입 정렬 수행
    insertion_sort(arr, n);
    
    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    // 메모리 해제
    free(arr);
    
    return 0;
}
