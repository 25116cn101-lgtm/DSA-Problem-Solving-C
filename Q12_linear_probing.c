#include <stdio.h>
#define SIZE 10

int table[SIZE];

void initialize(void) {
    int i;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;
}

int insert(int key) {
    int index = key % SIZE;
    int i, pos;

    for (i = 0; i < SIZE; i++) {
        pos = (index + i) % SIZE;

        if (table[pos] == -1) {
            table[pos] = key;
            printf("Inserted at index %d\n", pos);
            return pos;
        }

        if (table[pos] == key) {
            printf("Duplicate key\n");
            return -1;
        }
    }

    printf("Hash table is full\n");
    return -1;
}

int search(int key) {
    int index = key % SIZE;
    int i, pos;

    for (i = 0; i < SIZE; i++) {
        pos = (index + i) % SIZE;

        if (table[pos] == -1)
            return -1;

        if (table[pos] == key)
            return pos;
    }

    return -1;
}

void display(void) {
    int i;

    for (i = 0; i < SIZE; i++)
        printf("%d : %d\n", i, table[i]);
}

int main(void) {
    int ch, key, pos;

    initialize();

    do {
        printf("\n1.Insert 2.Search 3.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);

                if (key < 0) {
                    printf("Enter non-negative key\n");
                    break;
                }

                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);

                if (key < 0) {
                    printf("Invalid key\n");
                    break;
                }

                pos = search(key);
                printf("Index: %d\n", pos);
                break;

            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
