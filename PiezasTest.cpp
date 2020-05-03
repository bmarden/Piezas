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

TEST(PiezasTest, pieceAtOutOfRange) {
    Piezas newGame;

    // Testing multiple out of range possibilties. All should return Invalid
    ASSERT_EQ(newGame.pieceAt(2, 4), Invalid);
    ASSERT_EQ(newGame.pieceAt(3, 2), Invalid);
    ASSERT_EQ(newGame.pieceAt(-1, 2), Invalid);
}

TEST(PiezasTest, pieceAtReturnValue) {
    Piezas newGame;

    ASSERT_EQ(newGame.pieceAt(2, 3), Blank);
    ASSERT_EQ(newGame.pieceAt(0, 0), Blank);
    ASSERT_EQ(newGame.pieceAt(0, 3), Blank);
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

TEST(PiezasTest, dropPieceExpectedTurn) {
    Piezas newGame;

    ASSERT_EQ(newGame.dropPiece(0), O);
    ASSERT_EQ(newGame.dropPiece(2), X);
    ASSERT_EQ(newGame.dropPiece(2), O);
    ASSERT_EQ(newGame.dropPiece(3), X);
}

TEST(PiezasTest, dropPieceInvalidColumn) {
    Piezas newGame;

    ASSERT_EQ(newGame.dropPiece(4), Invalid);
    ASSERT_EQ(newGame.dropPiece(5), Invalid);
    ASSERT_EQ(newGame.dropPiece(-1), Invalid);
    ASSERT_EQ(newGame.dropPiece(100), Invalid);
}

TEST(PiezasTest, dropPieceFullColumn) {
    Piezas newGame;

    newGame.dropPiece(0);
    newGame.dropPiece(0);
    newGame.dropPiece(0);
    ASSERT_EQ(newGame.dropPiece(0), Blank);
    newGame.dropPiece(1);
    newGame.dropPiece(1);
    newGame.dropPiece(1);
    ASSERT_EQ(newGame.dropPiece(1), Blank);
    newGame.dropPiece(2);
    newGame.dropPiece(2);
    newGame.dropPiece(2);
    ASSERT_EQ(newGame.dropPiece(2), Blank);
}
