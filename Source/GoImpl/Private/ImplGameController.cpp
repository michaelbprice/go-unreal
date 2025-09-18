#include "ImplGameController.h"

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