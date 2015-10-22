#include <stdio.h>
#include <string.h>  /* memset */
#include <stdlib.h>  /* qsort */

int is_valid(int, int*, size_t count);

int compare(const void*, const void*);

int main(int argc, char *argv[]) {
    int input;
    int i = 0;
    int sequence[5];
    size_t count = sizeof(sequence) / sizeof(*sequence);

    memset(sequence, 0, sizeof(sequence));

    printf("Please input distinct positive 5 integers:\n");

    while (i < 5) {
        printf(">> ");
        scanf("%d", &input);

        if (is_valid(input, sequence, count)) {
            sequence[i] = input;
            i++;
            continue;
        }

        printf("You already typed this value.");
        printf("Please input a different value again.\n");
    }

    qsort(sequence, count, sizeof(*sequence), compare);
    printf(
        "The maximum number is %d and the minimum number is %d\n",
        sequence[count - 1],
        sequence[0]
    );

    return 0;
}

int is_valid(int number, int *sequence, size_t count) {
    for (int i = 0; i < count; i++) {
        if (number == (sequence[i])) {
            return 0;
        }
    }

    return 1;
}

int compare(const void *elem_a, const void *elem_b) {
    int a = *((int*) elem_a);
    int b = *((int*) elem_b);

    if (a > b) {
        return 1;
    } else if (b > a) {
        return -1;
    }

    return 0;
}

