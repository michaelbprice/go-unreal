#include "ImplGameController.h"

#include "Stone.hpp"
#include "Point.hpp"

#include "ImplPlayer.h"

///////////////////////////////////////////////////

UImplGameController::UImplGameController() = default;
UImplGameController::~UImplGameController() = default;

void UImplGameController::Start()
{
	BlackPlayer->get().setGameBoard(m_board);
	BlackPlayer->get().setStoneColor(Go::StoneColor::BLACK);
	WhitePlayer->get().setGameBoard(m_board);
	WhitePlayer->get().setStoneColor(Go::StoneColor::WHITE);
}

bool UImplGameController::IsValidMoveFor(EPlayerColor color, int32 row, int32 column)
{
	Go::PointCoords coords{ static_cast<size_t>(row), static_cast<size_t>(column) };
	Go::StoneColor stone = color == EPlayerColor::BLACK ? Go::StoneColor::BLACK : Go::StoneColor::WHITE;
	bool isValid = m_board.isValidMove(stone, coords);
	UE_LOG(LogTemp, Warning, TEXT("Move at (%d, %d) for %s is %s"), row, column, color == EPlayerColor::BLACK ? TEXT("Black") : TEXT("White"), isValid ? TEXT("valid") : TEXT("invalid"));
	return isValid;
}