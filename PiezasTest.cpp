/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>

#include "Piezas.h"

class PiezasTest : public ::testing::Test {
   protected:
    PiezasTest() {}             //constructor runs before each test
    virtual ~PiezasTest() {}    //destructor cleans up after tests
    virtual void SetUp() {}     //sets up before each test (after constructor)
    virtual void TearDown() {}  //clean up after each test, (before destructor)
};

TEST(PiezasTest, pieceAtColOutOfRangePositive) {
    Piezas p;
    ASSERT_EQ(p.pieceAt(2, 4), Invalid);
}

TEST(PiezasTest, pieceAtRowOutOfRangePositive) {
    Piezas p;
    ASSERT_EQ(p.pieceAt(3, 2), Invalid);
}

TEST(PiezasTest, pieceAtColOutOfRangeNegative) {
    Piezas p;
    ASSERT_EQ(p.pieceAt(3, -1), Invalid);
}

TEST(PiezasTest, pieceAtRowOutOfRangeNegative) {
    Piezas p;
    ASSERT_EQ(p.pieceAt(-1, 2), Invalid);
}

TEST(PiezasTest, pieceAtReturnBlank1) {
    Piezas p;
    ASSERT_EQ(p.pieceAt(2, 3), Blank);
}

TEST(PiezasTest, pieceAtReturnBlank2) {
    Piezas p;
    ASSERT_EQ(p.pieceAt(2, 0), Blank);
}

TEST(PiezasTest, pieceAtReturnBlank3) {
    Piezas p;
    ASSERT_EQ(p.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, resetBoard) {
    Piezas p;
    p.reset();
    for (size_t i = 0; i < BOARD_ROWS; i++) {
        for (size_t j = 0; j < BOARD_COLS; j++) {
            ASSERT_EQ(p.pieceAt(i, j), Blank);
        }
    }
}

TEST(PiezasTest, dropPieceExpectO) {
    Piezas p;
    EXPECT_EQ(p.dropPiece(0), O);
}

TEST(PiezasTest, dropPieceExpectX) {
    Piezas p;
    p.dropPiece(1);
    EXPECT_EQ(p.dropPiece(2), X);
}

TEST(PiezasTest, dropPieceExpectO1) {
    Piezas p;
    p.dropPiece(3);
    p.dropPiece(3);
    EXPECT_EQ(p.dropPiece(2), O);
}

TEST(PiezasTest, dropPieceExpectedTurn) {
    Piezas p;
    EXPECT_EQ(p.dropPiece(3), O);
}

TEST(PiezasTest, dropPieceInvalidColumn) {
    Piezas p;
    ASSERT_EQ(p.dropPiece(4), Invalid);
    ASSERT_EQ(p.dropPiece(100), Invalid);
}

TEST(PiezasTest, dropPieceFullColumn) {
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(0);
    ASSERT_EQ(p.dropPiece(0), Blank);
}

TEST(PiezasTest, dropPieceFullCol1) {
    Piezas p;
    p.dropPiece(1);
    p.dropPiece(1);
    p.dropPiece(1);
    ASSERT_EQ(p.dropPiece(1), Blank);
}

TEST(PiezasTest, dropPieceFullCol2) {
    Piezas p;
    p.dropPiece(2);
    p.dropPiece(2);
    p.dropPiece(2);
    ASSERT_EQ(p.dropPiece(2), Blank);
}

TEST(PiezasTest, dropPieceColValues) {
    Piezas p;
    p.dropPiece(0);
    p.dropPiece(0);
    p.dropPiece(0);
    EXPECT_EQ((char)p.pieceAt(0, 0), (char)X);
    EXPECT_EQ(p.pieceAt(1, 0), O);
    EXPECT_EQ(p.pieceAt(2, 0), X);
}

TEST(PiezasTest, gameStateGameIncomplete) {
    Piezas p;
    // Game Board
    /** 
     * 0 1 2 3
     * * * * *
     * * * * *
     * * * * * 
    **/
    ASSERT_EQ(p.gameState(), Invalid);
}

TEST(PiezasTest, gameStateGameIncomplete2) {
    Piezas p;

    // Game Board
    /** 
     * 0 1 2 3
     * * * * *
     * * * * *
     * X O X * 
    **/
    p.dropPiece(0);  // X
    p.dropPiece(1);  // O
    p.dropPiece(2);  // X
    ASSERT_EQ(p.gameState(), Invalid);
}

TEST(PiezasTest, gameStateXWinsbyRows) {
    Piezas p;

    // Game Board
    /** 
     * 0 1 2 3
     * O O X O
     * O O X O
     * X X X X 
    **/
    p.dropPiece(0);  // X
    p.dropPiece(0);  // O
    p.dropPiece(1);  // X
    p.dropPiece(0);  // O
    p.dropPiece(2);  // X
    p.dropPiece(1);  // O
    p.dropPiece(3);  // X
    p.dropPiece(1);  // O
    p.dropPiece(2);  // X
    p.dropPiece(3);  // O
    p.dropPiece(2);  // X
    p.dropPiece(3);  // O
    ASSERT_EQ((char)p.gameState(), (char)X);
}

TEST(PiezasTest, gameStateOWinsbyRows) {
    Piezas p;

    // Game Board
    /** 
     * 0 1 2 3
     * O O O O
     * X O X X
     * X O X X 
    **/
    p.dropPiece(0);  // X
    p.dropPiece(1);  // O
    p.dropPiece(2);  // X
    p.dropPiece(1);  // O
    p.dropPiece(3);  // X
    p.dropPiece(1);  // O
    p.dropPiece(0);  // X
    p.dropPiece(0);  // O
    p.dropPiece(2);  // X
    p.dropPiece(2);  // O
    p.dropPiece(3);  // X
    p.dropPiece(3);  // O

    ASSERT_EQ((char)p.gameState(), (char)O);
}

TEST(PiezasTest, gameStateXWinsbyCols) {
    Piezas p;
    // Game Board
    /** 
     * 0 1 2 3
     * O X X O
     * O X O X
     * X X O O 
    **/

    p.dropPiece(0);  // X
    p.dropPiece(0);  // O
    p.dropPiece(1);  // X
    p.dropPiece(0);  // O
    p.dropPiece(1);  // X
    p.dropPiece(2);  // O
    p.dropPiece(1);  // X
    p.dropPiece(2);  // O
    p.dropPiece(2);  // X
    p.dropPiece(3);  // O
    p.dropPiece(3);  // X
    p.dropPiece(3);  // O

    ASSERT_EQ((char)p.gameState(), (char)X);
}