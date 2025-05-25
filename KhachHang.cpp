#include <iostream>
#include "KhachHang.h"

void KhachHang::hienThiThongTin() const {
    std::cout << "Ma KH: " << id << ", Ten KH: " << tenKH
              << ", Dia chi: " << diaChi << ", SDT: " << sdt
              << ", Loai KH: " << loaiKH << std::endl;
}