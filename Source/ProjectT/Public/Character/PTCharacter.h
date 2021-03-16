// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Character.h"
#include "Interface/Initializable.h"
#include "PTCharacter.generated.h"

UCLASS(config=Game)
class PROJECTT_API APTCharacter final : public ACharacter, public IInitializable
{
	GENERATED_BODY()

public:
	APTCharacter(const FObjectInitializer& ObjectInitializer);

	float TakeDamage(float Damage, const FDamageEvent& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

	FORCEINLINE FVector GetPawnViewLocation() const override { return GetViewLocation(); }
	FORCEINLINE class UHookComponent* GetHookComponent() const noexcept { return HookComp; }
	FORCEINLINE class UWeaponComponent* GetWeaponComponent() const noexcept { return WeaponComp; }
	FORCEINLINE class UStaticMeshComponent* GetWeaponMeshComponent() const noexcept { return WeaponMeshComp; }

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	FVector GetViewLocation() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	float DamageToKnockback(float Damage) const;

private:
	void BeginPlay() override;
	void OnInitialize(int32 Key) override;

	void OnGetData(const struct FCharacterData& Data);

	UFUNCTION()
	void OnHit(AActor* DamagedActor, float Damage, const UDamageType*
		DamageType, AController* InstigatedBy, AActor* DamageCauser);

	FORCEINLINE FVector GetViewLocation_Implementation() const { return Super::GetPawnViewLocation(); }
	FORCEINLINE bool IsLoadAsync_Implementation() const noexcept override { return bLoadAsync; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component, meta = (AllowPrivateAccess = true))
	UHookComponent* HookComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component, meta = (AllowPrivateAccess = true))
	UWeaponComponent* WeaponComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Component, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* WeaponMeshComp;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UDataTable> CharacterDataTable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	float BackPercent;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = true))
	uint8 bLoadAsync : 1;
};
