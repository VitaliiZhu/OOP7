#include <iostream>
#include <list>
#include <string>
#include <Windows.h>
#include <stdexcept>
using namespace std;
struct Product {
    string id;
    int quantity;
};

void addProduct(list<Product>& stock, const string& id, int quantity) {
    for (auto& product : stock) {
        if (product.id == id) {
            product.quantity += quantity;
            return;
        }
    }
    stock.push_back({ id, quantity });
}

void processOrders(list<Product>& stock, list<Product>& orders) {
    for (auto it = orders.begin(); it != orders.end(); ) {
        auto stockIt = find_if(stock.begin(), stock.end(), [&it](const Product& product) {
            return product.id == it->id;
            });

        if (stockIt != stock.end() && stockIt->quantity >= it->quantity) {
            stockIt->quantity -= it->quantity;
            it = orders.erase(it);
        }
        else {
            ++it;
        }
    }
}

void displayStock(const list<Product>& stock) {
    cout << "���������� �� �����:" << endl;
    for (const auto& product : stock) {
        cout << "ID: " << product.id << ", ʳ������: " << product.quantity << endl;
    }
}

void displayOrders(const list<Product>& orders) {
    cout << "����������:" << endl;
    for (const auto& order : orders) {
        cout << "ID: " << order.id << ", ʳ������: " << order.quantity << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    list<Product> stock = { {"A001", 10}, {"A002", 5}, {"A003", 20} };
    list<Product> orders = { {"A001", 3}, {"A003", 15}, {"A002", 6} };
    bool error = 1;
    cout << "�� ��������� ����� ������:" << endl;
    displayStock(stock);
    displayOrders(orders);
    bool option = 0;
    error = 1;
    while (error) {
        cout << "��� ��������� ����� ������ �������� 1, � ������������ ������� 0:";

        try {
            cin >> option;
            if (cin.fail()) {
                throw invalid_argument("������� �����");
            }
            error = 0;
        }
        catch (const invalid_argument& e) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << e.what() << endl;

        }
    }
    
    
        string id;
        int quantity;
        cout << "������ ��� ������:";
        cin >> id;
        error = 1;
        while (error) {
        cout << "������ ������� ������ ������:";
        try {
            cin >> quantity;
            if (cin.fail()) {
                throw invalid_argument("������� �����");
            }
            error = 0;
        }
        catch (const invalid_argument& e) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << e.what() << endl;
            }
        }
        
        addProduct(stock, id, quantity);
        error = 1;
        while (error) {
            cout << "��� ��������� ����� ������ �������� 1, � ������������ ������� 0:";
            try {
                cin >> option;
                if (cin.fail()) {
                    throw invalid_argument("������� �����");
                }
                error = 0;
            }
            catch (const invalid_argument& e) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << e.what() << endl;
                
            }
        }
    
    cout << "\nϳ��� ��������� ����� ������:" << endl;
    displayStock(stock);
    
    option = 0;
    error = 1;
    while (error) {
        cout << "��� ��������� ����� ��������� �������� 1, � ������������ ������� 0:";
        try {
            cin >> option;
            if (cin.fail()) {
                throw invalid_argument("������� �����");
            }
            error = 0;
        }
        catch (const invalid_argument& e) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << e.what() << endl;

        }
    
    }
    while (option) {
        string id;
        int quantity;
        cout << "������ ��� ������:";
        cin >> id;
        error = 1;
        while (error) {
            cout << "������ ������� ������ ������:";
            try {
                cin >> quantity;
                if (cin.fail()) {
                    throw invalid_argument("������� �����");
                }
                error = 0;
            }
            catch (const invalid_argument& e) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << e.what() << endl;

            }
        }
    
        addProduct(orders, id, quantity);
        error = 1;
        while (error) {
            cout << "��� ��������� ����� ��������� �������� 1, � ������������ ������� 0:";
            try {
                cin >> option;
                if (cin.fail()) {
                    throw invalid_argument("������� �����");
                }
                error = 0;
            }
            catch (const invalid_argument& e) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << e.what() << endl;
                
            }
        }
    }
   
    processOrders(stock, orders);

    cout << "\nϳ��� ������� ���������:" << endl;
    displayStock(stock);
    displayOrders(orders);

    return 0;
}