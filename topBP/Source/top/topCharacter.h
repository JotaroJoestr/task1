// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "topCharacter.generated.h"

UCLASS(Blueprintable)
class AtopCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AtopCharacter();

	//projectile
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABullet*>ProjectileClass;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	
	UFUNCTION(Client, Reliable, BlueprintCallable)
		void ClientRPChit();

	UFUNCTION(Client, Reliable, BlueprintCallable)
		void ClientRPCfire();

	UPROPERTY(EditAnywhere, Category = "Location")
		FVector SpawnPoint;

	UPROPERTY(EditAnywhere)
		FVector BulletOffset;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	//fire
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};

