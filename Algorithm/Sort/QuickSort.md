# 🚀 C언어 퀵 정렬(Quick Sort) 알고리즘

`stdlib.h`에 포함된 표준 라이브러리 함수 `qsort`는 C언어에서 가장 널리 쓰이는 강력한 정렬 도구입니다. 이 문서에서는 `qsort`의 기반이 되는 **퀵 정렬(Quick Sort)** 알고리즘의 동작 원리를 알아보고, 직접 구현해 봅니다.

## 1. 퀵 정렬의 핵심 원리: 분할 정복 (Divide and Conquer)

퀵 정렬은 **'분할 정복'**이라는 전략을 사용합니다. 복잡한 문제를 더 이상 쪼갤 수 없을 때까지 작은 문제로 나눈 뒤, 이를 각각 해결하여 전체 문제를 해결하는 방식입니다.

**교실에서 키 순서로 줄 서기**에 비유할 수 있습니다.
1.  **기준(Pivot) 정하기**: 임의로 학생 한 명을 기준(피벗)으로 뽑습니다.
2.  **분할(Partition)**: 기준보다 작은 학생은 왼쪽, 큰 학생은 오른쪽으로 나눕니다. 이제 기준 학생은 자신의 최종 위치를 찾았습니다.
3.  **재귀(Recursion)**: 왼쪽 그룹과 오른쪽 그룹에서 각각 새로운 기준을 뽑아, 그룹의 크기가 1이 될 때까지 2번 과정을 반복합니다.

이 과정을 거치면 결국 전체 학생이 완벽하게 키 순서로 정렬됩니다.



---

## 2. C언어 직접 구현 코드

퀵 정렬은 주로 `partition` 함수와 이를 재귀적으로 호출하는 `quickSort` 함수로 구현됩니다.

```c
#include <stdio.h>

// 두 원소의 위치를 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 배열을 피벗 기준으로 분할하는 함수
 * @param arr 정렬할 배열
 * @param low 배열의 시작 인덱스
 * @param high 배열의 끝 인덱스
 * @return 피벗의 최종 위치 인덱스
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 가장 오른쪽 원소를 피벗으로 선택
    int i = (low - 1);     // 피벗보다 작은 원소 그룹의 마지막 인덱스

    for (int j = low; j <= high - 1; j++) {
        // 현재 원소가 피벗보다 작거나 같으면, 작은 원소 그룹으로 보낸다.
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // 최종적으로 피벗을 작은 그룹과 큰 그룹 사이에 위치시킨다.
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * @brief 퀵 정렬을 수행하는 메인 함수
 * @param arr 정렬할 배열
 * @param low 배열의 시작 인덱스
 * @param high 배열의 끝 인덱스
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 분할하여 피벗의 위치를 찾는다.
        int pi = partition(arr, low, high);

        // 피벗을 기준으로 나뉜 두 개의 부분 배열에 대해 재귀적으로 퀵 정렬을 호출한다.
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("정렬 전 배열: \n");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("정렬 후 배열: \n");
    printArray(arr, n);
    
    return 0;
}
