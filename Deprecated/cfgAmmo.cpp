// 10/17/2018 by Erik Kofahl

class CfgAmmo {
	class B_IRStrobe;
	class MS_IFF_Strobe:B_IRStrobe{
	    timeToLive = 18000;	//5 Hours
        aiAmmoUsageFlags = "2"; // Marking?
        //smokeColor[] = {0,0,0,0};									/Superfluous?
        effectsSmoke = "MS_IFF_Strobe_Effect";		//MOD THIS
	
	};

};