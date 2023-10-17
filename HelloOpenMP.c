#include <stdio.h>
#include <omp.h>


int main(int argc, char const* argv[]){
    int nthreads, thread_id;
    int i;
    int arr[5] = {1,3,5,7,9};
    #pragma omp parallel shared(nthreads){
        nthreads = omp_get_num_threads();
        thread_id = omp_get_thread_num();
        printf("Goodbye slow serial world and Hello OpenMP!\n");
        printf("I have %d thread(s) and my thread id is %d\n", nthreads, thread_id);
    }
    
    #pragma omp parallel for shared(arr) private(i)
    for (i = 0; i< 5; i++){
        printf("%d ", i+2);
    }
    return 0;
}

