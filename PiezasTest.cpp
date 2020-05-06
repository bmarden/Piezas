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
    Piezas newGame;
    ASSERT_EQ(newGame.pieceAt(2, 4), Invalid);
}

TEST(PiezasTest, pieceAtRowOutOfRangePositive) {
    Piezas newGame;
    ASSERT_EQ(newGame.pieceAt(3, 2), Invalid);
}

TEST(PiezasTest, pieceAtColOutOfRangeNegative) {
    Piezas newGame;
    ASSERT_EQ(newGame.pieceAt(3, -1), Invalid);
}

TEST(PiezasTest, pieceAtRowOutOfRangeNegative) {
    Piezas newGame;
    ASSERT_EQ(newGame.pieceAt(-1, 2), Invalid);
}

TEST(PiezasTest, pieceAtReturnBlank1) {
    Piezas newGame;
    ASSERT_EQ(newGame.pieceAt(2, 3), Blank);
}

TEST(PiezasTest, pieceAtReturnBlank2) {
    Piezas newGame;
    ASSERT_EQ(newGame.pieceAt(2, 0), Blank);
}

TEST(PiezasTest, pieceAtReturnBlank3) {
    Piezas newGame;
    ASSERT_EQ(newGame.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, resetBoard) {
    Piezas newGame;
    newGame.reset();
    for (size_t i = 0; i < BOARD_ROWS; i++) {
        for (size_t j = 0; j < BOARD_COLS; j++) {
            ASSERT_EQ(newGame.pieceAt(i, j), Blank);
        }
    }
}

TEST(PiezasTest, dropPieceExpectO) {
    Piezas newGame;
    EXPECT_EQ(newGame.dropPiece(0), O);
}

TEST(PiezasTest, dropPieceExpectX) {
    Piezas newGame;
    newGame.dropPiece(1);
    EXPECT_EQ(newGame.dropPiece(2), X);
}

TEST(PiezasTest, dropPieceExpectO1) {
    Piezas newGame;
    newGame.dropPiece(3);
    newGame.dropPiece(3);
    EXPECT_EQ(newGame.dropPiece(2), O);
}

TEST(PiezasTest, dropPieceExpectedTurn) {
    Piezas newGame;
    EXPECT_EQ(newGame.dropPiece(3), O);
}

TEST(PiezasTest, dropPieceInvalidColumn) {
    Piezas newGame;
    ASSERT_EQ(newGame.dropPiece(4), Invalid);
    ASSERT_EQ(newGame.dropPiece(100), Invalid);
}

TEST(PiezasTest, dropPieceFullColumn) {
    Piezas newGame;
    newGame.dropPiece(0);
    newGame.dropPiece(0);
    newGame.dropPiece(0);
    ASSERT_EQ(newGame.dropPiece(0), Blank);
}

TEST(PiezasTest, dropPieceFullCol1) {
    Piezas newGame;
    newGame.dropPiece(1);
    newGame.dropPiece(1);
    newGame.dropPiece(1);
    ASSERT_EQ(newGame.dropPiece(1), Blank);
}

TEST(PiezasTest, dropPieceFullCol2) {
    Piezas newGame;
    newGame.dropPiece(2);
    newGame.dropPiece(2);
    newGame.dropPiece(2);
    ASSERT_EQ(newGame.dropPiece(2), Blank);
}
