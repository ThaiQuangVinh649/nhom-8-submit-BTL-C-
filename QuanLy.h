#ifndef QUANLY_H
#define QUANLY_H

#include <string>

class QuanLy {
protected:
    std::string id; 
public:
    QuanLy(const std::string& id) : id(id) {}
    virtual ~QuanLy() {}
    std::string getId() const { return id; }
    virtual void hienThiThongTin() const = 0;
    virtual bool operator==(const QuanLy& other) const {
        return id == other.id;
    }
};

#endif // QUANLY_H
