#include <bits/stdc++.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

using namespace std;

const int LINE_THICKNESS = 3;
const int DELAY_INTERVAL = 500;

void drawThickLine(int x1, int y1, int x2, int y2, int thickness) {
    for (int i = 0; i < thickness; i++) {
        line(x1 + i, y1, x2 + i, y2);
    }
}

void drawThickCircle(int x, int y, int radius, int thickness) {
    for (int i = 0; i < thickness; i++) {
        circle(x, y, radius + i);
    }
}

void displayMainMenu() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    outtextxy(250, 10, "MENU");
    outtextxy(100, 50, "1. Show Name.");
    outtextxy(100, 100, "2. Animated Bicycle.");
    outtextxy(100, 150, "3. Line Drawing.");
    outtextxy(100, 200, "4. Circle Drawing.");
    outtextxy(100, 250, "5. Smile Face.");
    outtextxy(100, 300, "6. Traffic Signal.");
    outtextxy(100, 350, "7. Exit.");

    rectangle(50, 40, 600, 400);
}

void showName() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);
    outtextxy(100, 200, "Name Drawing");

    setlinestyle(SOLID_LINE, 0, LINE_THICKNESS);
    setcolor(YELLOW);

    drawThickLine(50, 30, 50, 100, LINE_THICKNESS);
    drawThickLine(50, 30, 70, 70, LINE_THICKNESS);
    drawThickLine(70, 70, 90, 30, LINE_THICKNESS);
    drawThickLine(90, 30, 90, 100, LINE_THICKNESS);

    drawThickCircle(130, 65, 35, LINE_THICKNESS);

    drawThickLine(170, 30, 210, 30, LINE_THICKNESS);
    drawThickLine(170, 30, 170, 65, LINE_THICKNESS);
    drawThickLine(170, 65, 210, 65, LINE_THICKNESS);
    drawThickLine(210, 65, 210, 100, LINE_THICKNESS);
    drawThickLine(170, 100, 210, 100, LINE_THICKNESS);

    drawThickLine(240, 30, 240, 100, LINE_THICKNESS);
    drawThickLine(280, 30, 280, 100, LINE_THICKNESS);
    drawThickLine(240, 65, 280, 65, LINE_THICKNESS);

    drawThickLine(310, 30, 310, 100, LINE_THICKNESS);

    drawThickLine(340, 30, 340, 100, LINE_THICKNESS);
    drawThickLine(380, 30, 380, 100, LINE_THICKNESS);
    drawThickLine(340, 100, 380, 100, LINE_THICKNESS);

    drawThickLine(410, 30, 410, 100, LINE_THICKNESS);
    drawThickLine(410, 30, 450, 30, LINE_THICKNESS);
    drawThickLine(450, 30, 450, 65, LINE_THICKNESS);
    drawThickLine(450, 65, 410, 65, LINE_THICKNESS);
    drawThickLine(410, 65, 450, 100, LINE_THICKNESS);

    getch();
}

void drawSmileFace() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);

    outtext("Smile Face");

    circle(300, 200, 100);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300, 200, YELLOW);

    setcolor(BLACK);
    circle(330, 160, 15);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(330, 160, BLACK);

    circle(265, 160, 15);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(265, 160, BLACK);

    ellipse(300, 220, 205, 335, 50, 25);
    ellipse(300, 220, 205, 335, 50, 26);
    ellipse(300, 220, 205, 335, 50, 27);
    ellipse(300, 220, 205, 335, 50, 28);
    ellipse(300, 220, 205, 335, 50, 29);
    ellipse(300, 220, 205, 335, 50, 30);

    setfillstyle(SOLID_FILL, BLACK);
    line(290, 203, 306, 203);
    line(290, 203, 298, 216);
    line(306, 203, 298, 216);
    floodfill(300, 205, BLACK);

    delay(1000);

    getch();
}

void drawLineUsingDDA() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);

    int startX, startY, endX, endY;
    cout << "Enter start coordinates (X Y): ";
    cin >> startX >> startY;
    cout << "Enter end coordinates (X Y): ";
    cin >> endX >> endY;

    int deltaX = abs(endX - startX);
    int deltaY = abs(endY - startY);

    int x = startX;
    int y = startY;
    int steps = max(deltaX, deltaY);

    x = round((double)deltaX / steps);
    y = round((double)deltaY / steps);

    while (startX <= endX || startY <= endY) {
        putpixel(startX, startY, GREEN);
        startX += x;
        startY += y;
        delay(100);
    }
    cout << "Completed" << endl;

    getch();
}

