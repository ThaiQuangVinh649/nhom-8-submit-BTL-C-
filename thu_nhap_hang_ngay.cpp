#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;

class ThuNhapNgay {
protected:
    string ngay;
    double tongThuNhap;
    double tienMat;
    double tienATM;

public:

    ThuNhapNgay(const string& n, double tm, double atm)
        : ngay(n), tienMat(tm), tienATM(atm) {
        tongThuNhap = tm + atm;
    }


    virtual ~ThuNhapNgay() {

    }

    string getNgay() { return ngay; }
    double getTongThuNhap() { return tongThuNhap; }
    double getTienMat() { return tienMat; }
    double getTienATM() { return tienATM; }


    void setTongThuNhap(double tn) { tongThuNhap = tn; }
    void setTienMat(double tm) {
        tienMat = tm;
        tongThuNhap = tienMat + tienATM;
    }
    void setTienATM(double atm) {
        tienATM = atm;
        tongThuNhap = tienMat + tienATM;
    }


    virtual void hienThiThongTin() {
        cout << "Ngay: " << ngay
             << ", Tong thu nhap: " << tongThuNhap << " VND"
             << " (Tien mat: " << tienMat << " VND, Tien ATM: " << tienATM << " VND)" << endl;
    }


    ThuNhapNgay operator+(const ThuNhapNgay& other) const {
        return ThuNhapNgay(this->ngay + " & " + other.ngay, this->tienMat + other.tienMat, this->tienATM + other.tienATM);
    }
};


ostream& operator<<(ostream& os, ThuNhapNgay& obj) {
    obj.hienThiThongTin();
    return os;
}

int main() {

    vector<ThuNhapNgay*> danhSachThuNhap;
    int choice;

    do {
        cout << "\n--- QUAN LY THU NHAP HANG NGAY CUA QUAN ---" << endl;
        cout << "1. Them thu nhap theo ngay (chi dinh tien mat & ATM)" << endl;
        cout << "2. Xem danh sach thu nhap theo ngay" << endl;
        cout << "3. Thay doi thong tin thu nhap theo ngay" << endl;
        cout << "4. Xem chi tiet thu nhap theo ngay" << endl;
        cout << "5. Tinh tong thu nhap tu nhieu ngay (qua tai toan tu +)" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string n;
                double tm, atm;
                cout << "Nhap ngay (YYYY-MM-DD): ";
                getline(cin, n);
                cout << "Nhap so tien mat: ";
                cin >> tm;
                cout << "Nhap so tien ATM: ";
                cin >> atm;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                danhSachThuNhap.push_back(new ThuNhapNgay(n, tm, atm));
                cout << "Thu nhap cho ngay " << n << " da duoc them." << endl;
                break;
            }
            case 2: {
                cout << "\n--- DANH SACH THU NHAP HANG NGAY ---" << endl;
                if (danhSachThuNhap.empty()) {
                    cout << "Khong co thong tin thu nhap nao." << endl;
                } else {
                    for (ThuNhapNgay* TNN : danhSachThuNhap) {
                        cout << *TNN;
                    }
                }
                break;
            }
            case 3: {
                string ngayCapNhat;
                cout << "Nhap ngay can thay doi thong tin (YYYY-MM-DD): ";
                getline(cin, ngayCapNhat);
                ThuNhapNgay* thuNhapCanCapNhat = nullptr;
                for (ThuNhapNgay* tnn : danhSachThuNhap) {
                    if (tnn->getNgay() == ngayCapNhat) {
                        thuNhapCanCapNhat = tnn;
                        break;
                    }
                }
                if (thuNhapCanCapNhat) {
                    double thuNhapMoiTM, thuNhapMoiATM;
                    cout << "Nhap so tien mat moi (nhap -1 neu khong thay doi): ";
                    cin >> thuNhapMoiTM;
                    cout << "Nhap so tien ATM moi (nhap -1 neu khong thay doi): ";
                    cin >> thuNhapMoiATM;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (thuNhapMoiTM != -1) {
                        thuNhapCanCapNhat->setTienMat(thuNhapMoiTM);
                    }
                    if (thuNhapMoiATM != -1) {
                        thuNhapCanCapNhat->setTienATM(thuNhapMoiATM);
                    }
                    cout << "Thong tin thu nhap cho ngay " << ngayCapNhat << " da duoc cap nhat." << endl;
                } else {
                    cout << "Khong tim thay thong tin thu nhap cho ngay: " << ngayCapNhat << endl;
                }
                break;
            }
            case 4: {
                string ngayXemThuNhap;
                cout << "Nhap ngay can xem chi tiet thu nhap (YYYY-MM-DD): ";
                getline(cin, ngayXemThuNhap);
                ThuNhapNgay* thuNhapCanXem = nullptr;
                for (ThuNhapNgay* tnn : danhSachThuNhap) {
                    if (tnn->getNgay() == ngayXemThuNhap) {
                        thuNhapCanXem = tnn;
                        break;
                    }
                }
                if (thuNhapCanXem) {
                    cout << "\n--- CHI TIET THU NHAP NGAY " << ngayXemThuNhap << " ---" << endl;
                    thuNhapCanXem->hienThiThongTin();
                } else {
                    cout << "Khong tim thay thong tin thu nhap cho ngay: " << ngayXemThuNhap << endl;
                }
                break;
            }
            case 5: {
                vector<string> ngayCanTongHop;
                string inputNgay;
                cout << "Nhap cac ngay can tong hop thu nhap (nhap 'ketthuc' de dung):\n";
                while (true) {
                    cout << "Ngay (YYYY-MM-DD): ";
                    getline(cin, inputNgay);
                    if (inputNgay == "ketthuc") {
                        break;
                    }
                    ngayCanTongHop.push_back(inputNgay);
                }

                if (ngayCanTongHop.empty()) {
                    cout << "Khong co ngay nao duoc nhap de tong hop." << endl;
                    break;
                }

                ThuNhapNgay tongHopThuNhap("", 0, 0);
                bool coDuLieu = false;

                cout << "\n--- TONG THU NHAP NHIEU NGAY ---" << endl;
                for (const string& ngayHienTai : ngayCanTongHop) {
                    ThuNhapNgay* tnHienTai = nullptr;
                    for (ThuNhapNgay* tn : danhSachThuNhap) {
                        if (tn->getNgay() == ngayHienTai) {
                            tnHienTai = tn;
                            break;
                        }
                    }

                    if (tnHienTai) {
                        tongHopThuNhap = tongHopThuNhap + *tnHienTai;
                        coDuLieu = true;
                    } else {
                        cout << "Luu y: Khong tim thay thong tin thu nhap cho ngay " << ngayHienTai << endl;
                    }
                }

                if (coDuLieu) {
                    cout << "Tong thu nhap tu cac ngay da chon la: " << tongHopThuNhap.getTongThuNhap() << " VND" << endl;
                    cout << "Tong tien mat: " << tongHopThuNhap.getTienMat() << " VND" << endl;
                    cout << "Tong tien ATM: " << tongHopThuNhap.getTienATM() << " VND" << endl;
                } else {
                    cout << "Khong co du lieu thu nhap de tong hop tu cac ngay da chon." << endl;
                }
                break;
            }
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
    } while (choice != 0);


    for (ThuNhapNgay* tn : danhSachThuNhap) {
        delete tn;
    }
    danhSachThuNhap.clear();

    return 0;
}
