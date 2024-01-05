#include "SpaceInvaders/SpaceInvadersPlayerView.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASpaceInvadersPlayerView::ASpaceInvadersPlayerView()
{
	PrimaryActorTick.bCanEverTick = false;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	CameraComponent->OrthoWidth = 10000.0f;
}