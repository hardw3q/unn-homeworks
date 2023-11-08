#include <stdio.h>
#include "stdlib.h"
#include <time.h>
#define LEN 500000
int sortSlianie(int *a, int c){
    if (c == 1){
    }else{
        int cd = c / 2, fr, lr;
        if (c % 2 !=  0){
            fr = cd;
            lr = cd + 1;
        }else{
            fr = cd;
            lr = cd;
        }
        int f [fr], l [lr];
        for(int i = 0; i < cd; i++){
            f[i] = a[i];
            l[i] = a[cd + i];
        }
        if(lr > fr){
            l[cd] = a[c - 1];
        }
        sortSlianie(f, fr);
        sortSlianie(l, lr);

        int ft = 0, lt = 0;
        for(int i = 0; i < c; i++){
            if (ft > fr - 1){
                a[i] = l[lt];
                lt += 1;
            }else if(lt > lr - 1){
                a[i] = f[ft];
                ft += 1;
            }else{
                if (f[ft] > l[lt]){
                    a[i] = l[lt];
                    lt += 1;
                }else{
                    a[i] = f[ft];
                    ft += 1;
                }
            }
        }
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
    int min = 1;
    int max = LEN;
    for(int i = 0; i < LEN; i++){
        massive[i] = rand() % (max - min) + min;;
//        printf("%d ",massive[i]);
//       printf("%d ", massive[i]);
    }
    timeToConsole();

    sortSlianie(massive, LEN);
    timeToConsole();

    for(int i = 0; i < LEN; i++){
        printf("%d ", massive[i]);
    }
    return 0;
}
