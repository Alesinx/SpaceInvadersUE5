#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceInvadersPlayerController.generated.h"

class ASpaceInvadersPlayerShip;
class ASpaceInvadersGameModeInGame;

/**
 * Space Invaders Player Controller
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASpaceInvadersPlayerController() = default;
	void SetupInputComponent() override;
	void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Space Invaders")
	float MovementSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Space Invaders")
	float FireRate = 0.5f;

private:
	UPROPERTY()
	ASpaceInvadersPlayerShip* PlayerShip;

	float LastFireTime = 0.0f;
	ASpaceInvadersGameModeInGame* GameMode = nullptr;

private:
	void InitializePlayerShip();
	void MovePlayerShip(float Direction);
	void Fire();
};