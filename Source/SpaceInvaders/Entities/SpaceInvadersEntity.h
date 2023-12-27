#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceInvadersEntity.generated.h"

class UBoxComponent;
class UMeshComponent;

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