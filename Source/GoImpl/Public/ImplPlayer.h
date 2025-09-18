#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Player.hpp"
#include "IPlayer.hpp"
#include "Stone.hpp"
#include "Point.hpp"

#include <memory>
#include <string>

#include "ImplPlayer.generated.h"

class UnrealUI
{
private:
	const Go::IPlayer& m_player;

public:
	UnrealUI(const Go::IPlayer& player)
		: m_player(player)
	{
	}

	void onInvalidMove(const Go::PointCoords&) {}
	void onWin() {}
	void onLoss() {}
	void onTie() {}

	Go::PointCoords promptForMove() { return Go::PointCoords{ 0, 0 }; }
	std::string promptForName() { return "Player"; }
	Go::StoneColor promptForStoneColor() { return Go::StoneColor::BLACK; }
	void updateGameState() {}
};

UCLASS(Blueprintable)
class UImplPlayer : public UObject
{
public:
	GENERATED_BODY()

	UImplPlayer();
	virtual ~UImplPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Go|Player")
	FString PlayerName = "Unknown";

	Go::IPlayer& get();

private:
	std::unique_ptr<Go::Player<UnrealUI>> m_player;
};
