#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders/Entities/SpaceInvadersEntity.h"
#include "SpaceInvadersPlayerShip.generated.h"

class ASpaceInvadersProjectileBase;

// Add delegate type declaration here
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShipHitDelegate);

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

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	// Add delegate declaration here
	FOnShipHitDelegate OnShipHit;
};