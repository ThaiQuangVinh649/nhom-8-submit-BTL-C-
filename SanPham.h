#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>
#include "QuanLy.h"

class SanPham : public QuanLy {
private:
    std::string tenSP;
    double gia;

public:
    SanPham() : QuanLy(""), tenSP(""), gia(0.0) {}
    SanPham(const std::string& ma, const std::string& ten, double g) : QuanLy(ma), tenSP(ten), gia(g) {}
    ~SanPham() override {}

    // Getters
    std::string getTenSP() const { return tenSP; }
    double getGia() const { return gia; }

    // Setters
    void setTenSP(const std::string& ten) { tenSP = ten; }
    void setGia(double g) { gia = g; }

    // Phương thức ảo (đa hình)
    void hienThiThongTin() const override;

    // Thay đổi giá
    void thayDoiGia(double phanTramThayDoi);

    // Quá tải toán tử
    bool operator==(const SanPham& other) const {
        return id == other.id;
    }
};

#endif // SANPHAM_H