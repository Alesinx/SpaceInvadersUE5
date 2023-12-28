#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceInvadersEntity.generated.h"

class UBoxComponent;
class UMeshComponent;

/**
 * Common class to Space Invaders enemies, player ship and defenses.
 * Any entity will destroy itself when colliding with something.
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersEntity : public APawn
{
	GENERATED_BODY()
	
public:	
	ASpaceInvadersEntity();

	virtual void InitMeshComponent();
	virtual void InitCollisionComponent();

	void OnCollision();

private:
	UBoxComponent* CollisionComponent;
	UMeshComponent* MeshComponent;
};