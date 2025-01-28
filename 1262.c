#include <stdio.h>
#include <string.h>

int calculateMinCycles(char *trace, int processes) {
    int cycles = 0;
    int i = 0;
    int len = strlen(trace);
    
    while (i < len) {
        if (trace[i] == 'W') {
            cycles++;
            i++;
        } else { 
            int reads = 0;
            while (i < len && trace[i] == 'R') {
                reads++;
                i++;
            }
            cycles += (reads + processes - 1) / processes;
        }
    }
    
    return cycles;
}

int main() {
    char trace[51];  
    int processes;
    while (scanf("%s", trace) != EOF) {
        scanf("%d", &processes);
        
        int result = calculateMinCycles(trace, processes);
        printf("%d\n", result);
    }
    
    return 0;
}
