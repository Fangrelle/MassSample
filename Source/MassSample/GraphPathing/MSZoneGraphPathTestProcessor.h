// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MSZoneGraphPathTestProcessor.generated.h"


struct FZoneGraphLaneLocation;
struct FZoneGraphLinkedLane;
struct FZoneGraphLaneHandle;


/**
 * This is an test processor(slows) that shows test paths on the ZoneGraph
 */
UCLASS()
class MASSSAMPLE_API UMSZoneGraphPathTestProcessor : public UMassProcessor
{
	GENERATED_BODY()

	
public:
	
	UMSZoneGraphPathTestProcessor();


	virtual void ConfigureQueries() override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;
	bool GetLaneClosestToTransform(FTransform InTransform, FZoneGraphLaneLocation& OutLaneLocation, float QueryMultiplier = 100.f);
	void DrawLineBetweenTwoPoints(FTransform FromTransform, FTransform ToTransform, FColor PathColor = FColor::Green, float LineThickness = 5.f);
	void DrawLineBetweenTwoPoints(FVector FromLocation, FVector ToLocation, FColor PathColor = FColor::Green, float LineThickness = 5.f);

	bool DFTFindPath(FZoneGraphLaneHandle& StartLaneLocationHandle, FZoneGraphLaneHandle& EndLaneLocationHandle, TArray<FZoneGraphLinkedLane>& OutPathLinkedLanes);
	bool DFT_ZoneGraph_Origin(FZoneGraphLaneHandle& StartLaneLocationHandle, FZoneGraphLaneHandle& EndLaneLocationHandle, TArray<FZoneGraphLinkedLane>& OutPathLinkedLanes, TSet<int>& InProgressLaneIndices);


	FMassEntityQuery FromQuery;

	FMassEntityQuery ToQuery;
};
