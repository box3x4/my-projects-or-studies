#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *add_elem(void *line)
{
        int *line_pointer = (int *)line;
        int accum = 0;
        for(int i = 0;i < 3;i++)
                accum += *(line_pointer+i);
        *line_pointer = accum;
        pthread_exit(NULL);
}

int main(void)
{
        pthread_t thread;
        int matrix[2][3];
        matrix[0][0] = 1;
        matrix[0][1] = 2;
        matrix[0][2] = 3;
        matrix[1][0] = 1;
        matrix[1][1] = 1;
        matrix[1][2] = 1;
        int rc;
        rc = pthread_create(&thread, NULL, add_elem, &matrix[1]);
        if(rc) {
                printf("ERROR; return code from pthread_create() is %i\n", rc);
                return -1;
        }
        int *line = matrix[0];
        int accum = 0;
        for(int i = 0;i < 3;i++)
                accum += *(line+i);
        *line = accum;
        if(pthread_join(thread, NULL)) {
                printf("error joining thread\n");
                return -1;
        }
        printf("line 1: %i\nline 2: %i\n\n", matrix[0][0], matrix[1][0]);
        pthread_exit(NULL);
        return 0;
}
