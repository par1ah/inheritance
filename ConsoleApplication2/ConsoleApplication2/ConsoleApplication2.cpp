#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal(const string& name, int age) : name_(name), age_(age) {}
    virtual ~Animal() {}
    virtual string getType() const = 0;
    virtual string getUniqueInfo() const = 0;
    string getName() const { return name_; }
    int getAge() const { return age_; }
protected:
    string name_;
    int age_;
};

class Dog : public Animal {
public:
    Dog(const string& name, int age, const string& breed, int training_level)
        : Animal(name, age), breed_(breed), training_level_(training_level) {}
    string getType() const override { return "dog"; }
    string getUniqueInfo() const override { return breed_ + ", level of training " + to_string(training_level_); }
private:
    string breed_;
    int training_level_;
};

class Cat : public Animal {
public:
    Cat(const string& name, int age, const string& breed, const string& coat_color)
        : Animal(name, age), breed_(breed), coat_color_(coat_color) {}
    string getType() const override { return "cat"; }
    string getUniqueInfo() const override { return breed_ + ", " + coat_color_; }
private:
    string breed_;
    string coat_color_;
};

class Giraffe : public Animal {
public:
    Giraffe(const string& name, int age, float neck_length, const string& color)
        : Animal(name, age), neck_length_(neck_length), color_(color) {}
    string getType() const override { return "giraffe"; }
    string getUniqueInfo() const override { return "neck length " + to_string(neck_length_) + " m, " + color_; }
private:
    float neck_length_;
    string color_;
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string type, name, unique_info;
        int age;
        cin >> type >> name >> age;
        if (type == "dog") {
            string breed;
            int training_level;
            cin >> breed >> training_level;
            Dog dog(name, age, breed, training_level);
            cout << dog.getName() << ", " << dog.getAge() << " years old: "
                << dog.getType() << ", " << dog.getUniqueInfo() << ".\n";
        }
        else if (type == "cat") {
            string breed, coat_color;
            cin >> breed >> coat_color;
            Cat cat(name, age, breed, coat_color);
            cout << cat.getName() << ", " << cat.getAge() << " years old: "
                << cat.getType() << ", " << cat.getUniqueInfo() << ".\n";
        }
        else if (type == "giraffe") {
            float neck_length;
            string color;
            cin >> neck_length >> color;
            Giraffe giraffe(name, age, neck_length, color);
            cout << giraffe.getName() << ", " << giraffe.getAge() << " years old: "
                << giraffe.getType() << ", " << giraffe.getUniqueInfo() << ".\n";
        }
    }
    return 0;
}