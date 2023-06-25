#include <iostream>
#include "libxl.h"

int main() {
    // Mở tệp Excel
    libxl::Book* book = xlCreateXMLBook();
    if (!book) {
        std::cout << "Không thể tạo đối tượng Book!" << std::endl;
        return 1;
    }
    if (!book->load("C:\\Users\\ACER\\workspace\\C++\\abc.xlsx")) {
        std::cout << "Không thể mở tệp Excel!" << std::endl;
        return 1;
    }

    // Lấy danh sách các sheet trong tệp Excel
    int sheetCount = book->sheetCount();
    std::cout << "Số sheet trong tệp Excel: " << sheetCount << std::endl;

    // Đọc dữ liệu từ sheet đầu tiên
    libxl::Sheet* sheet = book->getSheet(0);
    if (!sheet) {
        std::cout << "Không thể lấy Sheet!" << std::endl;
        return 1;
    }

    // Lấy số hàng và số cột của sheet
    int rowCount = sheet->lastRow();
    int colCount = sheet->lastCol();

    std::cout << "Số hàng: " << rowCount << std::endl;
    std::cout << "Số cột: " << colCount << std::endl;

    // Đọc dữ liệu từ mỗi ô và in ra
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            libxl::CellType cellType = sheet->cellType(row, col);
            if (cellType == libxl::CELLTYPE_NUMBER) {
                double value = sheet->readNum(row, col);
                std::cout << value << " ";
            } else if (cellType == libxl::CELLTYPE_STRING) {
                const char* value = sheet->readStr(row, col);
                std::cout << value << " ";
            }
        }
        std::cout << std::endl;
    }

    // Giải phóng tài nguyên
    book->release();

    return 0;
}