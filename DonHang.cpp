#include <iostream>
#include <iomanip>
#include "DonHang.h"

void DonHang::hienThiThongTin() const {
    std::cout << "Ma DH: " << id << ", Ma KH: " << maKH << ", Tong tien: "
              << std::fixed << std::setprecision(2) << tongTien << std::endl;
}

void DonHang::capNhatTongTien(double soTienThayDoi) {
    tongTien += soTienThayDoi;
}