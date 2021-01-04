#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "StatData.generated.h"

USTRUCT(Atomic, BlueprintType)
struct PROJECTT_API FStatData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ToopTip = "레벨 당 증가량"))
	float HealthInc;
};