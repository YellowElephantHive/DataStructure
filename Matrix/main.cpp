//
//  main.cpp
//  testmatrix
//
//  Created by ПрЈ|Т@ on 2021/11/4.
//

#include <iostream>
#include "matrix.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    int data_1[2][2] = {{1, 8}, {1, 8}}; // 2*2 array
    int data_2[3][3] = {{1, 2, 0}, {3, 4, 4}, {5, 6, 3}}; // 3*3 array
        
    int *ptr_1[2] = {data_1[0],data_1[1]}; 
    int *ptr_2[3] = {data_2[0], data_2[1], data_2[2]};

            
    Matrix m1, m2;
    Matrix transpose_matrix;
    Matrix add_matrix;
    Matrix multi_matrix;
    Matrix inverse_matrix;
    Matrix adjoint;
    Matrix cofactor;
    int determinant;
    
    m1 = Matrix(2, 2); // initialize empty matrix
    m1 = Matrix(ptr_1, 2, 2); // initialize 2 by 2 matr
    m2 = Matrix(3, 3);
    m2 = Matrix(ptr_2, 3, 3);
    
    transpose_matrix = m1.transpose();
    add_matrix = m1 + transpose_matrix;
    multi_matrix = m1 * transpose_matrix;
    inverse_matrix = m1.inverse();
    determinant = m2.determinant();
    adjoint = m2.adjoint();
    cofactor = m1.cofactor(0, 0);
    
    std::cout << "2*2 matirx m1 is:" << "\n";
    std::cout << m1 << "\n";
    std::cout << "3*3 matirx m2 is:" << "\n";
    std::cout << m2 << "\n";
    std::cout << "transpose of m1" << "\n";
    std::cout << transpose_matrix << "\n";
    std::cout << "Addition between m1 and tranposed m1" << "\n";
    std::cout << add_matrix << "\n";
    std::cout << "Multiplication between m1 and tranposed m1" << "\n";
    std::cout << multi_matrix << "\n";
    std::cout << "inverse of m1" << "\n";
    std::cout << inverse_matrix << "\n";
    std::cout << "determinant of m2" << "\n";
    std::cout << determinant << "\n";
    std::cout << "adjoint matrix of m2" << "\n";
    std::cout << adjoint << "\n";
    std::cout << "cofactor matrix of m1" << "\n";
    std::cout << cofactor << "\n";
    
    
    system("pause");
    return 0;
}

