// Copyright Andrew Baker 2016

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
			
private:
	UPROPERTY(EditAnywhere)
	float Reach = 100.0f;

	UPROPERTY(EditAnywhere)
	bool bDrawDebugLine = true;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* Input = nullptr;

	FVector PawnLocation;
	FRotator PawnRotator;

	void UpdateTransformData();

	void Grab();

	void Release();

	void GetPhysicsHandle();

	void GetInput();

	const FHitResult GetFirstPhysicsObjectFromTrace();

	const FVector GetLineTraceEnd();
};
