/**
 * Program Name: sales-terminal.cpp
 * Developer: Derek P Sifford
 * Date: 27.09.2016
 * Description: Program to act as a sales terminal for a coffee shop.
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/**
 * NOTE TO PROFESSOR: This exact problem was an assignment in CSC1100 at Wayne State.
 * This is literally a copy and paste from my saved work from last semester.
 */

void waitToProceed() {
    // Create holder for any character
    char x;
    cout << "Press Enter to continue..." << endl;
    // Proceed after enter is pressed
    cin.ignore(1);
    cin.get(x);
}

void logSale(int& ouncesSold, double& revenue, int& small, int& medium, int& large) {

    // Set price constants
    const double SMALL_PRICE = 1.75;
    const double MEDIUM_PRICE = 1.90;
    const double LARGE_PRICE = 2.00;

    // Set size constants
    const int SMALL_SIZE = 9;
    const int MEDIUM_SIZE = 12;
    const int LARGE_SIZE = 15;

    // Instantiate vars
    int choice, size;
    double price;
    bool wrongAnswer = true;

    // Print instructions
    printf( "Choose Size:\n\t1) Small (9oz)\n\t2) Medium (12oz)\n\t"
            "3) Large (15oz)\n");

    // Loop over stdin continuously until the person chooses
    // a correct selection
    while (wrongAnswer) {
        cin >> choice;
        switch (choice) {
            case 1:
                size = SMALL_SIZE;
                price = SMALL_PRICE;
                small++;
                wrongAnswer = false;
                break;
            case 2:
                size = MEDIUM_SIZE;
                price = MEDIUM_PRICE;
                medium++;
                wrongAnswer = false;
                break;
            case 3:
                size = LARGE_SIZE;
                price = LARGE_PRICE;
                large++;
                wrongAnswer = false;
                break;
            default:
                cout << "Wrong selection. Try again." << endl;
                break;
        }
    }

    // Increment the revenue and size (pointers)
    ouncesSold += size;
    revenue += price;
}

void viewCupsSold(int small, int medium, int large) {

    // Instantiate vars
    int choice;
    bool wrongAnswer = true;

    // Ask for input
    system("cls||clear");
    printf( "Choose the size you wish to view:\n"
            "\t1) Small\n\t2) Medium\n\t3) Large\n");

    while (wrongAnswer) {
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Small cups sold: " << small << endl;
                waitToProceed();
                wrongAnswer = false;
                break;
            case 2:
                cout << "Medium cups sold: " << medium << endl;
                waitToProceed();
                wrongAnswer = false;
                break;
            case 3:
                cout << "Large cups sold: " << large << endl;
                waitToProceed();
                wrongAnswer = false;
                break;
            default:
                cout << "Please enter a valid choice." << endl;
                break;
        }
    }

}

void pointOfSale(bool& quit) {

    // Instantiate static variables
    static double revenue;
    static int ouncesSold, smallSold, mediumSold, largeSold;

    int choice;
    system("cls||clear");
    printf( "\t+------------------------------+\n"
            "\t|        SALES TERMINAL        |\n"
            "\t+------------------------------+\n");
    printf("Choose operation:\n");
    printf( "\t1) Log sale\n"
            "\t2) View cups sold (by size)\n"
            "\t3) View total coffee sold (ounces)\n"
            "\t4) View revenue\n"
            "\t5) Exit\n");
    cin >> choice;
    system("cls||clear");

    switch (choice) {
        case 1:
            // Log the sale
            logSale(ouncesSold, revenue, smallSold, mediumSold, largeSold);
            break;
        case 2:
            // View cups sold by size
            viewCupsSold(smallSold, mediumSold, largeSold);
            break;
        case 3:
            cout << "Total ounces of coffee sold: " << ouncesSold << endl;
            waitToProceed();
            break;
        case 4:
            cout << showpoint << fixed << setprecision(2);
            cout << "Total revenue earned: $" << revenue << endl;
            waitToProceed();
            break;
        case 5:
            cout << "Goodbye." << endl;
            quit = true;
            break;
        default:
            cout << "Please enter a valid choice." << endl;
    }

}

int main() {

    bool quit = false;

    while (!quit) {
        pointOfSale(quit);
    }

    return 0;
}
