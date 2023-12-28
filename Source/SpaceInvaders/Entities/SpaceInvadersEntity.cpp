#include "SpaceInvadersEntity.h"
#include "Components/BoxComponent.h"
#include "Components/MeshComponent.h"

ASpaceInvadersEntity::ASpaceInvadersEntity()
{
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersEntity's construtor called"));
	InitMeshComponent();
	InitCollisionComponent();
}

void ASpaceInvadersEntity::InitMeshComponent()
{
	UStaticMeshComponent* cubeMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	UStaticMesh* cubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	cubeMeshComponent->SetStaticMesh(cubeMesh);
	RootComponent = cubeMeshComponent;
}

void ASpaceInvadersEntity::InitCollisionComponent()
{
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	if (CollisionComponent)
	{
		CollisionComponent->SetupAttachment(RootComponent);
	}
}

void ASpaceInvadersEntity::OnCollision()
{
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersEntity::OnCollision() called"));
	Destroy();
}