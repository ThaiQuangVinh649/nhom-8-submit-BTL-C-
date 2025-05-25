#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "KhachHang.h"
#include "DonHang.h"
#include "NhanVien.h"
#include "SanPham.h"
#include "ThuNhapNgay.h"

void quanLyKhachHang(std::vector<KhachHang*>& danhSachKhachHang) {
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
                std::string ma, ten, dc, so, loai;
                std::cout << "Nhap ma khach hang: ";
                std::getline(std::cin, ma);
                for (const KhachHang* kh : danhSachKhachHang) {
                    if (kh->getId() == ma) {
                        std::cout << "Ma khach hang da ton tai!" << std::endl;
                        break;
                    }
                }
                std::cout << "Nhap ten khach hang: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap dia chi khach hang: ";
                std::getline(std::cin, dc);
                std::cout << "Nhap so dien thoai khach hang: ";
                std::getline(std::cin, so);
                std::cout << "Nhap loai khach hang (VIP/Thuong): ";
                std::getline(std::cin, loai);
                if (loai != "VIP" && loai != "Thuong") {
                    std::cout << "Loai khach hang khong hop le, mac dinh la Thuong." << std::endl;
                    loai = "Thuong";
                }
                danhSachKhachHang.push_back(new KhachHang(ma, ten, dc, so, loai));
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
                    if (kh->getId() == maKHCapNhat) {
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
                    std::cout << "Nhap loai khach hang moi (VIP/Thuong, de trong neu khong thay doi): ";
                    std::string loaiMoi;
                    std::getline(std::cin, loaiMoi);
                    if (!loaiMoi.empty()) {
                        if (loaiMoi == "VIP" || loaiMoi == "Thuong") {
                            khachHangCanCapNhat->setLoaiKH(loaiMoi);
                        } else {
                            std::cout << "Loai khach hang khong hop le, giu nguyen loai cu." << std::endl;
                        }
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
                    if ((*it)->getId() == maKHXoa) {
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
                std::cout << "Quay lai menu chinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);
}

void quanLyDonHang(std::vector<DonHang*>& danhSachDonHang, const std::vector<KhachHang*>& danhSachKhachHang) {
    int choice;
    do {
        std::cout << "\n--- QUAN LY DON HANG ---" << std::endl;
        std::cout << "1. Them don hang" << std::endl;
        std::cout << "2. Xem danh sach don hang" << std::endl;
        std::cout << "3. Cap nhat tong tien don hang" << std::endl;
        std::cout << "4. Xoa don hang" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string ma, maKH;
                double tien;
                std::cout << "Nhap ma don hang: ";
                std::getline(std::cin, ma);
                for (const DonHang* dh : danhSachDonHang) {
                    if (dh->getId() == ma) {
                        std::cout << "Ma don hang da ton tai!" << std::endl;
                        break;
                    }
                }
                std::cout << "Nhap ma khach hang: ";
                std::getline(std::cin, maKH);
                bool khachHangTonTai = false;
                for (const KhachHang* kh : danhSachKhachHang) {
                    if (kh->getId() == maKH) {
                        khachHangTonTai = true;
                        break;
                    }
                }
                if (!khachHangTonTai) {
                    std::cout << "Khach hang khong ton tai!" << std::endl;
                    break;
                }
                std::cout << "Nhap tong tien don hang: ";
                std::cin >> tien;
                if (tien < 0) {
                    std::cout << "Tong tien khong the am!" << std::endl;
                    break;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                danhSachDonHang.push_back(new DonHang(ma, maKH, tien));
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
                    if (dh->getId() == maDHThayDoi) {
                        donHangCanThayDoi = dh;
                        break;
                    }
                }
                if (donHangCanThayDoi) {
                    std::cout << "Nhap so tien thay doi (co the am hoac duong): ";
                    std::cin >> soTienThayDoi;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (donHangCanThayDoi->getTongTien() + soTienThayDoi < 0) {
                        std::cout << "Tong tien sau cap nhat khong the am!" << std::endl;
                        break;
                    }
                    donHangCanThayDoi->capNhatTongTien(soTienThayDoi);
                    std::cout << "Tong tien don hang da duoc cap nhat." << std::endl;
                } else {
                    std::cout << "Khong tim thay don hang co ma: " << maDHThayDoi << std::endl;
                }
                break;
            }
            case 4: {
                std::string maDHXoa;
                std::cout << "Nhap ma don hang can xoa: ";
                std::getline(std::cin, maDHXoa);
                auto it = danhSachDonHang.begin();
                bool found = false;
                while (it != danhSachDonHang.end()) {
                    if ((*it)->getId() == maDHXoa) {
                        delete *it;
                        it = danhSachDonHang.erase(it);
                        found = true;
                        std::cout << "Don hang da duoc xoa." << std::endl;
                        break;
                    } else {
                        ++it;
                    }
                }
                if (!found) {
                    std::cout << "Khong tim thay don hang co ma: " << maDHXoa << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Quay lai menu chinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);
}

void quanLyNhanVien(std::vector<NhanVien*>& danhSachNhanVien) {
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string ma, ten, pb;
                double l;
                std::cout << "Nhap ma nhan vien: ";
                std::getline(std::cin, ma);
                for (const NhanVien* nv : danhSachNhanVien) {
                    if (nv->getId() == ma) {
                        std::cout << "Ma nhan vien da ton tai!" << std::endl;
                        break;
                    }
                }
                std::cout << "Nhap ten nhan vien: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap phong ban: ";
                std::getline(std::cin, pb);
                std::cout << "Nhap luong: ";
                std::cin >> l;
                if (l < 0) {
                    std::cout << "Luong khong the am!" << std::endl;
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
                    if (nv->getId() == maNVCapNhat) {
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
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (luongMoi != -1) {
                        if (luongMoi < 0) {
                            std::cout << "Luong khong the am!" << std::endl;
                            break;
                        }
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
                    if (nv->getId() == maNVTangLuong) {
                        nhanVienCanTangLuong = nv;
                        break;
                    }
                }
                if (nhanVienCanTangLuong) {
                    std::cout << "Nhap phan tram luong tang (vi du: 10 cho tang 10%): ";
                    std::cin >> phanTram;
                    if (phanTram < 0) {
                        std::cout << "Phan tram tang khong the am!" << std::endl;
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
                std::cout << "Quay lai menu chinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);
}

void quanLySanPham(std::vector<SanPham*>& danhSachSanPham) {
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
                for (const SanPham* sp : danhSachSanPham) {
                    if (sp->getId() == ma) {
                        std::cout << "Ma san pham da ton tai!" << std::endl;
                        break;
                    }
                }
                std::cout << "Nhap ten san pham: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap gia san pham: ";
                std::cin >> gia;
                if (gia < 0) {
                    std::cout << "Gia khong the am!" << std::endl;
                    break;
                }
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
                    if (sp->getId() == maSPThayDoi) {
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
                std::cout << "Quay lai menu chinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);
}

void quanLyThuNhap(std::vector<ThuNhapNgay*>& danhSachThuNhap, const std::vector<DonHang*>& danhSachDonHang) {
    int choice;
    do {
        std::cout << "\n--- QUAN LY THU NHAP HANG NGAY CUA QUAN ---" << std::endl;
        std::cout << "1. Them thu nhap theo ngay (chi dinh tien mat & ATM)" << std::endl;
        std::cout << "2. Xem danh sach thu nhap theo ngay" << std::endl;
        std::cout << "3. Thay doi thong tin thu nhap theo ngay" << std::endl;
        std::cout << "4. Xem chi tiet thu nhap theo ngay" << std::endl;
        std::cout << "5. Tinh tong thu nhap tu nhieu ngay" << std::endl;
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
                for (const ThuNhapNgay* tn : danhSachThuNhap) {
                    if (tn->getId() == n) {
                        std::cout << "Ngay da ton tai!" << std::endl;
                        break;
                    }
                }
                std::cout << "Nhap so tien mat: ";
                std::cin >> tm;
                std::cout << "Nhap so tien ATM: ";
                std::cin >> atm;
                if (tm < 0 || atm < 0) {
                    std::cout << "Tien mat hoac ATM khong the am!" << std::endl;
                    break;
                }
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
                    for (const ThuNhapNgay* TNN : danhSachThuNhap) {
                        std::cout << *TNN;
                    }
                }
                break;
            }
            case 3: {
                std::string ngayCapNhat;
                std::cout << "Nhap ngay can thay doi thong tin (YYYY-MM-DD): ";
                std::getline(std::cin, ngayCapNhat);
                ThuNhapNgay* thuNhapCanCapNhat = nullptr;
                for (ThuNhapNgay* tnn : danhSachThuNhap) {
                    if (tnn->getId() == ngayCapNhat) {
                        thuNhapCanCapNhat = tnn;
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
                        if (thuNhapMoiTM < 0) {
                            std::cout << "Tien mat khong the am!" << std::endl;
                            break;
                        }
                        thuNhapCanCapNhat->setTienMat(thuNhapMoiTM);
                    }
                    if (thuNhapMoiATM != -1) {
                        if (thuNhapMoiATM < 0) {
                            std::cout << "Tien ATM khong the am!" << std::endl;
                            break;
                        }
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
                for (ThuNhapNgay* tnn : danhSachThuNhap) {
                    if (tnn->getId() == ngayXemThuNhap) {
                        thuNhapCanXem = tnn;
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
                std::vector<std::string> ngayCanTongHop;
                std::string inputNgay;
                std::cout << "Nhap cac ngay can tong hop thu nhap (nhap 'ketthuc' de dung):\n";
                while (true) {
                    std::cout << "Ngay (YYYY-MM-DD): ";
                    std::getline(std::cin, inputNgay);
                    if (inputNgay == "ketthuc") {
                        break;
                    }
                    ngayCanTongHop.push_back(inputNgay);
                }

                if (ngayCanTongHop.empty()) {
                    std::cout << "Khong co ngay nao duoc nhap de tong hop." << std::endl;
                    break;
                }

                ThuNhapNgay tongHopThuNhap("", 0, 0);
                bool coDuLieu = false;

                std::cout << "\n--- TONG THU NHAP NHIEU NGAY ---" << std::endl;
                for (const std::string& ngayHienTai : ngayCanTongHop) {
                    ThuNhapNgay* tnHienTai = nullptr;
                    for (ThuNhapNgay* tn : danhSachThuNhap) {
                        if (tn->getId() == ngayHienTai) {
                            tnHienTai = tn;
                            break;
                        }
                    }

                    if (tnHienTai) {
                        tongHopThuNhap = tongHopThuNhap + *tnHienTai;
                        coDuLieu = true;
                    } else {
                        std::cout << "Luu y: Khong tim thay thong tin thu nhap cho ngay " << ngayHienTai << std::endl;
                    }
                }

                if (coDuLieu) {
                    std::cout << "Tong thu nhap tu cac ngay da chon la: " << tongHopThuNhap.getTongThuNhap() << " VND" << std::endl;
                    std::cout << "Tong tien mat: " << tongHopThuNhap.getTienMat() << " VND" << std::endl;
                    std::cout << "Tong tien ATM: " << tongHopThuNhap.getTienATM() << " VND" << std::endl;
                } else {
                    std::cout << "Khong co du lieu thu nhap de tong hop tu cac ngay da chon." << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Quay lai menu chinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);
}