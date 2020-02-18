//10/17/2018 bt Erik Kofahl

class CfgPatches
{
	class MS_IFF_Addon
	{
		// Meta information for editor
		name = "Multispectral IFF Strobes";
		author = "Fat_Lurch";

		// Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game.
		requiredVersion = 1.60; 
		// Required addons, used for setting load order.
		// When any of the addons is missing, pop-up warning will appear when launching the game.
		requiredAddons[] = {"A3_Functions_F", "ace_main", "ace_attach"};
		// List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content unlocking.
		units[] = {};
		// List of weapons (CfgWeapons classes) contained in the addon.
		weapons[] = {"ACE_ItemCore", "CBA_MiscItem_ItemInfo", "ACE_IR_Strobe_Item"};
	};
};


/*
class cfgAmmo
{
	class IRStrobeBase;
	class B_IRStrobe:IRStrobeBase
	{
			//The items commented out below didn't work
			
			//effectsSmoke = "CE_MS_IFF_Effect";
			//effectsSmoke = "MS_IFF_Effect";
			effectsSmoke = "ComplexEffect";
			
			explosionEffects = "MS_IFF_Effect";
			//effectFlare = "MS_IFF_Effect";
			//effectFly = "MS_IFF_Effect";
			//effectsFire = "CE_MS_IFF_Effect";
			//effectsMissile = "MS_IFF_Effect";
			//effectsMissileInit = "MS_IFF_Effect";
			
			animated = 1;	
			
			//Simulation =  "MS_IFF_Effect";		//Next to try
				
			Timetolive = 18000;
	};
};



class cfgMagazines
{
	class B_IR_Grenade
	{
		selectionFireAnim = "MS_IFF_Effect";
	};
};

*/

class ComplexEffect
{
   class CE_MS_IFF_Effect
   {
       simulation = "particles";   //type of simulation - particles or light
       type = "MS_IFF_Effect";           //name of PE's class defined in CfgCloudlets or light's class defined in CfgLights
       position[] = {0, 0, 0};     //position related to the default position or memorypoint
       lifeTime = 18000            //life time of emitter
 
       qualityLevel = -1;          // effect is only used when the the particle quality option particlesQuality in user settings matches this qualityLevel. -1 play everytime, 0 play only on low, 1 play only on normal, 2 play only on high. Default: -1
       start = 1;                  //is used only if the lifeTime parameter is defined, if value is changed from negative to positive then the effect is triggered
       enabled = 1;                //1 effect is enabled, -1 effect is disabled
   };
   
   /*
	class All;
	class ACE_IR_Strobe_Effect: All
	{
		//Nothing here
	};
	*/
	
};

class CfgWeapons
{
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;
	class ACE_IR_Strobe_Item: ACE_ItemCore
	{
		//ACE_attachable = "CE_MS_IFF_Effect";	Didn't work
		//ACE_attachable = "MS_IFF_Effect";			Didn't work
	};
};


class CfgCloudlets
{

	class MS_IFF_Effect
	{

		 interval =  1.5;
		 CircleRadius = 0;
		 CircleVelocity[] = {0,0,0};
		 particleShape ="\A3\data_f\cl_exp";
		 particleFSNtieth =1;
		 particleFSIndex =0;
		 particleFSFrameCount =1;
		 particleFSLoop =0;
		 angle =0;
		 angleVar =0;
		 animationName = "";
		 particleType = "Billboard";	             
		 timerPeriod = 0.05 ;			    
		 lifeTime = 0.5;			     
		 moveVelocity[] = {0, 0, 0};	             
		 rotationVelocity = 0;		   
		 weight = 10;			             
		 volume = 7.9;			            
		 rubbing = 0.075;			  
		 size[] = {1,1};			       
		 animationSpeed[] = {1};		    	   
		 lifeTimeVar = 0;			     
		 positionVar[] = {0, 0, 0};		   
		 positionVarConst[] = {0, 0, 0};	    
		 moveVelocityVar[] = {0, 0, 0};	  
		 moveVelocityVarConst[] = {0, 0, 0};     
		 rotationVelocityVar = 0;		    
		 sizeVar = 0;			     
		 colorVar[] = {0, 0, 0, 0};		     
		 randomDirectionPeriodVar = 0;	   
		 randomDirectionIntensityVar = 0;	   
		 sizeCoef = 1;                            
		 colorCoef[]={0,0,0,1};                   
		 animationSpeedCoef = 1;                  
		 destroyOnWaterSurface = 0;               
		 destroyOnWaterSurfaceOffset = 0;        
		 onSurface = true;                        
		 keepOnSurface = false;                   
		 surfaceOffset = 0;                     
		 bounceOnSurface = 0.6;                   
		 bounceOnSurfaceVar = 0.0;               
		 postEffects = "";           
		 particleEffects = "";
		 position[] = {0, 0, 0}; 
		 
		 color[] = {{0, 0, 0, 255},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 255}}; 
		 
		 randomDirectionPeriod = 0;
		 randomDirectionIntensity = 0;	
		 onTimerScript = "";	
		 beforeDestroyScript = "";

	};

};
