#include <iostream>
#include "SanPham.h"

void SanPham::hienThiThongTin() const {
    std::cout << "Ma SP: " << id << ", Ten SP: " << tenSP << ", Gia: " << gia << std::endl;
}

void SanPham::thayDoiGia(double phanTramThayDoi) {
    gia *= (1 + phanTramThayDoi / 100.0);
}