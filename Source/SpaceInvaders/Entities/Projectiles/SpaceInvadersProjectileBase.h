#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceInvaders/Entities/SpaceInvadersEntity.h"
#include "SpaceInvadersProjectileBase.generated.h"

UCLASS()
class SPACEINVADERS_API ASpaceInvadersProjectileBase : public ASpaceInvadersEntity
{
	GENERATED_BODY()
	
public:	
	ASpaceInvadersProjectileBase();
};