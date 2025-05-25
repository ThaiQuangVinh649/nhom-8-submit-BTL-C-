#ifndef THUNHAPNGAY_H
#define THUNHAPNGAY_H

#include <string>
#include "QuanLy.h"

class ThuNhapNgay : public QuanLy {
private:
    double tongThuNhap;
    double tienMat;
    double tienATM;

public:
    ThuNhapNgay(const std::string& n, double tm, double atm)
        : QuanLy(n), tienMat(tm), tienATM(atm) {
        tongThuNhap = tm + atm;
    }
    ~ThuNhapNgay() override {}

    
    double getTongThuNhap() const { return tongThuNhap; }
    double getTienMat() const { return tienMat; }
    double getTienATM() const { return tienATM; }

    
    void setTienMat(double tm) {
        tienMat = tm;
        tongThuNhap = tienMat + tienATM;
    }
    void setTienATM(double atm) {
        tienATM = atm;
        tongThuNhap = tienMat + tienATM;
    }

    
    void hienThiThongTin() const override;

    
    ThuNhapNgay operator+(const ThuNhapNgay& other) const;
};

std::ostream& operator<<(std::ostream& os, const ThuNhapNgay& obj);

#endif 
