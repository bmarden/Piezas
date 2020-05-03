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
