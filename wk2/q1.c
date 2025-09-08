#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int n) {
    // 뒷부분부터 정렬하는 선택 정렬
    for (int i = n - 1; i > 0; i--) {
        int maxI = 0; // 가장 큰 값의 인덱스
        
        // 1부터 i까지 중에서 가장 큰 값 찾기
        for (int j = 1; j <= i; j++) {
            if (arr[j] > arr[maxI]) {
                maxI = j;
            }
        }
        
        // 제자리 정렬
        if (maxI != i) {
            int temp = arr[i];
            arr[i] = arr[maxI];
            arr[maxI] = temp;
        }
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
    
    // 선택 정렬 수행
    selection_sort(arr, n);
    
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