void drawCircleUsingMidpoint() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);

    int centerX, centerY, radius;
    cout << "Enter center (X Y) and radius: ";
    cin >> centerX >> centerY >> radius;

    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x < y) {
        if (p >= 0) {
            x++;
            y--;
            p += 2 * x + 1 - 2 * y;
        } else {
            x++;
            p += 2 * x + 1;
        }
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);
    }

    cout << "Completed" << endl;

    getch();
}

void animateCycle() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);

    int position = 0;

    while (!kbhit()) {
        setcolor(WHITE);
        circle(70 + position, 370, 20);
        circle(170 + position, 370, 20);

        setcolor(WHITE);
        line(70 + position, 370, 100 + position, 350);
        line(100 + position, 350, 160 + position, 350);
        line(160 + position, 350, 170 + position, 370);

        line(100 + position, 350, 110 + position, 330);
        line(110 + position, 330, 130 + position, 330);
        line(130 + position, 330, 120 + position, 350);

        rectangle(130 + position, 350, 150 + position, 360);
        floodfill(135 + position, 355, WHITE);

        line(130 + position, 360, 120 + position, 370);
        line(130 + position, 360, 140 + position, 370);

        setcolor(GREEN);
        rectangle(0, 400, getmaxx(), 420);

        setcolor(RED);
        rectangle(50 + position, 390, 90 + position, 400);
        rectangle(150 + position, 390, 190 + position, 400);
        rectangle(250 + position, 390, 290 + position, 400);

        position++;
        delay(50);
        cleardevice();

        if (position > getmaxx()) {
            position = -300;
        }
    }

    getch();
}

void simulateTrafficLight() {
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int midX = getmaxx() / 2;
    int midY = getmaxy() / 2;

    setcolor(CYAN);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(midX, midY - 10, "TRAFFIC LIGHT SIMULATION");
    outtextxy(midX, midY + 10, "PRESS ANY KEY TO START");
    getch();

    cleardevice();
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    rectangle(midX - 30, midY - 80, midX + 30, midY + 80);

    setcolor(BLUE);
    circle(midX, midY - 50, 22);
    setfillstyle(SOLID_FILL, RED);
    floodfill(midX, midY - 50, BLUE);
    outtextxy(midX, midY - 50, "STOP");

    delay(2000);

    cleardevice();
    rectangle(midX - 30, midY - 80, midX + 30, midY + 80);

    circle(midX, midY - 50, 22);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(midX, midY - 50, WHITE);
    outtextxy(midX - 18, midY - 3, "READY");

    delay(2000);

    cleardevice();
    rectangle(midX - 30, midY - 80, midX + 30, midY + 80);

    circle(midX, midY + 50, 22);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(midX, midY + 50, WHITE);
    outtextxy(midX - 7, midY + 48, "GO");

    setcolor(RED);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    outtextxy(midX - 150, midY + 100, "Brrrmmm");

    getch();
    closegraph();
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    int option;

    displayMainMenu();

    while (1) {
        option = getch();

        switch (option) {
            case '1':
                outtextxy(200, 400, "You selected option 1!");
                showName();
                cleardevice();
                break;
            case '2':
                outtextxy(200, 400, "You selected option 2!");
                animateCycle();
                cleardevice();
                break;
            case '3':
                outtextxy(200, 400, "You selected option 3!");
                drawLineUsingDDA();
                cleardevice();
                break;
            case '4':
                outtextxy(200, 400, "You selected option 4!");
                delay(1000);
                cleardevice();
                drawCircleUsingMidpoint();
                delay(1000);
                cleardevice();
                break;
            case '5':
                outtextxy(200, 400, "You selected option 5!");
                delay(1000);
                cleardevice();
                drawSmileFace();
                delay(1000);
                cleardevice();
                break;
            case '6':
                outtextxy(200, 400, "You selected option 6!");
                delay(1000);
                cleardevice();
                simulateTrafficLight();
                delay(1000);
                cleardevice();
                break;
            case '7':
                closegraph();
                exit(0);
                break;
            default:
                outtextxy(200, 400, "Invalid option!");
                break;
        }

        delay(1000);
        displayMainMenu();
    }

    getch();
    closegraph();

    return 0;
}
