// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"

#include "ZoneGraphTypes.h"

#include "MSPathFindingProcessor.generated.h"


struct FZoneGraphLaneLocation;
struct FZoneGraphLinkedLane;
struct FZoneGraphLaneHandle;



/**
 * 
 */
UCLASS()
class MASSSAMPLE_API UMSPathFindingProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	
	UMSPathFindingProcessor();


	virtual void ConfigureQueries() override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;
	bool GetLaneClosestToTransform(FTransform InTransform, FZoneGraphLaneLocation& OutLaneLocation, float QueryMultiplier = 100.f);
	void DrawLineBetweenTwoPoints(FTransform FromTransform, FTransform ToTransform, FColor PathColor = FColor::Green, float LineThickness = 5.f, float LifeTime = 30.f);
	void DrawLineBetweenTwoPoints(FVector FromLocation, FVector ToLocation, FColor PathColor = FColor::Green, float LineThickness = 5.f, float LifeTime = 30.f);
	void DebugShowLane(FZoneGraphDataHandle& DataHandle ,TMap<int, int> OutPathLinkedLanes);
	bool FindAStarPath(FZoneGraphLaneLocation& StartLaneLocationHandle, FZoneGraphLaneLocation& EndLaneLocationHandle, TMap<int, int>& OutPathLinkedLanes);

	bool DFTFindPath(FZoneGraphLaneHandle& StartLaneLocationHandle, FZoneGraphLaneHandle& EndLaneLocationHandle, TMap<int, int>& OutPathLinkedLanes);
	bool DFT_ZoneGraph_Origin(FZoneGraphLaneHandle& StartLaneLocationHandle, FZoneGraphLaneHandle& EndLaneLocationHandle, TMap<int, int>& OutPathLinkedLanes, TSet<int>& InProgressLaneIndices);


	FMassEntityQuery FromQuery;

	FMassEntityQuery ToQuery;
	
};