#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void heapify(int pq[], int pq_size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq_size && pq[left] > pq[largest]) {
        largest = left;
    }
    if (right < pq_size && pq[right] > pq[largest]) {
        largest = right;
    }
    if (largest != index) {
        int temp = pq[index];
        pq[index] = pq[largest];
        pq[largest] = temp;
        heapify(pq, pq_size, largest);
    }
}

void process_case(int n) {
    int stack[1000], stack_top = -1;
    int queue[1000], queue_front = 0, queue_back = 0;
    int pq[1000], pq_size = 0;

    bool is_stack = true, is_queue = true, is_pq = true;

    for (int i = 0; i < n; i++) {
        int cmd, x;
        scanf("%d", &cmd);

        if (cmd == 1) {
            scanf("%d", &x);
            if (is_stack) stack[++stack_top] = x;
            if (is_queue) queue[queue_back++] = x;
            if (is_pq) {
                pq[pq_size++] = x;
                int j = pq_size - 1;
                while (j > 0 && pq[j] > pq[(j - 1) / 2]) {
                    int temp = pq[j];
                    pq[j] = pq[(j - 1) / 2];
                    pq[(j - 1) / 2] = temp;
                    j = (j - 1) / 2;
                }
            }

        } else if (cmd == 2) {
            scanf("%d", &x);
            if (is_stack) {
                if (stack_top >= 0 && stack[stack_top] == x) {
                    stack_top--;
                } else {
                    is_stack = false;
                }
            }
            if (is_queue) {
                if (queue_front < queue_back && queue[queue_front] == x) {
                    queue_front++;
                } else {
                    is_queue = false;
                }
            }
            if (is_pq) {
                if (pq_size > 0 && pq[0] == x) {
                    pq[0] = pq[--pq_size];
                    heapify(pq, pq_size, 0);
                } else {
                    is_pq = false;
                }
            }
        }
    }
    if (is_stack && !is_queue && !is_pq) {
        printf("stack\n");
    } else if (!is_stack && is_queue && !is_pq) {
        printf("queue\n");
    } else if (!is_stack && !is_queue && is_pq) {
        printf("priority queue\n");
    } else if (!is_stack && !is_queue && !is_pq) {
        printf("impossible\n");
    } else {
        printf("not sure\n");
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        process_case(n);
    }
    return 0;
}
