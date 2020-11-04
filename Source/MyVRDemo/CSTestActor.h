// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlockingComputeShaderObj.h"
#include "CSTestActor.generated.h"

//used to apply compute shader and update renderTarget
UCLASS()
class MYVRDEMO_API ACSTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACSTestActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		class UTextureRenderTarget2D* VelocityRenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		class UTextureRenderTarget2D* PositionRenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		FVector RangeMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		FVector RangeMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		float SeparationForceScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		float CohesionForceScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		float AlignForceScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		class UTextureRenderTarget* myTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		TArray<AActor*> actorList;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	TArray<FFloat16Color> ColorBuffer16;
	class FTextureRenderTarget2DResource* textureResource;
	//FVector v = FVector(0, 0, 0);
	FlockingComputeShaderObj shaderObj;
};
