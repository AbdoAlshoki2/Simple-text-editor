#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
fstream myfile;
fstream myfile2;
char name_of_file[100];
char name_of_file2[100];
void add_text();
void display_content();
void empty_file();
void encrypt_content();
void decrypt_content();
void MergeTwoFiles();
int CountWords();
int CountChars();
int CountLines();
string Search();
void repeated_words();
void upper_case();
void lower_case();
void title();
void save();
void exit();

int main() {
    string option;
    cout << "Ahlan ya user ya Habiby :)" << endl << "This is our text editor program " << endl;
    cout << "Please enter the file's name : " << endl;
    cin >> name_of_file;
    strcat(name_of_file, ".txt");
    myfile.open(name_of_file);
    ofstream file;
    if (myfile) {
        cout << "This File Already Exists " << endl;
    }
    else {
        file.open(name_of_file);
        cout << "This is a new file. I created it for you :)" << endl;
    }
    myfile.close();
    while (true) {
        cout << endl << "Please choose one of these functions " << endl <<
            "1- Add new text to the end of the file." << endl <<
            "2- Display the content of the file." << endl <<
            "3- Empty the file." << endl <<
            "4- Encrypt the file content." << endl <<
            "5- Decrypt the file content." << endl <<
            "6- Merge another file." << endl <<
            "7- Count the number of the words in the file." << endl <<
            "8- Count the number of characters in the file." << endl <<
            "9- Count the number of lines in the file." << endl <<
            "10- Search for a word in the file." << endl <<
            "11- Count the number of times a word exists in the file." << endl <<
            "12- Turn the file content to upper case." << endl <<
            "13- Turn the file content to lower case." << endl <<
            "14- Turn file content to 1st caps (first character of each word is capital)." << endl <<
            "15- Save." << endl <<
            "16- Exit." << endl;
        cin >> option;
        cout << endl;
        if (option == "1") add_text();
        else if (option == "2") display_content();
        else if (option == "3") empty_file();
        else if (option == "4") encrypt_content();
        else if (option == "5") decrypt_content();
        else if (option == "6") {
            cout << "Please enter the second file's name : " << endl;
            cin >> name_of_file;
            strcat(name_of_file, ".txt");
            MergeTwoFiles();
        }
        else if (option == "7") CountWords();
        else if (option == "8") CountChars();
        else if (option == "9") CountLines();
        else if (option == "10") Search();
        else if (option == "11") repeated_words();
        else if (option == "12") upper_case();
        else if (option == "13") lower_case();
        else if (option == "14") title();
        else if (option == "15") save();
        else if (option == "16") exit();
        else cout << "Please enter an option from 1-16 !" << endl;
    }
}

