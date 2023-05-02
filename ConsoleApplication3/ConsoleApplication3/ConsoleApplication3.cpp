#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Client {
protected:
    string number; // уникальный номер клиента
    int balance; // баланс клиента
public:
    Client(string n, int b) : number(n), balance(b) {}
    virtual ~Client() {}

    string getNumber() const { return number; }
    int getBalance() const { return balance; }

    virtual void addMoney(int amount) { balance += amount; }
    virtual bool withdrawMoney(int amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    virtual void printInfo() const {
        cout << "Client " << number << ": ";
        cout << "ordinary, balance " << balance << endl;
    }
};

class VipClient : public Client {
private:
    int bonus; // количество бонусов
    const int bonusRate = 5; // сколько бонусов начисляется за каждое пополнение
    const int discountRate = 10; // процент скидки на снятие денег
public:
    VipClient(string n, int b) : Client(n, b), bonus(0) {}
    ~VipClient() {}

    void addMoney(int amount) override {
        Client::addMoney(amount);
        bonus += amount / bonusRate;
    }

    bool withdrawMoney(int amount) override {
        int discountedAmount = amount * (100 - discountRate) / 100;
        bool success = Client::withdrawMoney(discountedAmount);
        if (success) {
            bonus -= discountedAmount / bonusRate;
        }
        return success;
    }

    void printInfo() const override {
        cout << "Client " << number << ": ";
        cout << "VIP, balance " << balance << ", ";
        cout << bonus << " bonuses" << endl;
    }
};

int main() {
    unordered_map<string, Client*> clients;

    string command;
    while (cin >> command) {
        if (command == "create") {
            string number, type;
            int balance;
            cin >> number >> type >> balance;
            if (type == "ordinary") {
                clients[number] = new Client(number, balance);
            }
            else if (type == "vip") {
                clients[number] = new VipClient(number, balance);
            }
        }
        else if (command == "add") {
            string number;
            int amount;
            cin >> number >> amount;
            if (clients.count(number)) {
                clients[number]->addMoney(amount);
            }
        }
        else if (command == "withdraw") {
            string number;
            int amount;
            cin >> number >> amount;
            if (clients.count(number)) {
                bool success = clients[number]->withdrawMoney(amount);
                if (success) {
                    cout << "Withdrawal successful" << endl;
                }
            }
        }
        else if (command == "info") {
            string number;
            cin >> number;
            if (clients.count(number)) {
                clients[number]->printInfo();
            }
        }
    }

    for (auto& p : clients) {
        delete p.second;
    }

    return 0;
}