#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> // Ïîòð³áíî äëÿ ôóíêö³¿ getch()

// --- Ïðîòîòèïè ôóíêö³é ---
double function(double x);
void printTable(double X1, unsigned int N, double step);
void print_table_header();
void print_table_line();

// --- Ãîëîâíà ôóíêö³ÿ ïðîãðàìè (ç âàë³äàö³ºþ) ---
int main()
{
    // Îãîëîøåííÿ çì³ííèõ
    double X1, X2, delta;
    unsigned int N;
    int temp;
    int variant;

    // --- ÊÐÎÊ 1: ÂÂÅÄÅÍÍß ÒÀ ÂÀË²ÄÀÖ²ß ÄÀÍÈÕ ---
    printf("Enter variant (1 or 2): ");
    scanf("%d", &variant);
    while(variant != 1 && variant != 2)
    {
        printf("\nVariant must be 1 or 2");
        printf("\nEnter variant: ");
        scanf("%d", &variant);
    }

    printf("\nEnter X1: ");
    scanf("%lf", &X1);

    do {
        printf("\nEnter X2 (must be > X1): ");
        scanf("%lf", &X2);
        if (X2 <= X1) {
            printf("\nError. X2 must be greater than X1. Please try again.\n");
        }
    } while (X2 <= X1);

    if(variant == 1)
    {
        printf("\nEnter N (number of points >= 2): ");
        scanf("%d", &temp);
        while(temp <= 1)
        {
            printf("\nError. N must be 2 or greater.");
            printf("\nEnter N: ");
            scanf("%d", &temp);
        }
        N = (unsigned int)temp;
        delta = (X2 - X1) / ((double)(N - 1));
    }
    else // variant == 2
    {
        do {
            printf("\nEnter delta (step > 0): ");
            scanf("%lf", &delta);
            if (delta <= 0) {
                printf("\nError. Delta must be positive.\n");
            }
        } while (delta <= 0);
        N = (unsigned int)((X2 - X1) / delta) + 1;
    }

    // --- ÊÐÎÊ 2: ÂÈÊËÈÊ ÔÓÍÊÖ²¯ ÄËß ÄÐÓÊÓ ÒÀÁËÈÖ² ---
    printTable(X1, N, delta);

    return 0;
}


// --- Ðåàë³çàö³ÿ ôóíêö³é ---

// ÐÅÀË²ÇÀÖ²ß ÔÓÍÊÖ²¯ ÄËß ÂÀÐ²ÀÍÒÓ 15
// f(x) = 2(x-1000)^3 - 3(x+500)^2 + 4x - 5
double function(double x) {
    return 2.0 * pow(x - 1000.0, 3) - 3.0 * pow(x + 500.0, 2) + 4.0 * x - 5.0;
}

// Ôóíêö³ÿ äëÿ ðîçðàõóíêó òà âèâîäó òàáëèö³
void printTable(double X1, unsigned int N, double step) {
    unsigned int i;
    double x, fx, prev_fx = 0.0;

    unsigned int displayedLines = 0;
    const int maxLinesPerScreen = 20;

    printf("\n\n--- Calculation parameters ---\n");
    printf("Start X: %.4f\n", X1);
    printf("Points:  %u\n", N);
    printf("Step:    %.4f\n\n", step);

    print_table_header();

    for (i = 0; i < N; i++) {
        x = X1 + i * step;
        fx = function(x);

        printf("| %-5u | %-26.4f | %-23.4f |\n", i + 1, x, fx);
        displayedLines++;

        if (i > 0 && fx * prev_fx < 0) {
            print_table_line();
            printf("!!! Attention: Function changed sign on the interval [%.4f, %.4f] !!!\n", x - step, x);
            print_table_line();
            displayedLines += 3;
        }
        prev_fx = fx;

        // Ïàã³íàö³ÿ (âåðñ³ÿ áåç ðîçðèâó òàáëèö³)
        if (displayedLines >= maxLinesPerScreen && i < N - 1) {
            print_table_line();
            printf("Press any key to continue...\n");
            getch();
            displayedLines = 0;
        }
    }
    print_table_line();
}


// Ôóíêö³¿ äëÿ ìàëþâàííÿ òàáëèö³ ïñåâäîãðàô³êîþ (äëÿ âàð³àíòó 15)
void print_table_header() {
    print_table_line();
    printf("| %-5s | %-26s | %-23s |\n", "N", "X", "F(X)");
    print_table_line();
}

void print_table_line() {
    printf("+-------+----------------------------+-------------------------+\n");
}
