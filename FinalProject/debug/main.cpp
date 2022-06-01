#include <iostream>
#include <vector>
#include "Income.h"
#include "Payment.h"
#include "Loan.h"
#include "BankBook.h"
#include "Date.h"
using namespace std;
class Menu {
private:
    string choose;
    bool  isSaved;
public:
    Menu() {
        choose = "";
        isSaved = false;
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
        double rate1;
        cout << "Nhap tien no 1 nam ruoi (VND): "; cin >> shortLoan;
        cout << "Nhap lai suat 1 nam ruoi (%/thang): "; cin >> rate1;
        cout << "Nhap tien no 3 nam (VND) (voi lai co dinh 6%/nam): "; cin >> longLoan;
        //---------------------------Init value----------------------------------
        Income familyIncomes[40];
        for (int i = 0; i < 36; i++) {
            familyIncomes[i].setWifeSalary(wifeSalary);
            familyIncomes[i].setHusbandSalary(husbandSalary);
            familyIncomes[i].setOtherIncome(otherIncome);
        }
        Payment familyPayments[40];
        for (int i = 0; i < 36; i++) {
            familyPayments[i].setHousePayment(housePayment);
            familyPayments[i].setFoodPayment(foodPayment);
            familyPayments[i].setOtherPayment(otherPayment);
        }
        Loan familyLoan(shortLoan, rate1, longLoan);
        vector <BankBook> familyBankBooks;
        bool isRunning = true;
        while (isRunning) {
            system("cls");
            cout << "0. Thoi diem tra het no. (chua xong)\n";
            cout << "1. Tra cuu.\n";
            cout << "2. Chinh sua.\n";
            cout << "3. Tinh hinh thu nhap cua thang (duong, am).\n";
            cout << "4. Gui tiet kiem.\n";
            cout << "5. So tiet kiem.\n";
            cout << "6. Xuat file excel. (chua xong)\n";
            cout << "7. Ket thuc chuong trinh.\n";
            cout << "Nhap yeu cau (0->7): "; cin >> choose;
            while ((choose.size() > 1) || (choose[0] - '0' < 0 && choose[0] - '0' > 7)) {
                cout << "Moi nhap lai yeu cau (0->7): ";
                cin >> choose;
            }
            switch (choose[0] - '0') {
            case 0:
                //option0();
                break;
            case 1:
                option1(familyIncomes, familyPayments, familyLoan);
                break;
            case 2:
                option2(familyIncomes, familyPayments, familyLoan);
                break;
            case 3:
                option3(familyIncomes, familyPayments);
                break;
            case 4:
                option4();
                break;
            case 5:
                option5();
                break;
            case 6:
                exportExcel();
                break;
            default:
                isRunning = false;
                break;
            }
        }
    };
    void option0(Income familyIncomes[], Payment familyPayments[], Loan familyLoan) {

    }
    void option1(Income familyIncomes[], Payment familyPayments[], Loan familyLoan) {
        system("cls");
        cout << "----Tra cuu.\n";
        Date date;
        date = date.input();
        cout << "1. Thu nhap.\n";
        cout << "2. Chi tieu.\n";
        cout << "3. Tien no.\n";
        cout << "Nhap lua chon (1->3): "; 
        int q; cin >> q;
        if (q == 1)
            cout << familyIncomes[date - Date(5, 2022)];
        else
        if (q == 2)
            cout << familyPayments[date - Date(5, 2022)];
        else
        if (q == 3) {
            cout << familyLoan;
            cout << "Tien lai thang " << date << ":\n";
            cout << "1 nam ruoi: " << familyLoan.getRate1() * familyLoan.getShortLoan() << " (VND)\n";
            cout << "1 nam ruoi: " << familyLoan.getRate2() * familyLoan.getLongLoan() << " (VND)\n";
        }
        system("pause");
    }
    void option2(Income familyIncomes[], Payment familyPayments[], Loan& familyLoan) {
        system("cls");
        cout << "----Chinh sua.\n";
        Date date;
        date = date.input();
        cout << "1. Thu nhap.\n";
        cout << "2. Chi tieu.\n";
        cout << "3. Tien no.\n";
        cout << "Nhap lua chon (1->3): ";
        int q; cin >> q;
        if (q == 1)
            cin >> familyIncomes[date - Date(5, 2022)];
        else
        if (q == 2)
            cin >> familyPayments[date - Date(5, 2022)];
        else
        if (q == 3)
            cin >> familyLoan;
        else {
            cout << "Lua chon sai.\nChinh sua that bai.\n";
            system("pause");
            return;
        }
        cout << "Chinh sua thanh cong.\n";
        system("pause");
    }
    void option3(Income familyIncomes[], Payment familyPayments[]) {
        system("cls");
        cout << "----Tinh hinh thu nhap.\n";
        Date date;
        date = date.input();
        long long found = familyIncomes[date - Date(5, 2022)].getOtherIncome() - familyPayments[date - Date(5, 2022)].sumPayment();
        if (found >= 0)
            cout << "Thu nhap thang " << date << " duong " << found << " (VND).\n";
        else {
            cout << "Thu nhap thang " << date << " am " << -found << " (VND).\n";
            long long pastMonthMoney = 0;
            for (int i = 0; i < date - Date(5, 2022); i++)
                pastMonthMoney += familyIncomes[i].getOtherIncome() - familyPayments[i].sumPayment();
            cout << "Tien du cac thang truoc: " << pastMonthMoney << " (VND).\n";
            cout << "Luong vo: " << familyIncomes[date - Date(5, 2022)].getWifeSalary() << " (VND).\n";
            cout << "Luong chong: " << familyIncomes[date - Date(5, 2022)].getHusbandSalary() << " (VND).\n";
            if (pastMonthMoney + familyIncomes[date - Date(5, 2022)].getWifeSalary() + familyIncomes[date - Date(5, 2022)].getHusbandSalary() + found < 0)
                cout << "Vo no.\n";
            else
                if (pastMonthMoney + found >= 0) {
                    cout << "Tien du cac thang truoc + thu nhap thang " << date << ": " << pastMonthMoney + found << " duong"
                        << " => Khong can dung luong vo/chong bu qua.\n";
                }
            else {
                if (found + familyIncomes[date - Date(5, 2022)].getHusbandSalary() >= 0) {
                    cout << "Dung " << -found << " luong chong bu qua thu nhap khac";
                    familyIncomes[date - Date(5, 2022)].setOtherIncome(familyIncomes[date - Date(5, 2022)].getOtherIncome() - found);
                    familyIncomes[date - Date(5, 2022)].setHusbandSalary(familyIncomes[date - Date(5, 2022)].getHusbandSalary() + found);
                }
                else {
                    cout << "Dung " << familyIncomes[date - Date(5, 2022)].getHusbandSalary() << " luong chong + "
                        << -(found + familyIncomes[date - Date(5, 2022)].getHusbandSalary()) << " luong vo\nbu qua thu nhap khac.\n";
                    familyIncomes[date - Date(5, 2022)].setOtherIncome(familyIncomes[date - Date(5, 2022)].getOtherIncome() - found);
                    familyIncomes[date - Date(5, 2022)].setWifeSalary(familyIncomes[date - Date(5, 2022)].getWifeSalary() + familyIncomes[date - Date(5, 2022)].getHusbandSalary() + found);
                    familyIncomes[date - Date(5, 2022)].setHusbandSalary(0);
                }
            }
        }
        system("pause");
    }
    void option4() {
        
    }
    void option5() {
        
    }
    void exportExcel() {

    }
};

int main(){
    Menu menu;
    menu.run();
}