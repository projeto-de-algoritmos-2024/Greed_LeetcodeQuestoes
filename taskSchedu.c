#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 26

int leastInterval(char* tasks, int tasksSize, int n) {
    int taskCounts[MAX_TASKS] = {0};

    for (int i = 0; i < tasksSize; i++) {
        taskCounts[tasks[i] - 'A']++;
    }

    int maxFreq = 0, maxFreqCount = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        if (taskCounts[i] > maxFreq) {
            maxFreq = taskCounts[i];
            maxFreqCount = 1;
        } else if (taskCounts[i] == maxFreq) {
            maxFreqCount++;
        }
    }

    int partCount = maxFreq - 1;
    int partLength = n - (maxFreqCount - 1);
    int emptySlots = partCount * partLength;
    int remainingTasks = tasksSize - (maxFreq * maxFreqCount);
    int idles = (emptySlots > remainingTasks) ? emptySlots - remainingTasks : 0;

    return tasksSize + idles;
}
