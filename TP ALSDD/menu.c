#include "menu.h"
#include "conio.c"


#define marginleft 30
#define margintop 5

void hide_cursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    
}

int up = 80, down = 72, mar = 40, ma = 45;
void bleu() { textbackground(CYAN); }
void noire() { textbackground(BLACK); }
void blanc() { textcolor(WHITE); }
void cyan() { textcolor(CYAN); }
void hmer() { textcolor(RED); }
void sfer() { textcolor(YELLOW); }

void menuprinci(int *choix)
{
    clrscr();
    noire();
    const int CHOICES = 5;
    int c;
    int cpt = 1;
    int y = margintop;

    gotoxy(marginleft, y++);
    blanc();
    printf("__________________________________________________________\n");
    y++;
    gotoxy(marginleft, y++);
    bleu();
    printf("          1. Manage list and Queues ( Items/Vehicles )    \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          2. Assign Items and launch Delivery             \n");
    y++;
    gotoxy(marginleft, y++);
    printf("          3. Set returns Pick-up / Delivery cancellation  \n");
    y++;
    gotoxy(marginleft, y++);
    printf("          4. Simulate End of the day and update Files     \n");
    y++;
    gotoxy(marginleft, y++);
    printf("          5. Exit Management System                       \n");
    y++;
    gotoxy(marginleft, y++);
    blanc();
    printf("__________________________________________________________\n");

    do
    {
        c = getch();
        clrscr();
        if (c == up)
        {
            cpt %= CHOICES;
            cpt++;
        }
        if (c == down)
        {
            cpt--;
            if (cpt == 0)
                cpt = CHOICES;
        }
        noire();
        y = margintop;
        gotoxy(marginleft, y++);
        blanc();
        printf("__________________________________________________________\n");
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 1)
            bleu();
        printf("          1. Manage list and Queues ( Items/Vehicles )    \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 2)
            bleu();
        printf("          2. Assign Items and launch Delivery             \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 3)
            bleu();
        printf("          3. Set returns Pick-up / Delivery cancellation  \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 4)
            bleu();
        printf("          4. Simulate End of the day and update Files     \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 5)
            bleu();
        printf("          5. Exit Management System                       \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        blanc();
        printf("__________________________________________________________\n");
    } while (c != 13);
    if (c == 13)
    {
        *choix = cpt;
    }
}

void menulistmanagement(int *choix)
{
    clrscr();
    noire();
    const int CHOICES = 10;
    int c;
    int cpt = 1;
    int y = margintop;

    gotoxy(marginleft, y++);
    blanc();

    printf("__________________________________________________________\n");
    y++;
    gotoxy(marginleft, y++);
    bleu();
    printf("          1. Load Item and Vehicle List form File         \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          2. Create VanQ and MotoQ from Vehicle List      \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          3. Print Item list                              \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          4. Print Vehicle List                           \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          5. Add new Item                                 \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          6. Add new Vehicle and Update Queues            \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          7. Delete Vehicle By ID                         \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          8. Print Van Queue                              \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          9. Print Moto Queue                             \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          10. Return to Main Menu                          \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    blanc();
    printf("__________________________________________________________\n");

    do
    {
        c = getch();
        clrscr();
        if (c == up)
        {
            cpt %= CHOICES;
            cpt++;
        }
        if (c == down)
        {
            cpt--;
            if (cpt == 0)
                cpt = CHOICES;
        }
        noire();
        y = margintop;
        gotoxy(marginleft, y++);
        blanc();
        printf("__________________________________________________________\n");
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 1)
            bleu();
        printf("          1. Load Item and Vehicle List form File         \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 2)
            bleu();
        printf("          2. Create VanQ and MotoQ from Vehicle List      \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 3)
            bleu();
        printf("          3. Print Item list                              \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 4)
            bleu();
        printf("          4. Print Vehicle List                           \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 5)
            bleu();
        printf("          5. Add new Item                                 \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 6)
            bleu();
        printf("          6. Add new Vehicle and Update Queues            \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 7)
            bleu();
        printf("          7. Delete Vehicle By ID                         \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 8)
            bleu();
        printf("          8. Print Van Queue                              \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 9)
            bleu();
        printf("          9. Print Moto Queue                             \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 10)
            bleu();
        printf("          10. Return to Main Menu                          \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        blanc();
        printf("__________________________________________________________\n");
    } while (c != 13);

    if (c == 13)
    {
        *choix = cpt;
    }
}

void menureturn(int *choix)
{
    clrscr();
    noire();
    const int CHOICES = 2;
    int c;
    int cpt = 1;
    int y = margintop;

    noire();
    y = margintop;
    gotoxy(marginleft, y++);
    blanc();
    printf("__________________________________________________________\n");
    y++;

    gotoxy(marginleft, y++);
    blanc();
    printf("\tIs there any returns ?\n");
    y++;

    gotoxy(marginleft, y++);
    bleu();
    printf("          1. Yes                  \n");
    noire();
    y++;
    gotoxy(marginleft, y++);
    printf("          2. No                   \n");
    noire();
    y++;

    gotoxy(marginleft, y++);
    blanc();
    printf("__________________________________________________________\n");

    do
    {
        c = getch();
        clrscr();
        if (c == up)
        {
            cpt %= CHOICES;
            cpt++;
        }
        if (c == down)
        {
            cpt--;
            if (cpt == 0)
                cpt = CHOICES;
        }

        noire();
        y = margintop;
        gotoxy(marginleft, y++);
        blanc();
        printf("__________________________________________________________\n");
        y++;

        gotoxy(marginleft, y++);
        blanc();
        printf("\tIs there any returns ?\n");
        y++;

        gotoxy(marginleft, y++);
        if (cpt == 1)
            bleu();
        printf("          1. Yes                   \n");
        noire();
        y++;
        gotoxy(marginleft, y++);
        if (cpt == 2)
            bleu();
        printf("          2. No                   \n");
        noire();
        y++;

        gotoxy(marginleft, y++);
        blanc();
        printf("__________________________________________________________\n");
    } while (c != 13);
    if (c == 13)
    {
        *choix = cpt;
    }
}

void animation(){
    system("cls"); // Waiting screen
            gotoxy(marginleft+5, 5);
            printf("-----------------------------------------\n");
            gotoxy(marginleft+5, 11);
            printf("-----------------------------------------");
            gotoxy(marginleft+5, 7);
            printf("    Items Are being assigned");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            gotoxy(marginleft+5, 9);
            printf("\tItems assigned Successfully !\n");
            Sleep(1500);

}
void animation2(){
            system("cls"); // Waiting screen
            gotoxy(marginleft+5, 5);
            printf("-----------------------------------------\n");
            gotoxy(marginleft+5, 11);
            printf("-----------------------------------------");
            gotoxy(marginleft+5, 7);
            printf("    Items Are being assigned");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            Sleep(300);
            printf(" .");
            gotoxy(marginleft+1, 9);
            printf(" * The is no availaible Vehicles Today Please comeback tomorrow * \n");
            getch();

}

