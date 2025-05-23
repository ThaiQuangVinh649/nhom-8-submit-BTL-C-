#include <iostream>
#include <string>
#include <vector>
#include <limits> 

class SanPham {
protected:
    std::string maSP;
    std::string tenSP;
    double gia;

public:
    SanPham() : maSP(""), tenSP(""), gia(0.0) {}
    SanPham(const std::string& ma, const std::string& ten, double g) : maSP(ma), tenSP(ten), gia(g) {}
    virtual ~SanPham() {}

    std::string getMaSP() const { return maSP; }
    std::string getTenSP() const { return tenSP; }
    double getGia() const { return gia; }

    void setTenSP(const std::string& ten) { tenSP = ten; }
    void setGia(double g) { gia = g; }

    virtual void hienThiThongTin() const {
        std::cout << "Ma SP: " << maSP << ", Ten SP: " << tenSP << ", Gia: " << gia << std::endl;
    }

    void thayDoiGia(double phanTramThayDoi) {
        gia *= (1 + phanTramThayDoi / 100.0);
    }

    bool operator==(const SanPham& other) const {
        return maSP == other.maSP;
    }
};

int main() {
    std::vector<SanPham*> danhSachSanPham;
    int choice;

    do {
        std::cout << "\n--- QUAN LY SAN PHAM ---" << std::endl;
        std::cout << "1. Them san pham" << std::endl;
        std::cout << "2. Xem danh sach san pham" << std::endl;
        std::cout << "3. Thay doi gia san pham" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string ma, ten;
                double gia;
                std::cout << "Nhap ma san pham: ";
                std::getline(std::cin, ma);
                std::cout << "Nhap ten san pham: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap gia san pham: ";
                std::cin >> gia;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                danhSachSanPham.push_back(new SanPham(ma, ten, gia));
                std::cout << "San pham da duoc them." << std::endl;
                break;
            }
            case 2: {
                std::cout << "\n--- DANH SACH SAN PHAM ---" << std::endl;
                if (danhSachSanPham.empty()) {
                    std::cout << "Khong co san pham nao." << std::endl;
                } else {
                    for (const SanPham* sp : danhSachSanPham) {
                        sp->hienThiThongTin();
                    }
                }
                break;
            }
            case 3: {
                std::string maSPThayDoi;
                double phanTramThayDoi;
                std::cout << "Nhap ma san pham can thay doi gia: ";
                std::getline(std::cin, maSPThayDoi);
                SanPham* sanPhamCanThayDoi = nullptr;
                for (SanPham* sp : danhSachSanPham) {
                    if (sp->getMaSP() == maSPThayDoi) {
                        sanPhamCanThayDoi = sp;
                        break;
                    }
                }
                if (sanPhamCanThayDoi) {
                    std::cout << "Nhap phan tram thay doi gia (vi du: 10 cho tang 10%, -5 cho giam 5%): ";
                    std::cin >> phanTramThayDoi;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    sanPhamCanThayDoi->thayDoiGia(phanTramThayDoi);
                    std::cout << "Gia san pham da duoc thay doi." << std::endl;
                } else {
                    std::cout << "Khong tim thay san pham co ma: " << maSPThayDoi << std::endl;
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

    for (SanPham* sp : danhSachSanPham) {
        delete sp;
    }
    danhSachSanPham.clear();

    return 0;
}
