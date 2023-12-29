#include "SpaceInvadersEntity.h"
#include "Components/BoxComponent.h"
#include "Components/MeshComponent.h"

ASpaceInvadersEntity::ASpaceInvadersEntity()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersEntity's construtor called"));

	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	MeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	MeshComponent->SetGenerateOverlapEvents(true);

	UStaticMesh* CubeMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	MeshComponent->SetStaticMesh(CubeMesh);
	
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpaceInvadersEntity::OnOverlapBegin);
}

void ASpaceInvadersEntity::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersEntity::OnCollision() called"));
	Destroy();
}