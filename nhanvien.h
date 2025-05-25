#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

class NhanVien {
protected:
    std::string maNV;
    std::string tenNV;
    std::string phongBan;
    double luong;

public:
    NhanVien();
    NhanVien(const std::string& ma, const std::string& ten, const std::string& pb, double l);
    virtual ~NhanVien();

    std::string getMaNV() const;
    std::string getTenNV() const;
    std::string getPhongBan() const;
    double getLuong() const;

    void setTenNV(const std::string& ten);
    void setPhongBan(const std::string& pb);
    void setLuong(double l);

    virtual void hienThiThongTin() const;
    void tangLuong(double phanTramTang);

    bool operator==(const NhanVien& other) const;
};

#endif
