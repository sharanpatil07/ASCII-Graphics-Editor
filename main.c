#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            canvas[i][j] = ' ';
        }
    }
}

void displayCanvas() {
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height) {
    int i, j;

    for(i = y; i < y + height; i++) {
        for(j = x; j < x + width; j++) {
            canvas[i][j] = '*';
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2) {
    int i;

    if(y1 == y2) {
        for(i = x1; i <= x2; i++) {
            canvas[y1][i] = '*';
        }
    }
}

void drawTriangle() {
    canvas[2][10] = '*';

    canvas[3][9] = '*';
    canvas[3][11] = '*';

    canvas[4][8] = '*';
    canvas[4][9] = '*';
    canvas[4][10] = '*';
    canvas[4][11] = '*';
    canvas[4][12] = '*';
}

void drawCircle() {
    canvas[7][10] = '*';
    canvas[6][9] = '*';
    canvas[6][11] = '*';
    canvas[8][9] = '*';
    canvas[8][11] = '*';
    canvas[7][8] = '*';
    canvas[7][12] = '*';
}

void modifyRectangle() {
    drawRectangle(15, 5, 8, 3);
}

void deleteRectangle() {
    int i, j;

    for(i = 5; i < 9; i++) {
        for(j = 5; j < 15; j++) {
            canvas[i][j] = ' ';
        }
    }
}
int main() {

    int choice;

    initializeCanvas();

    while(1) {

        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Canvas\n");
        printf("6. Clear Canvas\n");
        printf("7. Modify Rectangle\n");
       printf("8. Delete Rectangle\n");
       printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            int x, y, width, height;

printf("Enter x y width height: ");
scanf("%d %d %d %d", &x, &y, &width, &height);

drawRectangle(x, y, width, height);
        }
        else if(choice == 2) {
            drawLine(2, 2, 15, 2);
        }
        else if(choice == 3) {
            drawTriangle();
        }
        else if(choice == 4) {
            drawCircle();
        }
        else if(choice == 5) {
            displayCanvas();
        }
        else if(choice == 6) {
            initializeCanvas();
            printf("Canvas Cleared!\n");
        }
        else if(choice == 7) {
            modifyRectangle();
            printf("Rectangle Modified!\n");
        }
       else if(choice == 8) {
    deleteRectangle();
    printf("Rectangle Deleted!\n");
}
else if(choice == 9) {
    printf("Exiting...\n");
    break;
}
        else {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}