// __________________________________
void add_text() {
    string text;
    myfile.open(name_of_file, ios::app);
    cout << "Enter the text you want to add to the file and to exit type \"exit\" " << endl;
    cin.clear();
    getline(cin, text);
    if (text != "exit") myfile << text;
    while (true) {
        getline(cin, text);
        if (text != "exit") myfile << text << endl;
        else break;
        cin.clear();
    }
    myfile.close();
}
// __________________________________
void display_content() {
    string line;
    myfile.open(name_of_file, ios::in | ios::out);
    cout << endl;
    while (getline(myfile, line)) {
        cout << line << endl;
    }
    cout << endl;
    myfile.close();
    cout << "Press enter to return to the main menu " << endl;
    cin.sync();
    getchar();
}
// __________________________________
void empty_file() {
    ofstream file;
    file.open(name_of_file);
    cout << "Your file is now empty " << endl;
    myfile.close();
}
// __________________________________
void encrypt_content() {
    string file_content;
    myfile.open(name_of_file, ios::in);
    ostringstream item;
    item << myfile.rdbuf();
    file_content = item.str();
    for (auto& letter : file_content) {
        if (letter == '\n') continue;
        else if (letter == 32) continue;
        letter += 1;
    }
    ofstream file;
    file.open(name_of_file);
    myfile.close();
    myfile.open(name_of_file, ios::out | ios::in | ios::app);
    myfile << file_content;
    myfile.close();
}
// __________________________________
void decrypt_content() {
    string file_content;
    myfile.open(name_of_file, ios::in);
    ostringstream item;
    item << myfile.rdbuf();
    file_content = item.str();
    for (auto& letter : file_content) {
        if (letter == '\n') continue;
        else if (letter == 32) continue;
        letter -= 1;
    }
    ofstream file;
    file.open(name_of_file);
    myfile.close();
    myfile.open(name_of_file, ios::out | ios::in | ios::app);
    myfile << file_content;
    myfile.close();
}
// __________________________________
void MergeTwoFiles() {
    myfile.open(name_of_file, ios::in);
    myfile2.open(name_of_file2, ios::in);
    ofstream Merge("Merge.txt");
    string s;
    while (myfile) {
        getline(myfile, s);
        if (!myfile.eof())Merge << s << endl;
    }
    while (myfile2) {
        getline(myfile2, s);
        Merge << s << endl;
    }

}
// __________________________________
int CountWords() {
    string word;
    int number_of_words = 0;
    while (myfile >> word) {
        number_of_words++;
    }
    cout << number_of_words << endl;
    return number_of_words;
}
// __________________________________
int CountChars() {
    char c;
    int number_of_characters = 0;
    while (myfile >> c) {
        number_of_characters++;
    }
    cout << number_of_characters << endl;
    return number_of_characters;
}
// __________________________________
int CountLines() {
    int lines = 0;
    string line;
    while (myfile) {
        getline(myfile, line);
        lines++;
    }
    cout << lines << endl;
    return lines - 1;
}
// __________________________________
string Search() {
    myfile.open(name_of_file, ios::in);
    string word, s;
    cout << "Enter the word you want to search for in the file !\n";
    cin >> word;
    for (int i = 0; i < word.size(); i++) {
        word[i] = tolower(word[i]);// converting the whole string to lowercase
    }
    while (myfile >> s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);// converting each word I will take from the file to lowercase also, to compare it with the word (which) I am looking for.
        }
        if (s == word) {
            cout<< "The word is in this file"<<endl;
            return " ";
        }
    }
  cout<< "The word isn't in this file"<<endl;
  return " ";
}
// __________________________________
void repeated_words() {
    string word, temp; char letter; int count = 0;
    cout << "Enter the word that you search\n";
    cin >> word;
    for_each(word.begin(), word.end(), [](char& c) {
        c = ::tolower(c);
        });
    myfile.open(name_of_file);
    while (!myfile.eof()) {
        letter = myfile.get();
        if (letter == EOF) {
            if (temp == word)
                count++;
            temp = "";
            break;
        }
        else if (!isalpha(letter) && !isdigit(letter)) {
            if (temp == word)
                count++;
            temp = "";
            continue;
        }
        temp += tolower(letter);
    }
    cout << "THe word repeated " << count << " of times " << endl;
    myfile.close();
}
// __________________________________
void upper_case() {
    string text;
    char letter;
    myfile.open(name_of_file);
    while (!myfile.eof()) {
        letter = myfile.get();
        if (letter == EOF)
            break;
        text += toupper(letter);
    }
    myfile.close();
    myfile.open(name_of_file, ios::out);
    myfile << text;
    myfile.close();
}
// __________________________________
void lower_case() {
    string text;
    char letter;
    myfile.open(name_of_file);
    while (!myfile.eof()) {
        letter = myfile.get();
        if (letter == EOF)
            break;
        text += tolower(letter);
    }
    myfile.close();
    myfile.open(name_of_file, ios::out);
    myfile << text;
    myfile.close();
}
// __________________________________
void title() {
    string text;
    stringstream content;
    myfile.open(name_of_file, ios::in);
    content << myfile.rdbuf();
    text = content.str();
    myfile.close();
    myfile.open(name_of_file, ios::in);
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i]) && !(isalpha(text[i - 1])))
            text[i] = toupper(text[i]);
        else
            text[i] = tolower(text[i]);
    }
    myfile.close();
    myfile.open(name_of_file, ios::out);
    myfile << text;
    myfile.close();
}
// __________________________________
void save() {
    char newName[100];
    cout << "enter new name \n";
    cin >> newName;
    strcat(newName, ".txt");
    rename(name_of_file, newName);
}
// __________________________________
void exit() {
    cout << "See you soon ;) " << endl;
    exit(1);
}
