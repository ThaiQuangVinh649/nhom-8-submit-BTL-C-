#include <iostream>
#include <string>
#include <vector>
#include <limits> 
#include <numeric>


class ThuNhapNgay {
protected:
    std::string ngay;
    double tongThuNhap;
    double tienMat;
    double tienATM; 

public:
    
    ThuNhapNgay(const std::string& n, double tm, double atm)
        : ngay(n), tienMat(tm), tienATM(atm) {
        tongThuNhap = tm + atm; 
    }

   
    virtual ~ThuNhapNgay() {
    
    }

    std::string getNgay() { return ngay; }
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
        std::cout << "Ngay: " << ngay
                  << ", Tong thu nhap: " << tongThuNhap << " VND"
                  << " (Tien mat: " << tienMat << " VND, Tien ATM: " << tienATM << " VND)" << std::endl;
    }

   
    ThuNhapNgay operator+(const ThuNhapNgay& other) const {
      
        return ThuNhapNgay(this->ngay, this->tienMat + other.tienMat, this->tienATM + other.tienATM);
    }
};


std::ostream& operator<<(std::ostream& os, ThuNhapNgay& obj) {
    obj.hienThiThongTin();
    return os;
}

int main() {
    
    std::vector<ThuNhapNgay*> danhSachThuNhap; 
    int choice;

    do {
        std::cout << "\n--- QUAN LY THU NHAP HANG NGAY CUA QUAN ---" << std::endl;
        std::cout << "1. Them thu nhap theo ngay (chi dinh tien mat & ATM)" << std::endl;
        std::cout << "2. Xem danh sach thu nhap theo ngay" << std::endl;
        std::cout << "3. Thay doi thong tin thu nhap theo ngay" << std::endl;
        std::cout << "4. Xem chi tiet thu nhap theo ngay" << std::endl;
        std::cout << "5. Tinh tong thu nhap tu hai ngay (qua tai toan tu +)" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string n;
                double tm, atm;
                std::cout << "Nhap ngay (YYYY-MM-DD): ";
                std::getline(std::cin, n);
                std::cout << "Nhap so tien mat: ";
                std::cin >> tm;
                std::cout << "Nhap so tien ATM: ";
                std::cin >> atm;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                
                danhSachThuNhap.push_back(new ThuNhapNgay(n, tm, atm));
                std::cout << "Thu nhap cho ngay " << n << " da duoc them." << std::endl;
                break;
            }
            case 2: {
                std::cout << "\n--- DANH SACH THU NHAP HANG NGAY ---" << std::endl;
                if (danhSachThuNhap.empty()) {
                    std::cout << "Khong co thong tin thu nhap nao." << std::endl;
                } else {
                    for (ThuNhapNgay* tn : danhSachThuNhap) {
                        
                        std::cout << *tn; 
                    }
                }
                break;
            }
            case 3: {
                std::string ngayCapNhat;
                std::cout << "Nhap ngay can thay doi thong tin (YYYY-MM-DD): ";
                std::getline(std::cin, ngayCapNhat);
                ThuNhapNgay* thuNhapCanCapNhat = nullptr;
                for (ThuNhapNgay* tn : danhSachThuNhap) {
                    if (tn->getNgay() == ngayCapNhat) {
                        thuNhapCanCapNhat = tn;
                        break;
                    }
                }
                if (thuNhapCanCapNhat) {
                    double thuNhapMoiTM, thuNhapMoiATM;
                    std::cout << "Nhap so tien mat moi (nhap -1 neu khong thay doi): ";
                    std::cin >> thuNhapMoiTM;
                    std::cout << "Nhap so tien ATM moi (nhap -1 neu khong thay doi): ";
                    std::cin >> thuNhapMoiATM;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (thuNhapMoiTM != -1) {
                        thuNhapCanCapNhat->setTienMat(thuNhapMoiTM);
                    }
                    if (thuNhapMoiATM != -1) {
                        thuNhapCanCapNhat->setTienATM(thuNhapMoiATM);
                    }
                    std::cout << "Thong tin thu nhap cho ngay " << ngayCapNhat << " da duoc cap nhat." << std::endl;
                } else {
                    std::cout << "Khong tim thay thong tin thu nhap cho ngay: " << ngayCapNhat << std::endl;
                }
                break;
            }
            case 4: {
                std::string ngayXemThuNhap;
                std::cout << "Nhap ngay can xem chi tiet thu nhap (YYYY-MM-DD): ";
                std::getline(std::cin, ngayXemThuNhap);
                ThuNhapNgay* thuNhapCanXem = nullptr;
                for (ThuNhapNgay* tn : danhSachThuNhap) {
                    if (tn->getNgay() == ngayXemThuNhap) {
                        thuNhapCanXem = tn;
                        break;
                    }
                }
                if (thuNhapCanXem) {
                    std::cout << "\n--- CHI TIET THU NHAP NGAY " << ngayXemThuNhap << " ---" << std::endl;
                   
                    thuNhapCanXem->hienThiThongTin();
                } else {
                    std::cout << "Khong tim thay thong tin thu nhap cho ngay: " << ngayXemThuNhap << std::endl;
                }
                break;
            }
            case 5: {
                std::string ngay1, ngay2;
                std::cout << "Nhap ngay thu nhat (YYYY-MM-DD): ";
                std::getline(std::cin, ngay1);
                std::cout << "Nhap ngay thu hai (YYYY-MM-DD): ";
                std::getline(std::cin, ngay2);

                ThuNhapNgay* tn1 = nullptr;
                ThuNhapNgay* tn2 = nullptr;

                for (ThuNhapNgay* tn : danhSachThuNhap) {
                    if (tn->getNgay() == ngay1) {
                        tn1 = tn;
                    }
                    if (tn->getNgay() == ngay2) {
                        tn2 = tn;
                    }
                }

                if (tn1 && tn2) {
                   
                    ThuNhapNgay tongThuNhapHaiNgay = *tn1 + *tn2;
                    std::cout << "\n--- TONG THU NHAP HAI NGAY ---" << std::endl;
                    std::cout << "Tong thu nhap tu ngay " << ngay1 << " (" << tn1->getTongThuNhap()
                              << " VND) va ngay " << ngay2 << " (" << tn2->getTongThuNhap()
                              << " VND) la: " << tongThuNhapHaiNgay.getTongThuNhap() << " VND" << std::endl;
                    std::cout << "Tong tien mat: " << tongThuNhapHaiNgay.getTienMat() << " VND" << std::endl;
                    std::cout << "Tong tien ATM: " << tongThuNhapHaiNgay.getTienATM() << " VND" << std::endl;
                } else {
                    std::cout << "Khong tim thay thong tin thu nhap cho mot hoac ca hai ngay da nhap." << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Ket thuc chuong trinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);

    
    for (ThuNhapNgay* tn : danhSachThuNhap) {
        delete tn; 
    }
    danhSachThuNhap.clear(); 

    return 0;
}
