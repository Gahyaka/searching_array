#include <iostream>
#include <limits>

// bool searchArray(int arr[], int size, int target) { ... }
// bool searchCharArray(char arr[], int size, char target) { ... }

int searchArrayIndex(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int searchCharArrayIndex(char arr[], int size, char target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Menggabungkan fungsi input array dan pencarian untuk mengurangi duplikasi kode
template <typename T>
void inputArray(T* arr, int size) {
    std::cout << "Enter " << size << " elements: " << std::endl;
    for (int i = 0; i < size; i++) {
        while (true) {
            std::cout << "Element ke-" << (i + 1) << ": ";
            if (std::cin >> arr[i]) break;
            std::cout << "Invalid input. Please enter a valid value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    std::cout << "---Welcome To Searching Array Program---" << std::endl;

    char repeat;
    do {
        char choice;
        do {
            std::cout << "Do you want to search for a number or a character (n/c)? ";
            std::cin >> choice;
            if (choice != 'n' && choice != 'c') {
                std::cout << "Invalid choice. Please enter 'n' for number or 'c' for character." << std::endl;
            }
        } while (choice != 'n' && choice != 'c');

        int size;
        std::cout << "Enter the size of the array: ";
        while (!(std::cin >> size) || size <= 0) {
            std::cout << "Invalid input. Please enter a positive integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (choice == 'n') {
            int* arr = new int[size];
            inputArray(arr, size);

            int target;
            std::cout << "Enter the target value to search: ";
            while (!(std::cin >> target)) {
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            int index = searchArrayIndex(arr, size, target);
            if (index != -1) {
                std::cout << "Target found in the array at index " << index << "." << std::endl;
            } else {
                std::cout << "Target not found in the array." << std::endl;
            }

            delete[] arr;
        } else if (choice == 'c') {
            char* arr = new char[size];
            inputArray(arr, size);

            char target;
            std::cout << "Enter the target character to search: ";
            while (!(std::cin >> target)) {
                std::cout << "Invalid input. Please enter a character: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            int index = searchCharArrayIndex(arr, size, target);
            if (index != -1) {
                std::cout << "Target found in the array at index " << index << "." << std::endl;
            } else {
                std::cout << "Target not found in the array." << std::endl;
            }

            delete[] arr;
        }

        do {
            std::cout << "Do you want to repeat the program? (y/n): ";
            std::cin >> repeat;
            if (repeat == 'N' || repeat == 'n') {
                std::cout << "---Thank You For Using The Program!---" << std::endl;
                std::cout << "       --Program Completed--" << std::endl;
            } else if (repeat != 'y' && repeat != 'Y') {
                std::cout << "Invalid Input. Please Input (y/n)" << std::endl;
            }
        } while (repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N');

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
