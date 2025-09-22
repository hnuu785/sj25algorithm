#include <stdio.h>
#include <stdlib.h>

// 전역 변수
int H[100];  // 힙 배열 (인덱스 0은 사용하지 않음)
int n = 0;   // 현재 키 개수

// 키를 위로 이동
void upHeap(int i) {
    if (i == 1) return;  // 루트 노드면 종료
    
    int parent = i / 2;
    if (H[i] > H[parent]) {
        // 부모와 자식 교환
        int temp = H[i];
        H[i] = H[parent];
        H[parent] = temp;
        upHeap(parent);  // 재귀적으로 위로 올라감
    }
}

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

// 키 삽입
void insertItem(int key) {
    n++;
    H[n] = key;
    upHeap(n);
}

// 최대값 삭제
int removeMax() {
    int key = H[1];  // 루트 노드 (최대값)
    H[1] = H[n];     // 마지막 노드를 루트로 이동
    n--;             // 힙 크기 감소
    downHeap(1);     // 힙 속성 복원
    return key;
}

// 힙 내용 출력
void printHeap() {
    for (int i = 1; i <= n; i++) {
        printf("%d", H[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
}

// main 함수 - 대화식 힙 프로그램
int main() {
    char command;  // 입력받을 명령어
    int key;       // 삽입할 키 값
    
    // 무한 루프로 명령어를 계속 받음
    while (1) {
        scanf(" %c", &command);  // 공백을 포함한 문자 입력
        
        switch (command) {
            case 'i':  // 삽입 명령
                scanf("%d", &key);  // 키 값 입력
                insertItem(key);    // 힙에 키 삽입
                printf("0\n");      // 삽입 완료 신호 출력
                break;
                
            case 'd':  // 삭제 명령
                if (n > 0) {        // 힙이 비어있지 않으면
                    printf("%d\n", removeMax());  // 최대값 삭제 후 출력
                }
                break;
                
            case 'p':  // 출력 명령
                if (n > 0) {        // 힙이 비어있지 않으면
                    printHeap();    // 힙 내용 레벨 순서로 출력
                }
                break;
                
            case 'q':  // 종료 명령
                return 0; // 프로그램 종료
        }
    }
    
    return 0;
}
