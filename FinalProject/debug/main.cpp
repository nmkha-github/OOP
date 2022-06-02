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
        rate1 /= 100;
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
            cout << "0. Thoi diem tra het no.\n";
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
                option0(familyIncomes, familyPayments, familyLoan, familyBankBooks);
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
                option4(familyIncomes, familyBankBooks);
                break;
            case 5:
                option5(familyBankBooks);
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
    void option0(Income familyIncomes[], Payment familyPayments[], Loan familyLoan, vector<BankBook> &familyBankBook) {
        system("cls");
        // Short Loan
        Date date;
        date.month = 12;
        date.year = 2023;
        long long sumBooks = 0;
        long long sumShortLoan = familyLoan.getShortLoan() * (1 + familyLoan.getRate1());
        long long pastMonthMoney = 0;
        for (int i = 0; i < date - Date(5, 2022); i++)
            pastMonthMoney += familyIncomes[i].getOtherIncome() - familyPayments[i].sumPayment();
        long long thisMonth = pastMonthMoney - familyPayments[17].sumPayment();
        if (thisMonth < 0) {
            if (familyIncomes[17].getHusbandSalary() < -thisMonth) {
                thisMonth += familyIncomes[17].getHusbandSalary();
                familyIncomes[17].setHusbandSalary(0);
                thisMonth += familyIncomes[17].getWifeSalary();
                if (thisMonth < 0)
                {
                    familyIncomes[17].setWifeSalary(0);
                }
            }
        }

        for (int i = 0; i < familyBankBooks.size(); i++) {
            if (familyBankBooks[i].getDeadline() - date < 0) // truoc thoi han 12/2023 
            {
                sumBooks += familyBankBooks[i].getProfit(date);
                familyBankBooks.erase(familyBankBooks.begin() + i);
            }
        }
        // Long Loan
        Date dateLongLoan;
        dateLongLoan.month = 5;
        dateLongLoan.year = 2025;
        long long sumLongLoan = familyLoan.getLongLoan() * (1 + familyLoan.getRate2());
        long long  moneyAfterShortLoan = sumBooks + thisMonth - sumShortLoan;
        long long changeAfterShortLoan = moneyAfterShortLoan;
        if (moneyAfterShortLoan >= 0) {
            cout << "Co kha nang tra no thoi han ngan\n";
        }
        else {
            cout << "Khong co kha nang tra no thoi han ngan\n";
        }

        for (int i = 18; i < dateLongLoan - Date(12, 2023); i++)
            changeAfterShortLoan += familyIncomes[i].getOtherIncome() - familyPayments[i].sumPayment();
        long long changeTotal = changeAfterShortLoan - familyPayments[38].sumPayment(); // tong tien thua tinh den ngay 5/2025

        for (int i = 0; i < familyBankBooks.size(); i++) { // rut het so
            moneyAfterShortLoan += familyBankBooks[i].getProfit(dateLongLoan);
            familyBankBooks.erase(familyBankBooks.begin() + i);
        }

        if (moneyAfterShortLoan - sumLongLoan >= 0)
            cout << "Co kha nang tra no thoi han dai\n";
        else
            cout << "Khong co kha nang tra no thoi han dai\n";

        system("pause");
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
        cout << "Thang " << date << ":\n";
        if (q == 1)
            cout << familyIncomes[date - Date(5, 2022)];
        else
            if (q == 2)
                cout << familyPayments[date - Date(5, 2022)];
            else
                if (q == 3) {
                    cout << familyLoan;
                    cout << "Tien lai thang " << date << ":\n";
                    cout << "1 nam ruoi: " << familyLoan.getRate1() * (double)familyLoan.getShortLoan() << " (VND)\n";
                    cout << "3 nam: " << familyLoan.getRate2() * (double)familyLoan.getLongLoan() << " (VND)\n";
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
        cout << "Thang " << date << ":\n";
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
    void option4(Income familyIncomes[], vector<BankBook>& familyBankBooks) {
        system("cls");
        BankBook BankBooks;
        cout << "Nhap thoi diem muon gui tiet kiem\n";
        Date date;
        Date dateEnd;
        date = date.input();
        cout << "Chon loai gui\n";
        cout << "1. 6 thang (6%/thang)\n";
        cout << "2. 12 thang(6.6%/thang)\n";
        int choice = 0;
        cout << "Nhap yeu cau (1->2): ";
        cin >> choice;
        while (choice > 2 || choice < 1) {
            cout << "Moi nhap lai yeu cau (1->2): ";
            cin >> choice;
        }

        long long sum = familyIncomes[date - Date(5, 2022)].sumSalary();
        BankBooks.addMoney(sum);
        BankBooks.setStartDay(date);

        if (choice == 1) {
            dateEnd.month = date.month + 6;
            if (dateEnd.month > 12) {
                dateEnd.month = dateEnd.month - 12;
                dateEnd.year = date.year + 1;
            }
            else {
                dateEnd.year = date.year;
            }
            BankBooks.setRate(0.06);

        }
        else {
            dateEnd.month = date.month;
            dateEnd.year = date.year;
            BankBooks.setRate(0.066);
        }
        BankBooks.setDeadline(dateEnd);
        BankBooks.getProfit(dateEnd);

        familyBankBooks.push_back(BankBooks);
        cout << "Gui tiet kiem thanh cong\n";
        system("pause");
    }
    void option5(vector<BankBook> familyBankBooks) {
        system("cls");
        for (int i = 0; i < familyBankBooks.size(); i++)
        {
            cout << "=== So tiet kiem thu " << i + 1 << " ===\n";
            cout << "So tien gui: " << familyBankBooks[i].getMoneySaving() << endl;
            cout << "Lai suat: " << familyBankBooks[i].getRate() * 100 << "%/thang" << endl;
            cout << "Ngay gui: ";
            familyBankBooks[i].getStartDay().output();
            cout << "\nNgay den han: ";
            familyBankBooks[i].getDeadline().output();
            cout << "\nSo tien lai khi den han: " << familyBankBooks[i].getMoneySaving() * familyBankBooks[i].getRate() << endl << endl;
        }
        system("pause");
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
        cout << "Thang " << date << ":\n";
        if (q == 1)
            cout << familyIncomes[date - Date(5, 2022)];
        else
        if (q == 2)
            cout << familyPayments[date - Date(5, 2022)];
        else
        if (q == 3) {
            cout << familyLoan;
            cout << "Tien lai thang " << date << ":\n";
            cout << "1 nam ruoi: " << familyLoan.getRate1() * (double) familyLoan.getShortLoan() << " (VND)\n";
            cout << "3 nam: " << familyLoan.getRate2() * (double) familyLoan.getLongLoan() << " (VND)\n";
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
        cout << "Thang " << date << ":\n";
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
    void option4(Income familyIncomes[], vector<BankBook>& familyBankBooks) {
        system("cls");
        BankBook BankBooks;
        cout << "Nhap thoi diem muon gui tiet kiem\n";
        Date date;
        Date dateEnd;
        date = date.input();
        cout << "Chon loai gui\n";
        cout << "1. 6 thang (6%/thang)\n";
        cout << "2. 12 thang(6.6%/thang)\n";
        int choice = 0;
        cout << "Nhap yeu cau (1->2): ";
        cin >> choice;
        while (choice > 2 || choice < 1) {
            cout << "Moi nhap lai yeu cau (1->2): ";
            cin >> choice;
        }

        long long sum = familyIncomes[date - Date(5, 2022)].sumSalary();
        BankBooks.addMoney(sum);
        BankBooks.setStartDay(date);

        if (choice == 1) {
            dateEnd.month = date.month + 6;
            if (dateEnd.month > 12) {
                dateEnd.month = dateEnd.month - 12;
                dateEnd.year = date.year + 1;
            }
            else {
                dateEnd.year = date.year;
            }
            BankBooks.setRate(0.06);

        }
        else {
            dateEnd.month = date.month;
            dateEnd.year = date.year;
            BankBooks.setRate(0.066);
        }
        BankBooks.setDeadline(dateEnd);
        BankBooks.getProfit(dateEnd);

        familyBankBooks.push_back(BankBooks);
        cout << "Gui tiet kiem thanh cong\n";
        system("pause");
    }
    void option5(vector<BankBook> familyBankBooks) {
        system("cls");
        for (int i = 0; i < familyBankBooks.size(); i++)
        {
            cout << "=== So tiet kiem thu " << i + 1 << " ===\n";
            cout << "So tien gui: " << familyBankBooks[i].getMoneySaving() << endl;
            cout << "Lai suat: " << familyBankBooks[i].getRate() * 100 << "%/thang" << endl;
            cout << "Ngay gui: ";
            familyBankBooks[i].getStartDay().output();
            cout << "\nNgay den han: ";
            familyBankBooks[i].getDeadline().output();
            cout << "\nSo tien lai khi den han: " << familyBankBooks[i].getMoneySaving() * familyBankBooks[i].getRate() << endl << endl;
        }
        system("pause");
    }
    void exportExcel() {

    }
};

int main(){
    Menu menu;
    menu.run();
}