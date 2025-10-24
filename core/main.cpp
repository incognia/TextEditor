#include "file/FileManager.h"
#include <iostream>
#include <limits>

using namespace TextEditor::File;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMenu() {
    std::cout << "\n=== TextEditor CRUD File Manager ===\n";
    std::cout << "1. Create a new file\n";
    std::cout << "2. Read a file\n";
    std::cout << "3. Update a file\n";
    std::cout << "4. Delete a file\n";
    std::cout << "5. Check if file exists\n";
    std::cout << "6. Read file by lines\n";
    std::cout << "7. Append to file\n";
    std::cout << "0. Exit\n";
    std::cout << "====================================\n";
    std::cout << "Choose an option: ";
}

void createFileOption(FileManager& fm) {
    std::string filepath, content;
    std::cout << "Enter filepath: ";
    std::getline(std::cin, filepath);
    
    std::cout << "Enter content (press Enter twice to finish):\n";
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        content += line + "\n";
    }
    
    if (fm.createFile(filepath, content)) {
        std::cout << "✓ File created successfully!\n";
    } else {
        std::cout << "✗ Failed to create file.\n";
    }
}

void readFileOption(FileManager& fm) {
    std::string filepath;
    std::cout << "Enter filepath: ";
    std::getline(std::cin, filepath);
    
    auto content = fm.readFile(filepath);
    if (content.has_value()) {
        std::cout << "\n--- File Content ---\n";
        std::cout << content.value();
        std::cout << "\n--- End of File ---\n";
    } else {
        std::cout << "✗ Failed to read file.\n";
    }
}

void updateFileOption(FileManager& fm) {
    std::string filepath, content;
    std::cout << "Enter filepath: ";
    std::getline(std::cin, filepath);
    
    std::cout << "Enter new content (press Enter twice to finish):\n";
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        content += line + "\n";
    }
    
    if (fm.updateFile(filepath, content)) {
        std::cout << "✓ File updated successfully!\n";
    } else {
        std::cout << "✗ Failed to update file.\n";
    }
}

void deleteFileOption(FileManager& fm) {
    std::string filepath;
    std::cout << "Enter filepath: ";
    std::getline(std::cin, filepath);
    
    std::cout << "Are you sure you want to delete '" << filepath << "'? (y/n): ";
    std::string confirm;
    std::getline(std::cin, confirm);
    
    if (confirm == "y" || confirm == "Y") {
        if (fm.deleteFile(filepath)) {
            std::cout << "✓ File deleted successfully!\n";
        } else {
            std::cout << "✗ Failed to delete file.\n";
        }
    } else {
        std::cout << "Deletion cancelled.\n";
    }
}

void fileExistsOption(FileManager& fm) {
    std::string filepath;
    std::cout << "Enter filepath: ";
    std::getline(std::cin, filepath);
    
    if (fm.fileExists(filepath)) {
        std::cout << "✓ File exists.\n";
    } else {
        std::cout << "✗ File does not exist.\n";
    }
}

void readLinesOption(FileManager& fm) {
    std::string filepath;
    std::cout << "Enter filepath: ";
    std::getline(std::cin, filepath);
    
    auto lines = fm.readLines(filepath);
    if (lines.has_value()) {
        std::cout << "\n--- File Lines ---\n";
        int lineNum = 1;
        for (const auto& line : lines.value()) {
            std::cout << lineNum++ << ": " << line << "\n";
        }
        std::cout << "--- End of File ---\n";
    } else {
        std::cout << "✗ Failed to read file.\n";
    }
}

void appendToFileOption(FileManager& fm) {
    std::string filepath, content;
    std::cout << "Enter filepath: ";
    std::getline(std::cin, filepath);
    
    std::cout << "Enter content to append (press Enter twice to finish):\n";
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        content += line + "\n";
    }
    
    if (fm.appendToFile(filepath, content)) {
        std::cout << "✓ Content appended successfully!\n";
    } else {
        std::cout << "✗ Failed to append to file.\n";
    }
}

int main() {
    FileManager fileManager;
    int choice;
    
    std::cout << "Welcome to TextEditor Core - File Manager\n";
    std::cout << "Basic CRUD Operations Demo\n";
    
    while (true) {
        printMenu();
        
        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        clearInput();
        
        switch (choice) {
            case 0:
                std::cout << "Goodbye!\n";
                return 0;
            case 1:
                createFileOption(fileManager);
                break;
            case 2:
                readFileOption(fileManager);
                break;
            case 3:
                updateFileOption(fileManager);
                break;
            case 4:
                deleteFileOption(fileManager);
                break;
            case 5:
                fileExistsOption(fileManager);
                break;
            case 6:
                readLinesOption(fileManager);
                break;
            case 7:
                appendToFileOption(fileManager);
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
    
    return 0;
}
