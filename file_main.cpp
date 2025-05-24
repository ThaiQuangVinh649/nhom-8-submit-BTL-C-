#include <iostream>
#include <string>
#include <vector>
#include <limits>    
#include <iomanip>  
#include <numeric>  
#include <algorithm> 
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

    virtual ~ThuNhapNgay() {}

    std::string getNgay() const { return ngay; }
    double getTongThuNhap() const { return tongThuNhap; } 
    double getTienMat() const { return tienMat; } 
    double getTienATM() const { return tienATM; } 


    void setTongThuNhap(double tn) { tongThuNhap = tn; }
    void setTienMat(double tm) {
        tienMat = tm;
        tongThuNhap = tienMat + tienATM;
    }
    void setTienATM(double atm) {
        tienATM = atm;
        tongThuNhap = tienMat + tienATM;
    }

    virtual void hienThiThongTin() const {
        std::cout << "Ngay: " << ngay
                  << ", Tong thu nhap: " << tongThuNhap << " VND"
                  << " (Tien mat: " << tienMat << " VND, Tien ATM: " << tienATM << " VND)" << std::endl;
    }

    
    ThuNhapNgay operator+(const ThuNhapNgay& other) const {
        std::string combined_dates = "Tong hop tu cac ngay";
        return ThuNhapNgay(combined_dates, this->tienMat + other.tienMat, this->tienATM + other.tienATM);
    }
};
std::ostream& operator<<(std::ostream& os, const ThuNhapNgay& obj) { 
    obj.hienThiThongTin();
    return os;
}
void quanLyDonHang(std::vector<DonHang*>& danhSachDonHang) {
    int choice;
    do {
        std::cout << "\n--- QUAN LY DON HANG ---" << std::endl;
        std::cout << "1. Them don hang" << std::endl;
        std::cout << "2. Xem danh sach don hang" << std::endl;
        std::cout << "3. Cap nhat tong tien don hang" << std::endl;
        std::cout << "0. Quay lai menu chinh" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;
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
        std::cout << "0. Quay lai menu chinh" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer

        switch (choice) {
            case 1: {
                std::string ma, ten, pb;
                double l;
                std::cout << "Nhap ma nhan vien: ";
                std::getline(std::cin, ma);
                std::cout << "Nhap ten nhan vien: ";
                std::getline(std::cin, ten);
                std::cout << "Nhap phong ban: ";
                std::getline(std::cin, pb);
                std::cout << "Nhap luong: ";
                std::cin >> l;
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
        std::cout << "0. Quay lai menu chinh" << std::endl;
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
                std::cout << "Quay lai menu chinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);
}

void quanLyKhachHang(std::vector<KhachHang*>& danhSachKhachHang) {
    int choice;
    do {
        std::cout << "\n--- QUAN LY KHACH HANG ---" << std::endl;
        std::cout << "1. Them khach hang" << std::endl;
        std::cout << "2. Xem danh sach khach hang" << std::endl;
        std::cout << "3. Cap nhat thong tin khach hang" << std::endl;
        std::cout << "0. Quay lai menu chinh" << std::endl;
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
            case 0:
                std::cout << "Quay lai menu chinh." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (choice != 0);
}

void quanLyThuNhapNgay(std::vector<ThuNhapNgay*>& danhSachThuNhap) {
    int choice;
    do {
        std::cout << "\n--- QUAN LY THU NHAP HANG NGAY CUA QUAN ---" << std::endl;
        std::cout << "1. Them thu nhap theo ngay (chi dinh tien mat & ATM)" << std::endl;
        std::cout << "2. Xem danh sach thu nhap theo ngay" << std::endl;
        std::cout << "3. Thay doi thong tin thu nhap theo ngay" << std::endl;
        std::cout << "4. Xem chi tiet thu nhap theo ngay" << std::endl;
        std::cout << "5. Tinh tong thu nhap tu nhieu ngay (qua tai toan tu +)" << std::endl;
        std::cout << "0. Quay lai menu chinh" << std::endl;
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
                    for (ThuNhapNgay* TNN : danhSachThuNhap) {
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
                    if (tnn->getNgay() == ngayCapNhat) {
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
                for (ThuNhapNgay* tnn : danhSachThuNhap) {
                    if (tnn->getNgay() == ngayXemThuNhap) {
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

                ThuNhapNgay tongHopThuNhap("", 0, 0); // Initialize with placeholder values
                bool coDuLieu = false;

                std::cout << "\n--- TONG THU NHAP NHIEU NGAY ---" << std::endl;
                for (const std::string& ngayHienTai : ngayCanTongHop) {
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

int main() {
    std::vector<DonHang*> danhSachDonHang;
    std::vector<NhanVien*> danhSachNhanVien;
    std::vector<SanPham*> danhSachSanPham;
    std::vector<KhachHang*> danhSachKhachHang;
    std::vector<ThuNhapNgay*> danhSachThuNhap;

    int mainMenuChoice;

    do {
        std::cout << "\n========== UNIFIED MANAGEMENT SYSTEM ==========" << std::endl;
        std::cout << "1. Quan ly Don Hang" << std::endl;
        std::cout << "2. Quan ly Nhan Vien" << std::endl;
        std::cout << "3. Quan ly San Pham" << std::endl;
        std::cout << "4. Quan ly Khach Hang" << std::endl;
        std::cout << "5. Quan ly Thu Nhap Hang Ngay" << std::endl;
        std::cout << "0. Thoat chuong trinh" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> mainMenuChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (mainMenuChoice) {
            case 1:
                quanLyDonHang(danhSachDonHang);
                break;
            case 2:
                quanLyNhanVien(danhSachNhanVien);
                break;
            case 3:
                quanLySanPham(danhSachSanPham);
                break;
            case 4:
                quanLyKhachHang(danhSachKhachHang);
                break;
            case 5:
                quanLyThuNhapNgay(danhSachThuNhap);
                break;
            case 0:
                std::cout << "Dang thoat chuong trinh. Tam biet!" << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
        }
    } while (mainMenuChoice != 0);

    for (DonHang* dh : danhSachDonHang) {
        delete dh;
    }
    danhSachDonHang.clear();

    for (NhanVien* nv : danhSachNhanVien) {
        delete nv;
    }
    danhSachNhanVien.clear();

    for (SanPham* sp : danhSachSanPham) {
        delete sp;
    }
    danhSachSanPham.clear();

    for (KhachHang* kh : danhSachKhachHang) {
        delete kh;
    }
    danhSachKhachHang.clear();

    for (ThuNhapNgay* tn : danhSachThuNhap) {
        delete tn;
    }
    danhSachThuNhap.clear();

    return 0;
}
