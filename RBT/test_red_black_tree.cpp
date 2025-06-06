#include <gtest/gtest.h>
#include "RedBlackTree.h"

// Тест 1: Проверка создания пустого дерева и вставки первого элемента
TEST(RedBlackTreeTest, CanCreateEmptyTree) {
    RedBlackTree tree;
    // Вставляем первый элемент
    tree.insert(10);
    // Проверяем что корень существует
    ASSERT_NE(tree.root, nullptr);
    // Проверяем что корень содержит правильное значение
    EXPECT_EQ(tree.root->data, 10);
    // Проверяем что корень черный (свойство красно-черного дерева)
    EXPECT_EQ(tree.root->color, BLACK);
}

// Тест 2: Проверка вставки одного узла
TEST(RedBlackTreeTest, InsertSingleNode) {
    RedBlackTree tree;
    tree.insert(25);
    // Проверяем значение корня
    EXPECT_EQ(tree.root->data, 25);
    // Проверяем цвет корня
    EXPECT_EQ(tree.root->color, BLACK);
}

// Тест 3: Проверка вставки нескольких узлов и их цветов
TEST(RedBlackTreeTest, InsertMultipleNodesColorsCheck) {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // Должно вызвать поворот и перекраску

    // Проверяем что корень стал средним значением (балансировка)
    EXPECT_EQ(tree.root->data, 20);
    // Корень должен быть черным
    EXPECT_EQ(tree.root->color, BLACK);
    // Левый потомок
    EXPECT_EQ(tree.root->left->data, 10);
    EXPECT_EQ(tree.root->left->color, RED);
    // Правый потомок
    EXPECT_EQ(tree.root->right->data, 30);
    EXPECT_EQ(tree.root->right->color, RED);
}

// Тест 4: Проверка корректности обхода inorder (должен выводить отсортированную последовательность)
TEST(RedBlackTreeTest, InorderTraversalOutputsSorted) {
    RedBlackTree tree;
    std::stringstream buffer;
    std::streambuf* oldcout = std::cout.rdbuf(buffer.rdbuf());

    // Вставляем элементы в произвольном порядке
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Выполняем обход
    tree.inorder();
    std::cout.rdbuf(oldcout);

    // Проверяем что вывод отсортирован
    std::string output = buffer.str();
    EXPECT_EQ(output, "20 30 40 50 60 70 80 ");
}

// Тест 5: Проверка что корень всегда остается черным после вставок
TEST(RedBlackTreeTest, RootAlwaysBlack) {
    RedBlackTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    EXPECT_EQ(tree.root->color, BLACK);
}

// Тест 6: Проверка что левый потомок меньше родителя
TEST(RedBlackTreeTest, LeftChildLessThanParent) {
    RedBlackTree tree;
    tree.insert(20);
    tree.insert(10);
    EXPECT_LT(tree.root->left->data, tree.root->data);
}

// Тест 7: Проверка что правый потомок больше родителя
TEST(RedBlackTreeTest, RightChildGreaterThanParent) {
    RedBlackTree tree;
    tree.insert(20);
    tree.insert(30);
    EXPECT_GT(tree.root->right->data, tree.root->data);
}

// Тест 8: Проверка двойного поворота (левый-правый)
TEST(RedBlackTreeTest, DoubleRotationLeftRight) {
    RedBlackTree tree;
    tree.insert(30);
    tree.insert(10);
    tree.insert(20); // Должен вызвать двойной поворот
    // Проверяем что корень стал средним значением
    EXPECT_EQ(tree.root->data, 20);
}

// Тест 9: Проверка двойного поворота (правый-левый)
TEST(RedBlackTreeTest, DoubleRotationRightLeft) {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(20); // Должен вызвать двойной поворот
    // Проверяем что корень стал средним значением
    EXPECT_EQ(tree.root->data, 20);
}

// Тест 10: Проверка корректности обхода для большего набора данных
TEST(RedBlackTreeTest, TreeInorderCorrectness) {
    RedBlackTree tree;
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // Вставляем элементы в произвольном порядке
    for (int v : {40, 20, 60, 10, 30, 50, 70}) {
        tree.insert(v);
    }
    tree.inorder();

    std::cout.rdbuf(old);
    // Проверяем что вывод отсортирован
    EXPECT_EQ(buffer.str(), "10 20 30 40 50 60 70 ");
}

// Тест 11: Проверка структуры дерева после множественных вставок
TEST(RedBlackTreeTest, DeepInsertionsAndStructure) {
    RedBlackTree tree;
    // Вставляем 15 последовательных элементов
    for (int i = 1; i <= 15; ++i)
        tree.insert(i);

    // Проверяем базовые свойства
    EXPECT_EQ(tree.root->color, BLACK);
    EXPECT_TRUE(tree.root->left != nullptr);
    EXPECT_TRUE(tree.root->right != nullptr);
}


