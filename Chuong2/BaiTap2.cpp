#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CauhoiTN {
private:
    string noiDungCauHoi;
    string dapAnA;
    string dapAnB;
    char dapAnDung;

public:
    void nhap() {
        cout << "Nhap noi dung cau hoi: ";
        getline(cin, noiDungCauHoi);
        cout << "Nhap noi dung dap an A: ";
        getline(cin, dapAnA);
        cout << "Nhap noi dung dap an B: ";
        getline(cin, dapAnB);
        cout << "Nhap dap an dung (A/B): ";
        cin >> dapAnDung;
        cin.ignore(); // Doc ky tu thua '\n' sau khi nhap dapAnDung
    }

    void docfile(ifstream& f) {
        getline(f, noiDungCauHoi);
        getline(f, dapAnA);
        getline(f, dapAnB);
        f >> dapAnDung;
        f.ignore(); // Doc ky tu '\n' thua sau khi doc dapAnDung
    }

    void ghifile(ofstream& f) {
        f << noiDungCauHoi << endl;
        f << dapAnA << endl;
        f << dapAnB << endl;
        f << dapAnDung << endl;
    }

    void kiemtra() {
        cout << "Cau hoi: " << noiDungCauHoi << endl;
        char luaChon;
        cout << "Chon dap an (A/B): ";
        cin >> luaChon;
        if (luaChon == dapAnDung) {
            cout << "Dap an dung!" << endl;
        }
        else {
            cout << "Dap an sai!" << endl;
        }
    }

    void xuat() {
        cout << "Cau hoi: " << noiDungCauHoi << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;
        cout << "Dap an dung: " << dapAnDung << endl;
    }

    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    return (cau1.noiDungCauHoi == cau2.noiDungCauHoi) &&
        (cau1.dapAnA == cau2.dapAnA) &&
        (cau1.dapAnB == cau2.dapAnB) &&
        (cau1.dapAnDung == cau2.dapAnDung);
}

int main() {
    // Thuc don
    int luaChon;
    do {
        cout << "======= MENU =======" << endl;
        cout << "1. Tao de thi" << endl;
        cout << "2. Doc file TTN" << endl;
        cout << "3. Xoa khoang trang thua" << endl;
        cout << "4. Kiem tra hai cau hoi co giong nhau khong" << endl;
        cout << "5. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore(); // Doc ky tu '\n' thua sau khi nhap luaChon

        switch (luaChon) {
        case 1: {
            // Tao de thi trac nghiem
            int soLuongCauHoi;
            cout << "Nhap so luong cau hoi: ";
            cin >> soLuongCauHoi;
            cin.ignore(); // Doc ky tu '\n' thua sau khi nhap soLuongCauHoi

            ofstream outFile("de_thi.TTN");
            if (outFile.is_open()) {
                for (int i = 0; i < soLuongCauHoi; ++i) {
                    CauhoiTN cauHoi;
                    cauHoi.nhap();
                    cauHoi.ghifile(outFile);
                }
                outFile.close();
                cout << "Da tao de thi thanh cong!" << endl;
            }
            else {
                cout << "Khong the tao file de thi!" << endl;
            }
            break;
        }
        case 2: {
            // Doc noi dung file TTN
            ifstream inFile("de_thi.TTN");
            if (inFile.is_open()) {
                CauhoiTN cauHoi;
                while (!inFile.eof()) {
                    cauHoi.docfile(inFile);
                    cauHoi.xuat();
                }
                inFile.close();
            }
            else {
                cout << "Khong the mo file de thi!" << endl;
            }
            break;
        }
        case 3: {
            // Xoa khoang trang thua
            // Code xoa khoang trang thua o day
            break;
        }
        case 4: {
            // Kiem tra hai cau hoi co giong nhau khong
            CauhoiTN cau1, cau2;
            cout << "Nhap cau hoi 1: " << endl;
            cau1.nhap();
            cout << "Nhap cau hoi 2: " << endl;
            cau2.nhap();

            if (giongnhau(cau1, cau2)) {
                cout << "Hai cau hoi giong nhau!" << endl;
            }
            else {
                cout << "Hai cau hoi khong giong nhau!" << endl;
            }
            break;
        }
        case 5:
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (luaChon != 5);

    return 0;
}
