#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height) {
    for(int i=y;i<y+height && i<ROWS;i++) {
        for(int j=x;j<x+width && j<COLS;j++) {
            canvas[i][j] = '*';
        }
    }
}
void drawLine(int x1, int y1, int x2, int y2) {
    if(y1 == y2) { // Horizontal line
        for(int i = x1; i <= x2; i++) {
            canvas[y1][i] = '*';
        }
    }
    else if(x1 == x2) { // Vertical line
        for(int i = y1; i <= y2; i++) {
            canvas[i][x1] = '*';
        }
    }
}

int main() {
    int choice;
    initializeCanvas();

    while(1) {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Display Canvas\n");
        printf("3. Clear Canvas\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1) {
            int x,y,w,h;
            printf("Enter x y width height: ");
            scanf("%d%d%d%d",&x,&y,&w,&h);
            drawRectangle(x,y,w,h);
        }
        else if(choice==2) {
            displayCanvas();
        }
        else if(choice==3) {
            initializeCanvas();
            printf("Canvas Cleared!\n");
        }
        else if(choice==4) {
            break;
        }
    }

    return 0;
}