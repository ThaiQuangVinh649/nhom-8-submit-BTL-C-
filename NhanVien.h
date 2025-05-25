#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include "QuanLy.h"

class NhanVien : public QuanLy {
private:
    std::string tenNV;
    std::string phongBan;
    double luong;

public:
    NhanVien() : QuanLy(""), tenNV(""), phongBan(""), luong(0.0) {}
    NhanVien(const std::string& ma, const std::string& ten, const std::string& pb, double l)
        : QuanLy(ma), tenNV(ten), phongBan(pb), luong(l) {}
    ~NhanVien() override {}

    // Getters
    std::string getTenNV() const { return tenNV; }
    std::string getPhongBan() const { return phongBan; }
    double getLuong() const { return luong; }

    // Setters
    void setTenNV(const std::string& ten) { tenNV = ten; }
    void setPhongBan(const std::string& pb) { phongBan = pb; }
    void setLuong(double l) { luong = l; }

    // Phương thức ảo (đa hình)
    void hienThiThongTin() const override;

    // Tăng lương
    void tangLuong(double phanTramTang);

    // Quá tải toán tử
    bool operator==(const NhanVien& other) const {
        return id == other.id;
    }
};

#endif // NHANVIEN_H