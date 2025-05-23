#include <iostream>
#include <string>
#include <vector>
#include <limits>

class NhanVien {
protected:
    std::string maNV;
    std::string tenNV;
    std::string phongBan;
    double luong;

public:
    NhanVien() : maNV(""), tenNV(""), phongBan(""), luong(0.0) {}
    NhanVien(const std::string& ma, const std::string& ten, const std::string& pb, double l)
        : maNV(ma), tenNV(ten), phongBan(pb), luong(l) {}
    virtual ~NhanVien() {}

    std::string getMaNV() const { return maNV; }
    std::string getTenNV() const { return tenNV; }
    std::string getPhongBan() const { return phongBan; }
    double getLuong() const { return luong; }

    void setTenNV(const std::string& ten) { tenNV = ten; }
    void setPhongBan(const std::string& pb) { phongBan = pb; }
    void setLuong(double l) { luong = l; }

    virtual void hienThiThongTin() const {
        std::cout << "Ma NV: " << maNV << ", Ten NV: " << tenNV
                  << ", Phong ban: " << phongBan << ", Luong: " << luong << std::endl;
    }

    void tangLuong(double phanTramTang) {
        luong *= (1 + phanTramTang / 100.0);
    }

    bool operator==(const NhanVien& other) const {
        return maNV == other.maNV;
    }
};

bool maNVDaTonTai(const std::vector<NhanVien*>& ds, const std::string& ma) {
    for (const NhanVien* nv : ds) {
        if (nv->getMaNV() == ma) return true;
    }
    return false;
}

int main() {
    std::vector<NhanVien*> danhSachNhanVien;
    int choice;

    do {
        std::cout << "\n--- QUAN LY NHAN VIEN ---" << std::endl;
        std::cout << "1. Them nhan vien" << std::endl;
        std::cout << "2. Xem danh sach nhan vien" << std::endl;
        std::cout << "3. Thay doi thong tin nhan vien" << std::endl;
        std::cout << "4. Tang luong nhan vien" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nhap sai! Vui long nhap so." << std::endl;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string ma, ten, pb;
                double l;
                std::cout << "Nhap ma nhan vien: ";
                std::getline(std::cin, ma);

                if (maNVDaTonTai(danhSachNhanVien, ma)) {
                    std::cout << "Ma nhan vien da ton tai!" << std::endl;
                    break;
                }

                std::cout << "Nhap ten nhan vien: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap phong ban: ";
                std::getline(std::cin, pb);
                std::cout << "Nhap luong: ";
                std::cin >> l;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Luong khong hop le!" << std::endl;
                    break;
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                danhSachNhanVien.push_back(new NhanVien(ma, ten, pb, l));
                std::cout << "Nhan vien da duoc them." << std::endl;
                break;
            }
            case 2: {
                std::cout << "\n--- DANH SACH NHAN VIEN ---" << std::endl;
                if (danhSachNhanVien.empty()) {
                    std::cout << "Khong co nhan vien nao." << std::endl;
                } else {
                    for (const NhanVien* nv : danhSachNhanVien) {
                        nv->hienThiThongTin();
                    }
                }
                break;
            }
            case 3: {
                std::string maNVCapNhat;
                std::cout << "Nhap ma nhan vien can thay doi thong tin: ";
                std::getline(std::cin, maNVCapNhat);
                NhanVien* nhanVienCanCapNhat = nullptr;
                for (NhanVien* nv : danhSachNhanVien) {
                    if (nv->getMaNV() == maNVCapNhat) {
                        nhanVienCanCapNhat = nv;
                        break;
                    }
                }
                if (nhanVienCanCapNhat) {
                    std::cout << "Nhap ten moi (de trong neu khong thay doi): ";
                    std::string tenMoi;
                    std::getline(std::cin, tenMoi);
                    if (!tenMoi.empty()) {
                        nhanVienCanCapNhat->setTenNV(tenMoi);
                    }
                    std::cout << "Nhap phong ban moi (de trong neu khong thay doi): ";
                    std::string phongBanMoi;
                    std::getline(std::cin, phongBanMoi);
                    if (!phongBanMoi.empty()) {
                        nhanVienCanCapNhat->setPhongBan(phongBanMoi);
                    }
                    std::cout << "Nhap luong moi (nhap -1 neu khong thay doi): ";
                    double luongMoi;
                    std::cin >> luongMoi;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Luong khong hop le!" << std::endl;
                        break;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (luongMoi != -1) {
                        nhanVienCanCapNhat->setLuong(luongMoi);
                    }
                    std::cout << "Thong tin nhan vien da duoc cap nhat." << std::endl;
                } else {
                    std::cout << "Khong tim thay nhan vien co ma: " << maNVCapNhat << std::endl;
                }
                break;
            }
            case 4: {
                std::string maNVTangLuong;
                double phanTram;
                std::cout << "Nhap ma nhan vien can tang luong: ";
                std::getline(std::cin, maNVTangLuong);
                NhanVien* nhanVienCanTangLuong = nullptr;
                for (NhanVien* nv : danhSachNhanVien) {
                    if (nv->getMaNV() == maNVTangLuong) {
                        nhanVienCanTangLuong = nv;
                        break;
                    }
                }
                if (nhanVienCanTangLuong) {
                    std::cout << "Nhap phan tram luong tang (vi du: 10 cho tang 10%): ";
                    std::cin >> phanTram;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Phan tram khong hop le!" << std::endl;
                        break;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    nhanVienCanTangLuong->tangLuong(phanTram);
                    std::cout << "Luong nhan vien da duoc cap nhat." << std::endl;
                } else {
                    std::cout << "Khong tim thay nhan vien co ma: " << maNVTangLuong << std::endl;
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

    for (NhanVien* nv : danhSachNhanVien) {
        delete nv;
    }
    danhSachNhanVien.clear();

    return 0;
}
