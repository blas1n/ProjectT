// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Loadable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULoadable : public UInterface
{
	GENERATED_BODY()
};

class PROJECTT_API ILoadable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsLoadAsync() const;

protected:
	virtual bool IsLoadAsync_Implementation() const noexcept;
};