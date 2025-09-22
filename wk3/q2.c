#include <stdio.h>
#include <stdlib.h>

// 전역 변수
int H[100];  // 힙 배열 (인덱스 0은 사용하지 않음)
int n;       // 키 개수

// 키를 아래로 이동
void downHeap(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    
    // 왼쪽 자식이 존재하고 더 크면
    if (left <= n && H[left] > H[largest]) {
        largest = left;
    }
    
    // 오른쪽 자식이 존재하고 더 크면
    if (right <= n && H[right] > H[largest]) {
        largest = right;
    }
    
    // 최대값이 현재 노드가 아니면 교환
    if (largest != i) {
        int temp = H[i];
        H[i] = H[largest];
        H[largest] = temp;
        downHeap(largest);  // 재귀적으로 아래로 내려감
    }
}

// 힙 내용 출력
void printHeap() {
    for (int i = 1; i <= n; i++) {
        printf("%d", H[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
}

// 재귀 방식 상향식 힙 생성
void rBuildHeap(int i) {
    if (i > n) return;  // 범위를 벗어나면 종료
    
    rBuildHeap(2 * i);      // 왼쪽 서브트리 처리
    rBuildHeap(2 * i + 1);  // 오른쪽 서브트리 처리
    downHeap(i);            // 현재 노드에서 downHeap 수행
}

int main() {
    // 키 개수 입력
    scanf("%d", &n);
    
    // 키들 입력
    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }
    
    // 상향식 힙 생성
    rBuildHeap(1);
    
    // 힙 출력
    printHeap();
    
    return 0;
}
