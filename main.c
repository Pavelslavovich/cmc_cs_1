#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

long long number_of_comparison_1=0,number_of_movement_1=0,number_of_comparison_2=0,number_of_movement_2=0;
double average_number_of_comparison_1=0,average_number_of_comparison_2=0,average_number_of_movement_1=0,average_number_of_movement_2=0;

void reverse_sort(long long* a,long long n){
    for (int i=0;i<n-1;i++){
        long long max_index=i;
        for (int j=i+1;j<n;j++){
            
            if (a[max_index]<a[j]){
                max_index=j;
            }
            
        }
        if (max_index!=i){
            number_of_movement_1++;
            long long c=a[i];
            a[i]=a[max_index];
            a[max_index]=c;
        }
    }
}

void selection_sort(long long* a,long long n){
    for (int i=0;i<n-1;i++){
        long long min_index=i;
        for (int j=i+1;j<n;j++){
            number_of_comparison_1++;
            if (a[min_index]>a[j]){
                min_index=j;
            }
            
        }
        if (min_index!=i){
            number_of_movement_1++;
            long long c=a[i];
            a[i]=a[min_index];
            a[min_index]=c;
        }
    }
}

void shell_sort(long long *a, long long n) {
    for (long long step = n / 2; step > 0; step /= 2) {
        for (long long i = step; i < n; i++) {


            for (long long j = i - step; j >= 0 ; j -= step) {
                number_of_comparison_2++;
                if (a[j] > a[j + step]){
                    number_of_movement_2++;
                    long long c = a[j];
                    a[j] = a[j + step];
                    a[j + step] = c;
                }
                else{
                    break;
                }

            }
        }
    }
}


int main(void){
    long long n=10;
    
    
    //non-decreasing array
    long long* a_1=malloc(sizeof(long long)*n);
    long long* a_2=malloc(sizeof(long long)*n);
    srand(time(NULL));
    for (int i=0;i<n;i++){
        a_1[i]=(long long)rand()*(long long)rand()*(long long)rand();
    }
    selection_sort(a_1,n);
    memcpy(a_2,a_1,n*sizeof(long long));
    number_of_comparison_1=0;
    number_of_movement_1=0;
    selection_sort(a_1,n);
    shell_sort(a_2,n);
    average_number_of_comparison_1+=number_of_comparison_1;
    average_number_of_movement_1+=number_of_movement_1;
    average_number_of_comparison_2+=number_of_comparison_2;
    average_number_of_movement_2+=number_of_movement_2;
    printf("1:\nNumber_of_comparison = %lld %lld\nNumber_of_movement = %lld %lld\n",number_of_comparison_1,number_of_comparison_2,number_of_movement_1,number_of_movement_2);
    printf("\n");
    number_of_comparison_1=0;
    number_of_movement_1=0;
    number_of_comparison_2=0;
    number_of_movement_2=0;

    //non-increasing array;
    for (int i=0;i<n;i++){
        a_1[i]=(long long)rand()*(long long)rand()*(long long)rand();
    }
    reverse_sort(a_1,n);
    memcpy(a_2,a_1,n*sizeof(long long));
    selection_sort(a_1,n);
    shell_sort(a_2,n);
    average_number_of_comparison_1+=number_of_comparison_1;
    average_number_of_movement_1+=number_of_movement_1;
    average_number_of_comparison_2+=number_of_comparison_2;
    average_number_of_movement_2+=number_of_movement_2;
    printf("2:\nNumber_of_comparison = %lld %lld\nNumber_of_movement = %lld %lld\n",number_of_comparison_1,number_of_comparison_2,number_of_movement_1,number_of_movement_2);
    printf("\n");
    number_of_comparison_1=0;
    number_of_movement_1=0;
    number_of_comparison_2=0;
    number_of_movement_2=0;

    //non-sorted array 1
    for (int i=0;i<n;i++){
        a_1[i]=(long long)rand()*(long long)rand()*(long long)rand();
        
    }
    memcpy(a_2,a_1,n*sizeof(long long));
    selection_sort(a_1,n);
    shell_sort(a_2,n);
    average_number_of_comparison_1+=number_of_comparison_1;
    average_number_of_movement_1+=number_of_movement_1;
    average_number_of_comparison_2+=number_of_comparison_2;
    average_number_of_movement_2+=number_of_movement_2;
    printf("3:\nNumber_of_comparison = %lld %lld\nNumber_of_movement = %lld %lld\n",number_of_comparison_1,number_of_comparison_2,number_of_movement_1,number_of_movement_2);
    printf("\n");
    number_of_comparison_1=0;
    number_of_movement_1=0;
    number_of_comparison_2=0;
    number_of_movement_2=0;

    //non-sorted array 2
    for (int i=0;i<n;i++){
        a_1[i]=(long long)rand()*(long long)rand()*(long long)rand();
    }
    memcpy(a_2,a_1,n*sizeof(long long));
    selection_sort(a_1,n);
    shell_sort(a_2,n);
    average_number_of_comparison_1+=number_of_comparison_1;
    average_number_of_movement_1+=number_of_movement_1;
    average_number_of_comparison_2+=number_of_comparison_2;
    average_number_of_movement_2+=number_of_movement_2;

    average_number_of_comparison_1/=4;
    average_number_of_movement_1/=4;
    average_number_of_comparison_2/=4;
    average_number_of_movement_2/=4;

    printf("4:\nNumber_of_comparison = %lld %lld\nNumber_of_movement = %lld %lld\n",number_of_comparison_1,number_of_comparison_2,number_of_movement_1,number_of_movement_2);    
    number_of_comparison_1=0;
    number_of_movement_1=0;
    number_of_comparison_2=0;
    number_of_movement_2=0;
    printf("\n");
    printf("Average_number_of_comparison = %.2lf %.2lf\nAverage_number_of_movement = %.2lf %.2lf\n",average_number_of_comparison_1,average_number_of_comparison_2,average_number_of_movement_1,average_number_of_movement_2);
}
