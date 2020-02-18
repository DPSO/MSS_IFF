//11/11/2018 by Erik Kofahl

/*
2019-02-09 - Added new model
*/

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
		
		//requiredAddons[] = {"A3_Functions_F", "A3_Weapons_F","A3_Weapons_F_EPB", "ace_main","ace_attach"};
		requiredAddons[] = {"A3_Functions_F", "A3_Weapons_F","A3_Weapons_F_EPB"};
		
		
		// List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content unlocking.
		units[] = {};
		// List of weapons (CfgWeapons classes) contained in the addon.
		weapons[] = {"Throw"};
		//magazines[] = {"MS_IFF_Mag"};	//Old method
		magazines[]={"B_IR_Grenade", "MS_Strobe_Mag_1", "MS_Strobe_Mag_2"};
		//ammo[] = {"IFF_MS_Ammo"};		//Old method
		ammo[]={"B_IRstrobe",  "IRStrobeBase", "GrenadeCore", "MS_Strobe_Ammo_1", "MS_Strobe_Ammo_2"};
		

	};
};


class cfgAmmo
{
	
	class IRStrobeBase;
	class B_IRstrobe:IRStrobeBase
	{
		timeToLive = 18000;	
	};
	
	class MS_Strobe_Ammo_1: B_IRstrobe
	{
		
		hit = 0;
		indirectHit=0;
		explosionTime=0;				
		explosionEffects="CE_MS_IFF_Effect_1";		//This is the only one that's worked so far 
		mintimetolive=18000;
		explosive = 1; //Needs to be 1 to work at all so far
		effectFly = "CE_MS_IFF_Effect_1";		//This appears to be the only effect that works for attaching items via ACE
		craterEffects = "";
		craterWaterEffects = "";
		model="MS_IFF_Strobe\MS_IFF.p3d";
		fuseDistance = 1e11;	//added 2019-02-09 to resolve A2 trees knocking strobes off


	};
	
	class MS_Strobe_Ammo_2:MS_Strobe_Ammo_1
	{
		explosionEffects="CE_MS_IFF_Effect_2";		//This is the only one that's worked so far 
		effectFly = "CE_MS_IFF_Effect_2";		//This appears to be the only effect that works for attaching items via ACE
	};
};


class CfgMagazines
{

	class CA_Magazine;
	class B_IR_Grenade: CA_Magazine
	{
		mass = 0.5;	
	};
	
	class MS_Strobe_Mag_1:B_IR_Grenade
	{
		ammo = "MS_Strobe_Ammo_1";
		ACE_Attachable = "MS_Strobe_Ammo_1";
		author = "Fat_Lurch";
		displayname = "MS IFF Strobe -1";
		descriptionShort = "Multispectral IFF Strobe (1 Pulse)";
		displayNameShort = "MS IFF Strobe -1";
		mass = 0.5;
		model="\MS_IFF_Strobe\MS_IFF.p3d";
		picture="\MS_IFF_Strobe\data\gear_MS_IFF_Strobe_ca.paa";
	};
	class MS_Strobe_Mag_2:MS_Strobe_Mag_1
	{
		ammo = "MS_Strobe_Ammo_2";
		ACE_Attachable = "MS_Strobe_Ammo_2";
		displayname = "MS IFF Strobe -2";
		descriptionShort = "Multispectral IFF Strobe (2 Pulse)";
		displayNameShort = "MS IFF Strobe -2";
	};

};

class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		muzzles[] += {"MS_IFF_Muzzle_1","MS_IFF_Muzzle_2"};
		class ThrowMuzzle;
		class MS_IFF_Muzzle_1: ThrowMuzzle
		{
			magazines[] = {"MS_Strobe_Mag_1"};
		};
		class MS_IFF_Muzzle_2: ThrowMuzzle
		{
			magazines[] = {"MS_Strobe_Mag_2"};
		};
	};
};

class CE_MS_IFF_Effect_1
{
   class MWIR
   {
       simulation = "particles";   //type of simulation - particles or light
       type = "MWIR_Effect_1Fast";           //name of PE's class defined in CfgCloudlets or light's class defined in CfgLights
       position[] = {0, 0, 0};     //position related to the default position or memorypoint
       lifeTime = 18000            //life time of emitter
 
       qualityLevel = -1;          // effect is only used when the the particle quality option particlesQuality in user settings matches this qualityLevel. -1 play everytime, 0 play only on low, 1 play only on normal, 2 play only on high. Default: -1
       start = 1;                  //is used only if the lifeTime parameter is defined, if value is changed from negative to positive then the effect is triggered
       enabled = 1;                //1 effect is enabled, -1 effect is disabled
   };
   	
};

class CE_MS_IFF_Effect_2
{
   class MWIR
   {
       simulation = "particles";   //type of simulation - particles or light
       type = "MWIR_Effect_2Fast";           //name of PE's class defined in CfgCloudlets or light's class defined in CfgLights
       position[] = {0, 0, 0};     //position related to the default position or memorypoint
       lifeTime = 18000            //life time of emitter
 
       qualityLevel = -1;          // effect is only used when the the particle quality option particlesQuality in user settings matches this qualityLevel. -1 play everytime, 0 play only on low, 1 play only on normal, 2 play only on high. Default: -1
       start = 1;                  //is used only if the lifeTime parameter is defined, if value is changed from negative to positive then the effect is triggered
       enabled = 1;                //1 effect is enabled, -1 effect is disabled
   };
   	
};


class CfgCloudlets		//two fast blinks
{
	class MWIR_Effect_2Fast
	{
		 //sizeCoef = "0.5 * speedSize + 0.5"; 
		sizeCoef = 1;
		size[] = {1,1};
		
		
		interval =  1.5;
		CircleRadius = 0;
		CircleVelocity[] = {0,0,0};
		particleShape ="\A3\data_f\cl_exp";
		particleFSNtieth =1;
		particleFSIndex =0;
		particleFSFrameCount =1;
		particleFSLoop =1;			//this was 0 on 10/23
		angle =0;
		angleVar =180;
		animationName = "";
		particleType = "Billboard";	             
		timerPeriod = 0 ;			    
		lifeTime = 0.5;			     
		moveVelocity[] = {0, 0, 0};	             
		rotationVelocity = 0;		   
		weight = 10;			             
		volume = 7.9;			            
		rubbing = 0;			  
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
		
		color[] = {{0, 0, 0, 1000000000},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 1000000000}}; 
		 
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;	
		onTimerScript = "";	
		beforeDestroyScript = "";
	};
		
	class MWIR_Effect_1Fast:MWIR_Effect_2Fast
	{
		size[] = {"1"};	
		lifeTime = 0.08;	
		interval =  1.5;
		color[] = {{0, 0, 0, 1000000000}}; 
		
	};
		

};




