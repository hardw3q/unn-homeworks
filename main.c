#include <stdio.h>
#define LEN 10
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

int main() {
    int a[LEN] = {2,3,5,1,3,4,5,4,7,3};
    sortSlianie(a, LEN);
    for(int i = 0; i < LEN; i++){
        printf("%d", a[i]);
    }
    return 0;
}
