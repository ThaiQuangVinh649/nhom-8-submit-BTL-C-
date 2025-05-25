#include <iostream>
#include <vector>
#include <limits>
#include "KhachHang.h"
#include "DonHang.h"
#include "NhanVien.h"
#include "SanPham.h"
#include "ThuNhapNgay.h"
void quanLyKhachHang(std::vector<KhachHang*>& danhSachKhachHang);
void quanLyDonHang(std::vector<DonHang*>& danhSachDonHang, const std::vector<KhachHang*>& danhSachKhachHang);
void quanLyNhanVien(std::vector<NhanVien*>& danhSachNhanVien);
void quanLySanPham(std::vector<SanPham*>& danhSachSanPham);
void quanLyThuNhap(std::vector<ThuNhapNgay*>& danhSachThuNhap, const std::vector<DonHang*>& danhSachDonHang);

int main() {
    std::vector<KhachHang*> danhSachKhachHang;
    std::vector<DonHang*> danhSachDonHang;
    std::vector<NhanVien*> danhSachNhanVien;
    std::vector<SanPham*> danhSachSanPham;
    std::vector<ThuNhapNgay*> danhSachThuNhap;

    int luaChon;
    do {
        std::cout << "\n=========== MENU TONG HOP ===========" << std::endl;
        std::cout << "1. Quan ly san pham" << std::endl;
        std::cout << "2. Quan ly khach hang" << std::endl;
        std::cout << "3. Quan ly don hang" << std::endl;
        std::cout << "4. Quan ly nhan vien" << std::endl;
        std::cout << "5. Quan ly thu nhap hang ngay" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        while (!(std::cin >> luaChon)) {
            std::cout << "Vui long nhap so hop le: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (luaChon) {
            case 1:
                quanLySanPham(danhSachSanPham);
                break;
            case 2:
                quanLyKhachHang(danhSachKhachHang);
                break;
            case 3:
                quanLyDonHang(danhSachDonHang, danhSachKhachHang);
                break;
            case 4:
                quanLyNhanVien(danhSachNhanVien);
                break;
            case 5:
                quanLyThuNhap(danhSachThuNhap, danhSachDonHang);
                break;
            case 0:
                std::cout << "[!] Ket thuc chuong trinh." << std::endl;
                break;
            default:
                std::cout << "[!] Lua chon khong hop le. Vui long nhap lai." << std::endl;
        }
    } while (luaChon != 0);
    for (KhachHang* kh : danhSachKhachHang) delete kh;
    for (DonHang* dh : danhSachDonHang) delete dh;
    for (NhanVien* nv : danhSachNhanVien) delete nv;
    for (SanPham* sp : danhSachSanPham) delete sp;
    for (ThuNhapNgay* tn : danhSachThuNhap) delete tn;

    danhSachKhachHang.clear();
    danhSachDonHang.clear();
    danhSachNhanVien.clear();
    danhSachSanPham.clear();
    danhSachThuNhap.clear();

    return 0;
}
