#include "SpaceInvadersProjectileBase.h"

ASpaceInvadersProjectileBase::ASpaceInvadersProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersProjectileBase's constructor called"));

	MeshComponent->SetWorldScale3D(FVector(1.0f, 0.1f, 1.0f));
}

void ASpaceInvadersProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector CurrentLocation = GetActorLocation();
	const FVector Velocity = GetActorForwardVector() * MovementSpeed * DeltaTime;
	SetActorLocation(CurrentLocation + Velocity);
}