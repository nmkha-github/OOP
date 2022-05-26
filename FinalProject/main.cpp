#include <iostream>
#include "Income.h"
#include "Payment.h"
#include "Loan.h"
#include <Windows.h>
using namespace std;
class Menu {
private:
    string choose;
    void gotoxy(int x, int y) {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
public:
    Menu() {
        choose = "";
    }
    void run() {
        cout << "--------------Thong tin thu nhap hang thang---------------\n";
        long long wifeSalary, husbandSalary, otherIncome;
        cout << "Nhap luong vo hang thang: "; cin >> wifeSalary;
        cout << "Nhap luong chong hang thang: "; cin >> husbandSalary;
        cout << "Nhap nguon thu khac cua hai vo chong: "; cin >> otherIncome;
        cout << "--------------Thong tin chi tieu hang thang---------------\n";
        long long housePayment, foodPayment, otherPayment;
        cout << "Nhap tien dien nuoc hang thang: "; cin >> housePayment;
        cout << "Nhap tien an hang thang: "; cin >> foodPayment;
        cout << "Nhap khoan chi tieu khac: "; cin >> otherPayment;
        cout << "--------------Thong tin vay no----------------------------\n";
        long long shortLoan, longLoan;
        cout << "Nhap tien no 1 nam ruoi: "; cin >> shortLoan;
        cout << "Nhap tien no 3 nam: "; cin >> longLoan;
        Income familyIncome(wifeSalary, husbandSalary, otherIncome);
        Payment familyPayment(housePayment, foodPayment, otherPayment);
        Loan familyLoan(shortLoan, longLoan, 0.065);
        bool isRunning = true;
        while (isRunning) {
            system("cls");
            cout << familyLoan << endl;
            cout << familyIncome << endl;
            cout << familyPayment << endl;
            cout << "--------------------------------------------------------------------\n";
            cout << "0. Thoi diem tra het no.\n";
            cout << "1. Tra cuu + tinh tong thu, chi thang cu the.\n";
            cout << "2. Tinh toan chi tieu thang am hoac duong + gui ngan hang.\n";
            cout << "3. Chinh sua lai suat tien vay no.\n";
            cout << "4. Xuat file excel.\n";
            cout << "5. Ket thuc chuong trinh.\n";
            cout << "Nhap yeu cau (0->5): "; cin >> choose;
            while ((choose.size() > 1) || (choose[0] - '0' >= 0 && choose[0] - '0' <= 5)) {
                cout << "Moi nhap lai yeu cau (0->5): ";
                cin >> choose;
            }
            switch (choose[0] - '0') {
            case 0:
                
                break;
            case 1:
                menu1(familyIncome, familyPayment, familyLoan);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                exportExcel();
                break;
            default:
                isRunning = false;
                break;
            }
        }
    };
    void menu1(Income familyIncome, Payment familyPayment, Loan familyLoan) {
        bool isRunning = true;
        while (isRunning) {
            system("cls");
            cout << familyLoan << endl;
            cout << familyIncome << endl;
            cout << familyPayment << endl;
            cout << "--------------------------------------------------------------------\n";
            int month, year;
            cout << "Nhap thang de tra cuu (1->12): "; cin >> month;
            cout << "Nhap nam de tra cuu (2022->2025): "; cin >> year;

        }
    }
    void exportExcel() {

    }
};

int main(){
    Menu menu;
    menu.run();
}