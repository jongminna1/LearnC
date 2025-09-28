# LearnC
Learning about Clang especially C99

## 📚 C언어 스택(Stack) 자료구조 완전 정복

이 문서는 C언어의 핵심 자료구조 중 하나인 스택(Stack)의 개념부터 구현까지의 학습 내용을 정리한 노트입니다.

### 1. 스택(Stack)이란? 🥞

스택은 **LIFO(Last-In, First-Out, 후입선출)** 원칙을 따르는 선형 자료구조입니다. 마치 프링글스 과자 통처럼, 가장 마지막에 넣은 데이터가 가장 먼저 나오는 구조를 가지고 있습니다.

-   **LIFO 원칙**: 가장 나중에 들어온 것이 가장 먼저 나간다.
-   **핵심 비유**: 프링글스 과자 통, 쌓아 올린 접시 더미

### 2. 스택의 핵심 연산(Operations)

스택은 다음과 같은 핵심 기능(ADT)을 가집니다.

-   **`push(item)`**: 스택의 맨 위에 새로운 데이터를 추가합니다.
-   **`pop()`**: 스택의 맨 위에서 데이터를 제거하고 그 값을 반환합니다.
-   **`peek()`** 또는 **`top()`**: 스택의 맨 위 데이터를 제거하지 않고 값만 확인합니다.
-   **`isEmpty()`**: 스택이 비어있는지 확인합니다. (비어있으면 True/1)
-   **`isFull()`**: (배열 구현 시) 스택이 꽉 찼는지 확인합니다.

### 3. C언어 배열 기반 스택 구현 코드

구조체와 배열을 이용해 C언어로 스택을 직접 구현한 코드입니다.

```c
#include <stdio.h>
#define STACK_SIZE 10 // 스택의 최대 크기 정의

// 스택을 표현하는 구조체
typedef struct {
    int data[STACK_SIZE]; // 데이터를 저장할 배열
    int top;              // 스택의 맨 위를 가리키는 인덱스
} Stack;

// 1. 스택 초기화 함수
void init_stack(Stack *s) {
    s->top = -1; // top이 -1이면 스택이 비어있다는 의미
}

// 2. 스택이 비어있는지 확인하는 함수
int is_empty(Stack *s) {
    // (s->top == -1) 비교문의 결과(1 또는 0)를 바로 반환
    return (s->top == -1);
}

// 3. 스택이 꽉 찼는지 확인하는 함수
int is_full(Stack *s) {
    return (s->top == STACK_SIZE - 1);
}

// 4. 스택에 데이터를 넣는 함수 (push)
void push(Stack *s, int item) {
    if (is_full(s)) {
        printf("스택이 꽉 찼습니다!\n");
        return;
    }
    s->data[++(s->top)] = item;
}

// 5. 스택에서 데이터를 빼는 함수 (pop)
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("스택이 비어있습니다!\n");
        return -1; // 오류를 의미하는 값
    }
    return s->data[(s->top)--];
}

int main(void) {
    Stack my_stack;
    init_stack(&my_stack);

    printf("스택에 10, 20, 30을 push 합니다.\n");
    push(&my_stack, 10);
    push(&my_stack, 20);
    push(&my_stack, 30);

    printf("스택에서 pop 합니다.\n");
    while (!is_empty(&my_stack)) {
        printf("pop -> %d\n", pop(&my_stack));
    }

    return 0;
}
