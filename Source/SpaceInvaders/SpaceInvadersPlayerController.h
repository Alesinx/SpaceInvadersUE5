#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceInvadersPlayerController.generated.h"

class ASpaceInvadersPlayerShip;

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
	float MovementSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Space Invaders")
	float MaxXLocation = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Space Invaders")
	float MinXLocation = 0.0f;

private:
	UPROPERTY()
	ASpaceInvadersPlayerShip* PlayerShip;

private:
	void InitializePlayerShip();
	void MovePlayerShip(float Amount);
	void Fire();
};