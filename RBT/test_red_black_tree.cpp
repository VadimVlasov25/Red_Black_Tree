#include <gtest/gtest.h>
#include "RedBlackTree.h"

// ���� 1: �������� �������� ������� ������ � ������� ������� ��������
TEST(RedBlackTreeTest, CanCreateEmptyTree) {
    RedBlackTree tree;
    // ��������� ������ �������
    tree.insert(10);
    // ��������� ��� ������ ����������
    ASSERT_NE(tree.root, nullptr);
    // ��������� ��� ������ �������� ���������� ��������
    EXPECT_EQ(tree.root->data, 10);
    // ��������� ��� ������ ������ (�������� ������-������� ������)
    EXPECT_EQ(tree.root->color, BLACK);
}

// ���� 2: �������� ������� ������ ����
TEST(RedBlackTreeTest, InsertSingleNode) {
    RedBlackTree tree;
    tree.insert(25);
    // ��������� �������� �����
    EXPECT_EQ(tree.root->data, 25);
    // ��������� ���� �����
    EXPECT_EQ(tree.root->color, BLACK);
}

// ���� 3: �������� ������� ���������� ����� � �� ������
TEST(RedBlackTreeTest, InsertMultipleNodesColorsCheck) {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // ������ ������� ������� � ����������

    // ��������� ��� ������ ���� ������� ��������� (������������)
    EXPECT_EQ(tree.root->data, 20);
    // ������ ������ ���� ������
    EXPECT_EQ(tree.root->color, BLACK);
    // ����� �������
    EXPECT_EQ(tree.root->left->data, 10);
    EXPECT_EQ(tree.root->left->color, RED);
    // ������ �������
    EXPECT_EQ(tree.root->right->data, 30);
    EXPECT_EQ(tree.root->right->color, RED);
}

// ���� 4: �������� ������������ ������ inorder (������ �������� ��������������� ������������������)
TEST(RedBlackTreeTest, InorderTraversalOutputsSorted) {
    RedBlackTree tree;
    std::stringstream buffer;
    std::streambuf* oldcout = std::cout.rdbuf(buffer.rdbuf());

    // ��������� �������� � ������������ �������
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // ��������� �����
    tree.inorder();
    std::cout.rdbuf(oldcout);

    // ��������� ��� ����� ������������
    std::string output = buffer.str();
    EXPECT_EQ(output, "20 30 40 50 60 70 80 ");
}

// ���� 5: �������� ��� ������ ������ �������� ������ ����� �������
TEST(RedBlackTreeTest, RootAlwaysBlack) {
    RedBlackTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    EXPECT_EQ(tree.root->color, BLACK);
}

// ���� 6: �������� ��� ����� ������� ������ ��������
TEST(RedBlackTreeTest, LeftChildLessThanParent) {
    RedBlackTree tree;
    tree.insert(20);
    tree.insert(10);
    EXPECT_LT(tree.root->left->data, tree.root->data);
}

// ���� 7: �������� ��� ������ ������� ������ ��������
TEST(RedBlackTreeTest, RightChildGreaterThanParent) {
    RedBlackTree tree;
    tree.insert(20);
    tree.insert(30);
    EXPECT_GT(tree.root->right->data, tree.root->data);
}

// ���� 8: �������� �������� �������� (�����-������)
TEST(RedBlackTreeTest, DoubleRotationLeftRight) {
    RedBlackTree tree;
    tree.insert(30);
    tree.insert(10);
    tree.insert(20); // ������ ������� ������� �������
    // ��������� ��� ������ ���� ������� ���������
    EXPECT_EQ(tree.root->data, 20);
}

// ���� 9: �������� �������� �������� (������-�����)
TEST(RedBlackTreeTest, DoubleRotationRightLeft) {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(20); // ������ ������� ������� �������
    // ��������� ��� ������ ���� ������� ���������
    EXPECT_EQ(tree.root->data, 20);
}

// ���� 10: �������� ������������ ������ ��� �������� ������ ������
TEST(RedBlackTreeTest, TreeInorderCorrectness) {
    RedBlackTree tree;
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // ��������� �������� � ������������ �������
    for (int v : {40, 20, 60, 10, 30, 50, 70}) {
        tree.insert(v);
    }
    tree.inorder();

    std::cout.rdbuf(old);
    // ��������� ��� ����� ������������
    EXPECT_EQ(buffer.str(), "10 20 30 40 50 60 70 ");
}

// ���� 11: �������� ��������� ������ ����� ������������� �������
TEST(RedBlackTreeTest, DeepInsertionsAndStructure) {
    RedBlackTree tree;
    // ��������� 15 ���������������� ���������
    for (int i = 1; i <= 15; ++i)
        tree.insert(i);

    // ��������� ������� ��������
    EXPECT_EQ(tree.root->color, BLACK);
    EXPECT_TRUE(tree.root->left != nullptr);
    EXPECT_TRUE(tree.root->right != nullptr);
}


