#include <iostream>
#include <string>
#include <vector>
#include <limits> 

class KhachHang {
protected:
    std::string maKH;
    std::string tenKH;
    std::string diaChi;
    std::string sdt;

public:
    KhachHang() : maKH(""), tenKH(""), diaChi(""), sdt("") {}
    KhachHang(const std::string& ma, const std::string& ten, const std::string& dc, const std::string& so)
        : maKH(ma), tenKH(ten), diaChi(dc), sdt(so) {}
    virtual ~KhachHang() {}

    std::string getMaKH() const { return maKH; }
    std::string getTenKH() const { return tenKH; }
    std::string getDiaChi() const { return diaChi; }
    std::string getSDT() const { return sdt; }

    void setTenKH(const std::string& ten) { tenKH = ten; }
    void setDiaChi(const std::string& dc) { diaChi = dc; }
    void setSDT(const std::string& so) { sdt = so; }

    virtual void hienThiThongTin() const {
        std::cout << "Ma KH: " << maKH << ", Ten KH: " << tenKH
                  << ", Dia chi: " << diaChi << ", SDT: " << sdt << std::endl;
    }

    bool operator==(const KhachHang& other) const {
        return maKH == other.maKH;
    }
};

int main() {
    std::vector<KhachHang*> danhSachKhachHang;
    int choice;

    do {
        std::cout << "\n--- QUAN LY KHACH HANG ---" << std::endl;
        std::cout << "1. Them khach hang" << std::endl;
        std::cout << "2. Xem danh sach khach hang" << std::endl;
        std::cout << "3. Cap nhat thong tin khach hang" << std::endl;
        std::cout << "4. Xoa khach hang" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

       
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string ma, ten, dc, so;
                std::cout << "Nhap ma khach hang: ";
                std::getline(std::cin, ma);
                std::cout << "Nhap ten khach hang: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap dia chi khach hang: ";
                std::getline(std::cin, dc);
                std::cout << "Nhap so dien thoai khach hang: ";
                std::getline(std::cin, so);
                danhSachKhachHang.push_back(new KhachHang(ma, ten, dc, so));
                std::cout << "Khach hang da duoc them." << std::endl;
                break;
            }
            case 2: {
                std::cout << "\n--- DANH SACH KHACH HANG ---" << std::endl;
                if (danhSachKhachHang.empty()) {
                    std::cout << "Khong co khach hang nao." << std::endl;
                } else {
                    for (const KhachHang* kh : danhSachKhachHang) {
                        kh->hienThiThongTin();
                    }
                }
                break;
            }
            case 3: {
                std::string maKHCapNhat;
                std::cout << "Nhap ma khach hang can cap nhat thong tin: ";
                std::getline(std::cin, maKHCapNhat);
                KhachHang* khachHangCanCapNhat = nullptr;
                for (KhachHang* kh : danhSachKhachHang) {
                    if (kh->getMaKH() == maKHCapNhat) {
                        khachHangCanCapNhat = kh;
                        break;
                    }
                }
                if (khachHangCanCapNhat) {
                    std::cout << "Nhap ten moi (de trong neu khong thay doi): ";
                    std::string tenMoi;
                    std::getline(std::cin, tenMoi);
                    if (!tenMoi.empty()) {
                        khachHangCanCapNhat->setTenKH(tenMoi);
                    }
                    std::cout << "Nhap dia chi moi (de trong neu khong thay doi): ";
                    std::string diaChiMoi;
                    std::getline(std::cin, diaChiMoi);
                    if (!diaChiMoi.empty()) {
                        khachHangCanCapNhat->setDiaChi(diaChiMoi);
                    }
                    std::cout << "Nhap so dien thoai moi (de trong neu khong thay doi): ";
                    std::string sdtMoi;
                    std::getline(std::cin, sdtMoi);
                    if (!sdtMoi.empty()) {
                        khachHangCanCapNhat->setSDT(sdtMoi);
                    }
                    std::cout << "Thong tin khach hang da duoc cap nhat." << std::endl;
                } else {
                    std::cout << "Khong tim thay khach hang co ma: " << maKHCapNhat << std::endl;
                }
                break;
            }
            case 4: {
                std::string maKHXoa;
                std::cout << "Nhap ma khach hang can xoa: ";
                std::getline(std::cin, maKHXoa);
                auto it = danhSachKhachHang.begin();
                bool found = false;
                while (it != danhSachKhachHang.end()) {
                    if ((*it)->getMaKH() == maKHXoa) {
                        delete *it; 
                        it = danhSachKhachHang.erase(it); 
                        found = true;
                        std::cout << "Khach hang da duoc xoa." << std::endl;
                        break;
                    } else {
                        ++it;
                    }
                }
                if (!found) {
                    std::cout << "Khong tim thay khach hang co ma: " << maKHXoa << std::endl;
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

    
    for (KhachHang* kh : danhSachKhachHang) {
        delete kh;
    }
    danhSachKhachHang.clear();

    return 0;
}
