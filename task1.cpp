#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2, result;
    char again;


     cout << " Basic Calculator \n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

    do {
       


        if (choice == 5) {
            cout << "Exiting calculator...\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result = " << result << endl;
                break;

            case 2:
                result = num1 - num2;
                cout << "Result = " << result << endl;
                break;

            case 3:
                result = num1 * num2;
                cout << "Result = " << result << endl;
                break;

            case 4:
                if (num2 == 0) {
                    cout << "Division by zero is not allowed!\n";
                } else {
                    result = num1 / num2;
                    cout << "Result = " << result << endl;
                }
                break;
        }

        cout << "Do you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Program ended.\n";

    return 0;
}