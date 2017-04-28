#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct params {
        int i, j, n;
};

int **a, **b, **c;

void *matrix_mul(void *params)
{
        struct params *args = (struct params *)params;
        int sum = 0;
        for(int i = 0;i < args->n;i++) {
                sum += a[args->i][i] * b[i][args->j];
        }
        c[args->i][args->j] = sum;
        pthread_exit(NULL);
}

int main(void)
{
        int n;
        printf("size of the square matrix: ");
        scanf("%i", &n);
        a = (int **)malloc(n * sizeof(int *));
        b = (int **)malloc(n * sizeof(int *));
        c = (int **)malloc(n * sizeof(int *));
        for(int i = 0;i < n;i++) {
                a[i] = (int *)malloc(n * sizeof(int));
                b[i] = (int *)malloc(n * sizeof(int));
                c[i] = (int *)malloc(n * sizeof(int));
        }
        printf("enter number for the first matrix: ");
        for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                        scanf("%i", &a[i][j]);
        printf("enter number for the second matrix: ");
        for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                        scanf("%i", &b[i][j]);
        for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                        struct params *args = (struct params *)malloc(sizeof(struct params));
                        args->i = i;
                        args->j = j;
                        args->n = n;
                        pthread_t thread;
                        int threadr = pthread_create(&thread, NULL, matrix_mul, (void *)args);
                        if(threadr) {
                                printf("Error creating thread. %i\n", threadr);
                                return -1;
                        }
                        int joinr = pthread_join(thread, NULL);
                        if(joinr) {
                                printf("Error returning threads. %i\n", joinr);
                                return -1;
                        }
                }
        }
        for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++)
                        printf("%i\t", c[i][j]);
                printf("\n");
        }
        return 0;
}
