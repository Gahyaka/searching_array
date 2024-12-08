#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>


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

// Fungsi untuk membaca kumpulan angka
void inputNumberArray(std::vector<int>& arr) {
    std::string line;
    std::cout << "Enter numbers separated by spaces: ";
    std::cin.ignore();
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number;
    while (iss >> number) {
        arr.push_back(number);
    }
}

// Fungsi untuk membaca kalimat
void inputCharArray(std::string& arr) {
    std::cout << "Enter a sentence: ";
    std::cin.ignore();
    std::getline(std::cin, arr);
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

        if (choice == 'n') {
            std::vector<int> arr;
            inputNumberArray(arr);

            int target;
            std::cout << "Enter the target value to search: ";
            while (!(std::cin >> target)) {
                std::cout << "Invalid input. Please enter an integer: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            int index = searchArrayIndex(arr.data(), arr.size(), target);
            if (index != -1) {
                std::cout << "Target found in the array at index " << index << "." << std::endl;
            } else {
                std::cout << "Target not found in the array." << std::endl;
            }
        } else if (choice == 'c') {
            std::string arr;
            inputCharArray(arr);

            char target;
            std::cout << "Enter the target character to search: ";
            while (!(std::cin >> target)) {
                std::cout << "Invalid input. Please enter a character: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            int index = searchCharArrayIndex(arr.data(), arr.size(), target);
            if (index != -1) {
                std::cout << "Target found in the array at index " << index << "." << std::endl;
            } else {
                std::cout << "Target not found in the array." << std::endl;
            }
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
