#include <iostream>
#include <vector>
#include "Income.h"
#include "Payment.h"
#include "Loan.h"
#include "BankBook.h"
#include "Date.h"
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>
using namespace std;
class Menu {
private:
    string choose;
    bool  isSaved;
    int monthShortLoan, yearShortLoan;
    int monthLongLoan, yearLongLoan;
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
            cout << "5. Tra cuu so tiet kiem ngan hang.\n";
            cout << "6. Xuat file excel.\n";
            cout << "7. Lay du lieu da nhap lan truoc.\n";
            cout << "8. So tiet kiem gia dinh.\n";
            cout << "9. Ket thuc chuong trinh.\n";
            cout << "Nhap yeu cau (0->9): "; cin >> choose;
            while ((choose.size() > 1) || (choose[0] - '0' < 0 && choose[0] - '0' > 9)) {
                cout << "Moi nhap lai yeu cau (0->9): ";
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
                option4(familyIncomes, familyPayments, familyBankBooks);
                break;
            case 5:
                option5(familyBankBooks);
                break;
            case 6:
                exportExcel(familyIncomes, familyPayments, familyLoan, familyBankBooks);
                break;
            case 7:
                readExcel(familyIncomes, familyPayments, familyLoan, familyBankBooks);
                break;
            case 8:
                option8(familyBankBooks, familyIncomes, familyPayments);
                break;
            default:
                isRunning = false;
                break;
            }
        }
    }

    void option0(Income familyIncomes[], Payment familyPayments[], Loan familyLoan, vector<BankBook> familyBankBooks) {
        system("cls");
        int dayPay = 0;
        // Short Loan
        Date date;
        date.month = 12;
        date.year = 2023;
        bool check = true; // lay ngay tra truoc thoi han
        long long sumBeforeShortLoan = 0;
        long long sumShortLoan = familyLoan.getShortLoan() * (1 + familyLoan.getRate1() * 18);
        for (int i = 0; i <= date - Date(5, 2022); i++)
        {
            long long sumBooks = 0;
            for (int j = 0; j < familyBankBooks.size(); j++) {
                if (familyBankBooks[j].getDeadline() - date < 0) // truoc thoi han 12/2023 
                {
                    sumBooks += familyBankBooks[j].getRate() * familyBankBooks[j].getMoneySaving();
                    familyBankBooks.erase(familyBankBooks.begin() + j);
                    break;
                }
            }

            sumBeforeShortLoan += familyIncomes[i].sumIncome() - familyPayments[i].sumPayment() + sumBooks;
            if (sumBeforeShortLoan - sumShortLoan >= 0 && check) {
                dayPay = i + 1;
                check = false;
            }
        }

        if (dayPay < 18 && dayPay != 0) {
            Date d(5, 2022);
            d.month += dayPay % 12;
            d.year += dayPay / 12;
            if (d.month > 12) {
                d.month -= 12;
                d.year++;
            }
            monthShortLoan = d.month;
            yearShortLoan = d.year;
            cout << "-Co kha nang tra no 1 nam ruoi\n";
            cout << "Thoi gian tra: " << d.month << "/" << d.year << endl;
        }
        else {
            if (sumBeforeShortLoan - sumShortLoan >= 0) {
                cout << "-Co kha nang tra no 1 nam ruoi\n";
                cout << "Thoi gian tra: 12/2023\n";
            }
            else {
                cout << "-Khong co kha nang tra no 1 nam ruoi\n";
            }
        }

        // Long Loan
        Date dateLongLoan;
        dateLongLoan.month = 5;
        dateLongLoan.year = 2025;
        long long sumLongLoan = familyLoan.getLongLoan() * (1 + familyLoan.getRate2());
        long long sumAfterShortLoan = sumBeforeShortLoan - sumShortLoan;
        check = true;
        for (int i = 18; i <= dateLongLoan - Date(12, 2025); i++) {
            long long sumBooks = 0;
            for (int j = 0; j < familyBankBooks.size(); j++) {
                if (familyBankBooks[j].getDeadline() - dateLongLoan < 0) // truoc thoi han 5/2025 
                {
                    sumBooks += familyBankBooks[j].getRate() * familyBankBooks[j].getMoneySaving();
                    familyBankBooks.erase(familyBankBooks.begin() + j);
                    break;
                }
            }
            sumAfterShortLoan += familyIncomes[i].sumIncome() - familyPayments[i].sumPayment() + sumBooks;
            if (sumLongLoan - sumAfterShortLoan >= 0 && check) {
                dayPay = i - 17;
                check = false;
            }
        }

        if (dayPay < 18 && dayPay != 0) {
            Date d(12, 2023);
            d.month += dayPay % 12;
            d.year += dayPay / 12;
            if (d.month > 12) {
                d.month -= 12;
                d.year++;
            }
            monthLongLoan = d.month;
            yearLongLoan = d.year;
            cout << "-Co kha nang tra no 3 nam\n";
            cout << "Thoi gian tra: " << d.month << "/" << d.year << endl;
        }
        else {
            long long books = 0;
            for (int i = 0; i < familyBankBooks.size(); i++) { // rut het so
                books += familyBankBooks[i].getRate() * familyBankBooks[i].getMoneySaving();
                familyBankBooks.erase(familyBankBooks.begin() + i);
            }
            sumAfterShortLoan += books;
            if (sumLongLoan - sumAfterShortLoan >= 0)
            {
                cout << "-Co kha nang tra no 3 nam\n";
                cout << "Thoi gian tra: 5/2025\n";
            }
            else
                cout << "-Khong co kha nang tra no 3 nam\n";
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
        cout << "\nThang " << date << ":\n";
        if (q == 1)
            cout << familyIncomes[date - Date(5, 2022)];
        else
            if (q == 2)
                cout << familyPayments[date - Date(5, 2022)];
            else
                if (q == 3) {
                    cout << familyLoan;
                    cout << "\nTien lai thang " << date << ":\n";
                    cout << "- 1 nam ruoi: " << familyLoan.getRate1() * (double)familyLoan.getShortLoan() << " (VND)\n";
                    cout << "- 3 nam: " << familyLoan.getRate2() * (double)familyLoan.getLongLoan() << " (VND)\n";
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
        cout << "\nThang " << date << ":\n";
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
                    else
                        if (found + familyIncomes[date - Date(5, 2022)].getHusbandSalary() + familyIncomes[date - Date(5, 2022)].getWifeSalary() >= 0) {
                            cout << "Dung " << familyIncomes[date - Date(5, 2022)].getHusbandSalary() << " luong chong + "
                                << -(found + familyIncomes[date - Date(5, 2022)].getHusbandSalary()) << " luong vo\nbu qua thu nhap khac.\n";
                            familyIncomes[date - Date(5, 2022)].setOtherIncome(familyIncomes[date - Date(5, 2022)].getOtherIncome() - found);
                            familyIncomes[date - Date(5, 2022)].setWifeSalary(familyIncomes[date - Date(5, 2022)].getWifeSalary() + familyIncomes[date - Date(5, 2022)].getHusbandSalary() + found);
                            familyIncomes[date - Date(5, 2022)].setHusbandSalary(0);
                        }
                        else
                            if (found + familyIncomes[date - Date(5, 2022)].getHusbandSalary() + familyIncomes[date - Date(5, 2022)].getWifeSalary() < 0) {
                                cout << "Dung " << familyIncomes[date - Date(5, 2022)].getHusbandSalary() << " luong chong + "
                                    << familyIncomes[date - Date(5, 2022)].getWifeSalary() << " luong vo\nbu qua thu nhap khac.\n";
                                familyIncomes[date - Date(5, 2022)].setOtherIncome(familyIncomes[date - Date(5, 2022)].getWifeSalary() + familyIncomes[date - Date(5, 2022)].getWifeSalary());
                                familyIncomes[date - Date(5, 2022)].setWifeSalary(0);
                                familyIncomes[date - Date(5, 2022)].setHusbandSalary(0);
                            }
                }
        }
        system("pause");
    }

    void option4(Income familyIncomes[], Payment familyPayments[], vector <BankBook>& familyBankBooks) {
        system("cls");
        cout << "----Gui tien tiet kiem\n";
        Date date;
        date = date.input();
        cout << "\nLoai ki han:\n1. 6 thang (6%/thang)\n2. 1 nam (6.6%/thang)\n3. Khong gui\n";
        cout << "Nhap lua chon: "; int q;
        cin >> q;
        if (q == 1) {
            familyBankBooks.push_back({
                familyIncomes[date - Date(5, 2022)].getHusbandSalary() + familyIncomes[date - Date(5, 2022)].getWifeSalary(),
                date,
                date + 6,
                0.06
                });
            familyIncomes[date - Date(5, 2022)].setHusbandSalary(0);
            familyIncomes[date - Date(5, 2022)].setWifeSalary(0);
            cout << "Gui thanh cong\n";
        }
        else if (q == 2) {
            familyBankBooks.push_back({
                familyIncomes[date - Date(5, 2022)].getHusbandSalary() + familyIncomes[date - Date(5, 2022)].getWifeSalary(),
                date,
                date + 12,
                0.066
                });
            familyIncomes[date - Date(5, 2022)].setHusbandSalary(0);
            familyIncomes[date - Date(5, 2022)].setWifeSalary(0);
            cout << "Gui thanh cong\n";
        }
        else if (q > 3) {
            cout << "Gui khong thanh cong\n";
        }
        system("pause");
    }

    void option5(vector <BankBook> familyBankBooks) {
        system("cls");
        cout << "----Tra cuu so tiet kiem\n";
        int stt = 0;
        for (auto book : familyBankBooks) {
            stt++;
            cout << "So tiet kiem " << stt << ":\n";
            cout << "- So tien: " << book.getMoneySaving() << ", " << "lai suat: " << book.getRate() << '\n';
            cout << "- Ngay gui: " << book.getStartDay().month << '/' << book.getStartDay().year << '\n';
            cout << "- Ngay het han: " << book.getDeadline().month << '/' << book.getDeadline().year << '\n';
        }
        system("pause");
    }
    void exportExcel(Income familyIncomes[], Payment familyPayments[], Loan familyLoan, vector <BankBook> familyBankBooks) {
        cout << "----Xuat file excel.\n";
        cout << "Nhap ten file (.csv): ";
        string fileName; cin >> fileName;
        ofstream file;
        file.open(fileName + ".csv");
        file << "Quan ly thu chi\n";
        file << "So tien no\n";
        file << ",Tien no 1 nam ruoi:," << familyLoan.getShortLoan() << ",Lai suat (%/thang):," << familyLoan.getRate1() * 100 << '\n';
        file << ",Ngay tra no duoc no:," << monthShortLoan << '/' << yearShortLoan << '\n';
        file << ",Tien no 3 nam:," << familyLoan.getLongLoan() << ",Lai suat (%/nam):," << familyLoan.getRate2() * 100 << '\n';
        file << ",Ngay tra no duoc no:," << monthLongLoan << '/' << yearLongLoan << '\n';

        file << '\n' << familyBankBooks.size() << ",So tiet kiem\n";
        file << "STT,So tien,Lai suat,Ngay gui,Ngay het han\n";
        int stt = 0;
        for (auto book : familyBankBooks) {
            stt++;
            file << stt << ',' << book.getMoneySaving() << ',' << book.getRate() << ','
                << book.getStartDay().month << '/' << book.getStartDay().year << ','
                << book.getDeadline().month << '/' << book.getDeadline().year << '\n';
        }
        file << "\nThong tin thu nhap - chi tieu\n";
        file << "Thang,Luong vo,Luong chong,Thu nhap khac,Tien dien nuoc,Tien an,Chi tieu khac\n";
        for (int i = 0; i < 36; i++)
            file << i + 1 << ',' << familyIncomes[i].getWifeSalary() << ',' << familyIncomes[i].getHusbandSalary() << ',' << familyIncomes[i].getOtherIncome() << ','
            << familyPayments[i].getHousePayment() << ',' << familyPayments[i].getFoodPayment() << ',' << familyPayments[i].getOtherPayment() << ",\n";
        file.close();
        cout << "Da xuat file excel thanh cong\n";
        system("pause");
    }
    void readExcel(Income familyIncomes[], Payment familyPayments[], Loan& familyLoan, vector <BankBook>& familyBankBooks) {
        cout << "----Doc du lieu da nhap trong file excel cu.\n";
        cout << "Nhap ten file (.csv): ";
        string fileName; cin >> fileName;
        ifstream file;
        file.open(fileName + ".csv");
        string line;
        getline(file, line); //row 0
        getline(file, line); //row 1

        getline(file, line); //row 2
        stringstream s(line);
        string element;
        vector <string> row;
        while (getline(s, element, ','))
            row.push_back(element);
        familyLoan.setShortLoan(stoll(row[2]));
        familyLoan.changeRate1(stod(row[4]) / 100);

        getline(file, line); //row 3
        getline(file, line); //row 4
        s = (stringstream)line;
        row.clear();
        while (getline(s, element, ','))
            row.push_back(element);
        familyLoan.setLongLoan(stoll(row[2]));
        familyLoan.changeRate2(stod(row[4]) / 100);

        getline(file, line); //row 5
        getline(file, line); //row 6
        getline(file, line); //row 7
        s = (stringstream)line;
        row.clear();
        while (getline(s, element, ','))
            row.push_back(element);
        int nBankBooks = stoi(row[0]);
        familyBankBooks.clear();
        getline(file, line); //row 8
        for (int i = 0; i < nBankBooks; i++) {
            getline(file, line); //row 9 + i
            s = (stringstream)line;
            row.clear();
            while (getline(s, element, ','))
                row.push_back(element);
            long long moneySaving = stoll(row[1]);
            double rate = stod(row[2]);
            Date startDay;
            startDay.month = stoi(row[3].substr(0, row[3].find('/')));
            startDay.year = stoi(row[3].substr(row[3].find('/') + 1, row[3].size() - row[3].find('/') - 1));
            Date deadline;
            deadline.month = stoi(row[4].substr(0, row[4].find('/')));
            deadline.year = stoi(row[4].substr(row[4].find('/') + 1, row[4].size() - row[4].find('/') - 1));
            familyBankBooks.push_back(BankBook(moneySaving, startDay, deadline, rate));
        }
        getline(file, line); //row 8 + nBankBooks
        getline(file, line); //row 8 + nBankBooks + 1
        getline(file, line); //row 8 + nBankBooks + 2
        for (int i = 0; i < 36; i++) {
            getline(file, line); //row 8 + nBankBooks + 3 + i
            s = (stringstream)line;
            row.clear();
            while (getline(s, element, ','))
                row.push_back(element);
            long long wifeSalary = stoll(row[1]),
                husbandSalary = stoll(row[2]),
                otherIncome = stoll(row[3]),
                housePayment = stoll(row[4]),
                foodPayment = stoll(row[5]),
                otherPayment = stoll(row[6]);
            familyIncomes[i].setWifeSalary(wifeSalary);
            familyIncomes[i].setHusbandSalary(husbandSalary);
            familyIncomes[i].setOtherIncome(otherIncome);
            familyPayments[i].setHousePayment(housePayment);
            familyPayments[i].setFoodPayment(foodPayment);
            familyPayments[i].setOtherPayment(otherPayment);
        }
        system("pause");
    }

    void option8(vector <BankBook>& familyBankBooks, Income familyIncomes[], Payment familyPayments[]) {
        system("cls");
        cout << "Kiem tra ngay dao han so tiet kiem\n";
        cout << "Nhap ngay can tra cuu\n";
        Date d;
        d = d.input();
        
        int stt = 0;
        int num = 0;
        for (auto book : familyBankBooks) {
            if (book.getDeadline() - d <= 0)
            {
                num++;
                cout << "Co so tiet kiem thu " << stt + 1 << " toi han\n";
                cout << "Thong tin so tiet kiem\n";
                cout << "- So tien: " << book.getMoneySaving() << ", " << "lai suat: " << book.getRate() << '\n';
                cout << "- Ngay gui: " << book.getStartDay().month << '/' << book.getStartDay().year << '\n';
                cout << "- Ngay het han: " << book.getDeadline().month << '/' << book.getDeadline().year << '\n';
                cout << "1. Rut\n";
                cout << "2. Khong rut\n";
                int choice = 0;
                while (true) {
                    cin >> choice;
                    if (choice != 1 && choice != 2)
                        cout << "Moi nhap lai yeu cau (1->2): ";
                    else
                        break;
                }
                if (choice == 1)
                {
                    int i = d - Date(5, 2022);
                    familyIncomes[i].setOtherIncome(familyIncomes[i].getOtherIncome() + book.getProfit(d));
                    familyBankBooks.erase(familyBankBooks.begin() + stt);
                    cout << "Rut so thanh cong\n";
                }
                stt++;
            }
            else {
                if (num == 0) {
                    cout << "Khong co so tiet kiem nao toi han\n";
                }
            }
        }
        long long savingMoney = 0;
        for (int i = 0; i <= d - Date(5, 2022); i++) {
            savingMoney += familyIncomes[i].getHusbandSalary() + familyIncomes[i].getWifeSalary() + familyIncomes[i].getOtherIncome();
            savingMoney -= familyPayments[i].sumPayment();
        }
        cout << "So tien tiet kiem trong so tiet kiem gia dinh: " << savingMoney << endl;
        system("pause");
    }
};

int main() {
    Menu menu;
    menu.run();
}