#pragma once

#include "CoreMinimal.h"
#include "SpaceInvadersEntity.h"
#include "SpaceInvadersMoveable.generated.h"

/**
 * Common class to Space Invaders enemies and player ship in charge of handling the movement
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersMoveable : public ASpaceInvadersEntity
{
	GENERATED_BODY()

public:
	ASpaceInvadersMoveable();

public:
	float MovementStepX = 5.0f;
	float MovementStepY = 5.0f;
	float MaxXLocation = 100.0f;
	float MinXLocation = 0.0f;
	float MaxYLocation = 100.0f;
	float MinYLocation = 0.0f;

public:
	void MoveRight();
	void MoveLeft();

protected:
	void Move(float OffsetX, float OffsetY);
};
