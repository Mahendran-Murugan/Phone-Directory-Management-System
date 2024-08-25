#include <iostream>
#include <string>
using namespace std;
namespace fs = std::filesystem;


int lastIndex = 0;

class Directory
{
public:
    long phoneno;
    string fname, lname;

    Directory(long phoneno = 0, string fname = "", string lname = "")
        : phoneno(phoneno), fname(fname), lname(lname) {}
};


void listAllFiles(const string& path) { // TO see the list files
    cout << "List of all Files:\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << entry.path().filename().string() << endl;
    }
}

void listFilesByExtension(const string& path, const string& extension) { // to see list of  extension files
    cout << "Listing Files with Extension: " << extension << endl;
    int count = 0;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry) && entry.path().extension() == extension) {
            cout << entry.path().filename().string() << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "No files found with extension " << extension << endl;
}

void listFilesByPattern(const string& path, const string& pattern) { // too see files from extension
    cout << "Listing Files Matching Pattern: " << pattern << endl;
    int count = 0;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry) && entry.path().filename().string().find(pattern) != string::npos) {
            cout << entry.path().filename().string() << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "No files found matching pattern " << pattern << endl;
}

void createDirectory(const string& path) { // To create new directory
    if (fs::create_directory(path)) {
        cout << "Directory Successfully Created:" << path << endl;
    } else {
        cout << "Error" << endl;
    }
}

void changeDirectory(string& path) { // To change directory
    int choice;
    cout << "Change Directory Options:\n";
    cout << "1. Step by step backward. \n";
    cout << "2.Goto Root Directory.\n";
    cout << "3. Forward directory. \n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            path = fs::current_path().parent_path().string();
            break;
        case 2:
            path = fs::path("/").string();
            break;
        case 3: {
            string newPath;
            cout << "Enter the path of the directory: ";
            cin >> newPath;
            if (fs::exists(newPath) && fs::is_directory(newPath)) {
                path = newPath;
            } else {
                cout << "Invalid path or directory does not exist." << endl;
            }
            break;
        }
        default:
            cout << "Invalid option!" << endl;
    }
    fs::current_path(path); // Update the current working directory
    cout << "Current directory changed to: " << fs::current_path() << endl;
}

int main() {

    string currentPath = fs::current_path().string();
    int ch;

    cout << "\nWelcome to Phone Directory and File Management System\n";
    do {
        cout << "\nMain Menu\n";
        cout << "_____________\n";
        cout << "1. Display List of Files\n";
        cout << "2. Create a New Directory\n";
        cout << "3. Change the Working Directory\n";
        cout << "4. Exit\n";
        cout << "Enter The Number: ";
        cin >> ch;

        switch (ch) { // main menu choices
            case 1: {
                int subChoice;
                cout << "\nList Files Detail\n";
                cout << "\n_______________\n";
                cout << "1. List all files .\n";
                cout << "2. List of extension files.\n";
                cout << "3. List of Name Wise     \n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice) { // DIsplay List of files choices
                    case 1:
                        listAllFiles(currentPath);
                        break;
                    case 2: {
                        string extension;
                        cout << "Enter the file extension (e.g., .txt): ";
                        cin >> extension;
                        listFilesByExtension(currentPath, extension);
                        break;
                    }
                    case 3: {
                        string pattern;
                        cout << "Enter the file name pattern (e.g., moha*.*): ";
                        cin >> pattern;
                        listFilesByPattern(currentPath, pattern);
                        break;
                    }
                    default:
                        cout << "Invalid option!" << endl;
                }
                break;
            }
            case 2: { // main menu choices
                string dirName;
                cout << "Enter the name of the directory name: ";
                cin >> dirName;
                createDirectory(currentPath + "/" + dirName);
                break;
            }
            case 3: // main menu choices
                changeDirectory (currentPath);
                break;
            case 4: // main menu choices
                cout << "Thank you for using the system. Exiting...\n";
                return 0;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    } while (ch != 4);

    return 0;
}
