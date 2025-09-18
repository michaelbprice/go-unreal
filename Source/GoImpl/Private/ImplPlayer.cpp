#include "ImplPlayer.h"

#include "IPlayer.hpp"

///////////////////////////////////////////////////

UImplPlayer::UImplPlayer() = default;
UImplPlayer::~UImplPlayer() = default;

Go::IPlayer& UImplPlayer::get()
{
	if (!m_player)
	{
		m_player = std::make_unique<Go::Player<UnrealUI>>(std::string(TCHAR_TO_UTF8(*PlayerName)));
	}
	return *m_player;
}

void UImplPlayer::PlaceStoneAt(int32 row, int32 column)
{
	Go::PointCoords coords{ static_cast<size_t>(row), static_cast<size_t>(column) };
	get().placeStoneAt(coords);
	UE_LOG(LogTemp, Warning, TEXT("%s placed stone at (row: %d, column: %d)"), *PlayerName, row, column);
}