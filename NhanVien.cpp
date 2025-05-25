#include <iostream>
#include "NhanVien.h"

void NhanVien::hienThiThongTin() const {
    std::cout << "Ma NV: " << id << ", Ten NV: " << tenNV
              << ", Phong ban: " << phongBan << ", Luong: " << luong << std::endl;
}

void NhanVien::tangLuong(double phanTramTang) {
    luong *= (1 + phanTramTang / 100.0);
}