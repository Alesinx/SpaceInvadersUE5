#include "SpaceInvaders/SpaceInvadersPlayerView.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASpaceInvadersPlayerView::ASpaceInvadersPlayerView()
{
	PrimaryActorTick.bCanEverTick = false;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;
}