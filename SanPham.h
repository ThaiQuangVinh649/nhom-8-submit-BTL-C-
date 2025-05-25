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

    std::string getTenSP() const { return tenSP; }
    double getGia() const { return gia; }

    void setTenSP(const std::string& ten) { tenSP = ten; }
    void setGia(double g) { gia = g; }

    void hienThiThongTin() const override;


    void thayDoiGia(double phanTramThayDoi);


    bool operator==(const SanPham& other) const {
        return id == other.id;
    }
};

#endif 
