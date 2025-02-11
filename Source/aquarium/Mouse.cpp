// Fill out your copyright notice in the Description page of Project Settings.


#include "Mouse.h"

// Sets default values
AMouse::AMouse()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMouse::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerControllerRef = Cast<APlayerController>(GetController());
}

// Called every frame
void AMouse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControllerRef)
    {
        FHitResult HitResult;
        PlayerControllerRef->GetHitResultUnderCursor(
            ECollisionChannel::ECC_Visibility,
            false,
            HitResult); 
        
        DrawDebugSphere(
            GetWorld(), 
            HitResult.ImpactPoint,
            25.f,
            12,
            FColor::Red,
            false,
            -1.f);
    }
}

// Called to bind functionality to input
void AMouse::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

