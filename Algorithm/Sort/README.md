# 🚀 C언어 퀵 정렬(Quick Sort) 알고리즘 분석 및 구현

> `stdlib.h`의 `qsort`는 어떻게 동작할까? 이 문서는 C언어의 대표적인 정렬 알고리즘인 **퀵 정렬(Quick Sort)**의 핵심 원리인 **분할 정복(Divide and Conquer)**을 이해하고, C언어로 직접 구현하며 그 장단점을 표준 라이브러리와 비교 분석합니다.

---

### 🎯 퀵 정렬의 핵심 아이디어

퀵 정렬은 **분할 정복 (Divide and Conquer)**이라는 강력한 전략을 사용하는, 평균 시간 복잡도 **$O(N \log N)$**의 매우 빠른 정렬 알고리즘입니다.

핵심 과정은 다음과 같습니다.

1.  **기준 (Pivot) 선택**: 배열 내에서 임의의 원소 하나를 **피벗(pivot)**으로 선택합니다.
2.  **분할 (Partition)**: 피벗을 기준으로 작은 값들은 모두 왼쪽으로, 큰 값들은 모두 오른쪽으로 재배치합니다. 이 과정이 끝나면 피벗은 자신의 최종 위치에 놓이게 됩니다.
3.  **재귀 (Recursion)**: 피벗을 제외한 왼쪽 부분 배열과 오른쪽 부분 배열에 대해, 배열의 크기가 1이 될 때까지 1, 2번 과정을 재귀적으로 반복합니다.



---

### ⚙️ C언어 직접 구현 코드

퀵 정렬은 주로 `partition` 함수와 이를 재귀적으로 호출하는 `quickSort` 함수로 구현됩니다.

```c
#include <stdio.h>

/**
 * @brief 두 정수 원소의 위치를 교환합니다.
 * @param a 교환할 첫 번째 정수의 포인터
 * @param b 교환할 두 번째 정수의 포인터
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 배열을 피벗 기준으로 분할하고, 피벗의 최종 위치를 반환합니다.
 * @param arr 정렬할 배열
 * @param low 배열의 시작 인덱스
 * @param high 배열의 끝 인덱스 (피벗으로 사용됨)
 * @return 분할 후 피벗의 위치 인덱스
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * @brief 퀵 정렬 알고리즘을 재귀적으로 수행합니다.
 * @param arr 정렬할 배열
 * @param low 배열의 시작 인덱스
 * @param high 배열의 끝 인덱스
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

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
