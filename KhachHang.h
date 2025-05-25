#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <string>
#include "QuanLy.h"

class KhachHang : public QuanLy {
private:
    std::string tenKH;
    std::string diaChi;
    std::string sdt;
    std::string loaiKH; 

public:
    KhachHang() : QuanLy(""), tenKH(""), diaChi(""), sdt(""), loaiKH("Thuong") {}
    KhachHang(const std::string& ma, const std::string& ten, const std::string& dc, const std::string& so, const std::string& loai)
        : QuanLy(ma), tenKH(ten), diaChi(dc), sdt(so), loaiKH(loai) {}
    ~KhachHang() override {}

 
    std::string getTenKH() const { return tenKH; }
    std::string getDiaChi() const { return diaChi; }
    std::string getSDT() const { return sdt; }
    std::string getLoaiKH() const { return loaiKH; }

   
    void setTenKH(const std::string& ten) { tenKH = ten; }
    void setDiaChi(const std::string& dc) { diaChi = dc; }
    void setSDT(const std::string& so) { sdt = so; }
    void setLoaiKH(const std::string& loai) { loaiKH = loai; }

  
    void hienThiThongTin() const override;

 
    bool operator==(const KhachHang& other) const {
        return id == other.id;
    }
};


