#include <stdio.h>
#include <stdlib.h>

// 이진트리 노드 구조체
typedef struct TreeNode {
    int data;                    // 노드 번호
    struct TreeNode* left;       // 왼쪽 자식
    struct TreeNode* right;      // 오른쪽 자식
} TreeNode;

// 노드 생성 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 트리 생성 함수 (선위순회 순서로)
TreeNode* buildTree(int nodes[][3], int n, int* index) {
    if (*index >= n) return NULL;
    
    int nodeData = nodes[*index][0];
    int leftChild = nodes[*index][1];
    int rightChild = nodes[*index][2];
    (*index)++;
    
    TreeNode* root = createNode(nodeData);
    
    // 왼쪽 자식이 있으면 재귀적으로 생성
    if (leftChild != 0) {
        root->left = buildTree(nodes, n, index);
    }
    
    // 오른쪽 자식이 있으면 재귀적으로 생성
    if (rightChild != 0) {
        root->right = buildTree(nodes, n, index);
    }
    
    return root;
}

// 트리 탐색 함수
void traverseTree(TreeNode* root, char* path) {
    TreeNode* current = root;
    printf(" %d", current->data);  // 루트 노드 출력
    
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == 'L' && current->left != NULL) {
            current = current->left;
            printf(" %d", current->data);
        } else if (path[i] == 'R' && current->right != NULL) {
            current = current->right;
            printf(" %d", current->data);
        } else {
            // 경로가 유효하지 않으면 탐색 중단
            break;
        }
    }
    printf("\n");
}

// 메모리 해제 함수
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 노드 정보를 저장할 배열
    int nodes[1000][3];
    
    // 노드 정보 입력
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &nodes[i][0], &nodes[i][1], &nodes[i][2]);
    }
    
    // 트리 생성
    int index = 0;
    TreeNode* root = buildTree(nodes, n, &index);
    
    // 탐색 횟수 입력
    int s;
    scanf("%d", &s);
    
    // 탐색 수행
    for (int i = 0; i < s; i++) {
        char path[100];
        scanf("%s", path);
        traverseTree(root, path);
    }
    
    // 메모리 해제
    freeTree(root);
    
    return 0;
}
