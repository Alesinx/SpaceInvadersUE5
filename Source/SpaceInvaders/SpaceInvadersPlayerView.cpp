#include "SpaceInvaders/SpaceInvadersPlayerView.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASpaceInvadersPlayerView::ASpaceInvadersPlayerView()
{
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}

void ASpaceInvadersPlayerView::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector location = FVector(0, 0, 6000.0f);
	const FRotator rotation = FRotator(-90, 90, 0);
	SetActorLocationAndRotation(location, rotation);
}