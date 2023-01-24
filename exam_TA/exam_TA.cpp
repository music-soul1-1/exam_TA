// exam task for TA
// ticket #13

#include <iostream>
#include <iomanip>
#include <cstdlib> // lib for "system" commands

using namespace std;

int main()
{
    const int SIZE = 5;
    int list[SIZE]{},
        end = -1, start = -1,
        menuCursor = 1,
        element, positionOfElement,
        countSwaps = 0;

    while (menuCursor != 0) {
        cout << "Choose an action: \n\n";

        cout << "1) Add element \n";
        cout << "2) Delete element \n";
        cout << "3) Content list \n";
        cout << "4) Count elements in list \n";
        cout << "5) Clean list \n";
        cout << "6) Delete elements bigger than entered \n\n";

        cout << "0) Exit \n";
        cin >> menuCursor;


        switch (menuCursor) {
            case 1: {
                if (end - start + 1 == SIZE) {
                    cout << "List is full. Please remove element \n";
                }
                else {
                    if (end == -1) {
                        start = 0;
                        cout << "Insertion is possible only in 1\n";
                        cout << "Input element: \n";
                        cin >> element;
                        list[++end] = element;
                    }
                    else {
                        do {
                            cout << "Enter position for new element(from 1 to " << end - start + 2 << "): \n";
                            cin >> positionOfElement;
                        } while (positionOfElement < 1 || positionOfElement > end - start + 2);

                        cout << "Input element: \n";
                        cin >> element;
                        end++;
                        for (int i = start + positionOfElement - 1; i <= end; i++) {
                            swap(list[i], element);
                        }
                    }
                }

                break;
            }
            case 2: {
                if (end == -1) {
                    cout << "List is empty \n";
                }
                else {
                    cout << "Element " << list[start++] << " removed\n";
                    if (start > end) {
                        start = end = -1;
                    }
                }

                break;
            }
            case 3: {
                if (end == -1) {
                    cout << "list is empty\n";
                }
                else {
                    for (int i = start; i <= end; i++) {
                        cout << setw(8) << list[i];
                    }
                    cout << "\n";
                }

                break;
            }
            case 4: {
                if (end == -1) {
                    cout << "List is empty\n";
                }
                else {
                    cout << "Size of list is " << end - start + 1 << "\n";
                }

                break;
            }
            case 5: {
                end = start = -1;
                cout << "List was been cleaned\n";
                
                break;
            }
            case 6: {
                // temporary array for storing list elements
                int temp[SIZE] {};
                countSwaps = 0;

                if (end == -1) {
                    cout << "List is empty \n";
                }
                else {
                    cout << "Enter an element: \n";
                    cin >> element;
                    // putting elements that are <= element into temporary array:
                    for (int i = start; i <= end; i++) {
                        if (list[i] <= element) {
                            swap(list[i], temp[countSwaps++]);
                        }
                    }
                    // new list size:
                    start = 0;
                    end = countSwaps - 1;
                    // putting elements from temp back to list:
                    for (int i = start; i <= end; i++) {
                        swap(temp[i], list[i]);
                    }
                    cout << "Elements bigger than " << element << " have been removed \n";
                }

                break;
            }
        }
        system("PAUSE");
        system("CLS");
    }

    return 0;
}
