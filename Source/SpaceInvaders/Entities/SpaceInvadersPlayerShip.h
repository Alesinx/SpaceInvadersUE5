#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders/Entities/SpaceInvadersEntity.h"
#include "SpaceInvadersPlayerShip.generated.h"

/**
 * Class representing a space invaders player ship
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersPlayerShip : public ASpaceInvadersEntity
{
	GENERATED_BODY()

public:
	ASpaceInvadersPlayerShip();
	void Fire();
};