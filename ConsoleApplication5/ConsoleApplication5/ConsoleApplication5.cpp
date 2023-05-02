#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Animal {
protected:
    int age;
    int weight;
    string gender;
public:
    Animal(int age, int weight, string gender) : age(age), weight(weight), gender(gender) {}
    virtual void move() = 0;
    virtual void feed() = 0;
    virtual void print() = 0;
};

class Mammal : public Animal {
protected:
    string locationOfMammaryGlands;
    int pregnancyTime;
public:
    Mammal(int age, int weight, string gender,  int pregnancyTime) : Animal(age, weight, gender), pregnancyTime(pregnancyTime) {}
    void move() override {
        cout << "Млекопитающие передвигается" << endl;
    }
    void feed() override {
        cout << "Млекопитающее кормит молоком свое потомство" << endl;
    }
    virtual void gestate() = 0;
    virtual void print() = 0;
};

class Human : public Mammal {
protected:
    string name;
    string surname;
    string dateOfBirth;
    string born;
public:
    Human(int age, int weight, string gender,  int pregnancyTime, string name, string surname, string dateOfBirth) : Mammal(age, weight, gender,  pregnancyTime), name(name), surname(surname), dateOfBirth(dateOfBirth) {}
    void gestate() override {
        cout << "Беременность матери длилась " << pregnancyTime << " месяцев" << endl;
    }

    void print() override {
        if (gender == "female") {
            born = "родилась";
        }
        else {
            born = "родился";
        }
        cout << name << " " << surname << ", "<< born <<" " << dateOfBirth << ", " << gender << " ,весит " << weight << " кг, " << age << " лет" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int age, weight, pregnancyTime;
    string gender, name, surname, dateOfBirth;

    cout << "Введите возраст: ";
    cin >> age;

    cout << "введите вес: ";
    cin >> weight;

    cout << "Введите пол: ";
    cin >> gender;


    cout << "Срок беременности: ";
    cin >> pregnancyTime;

    cout << "Имя: ";
    cin >> name;

    cout << "Фамилия: ";
    cin >> surname;

    cout << "Дата рождения (dd/mm/yyyy): ";
    cin >> dateOfBirth;

    Human person(age, weight, gender, pregnancyTime, name, surname, dateOfBirth);
    person.move();
    person.feed();
    person.gestate();
    person.print();
    return 0;
}
