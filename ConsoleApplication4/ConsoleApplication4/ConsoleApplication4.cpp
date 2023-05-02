#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый класс для предметов
class Item {
protected:
    int health_bonus; // Бонус к здоровью
    int speed_bonus; // Бонус к скорости
    int damage_bonus; // Бонус к урону
public:
    Item(int health_bonus, int speed_bonus, int damage_bonus) :
        health_bonus(health_bonus), speed_bonus(speed_bonus), damage_bonus(damage_bonus) {}

    // Вывод информации о предмете
    virtual void print() const {
        cout << "health: " << health_bonus << endl;
        cout << "speed: " << speed_bonus << endl;
        cout << "damage: " << damage_bonus << endl;
    }
};

// Предмет "Броня"
class Armor : public Item {
public:
    Armor(int health_bonus, int speed_bonus, int damage_bonus) :
        Item(health_bonus, speed_bonus, damage_bonus) {}

    void print() const override {
        cout << "Armor:" << endl;
        Item::print();
    }
};

// Предмет "Оружие"
class Weapon : public Item {
public:
    Weapon(int health_bonus, int speed_bonus, int damage_bonus) :
        Item(health_bonus, speed_bonus, damage_bonus) {}

    void print() const override {
        cout << "Weapon:" << endl;
        Item::print();
    }
};

// Предмет "Ботинки"
class Boots : public Item {
public:
    Boots(int health_bonus, int speed_bonus, int damage_bonus) :
        Item(health_bonus, speed_bonus, damage_bonus) {}

    void print() const override {
        cout << "Boots:" << endl;
        Item::print();
    }
};

// Базовый класс для юнитов
class Unit {
protected:
    string type; // Тип юнита
    int health; // Уровень здоровья
    int speed; // Скорость передвижения
    int damage; // Урон
    vector<Item*> items; // Список предметов
public:
    Unit(string type, int health, int speed, int damage) :
        type(type), health(health), speed(speed), damage(damage) {}

    // Добавление предмета к юниту
    void addItem(Item* item) {
        items.push_back(item);
    }

    // Вывод информации о юните и его предметах
    virtual void print() const {
        cout << type << endl;
        cout << "health: " << health << endl;
        cout << "speed: " << speed << endl;
        cout << "damage: " << damage << endl;
        cout << endl;
        for (auto item : items) {
            item->print();
            cout << endl;
        }
    }
};
// Класс "Маг"
class Mage : public Unit {
public:
    Mage(int health, int speed, int damage) :
        Unit("Mage", health, speed, damage) {}
};

// Класс "Воин"
class Warrior : public Unit {
public:
    Warrior(int health, int speed, int damage) :
        Unit("Warrior", health, speed, damage) {}
};

// Класс "Рыцарь"
class Knight : public Unit {
public:
    Knight(int health, int speed, int damage) :
        Unit("Knight", health, speed, damage) {}
};

int main() {
    int num_units;
    cout << "Enter the number of units: ";
    cin >> num_units;

    vector<Unit*> units;
    for (int i = 0; i < num_units; i++) {
        string type;
        int health, speed, damage;
        cout << "Enter unit type, health, speed and damage: ";
        cin >> type >> health >> speed >> damage;

        Unit* unit = new Unit(type, health, speed, damage);

        int num_items;
        cout << "Enter the number of items for this unit: ";
        cin >> num_items;

        for (int j = 0; j < num_items; j++) {
            string item_type;
            int bonus;
            cout << "Enter item type, health bonus, speed bonus and damage bonus: ";
            cin >> item_type >> bonus;

            Item* item;
            if (item_type == "armor") {
                item = new Armor(bonus, 0, 0);
            }
            else if (item_type == "weapon") {
                item = new Weapon(0, 0, bonus);
            }
            else if (item_type == "boots") {
                item = new Boots(0, bonus, 0);
            }
            else {
                cout << "Invalid item type" << endl;
                continue;
            }

            unit->addItem(item);
        }

        units.push_back(unit);
    }

    // Вывод информации о всех юнитах
    for (auto unit : units) {
        unit->print();
        cout << endl;
    }

    // Освобождение памяти
    for (auto unit : units) {
        delete unit;
    }

    return 0;
}