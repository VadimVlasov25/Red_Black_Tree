#include <iostream>
#include <locale> 
#include <clocale> 
#include "RedBlackTree.h"

int main1() {
    setlocale(LC_ALL, "Russian");

    RedBlackTree tree; // ������� ��������� ������-������� ������

    // ������ ������� ������
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);

    // ������� �������� ������ � ������� �����������
    std::cout << "�������� ������ � ������� �����������: ";
    tree.inorder();
    std::cout << std::endl;

    return 0;
}
// *����������� main:)*
// #include <iostream>
// #include <locale> 
// #include <clocale> 
// #include "RedBlackTree.h" 

// int main() {
//     setlocale(LC_ALL, "Russian");
//     RedBlackTree tree; 

//     // ��������� �������� � ������
//     std::cout << "��������� �������� � ������: " << std::endl;
//     int elements[] = { 20, 15, 25, 10, 5, 1, 30, 35, 40 }; // ������ ��������� ��� �������
//     for (int el : elements) { // �������� �� ������� �������� �������
//         std::cout << "�������: " << el << std::endl; // ������� ��������� � �������
//         tree.insert(el); // ��������� ������� � ������
//     }

//     // ������� �������� ������ � ������� �����������
//     std::cout << "�������� ������ � ������� �����������: ";
//     tree.inorder(); // ����� ��� ������ ��������� ������ � ������� �����������
//     std::cout << std::endl;

//     // ������� �������� ����������� �������
//     std::cout << "�������� �������� ����������� �������: 20" << std::endl;
//     tree.insert(20); // ������������, ��� ����� insert ���������� ���������

//     // ������� �������� ������ ����� ������� ������� ���������
//     std::cout << "�������� ������ ����� ������� ������� ���������: ";
//     tree.inorder(); // ����� ������� �������� ������
//     std::cout << std::endl;

//     // ������� ��� ���������� ��������� ��� ������������
//     std::cout << "��������� �������������� ��������: 22, 18, 27" << std::endl;
//     tree.insert(22);
//     tree.insert(18); 
//     tree.insert(27); 

//     // ������� �������� ������ ����� �������������� �������
//     std::cout << "�������� ������ ����� �������������� �������: ";
//     tree.inorder(); 
//     std::cout << std::endl;

//     return 0; 
// }


