
#include <stdint.h>
#include <iosfwd>
#include <stdexcept>
#include <limits>


class Matrix {
private:
    int mat_[2][2];


public:
    Matrix(const int mat[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat_[i][j] = mat[i][j];
            }

        }

    }

    int getIndex(const int i, const int j) {
        return mat_[i][j];
    }
    //operator[][](const int i, const int j) {
    //    return mat_[i][j];
    //}
    // bool operator==(const int i, const int j) const {
     //    if (i < 0 || j<0)
      //       throw "negative size";
    //     else if()
    // };
    // bool operator==(const int i, const int j) const {
    //     return !(operator==(mat_));
    // };

    std::ostream& WriteTo(std::ostream& ostrm) {
         /*for (int i = 0; i < 2; i++)
             for(int j=0;j<2;j++)
                 ostream <<

                 */



         return ostrm;
     };
     std::istream& ReadFrom(std::istream& istrm);


};


/*
TEST_CASE{
    int mat[2][2] = { {1, 2},
                      {2, 4} };

    Matrix<int> mat1(mat);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            CHECK(mat[i][j] == mat1[i][j])
}

*/

bool test() {
    int mat[2][2] = { {0, 2},
                      {1, 2} };

    Matrix m1(mat);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (mat[i][j] != m1.getIndex(i, j))
                return false;

    return true;
}

int main() {
    std::string result;
        if (test())
            result = "Success";
        else
            result = "Fail";
    return 0;
}















