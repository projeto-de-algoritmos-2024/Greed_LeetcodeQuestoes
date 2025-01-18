#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return ((int*)a)[1] - ((int*)b)[1];
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    qsort(courses, coursesSize, sizeof(courses[0]), compare);

    int* maxHeap = (int*)malloc(coursesSize * sizeof(int));
    int heapSize = 0, totalTime = 0;

    for (int i = 0; i < coursesSize; i++) {
        int duration = courses[i][0];
        int lastDay = courses[i][1];

        if (totalTime + duration <= lastDay) {
            maxHeap[heapSize++] = duration;
            totalTime += duration;

            for (int j = heapSize - 1; j > 0 && maxHeap[j] > maxHeap[j - 1]; j--) {
                int temp = maxHeap[j];
                maxHeap[j] = maxHeap[j - 1];
                maxHeap[j - 1] = temp;
            }
        } else if (heapSize > 0 && maxHeap[0] > duration) {
            totalTime += duration - maxHeap[0];
            maxHeap[0] = duration;

            for (int j = 0; j < heapSize - 1 && maxHeap[j] < maxHeap[j + 1]; j++) {
                int temp = maxHeap[j];
                maxHeap[j] = maxHeap[j + 1];
                maxHeap[j + 1] = temp;
            }
        }
    }

    int result = heapSize;
    free(maxHeap);
    return result;
}