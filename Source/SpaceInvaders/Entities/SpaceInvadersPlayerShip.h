#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders/Entities/SpaceInvadersMoveable.h"
#include "SpaceInvadersPlayerShip.generated.h"

/**
 * Class representing a space invaders player ship
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersPlayersShip : public ASpaceInvadersMoveable
{
	GENERATED_BODY()

	public:
		ASpaceInvadersPlayersShip();

		void MoveLeft();
		void MoveRight();
};