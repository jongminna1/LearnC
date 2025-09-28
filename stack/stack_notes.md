# 🥞 스택 (Stack) 자료구조 핵심 정리

이 문서는 C언어의 핵심 자료구조 중 하나인 스택(Stack)의 기본 개념부터 구현까지의 내용을 요약합니다.

## 1. 스택이란?

**스택(Stack)**은 **LIFO(Last-In, First-Out, 후입선출)** 원칙을 따르는 선형 자료구조입니다. 가장 마지막에 쌓은 접시를 가장 먼저 꺼내는 것처럼, 마지막에 입력된 데이터가 가장 먼저 출력되는 구조를 가지고 있습니다.



-   **핵심 원칙**: **LIFO (후입선출)**. 가장 나중에 들어온 것이 가장 먼저 나간다.
-   **주요 비유**: 프링글스 과자 통, 쌓아 올린 접시 더미, 막다른 골목길

---

## 2. 스택의 핵심 연산 (Core Operations)

스택이라는 추상 자료형(ADT)은 주로 아래와 같은 기능(연산)들로 정의됩니다.

| 연산         | 설명                                                         |
| :----------- | :----------------------------------------------------------- |
| **`push()`** | 스택의 가장 윗부분(top)에 새로운 데이터를 추가합니다.        |
| **`pop()`** | 스택의 가장 윗부분(top)에서 데이터를 제거하고 그 값을 반환합니다. |
| **`peek()`** | 스택의 가장 윗부분(top)의 데이터를 제거하지 않고 값만 확인합니다. |
| **`isEmpty()`** | 스택이 비어있는지 확인합니다. (비어있으면 1/True)             |
| **`isFull()`** | (배열 구현 시) 스택이 가득 찼는지 확인합니다.                |

---

## 3. C언어 배열 기반 스택 구현 예제

구조체와 배열을 이용해 C언어로 스택을 직접 구현한 기본 코드입니다.

```c
#include <stdio.h>
#define STACK_SIZE 10 // 스택의 최대 크기

// 스택을 표현하는 구조체
typedef struct {
    int data[STACK_SIZE]; // 데이터를 저장할 배열
    int top;              // 스택의 맨 위를 가리키는 인덱스
} Stack;

// 스택 초기화
void init_stack(Stack *s) {
    s->top = -1; // top이 -1이면 스택이 비어있다는 의미
}

// 스택이 비어있는지 확인
int is_empty(Stack *s) {
    return (s->top == -1);
}

// 스택이 꽉 찼는지 확인
int is_full(Stack *s) {
    return (s->top == STACK_SIZE - 1);
}

// 스택에 데이터 추가 (push)
void push(Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++(s->top)] = item;
}

// 스택에서 데이터 꺼내기 (pop)
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack Underflow!\n");
        return -1; // 오류 값
    }
    return s->data[(s->top)--];
}
