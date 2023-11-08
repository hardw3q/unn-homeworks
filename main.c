#include <stdio.h>
#include "stdlib.h"
#include <time.h>

#define LEN 100000
void bubbleSorting(int pyzir[LEN]){
    for(int i = 0; i + 1 < LEN; i++){
        if(i % (LEN/10) == 0){
            printf("%d\n", i);
        }
        for(int а = 0; а + 1 < (LEN - i) ; а++){
            if(pyzir[а + 1] < pyzir[а]){
                int tmp = pyzir[а];
                pyzir[а] = pyzir[а + 1];
                pyzir[а + 1] = tmp;
            }
        }
    }
}

void viborSorting(int vibor[LEN]){
    for(int i = 0; i < LEN; i++){
        if(i % (LEN/10) == 0){
            printf("%d\n", i);
        }
        for(int j = i; j < LEN; j++){
            if(vibor[j] < vibor[i]){
                int temp = vibor[i];
                vibor[i] = vibor[j];
                vibor[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[]) {
    int i, k, j;
    for (i = 1; i < LEN; i++) {
        if(i % (LEN/10) == 0){
            printf("%d\n", i);
        }
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}
void printArray(int arr[]){
    for (int i = 1; i < LEN; i++) {
        printf("%d ", arr[i]);
    }
}
void timeToConsole(){
    time_t currentTime;
    struct tm *localTime;

    // Получаем текущее время
    currentTime = time(NULL);

    // Преобразуем текущее время в локальное время
    localTime = localtime(&currentTime);

    // Выводим текущее время
    printf("Текущее время: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

}
int main() {
    int massive[LEN];
    int vibor[LEN];
    int pyzir[LEN];
    int insertion[LEN];
    int min = 1;
    int max = LEN;
    for(int i = 0; i < LEN; i++){
       massive[i] = rand() % (max - min) + min;;
       vibor[i] = massive[i];
       pyzir[i] = massive[i];
       insertion[i] = massive[i];
//       printf("%d ", massive[i]);
    }
    timeToConsole();
    printf("\n");
    printf("%s\n", "Сортировка выбором:");
    // Сортировка выбором
    viborSorting(vibor);
    timeToConsole();
//    printArray(vibor);
    printf("\n");
    printf("%s\n", "Сортировка пузырьком:");
    bubbleSorting(pyzir);
    timeToConsole();
//    printArray(pyzir);
    printf("\n");
    printf("%s\n", "Сортировка вставками:");
    insertionSort(insertion);
    timeToConsole();
//    printArray(insertion);
    return 0;
}




