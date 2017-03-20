/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};
TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(PiezasTest, constructorTest)
{
	Piezas t;
	ASSERT_EQ(Blank, t.pieceAt(0, 2));
}
TEST(PiezasTest, placeOnePiece)
{
	Piezas t;
	t.dropPiece(1);
	ASSERT_EQ(X, t.pieceAt(0, 1));
}
TEST(PiezasTest, placeTwoPiece)
{
	Piezas t;
	t.dropPiece(1);
	t.dropPiece(1);
	ASSERT_EQ(O, t.pieceAt(1, 1));
}
TEST(PiezasTest, placeThreePiece)
{
	Piezas t;
	t.dropPiece(1);
	t.dropPiece(1);
	t.dropPiece(1);
	ASSERT_EQ(X, t.pieceAt(2, 1));
}
TEST(PiezasTest, placeFourPiece)
{
	Piezas t;
	t.dropPiece(1);
	t.dropPiece(1);
	t.dropPiece(1);
	ASSERT_EQ(Blank, t.dropPiece(1));
}
TEST(PiezasTest, clearBoard)
{
	Piezas t;
	t.dropPiece(1);
	t.reset();
	ASSERT_EQ(O, t.dropPiece(1));
}
TEST(PiezasTest, invalidDropPiece)
{
	Piezas t;
	ASSERT_EQ(Invalid, t.dropPiece(-1));
}
TEST(PiezasTest, invalidDropPiece2)
{
	Piezas t;
	ASSERT_EQ(Invalid, t.dropPiece(4));
}
TEST(PiezasTest, invalidPieceAt)
{
	Piezas t;
	ASSERT_EQ(Invalid, t.pieceAt(-1, 0));
}
TEST(PiezasTest, invalidPieceAt2)
{
	Piezas t;
	ASSERT_EQ(Invalid, t.pieceAt(1, -1));
}
TEST(PiezasTest, invalidGameState)
{
	Piezas t;
	ASSERT_EQ(Invalid, t.gameState());
}
TEST(PiezasTest, xWinnerCols)
{
	Piezas t;
	t.dropPiece(0);
	t.dropPiece(3);
	t.dropPiece(0);
	t.dropPiece(2);
	t.dropPiece(0);
	t.dropPiece(1);
	t.dropPiece(1);
	t.dropPiece(1);
	t.dropPiece(2);
	t.dropPiece(2);
	t.dropPiece(3);
	t.dropPiece(3);
	ASSERT_EQ(X, t.gameState());
}
TEST(PiezasTest, equalXandO)
{
	Piezas t;
	t.dropPiece(0);
	t.dropPiece(0);
	t.dropPiece(0);
	t.dropPiece(1);
	t.dropPiece(1);
	t.dropPiece(1);
	t.dropPiece(2);
	t.dropPiece(2);
	t.dropPiece(2);
	t.dropPiece(3);
	t.dropPiece(3);
	t.dropPiece(3);
	ASSERT_EQ(Blank, t.gameState());
}
TEST(PiezasTest, OWinnerCols)
{
	Piezas t;
	t.dropPiece(0);
	t.dropPiece(0);
	t.dropPiece(0);
	t.dropPiece(2);
	t.dropPiece(3);
	t.dropPiece(3);
	t.dropPiece(3);
	t.dropPiece(2);
	t.dropPiece(1);
	t.dropPiece(1);
	t.dropPiece(2);
	t.dropPiece(1);
	ASSERT_EQ(O, t.gameState());
}
TEST(PiezasTest, XWinnerRows)
{
	Piezas t;
	t.dropPiece(0); //x
	t.dropPiece(1);
	t.dropPiece(0); //x
	t.dropPiece(1);
	t.dropPiece(0); //x
	t.dropPiece(2);
	t.dropPiece(3); //x
	t.dropPiece(3);
	t.dropPiece(2); //x
	t.dropPiece(2);
	t.dropPiece(1); //x
	t.dropPiece(3);
	ASSERT_EQ(X, t.gameState());
}
TEST(PiezasTest, OWinnerRows)
{
	Piezas t;
	t.dropPiece(0); //x
	t.dropPiece(1);
	t.dropPiece(0); //x
	t.dropPiece(1);
	t.dropPiece(3); //x
	t.dropPiece(2);
	t.dropPiece(2); //x
	t.dropPiece(1);
	t.dropPiece(3); //x
	t.dropPiece(3);
	t.dropPiece(2); //x
	t.dropPiece(0);
	ASSERT_EQ(O, t.gameState());
}
