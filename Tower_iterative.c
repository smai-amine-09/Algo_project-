#include <stdio.h>
#include <math.h>
#include <time.h>  
#define Tmax 100

// ===============================
//   Stack Structure (as in class)
// ===============================
typedef struct {
    int Elements[Tmax];   // array of disks
    int top;              // index of top element
    int capacity;         // maximum number of disks
} Stack;


// Initialize stack
void initStack(Stack *P, int capacity) {
    P->top = -1;
    P->capacity = capacity;
}


// Check if empty
int isEmpty(Stack *P) {
    return (P->top == -1);
}


// Push onto stack
void push(Stack *P, int x) {
    if (P->top < P->capacity - 1) {
        P->Elements[++P->top] = x;
    }
}


// Pop from stack
int pop(Stack *P) {
    if (isEmpty(P)) return -1;
    return P->Elements[P->top--];
}


// Print move
void moveDisk(char from, char to, int disk) {
    printf("Move disk %d from %c → %c\n", disk, from, to);
}


// Make a legal move between two pegs
void moveBetween(Stack *src, Stack *dest, char s, char d) {
    int top1 = pop(src);
    int top2 = pop(dest);

    // If src empty
    if (top1 == -1) {
        push(src, top2);
        moveDisk(d, s, top2);
    }
    // If dest empty
    else if (top2 == -1) {
        push(dest, top1);
        moveDisk(s, d, top1);
    }
    // If top of src > top of dest → move from dest to src
    else if (top1 > top2) {
        push(src, top1);
        push(src, top2);
        moveDisk(d, s, top2);
    }
    // Else move from src to dest
    else {
        push(dest, top2);
        push(dest, top1);
        moveDisk(s, d, top1);
    }
}

void printBegin(Stack A, Stack B, Stack C) {
    printf("\n========== BEGIN STATE ==========\n");

    printf("Peg A: ");
    for (int i = 0; i <= A.top; i++) printf("%d ", A.Elements[i]);
    printf("\n");

    printf("Peg B: ");
    for (int i = 0; i <= B.top; i++) printf("%d ", B.Elements[i]);
    printf("\n");

    printf("Peg C: ");
    for (int i = 0; i <= C.top; i++) printf("%d ", C.Elements[i]);
    printf("\n");

    printf("=================================\n\n");
}
// Print final state
void printFinal(Stack A, Stack B, Stack C) {
    printf("\n========== FINAL STATE ==========\n");

    printf("Peg A: ");
    for (int i = 0; i <= A.top; i++) printf("%d ", A.Elements[i]);
    printf("\n");

    printf("Peg B: ");
    for (int i = 0; i <= B.top; i++) printf("%d ", B.Elements[i]);
    printf("\n");

    printf("Peg C: ");
    for (int i = 0; i <= C.top; i++) printf("%d ", C.Elements[i]);
    printf("\n");

    printf("=================================\n\n");
}


// Main iterative Hanoi function
void iterativeHanoi(int n) {

    Stack A, B, C;

    initStack(&A, n);
    initStack(&B, n);
    initStack(&C, n);

    char s = 'A', a = 'B', d = 'C';

    // If n is even → swap auxiliary and destination
    if (n % 2 == 0) {
        char temp = d;
        d = a;
        a = temp;
    }

    // Initialize peg A with disks n..1
    for (int i = n; i >= 1; i--)
        push(&A, i);

    int totalMoves = pow(2, n) - 1;

    printBegin(A,B,C);
    // Perform moves
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1)
            moveBetween(&A, &C, s, d);
        else if (i % 3 == 2)
            moveBetween(&A, &B, s, a);
        else
            moveBetween(&B, &C, a, d);
    }

    // Print final configuration
    printFinal(A, B, C);
}


int main() {
      int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nIterative solution using Stack structure:\n");

    // Start the timer
    clock_t start = clock();

    iterativeHanoi(n);

    // Stop the timer
    clock_t end = clock();

    // Calculate elapsed time in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %.6f seconds\n", time_taken);

    return 0;
}
