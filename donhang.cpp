#include <iostream>
#include <string>
#include <vector>
#include <limits> // C?n cho std::numeric_limits
#include <iomanip> // C?n cho std::fixed và std::setprecision

class DonHang {
protected:
    std::string maDH;
    std::string tenKH;
    double tongTien;

public:
    DonHang() : maDH(""), tenKH(""), tongTien(0.0) {}
    DonHang(const std::string& ma, const std::string& ten, double tien) : maDH(ma), tenKH(ten), tongTien(tien) {}
    virtual ~DonHang() {}

    std::string getMaDH() const { return maDH; }
    std::string getTenKH() const { return tenKH; }
    double getTongTien() const { return tongTien; }

    void setTenKH(const std::string& ten) { tenKH = ten; }
    void setTongTien(double tien) { tongTien = tien; }

    virtual void hienThiThongTin() const {
        std::cout << "Ma DH: " << maDH << ", Ten KH: " << tenKH << ", Tong tien: "
                  << std::fixed << std::setprecision(2) << tongTien << std::endl;
    }

    void capNhatTongTien(double soTienThayDoi) {
        tongTien += soTienThayDoi;
    }

    bool operator==(const DonHang& other) const {
        return maDH == other.maDH;
    }
};

int main() {
    std::vector<DonHang*> danhSachDonHang;
    int choice;

    do {
        std::cout << "\n--- QUAN LY DON HANG ---" << std::endl;
        std::cout << "1. Them don hang" << std::endl;
        std::cout << "2. Xem danh sach don hang" << std::endl;
        std::cout << "3. Cap nhat tong tien don hang" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

        // Clear buffer sau khi nh?p s?
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string ma, ten;
                double tien;
                std::cout << "Nhap ma don hang: ";
                std::getline(std::cin, ma);
                std::cout << "Nhap ten khach hang: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap tong tien don hang: ";
                std::cin >> tien;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                danhSachDonHang.push_back(new DonHang(ma, ten, tien));
                std::cout << "Don hang da duoc them." << std::endl;
                break;
            }
            case 2: {
                std::cout << "\n--- DANH SACH DON HANG ---" << std::endl;
                if (danhSachDonHang.empty()) {
                    std::cout << "Khong co don hang nao." << std::endl;
                } else {
                    for (const DonHang* dh : danhSachDonHang) {
                        dh->hienThiThongTin();
                    }
                }
                break;
            }
            case 3: {
                std::string maDHThayDoi;
                double soTienThayDoi;
                std::cout << "Nhap ma don hang can cap nhat tong tien: ";
                std::getline(std::cin, maDHThayDoi);
                DonHang* donHangCanThayDoi = nullptr;
                for (DonHang* dh : danhSachDonHang) {
                    if (dh->getMaDH() == maDHThayDoi) {
                        donHangCanThayDoi = dh;
                        break;
                    }
                }
                if (donHangCanThayDoi) {
                    std::cout << "Nhap so tien thay doi (co the am hoac duong): ";
                    std::cin >> soTienThayDoi;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    donHangCanThayDoi->capNhatTongTien(soTienThayDoi);
                    std::cout << "Tong tien don hang da duoc cap nhat." << std::endl;
                } else {
                    std::cout << "Khong tim thay don hang co ma: " << maDHThayDoi << std::endl;
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

    // Gi?i phóng b? nh?
    for (DonHang* dh : danhSachDonHang) {
        delete dh;
    }
    danhSachDonHang.clear();

    return 0;
}
