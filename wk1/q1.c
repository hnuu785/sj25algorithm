#include <stdio.h>
#include <stdlib.h>

// 이중연결리스트 노드 구조체
typedef struct Node {
    char elem;
    struct Node* prev;
    struct Node* next;
} Node;

// 이중연결리스트 구조체
typedef struct List {
    Node* header;
    Node* trailer;
    int size;
} List;

// 리스트 초기화
void initList(List* list) {
    list->header = (Node*)malloc(sizeof(Node));
    list->trailer = (Node*)malloc(sizeof(Node));
    
    list->header->prev = NULL;
    list->header->next = list->trailer;
    list->trailer->prev = list->header;
    list->trailer->next = NULL;
    list->size = 0;
}

// 순위 r에 원소 e 삽입
void add(List* list, int r, char e) {
    if (r < 1 || r > list->size + 1) {
        printf("invalid position\n");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->elem = e;
    
    // 순위 r에 삽입할 위치 찾기
    Node* current = list->header;
    for (int i = 0; i < r; i++) {
        current = current->next;
    }
    
    // 새 노드 연결
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    
    list->size++;
}

// 순위 r의 원소 삭제
void delete(List* list, int r) {
    if (r < 1 || r > list->size) {
        printf("invalid position\n");
        return;
    }
    
    // 삭제할 노드 찾기
    Node* current = list->header;
    for (int i = 0; i < r; i++) {
        current = current->next;
    }
    
    // 노드 연결 해제
    current->prev->next = current->next;
    current->next->prev = current->prev;
    
    free(current);
    list->size--;
}

// 순위 r의 원소 반환
char get(List* list, int r) {
    if (r < 1 || r > list->size) {
        printf("invalid position\n");
        return '\0';
    }
    
    Node* current = list->header;
    for (int i = 0; i < r; i++) {
        current = current->next;
    }
    
    return current->elem;
}

// 리스트의 모든 원소 출력
void print(List* list) {
    Node* current = list->header->next;
    while (current != list->trailer) {
        printf("%c", current->elem);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List list;
    initList(&list);
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char operation;
        scanf(" %c", &operation);
        
        if (operation == 'A') {
            int r;
            char e;
            scanf("%d %c", &r, &e);
            add(&list, r, e);
        }
        else if (operation == 'D') {
            int r;
            scanf("%d", &r);
            delete(&list, r);
        }
        else if (operation == 'G') {
            int r;
            scanf("%d", &r);
            char result = get(&list, r);
            if (result != '\0') {
                printf("%c\n", result);
            }
        }
        else if (operation == 'P') {
            print(&list);
        }
    }
    
    return 0;
}
