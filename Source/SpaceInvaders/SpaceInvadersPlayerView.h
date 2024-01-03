#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceInvadersPlayerView.generated.h"

class UCameraComponent;

UCLASS()
class SPACEINVADERS_API ASpaceInvadersPlayerView : public APawn
{
	GENERATED_BODY()

public:
	ASpaceInvadersPlayerView();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Space Invaders")
	class UCameraComponent* CameraComponent;
};
