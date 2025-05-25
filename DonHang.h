#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include "QuanLy.h"

class DonHang : public QuanLy {
private:
    std::string maKH; // Thay tenKH bằng maKH để liên kết với KhachHang
    double tongTien;

public:
    DonHang() : QuanLy(""), maKH(""), tongTien(0.0) {}
    DonHang(const std::string& ma, const std::string& maKH, double tien) : QuanLy(ma), maKH(maKH), tongTien(tien) {}
    ~DonHang() override {}

    // Getters
    std::string getMaKH() const { return maKH; }
    double getTongTien() const { return tongTien; }

    // Setters
    void setMaKH(const std::string& ma) { maKH = ma; }
    void setTongTien(double tien) { tongTien = tien; }

    // Phương thức ảo (đa hình)
    void hienThiThongTin() const override;

    // Cập nhật tổng tiền
    void capNhatTongTien(double soTienThayDoi);

    // Quá tải toán tử
    bool operator==(const DonHang& other) const {
        return id == other.id;
    }
};

#endif // DONHANG_H