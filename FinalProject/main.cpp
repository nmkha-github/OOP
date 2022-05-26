#include <iostream>
#include "Income.h"
#include "Payment.h"
#include "Loan.h"
#include "BankBook.h"
using namespace std;
class Menu {
private:
    string choose;
public:
    Menu() {
        choose = "";
    }
    void run() {
        cout << "--------------Thong tin thu nhap hang thang---------------\n";
        long long wifeSalary, husbandSalary, otherIncome;
        cout << "Nhap luong vo hang thang (VND): "; cin >> wifeSalary;
        cout << "Nhap luong chong hang thang (VND): "; cin >> husbandSalary;
        cout << "Nhap nguon thu khac cua hai vo chong (VND): "; cin >> otherIncome;
        cout << "--------------Thong tin chi tieu hang thang---------------\n";
        long long housePayment, foodPayment, otherPayment;
        cout << "Nhap tien dien nuoc hang thang (VND): "; cin >> housePayment;
        cout << "Nhap tien an hang thang (VND): "; cin >> foodPayment;
        cout << "Nhap khoan chi tieu khac (VND): "; cin >> otherPayment;
        cout << "--------------Thong tin vay no----------------------------\n";
        long long shortLoan, longLoan;
        cout << "Nhap tien no 1 nam ruoi (VND): "; cin >> shortLoan;
        cout << "Nhap tien no 3 nam (VND): "; cin >> longLoan;
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
            cout << "0. Thoi diem tra het no. (chua xong)\n";
            cout << "1. Tra cuu + tinh tong thu, chi thang cu the.\n";
            cout << "2. Tinh toan chi tieu thang am hoac duong.\n";
            cout << "3. Thay doi thu nhap, chi tieu hang thang.\n";
            cout << "4. Chinh sua lai suat tien vay no.\n";
            cout << "5. Gui tiet kiem.\n";
            cout << "6. So tiet kiem.\n";
            cout << "7. Xuat file excel. (chua xong)\n";
            cout << "8. Ket thuc chuong trinh.\n";
            cout << "Nhap yeu cau (0->7): "; cin >> choose;
            while ((choose.size() > 1) || (choose[0] - '0' < 0 && choose[0] - '0' > 7)) {
                cout << "Moi nhap lai yeu cau (0->5): ";
                cin >> choose;
            }
            switch (choose[0] - '0') {
            case 0:
                
                break;
            case 1:
                option1(familyIncome, familyPayment, familyLoan);
                break;
            case 2:
                option2(familyIncome, familyPayment, familyLoan);
                break;
            case 3:
                option3(familyIncome, familyPayment, familyLoan);
                break;
            case 4:
                option4(familyIncome, familyPayment, familyLoan);
                break;
            case 5:
                //option5();
            case 6:
                
                break;
            case 7:
                exportExcel();
                break;
            default:
                isRunning = false;
                break;
            }
        }
    };
    void option1(Income familyIncome, Payment familyPayment, Loan familyLoan) {    
        system("cls");
        cout << familyLoan << endl;
        cout << familyIncome << endl;
        cout << familyPayment << endl;
        cout << "--------------------------------------------------------------------\n";
        int month, year;
        cout << "Nhap nam de tra cuu (2022->2025): "; cin >> year;
        if (year == 2022)
            cout << "Nhap thang de tra cuu (5->12): ";
        else if (year == 2025)
            cout << "Nhap thang de tra cuu (1->5): ";
        else 
            cout << "Nhap thang de tra cuu (1->12): ";
        cin >> month;
        
        cout << "Thong tin thang " << month << '/' << year << ':' << endl;
        cout << "- Tong thu: " << familyIncome.sumIncome() << '\n';
        cout << "- Tong chi: " << familyPayment.sumPayment() << '\n';
        cout << "- Tien du cac thang truoc: "
            << (familyIncome.sumIncome() - familyPayment.sumPayment()) * (year * 12 + month - 2022 * 12 - 5) << '\n';
        system("pause");
    }
    void option2(Income familyIncome, Payment familyPayment, Loan familyLoan) {
        system("cls");
        cout << familyLoan << endl;
        cout << familyIncome << endl;
        cout << familyPayment << endl;
        cout << "--------------------------------------------------------------------\n";
        int month, year;
        cout << "Nhap nam de tra cuu (2022->2025): "; cin >> year;
        if (year == 2022)
            cout << "Nhap thang de tra cuu (5->12): ";
        else if (year == 2025)
            cout << "Nhap thang de tra cuu (1->5): ";
        else
            cout << "Nhap thang de tra cuu (1->12): ";
        cin >> month;

        long long monthPaying = (familyIncome.sumIncome() - familyPayment.sumPayment());
        if (monthPaying >= 0)
            cout << "Chi tieu thang " << month << '/' << year << " duong " << monthPaying << " (VND)\n";
        else {
            cout << "Chi tieu thang " << month << '/' << year << " am " << monthPaying << " (VND)\n";
            cout << "Can thay doi chi tieu (lua chon so 3)";
        }
        system("pause");
    }
    void option3(Income& familyIncome, Payment& familyPayment, Loan& familyLoan) {
        system("cls");
        cout << familyLoan << endl;
        cout << familyIncome << endl;
        cout << familyPayment << endl;
        cout << "--------------------------------------------------------------------\n";
        cout << "1. Thay doi chi tieu.\n";
        cout << "2. Thay doi thu nhap.\n";
        int q;
        cout << "Nhap lua chon (1->2): "; cin >> q;
        if (q == 1)
            cin >> familyPayment;
        else if (q == 2)
            cin >> familyIncome;
        system("pause");
    }
    void option4(Income familyIncome, Payment familyPayment, Loan& familyLoan) {
        system("cls");
        cout << familyLoan << endl;
        cout << familyIncome << endl;
        cout << familyPayment << endl;
        cout << "--------------------------------------------------------------------\n";
        cout << "Nhap lai suat tien vay no 1 nam ruoi (%): ";
        double rate;
        cin >> rate;
        familyLoan.changeRate1(rate / 100);
        cout << "Nhap lai suat tien vay no 3 nam (%): ";
        cin >> rate;
        familyLoan.changeRate2(rate / 100);
        system("cls");
        cout << familyLoan << endl;
        cout << familyIncome << endl;
        cout << familyPayment << endl;
        cout << "--------------------------------------------------------------------\n";
        cout << "Nhap lai suat tien vay no 1 nam ruoi (%): " << familyLoan.getRate1() << endl;
        cout << "Nhap lai suat tien vay no 3 nam (%): " << familyLoan.getRate2() << endl;
        system("pause");
    }
    void option5(Income familyIncome, Payment familyPayment, Loan& familyLoan, BankBook& familyBankBook) {
        system("cls");
        cout << familyLoan << endl;
        cout << familyIncome << endl;
        cout << familyPayment << endl;
        cout << "--------------------------------------------------------------------\n";
        int month, year;
        cout << "Nhap nam de tra cuu (2022->2025): "; cin >> year;
        if (year == 2022)
            cout << "Nhap thang de tra cuu (5->12): ";
        else if (year == 2025)
            cout << "Nhap thang de tra cuu (1->5): ";
        else
            cout << "Nhap thang de tra cuu (1->12): ";
        cin >> month;
        cout << "Thong tin so tiet kiem thang " << month << '/' << year << ":\n";
        cout << familyBankBook;
    }
    void exportExcel() {

    }
};

int main(){
    Menu menu;
    menu.run();
}