#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders/Entities/SpaceInvadersEntity.h"
#include "SpaceInvadersPlayerShip.generated.h"

class ASpaceInvadersProjectileBase;

/**
 * Class representing a space invaders player ship
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersPlayerShip : public ASpaceInvadersEntity
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Space Invaders")
	FVector ProjectileOffset = FVector(0.0f, 100.0f, 0.0f);

public:
	ASpaceInvadersPlayerShip();

	UFUNCTION()
	void Fire();
};