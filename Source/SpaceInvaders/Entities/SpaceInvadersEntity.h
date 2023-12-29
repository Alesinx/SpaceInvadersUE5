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
class SPACEINVADERS_API ASpaceInvadersEntity : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpaceInvadersEntity();

protected:
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UStaticMeshComponent* MeshComponent;
};