#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void exchangeCurrency() {
    double amountInRUB;
    const double commissionRate = 0.05; 

   
    double exchangeRates[5] = { 75.0, 85.0, 11.0, 0.02, 0.65 }; 
    string currencyNames[5] = { "Доллар", "Евро", "Юань", "Фарит", "Йена" };

    cout << "Введите сумму в рублях: ";
    cin >> amountInRUB;

    cout << "Выберите валюту для обмена:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << currencyNames[i] << endl;
    }

    int choice;
    cout << "Ваш выбор (1-5): ";
    cin >> choice;

   
    if (choice < 1 || choice > 5) {
        cout << "Неверный выбор. Попробуйте снова." << endl;
        return;
    }

   
    double commission = amountInRUB * commissionRate;
    double amountAfterCommission = amountInRUB - commission;

   
    double amountInCurrency = amountAfterCommission/ exchangeRates[choice - 1];

   
    cout << fixed << setprecision(2);
    cout << "Вы получили: " << amountInCurrency << " " << currencyNames[choice - 1] << "." << endl;
    cout << "Сумма комиссии: " << commission << " рублей." << endl;
}

int main() {
    char repeat;

    do {
        exchangeCurrency();

        cout << "Хотите обменять еще раз (y/n)? ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    cout << "Спасибо за использование нашего сервиса!" << endl;

    return 0;
}