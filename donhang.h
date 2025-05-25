#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include <iostream> 
#include <iomanip>  

class DonHang {
protected:
    std::string maDH;
    std::string tenKH;
    double tongTien;

public:
    DonHang();
    DonHang(const std::string& ma, const std::string& ten, double tien);

    virtual ~DonHang();

    std::string getMaDH() const;
    std::string getTenKH() const;
    double getTongTien() const;

    void setTenKH(const std::string& ten);
    void setTongTien(double tien);

    virtual void hienThiThongTin() const;

    void capNhatTongTien(double soTienThayDoi);

    bool operator==(const DonHang& other) const;
};

#endif 
