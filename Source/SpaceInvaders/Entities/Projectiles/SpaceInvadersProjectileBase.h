#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceInvaders/Entities/SpaceInvadersEntity.h"
#include "SpaceInvadersProjectileBase.generated.h"

/**
 * Class representing a projectile. Probably not actually used in the current scope of the project, but still a nice class to have when things scale up
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersProjectileBase : public ASpaceInvadersEntity
{
	GENERATED_BODY()
	
public:	
	ASpaceInvadersProjectileBase();

protected:
	UPROPERTY()
	float MovementSpeed = 1000.0f;

protected:
	virtual void Tick(float DeltaTime) override;
};