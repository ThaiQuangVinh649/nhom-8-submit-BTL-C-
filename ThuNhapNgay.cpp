#include <iostream>
#include "ThuNhapNgay.h"

void ThuNhapNgay::hienThiThongTin() const {
    std::cout << "Ngay: " << id
              << ", Tong thu nhap: " << tongThuNhap << " VND"
              << " (Tien mat: " << tienMat << " VND, Tien ATM: " << tienATM << " VND)" << std::endl;
}

ThuNhapNgay ThuNhapNgay::operator+(const ThuNhapNgay& other) const {
    return ThuNhapNgay("", tienMat + other.tienMat, tienATM + other.tienATM);
}

std::ostream& operator<<(std::ostream& os, const ThuNhapNgay& obj) {
    obj.hienThiThongTin();
    return os;
}