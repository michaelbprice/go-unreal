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

