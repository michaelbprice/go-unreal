#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "ImplPlayer.h"

#include "Board.hpp"

#include "ImplGameController.generated.h"

UCLASS(Blueprintable)
class UImplGameController : public UObject
{
public:
	GENERATED_BODY()

	UImplGameController();
	virtual ~UImplGameController();

	UFUNCTION(BlueprintCallable, Category = "Go|GameController")
	void Start();

	UFUNCTION(BlueprintCallable, Category = "Go|GameController")
	bool IsValidMoveFor(EPlayerColor color, int32 row, int32 column);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Go|GameController")
	UImplPlayer* BlackPlayer = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"), Category = "Go|GameController")
	UImplPlayer* WhitePlayer = nullptr;

private:
	Go::Board m_board;
};
