#include <iostream>
#include <fstream>
using namespace std;

struct Person {
    const char *name;
    const char *surname;
    const int age;
};


void dumpToFile(ofstream& file, const Person& person) {
    const char *rawPoint = reinterpret_cast<const char*>(&person);
    const int bytesToWrite = sizeof(person);

    file.write(rawPoint, bytesToWrite);
    file << endl;
}


void dumpToFile(ofstream& file, const Person *people, const int count) {
    for (int i = 0; i < count; i++)
        dumpToFile(file, people[i]);
}


void loadFromFile(ifstream& file, Person& result) {
    char *target = reinterpret_cast<char*>(&result); 
    const int bytesToRead = sizeof(result);
    
    file.read(target, bytesToRead);
    file.get();
}

void loadFromFile(ifstream& file, Person *people, const int count) {
    for (int i = 0; i < count; i++)
        loadFromFile(file, people[i]);
}


int main()
{
    const Person people[3] = {
        {"luca", "abete", 20},
        {"mario", "rossi", 30},
        {"pinco", "pallino", 40},
    };

    ofstream outFile("people.dump");
    dumpToFile(outFile, people, 3);
    outFile.close();

    Person loadedPeople[3] = {};

    ifstream inFile("people.dump");
    loadFromFile(inFile, loadedPeople, 3);
    inFile.close();

    for (int i = 0; i < 3; i++) {
        const Person& person = loadedPeople[i];
        cout 
            << person.name << ", "
            << person.surname << ", "
            << person.age << '\n';
    }
}