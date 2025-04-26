class CfgPatches {
    class Tenthed_Ammo {
        author = "Akira";
        name = "10th JTF: Ammo";
        requiredAddons[] = {
            "Tenthed_core"
        };
        weapons[] = {};
        units[] = {};
		ammo[] = {
			"Tenthed_SC_338_NM_Ball",
			"Tenthed_B_127x99_Ball_Tracer_Yellow",
			"Tenthed_B_127x40_NARQ_Ball"
		};
		magazines[] = {
			"Tenthed_SC_200Rnd_338_Mag",
			"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
			"Tenthed_6Rnd_127x40_Cyl_NARQ",
			"Tenthed_6Rnd_127x40_Cyl_NARQ_Tracer"
		};
    };
};
class CfgAmmo {
	class B_338_Ball;
	class Tenthed_SC_338_NM_Ball : B_338_Ball {
		hit = 14;
	};

	class B_127x99_Ball;
	class Tenthed_B_127x99_Ball_Tracer_Yellow : B_127x99_Ball {
		hit = 30;
	};

	class B_127x33_Ball;
	class Tenthed_B_127x40_NARQ_Ball: B_127x33_Ball {
		caliber=2;
		hit=0.1;
		typicalSpeed=620;
		cartridge="FxCartridge_small";
		model="\A3\Weapons_f\Data\bullettracer\tracer_red";
	};
};
class CfgMagazines {
	class 130Rnd_338_Mag;
	class Tenthed_SC_200Rnd_338_Mag : 130Rnd_338_Mag {
		scope = 2;
		displayName = "[10th] 200Rnd .338 Magazine";
		picture = "\A3\Weapons_F_Mark\Data\UI\M_338_NM_CA.paa";
		count = 200;
		ammo = "Tenthed_SC_338_NM_Ball";
		tracersEvery = 3;
		lastRoundsTracer = 20;
		descriptionshort = "Rounds: 200";
		mass = 75;
	};

	class 100Rnd_127x99_mag;
	class Tenthed_100Rnd_127x99_mag_Tracer_Yellow : Tenthed_SC_200Rnd_338_Mag {
		scope = 2;
		displayName = "[10th] 100Rnd 127x99 mag Tracer Yellow";
		picture = "\A3\Weapons_F_Mark\Data\UI\M_338_NM_CA.paa";
		count = 100;
		ammo = "Tenthed_B_127x99_Ball_Tracer_Yellow";
		tracersEvery = 3;
		lastRoundsTracer = 20;
		descriptionShort = "Rounds: 200<br/>Used in: [10th] HMG";
		displaynameshort = "100Rnd 127x99";
		mass = 75;
	};

	class 20Rnd_762x51_Mag;
	class Tenthed_6Rnd_127x40_Cyl_NARQ : 20Rnd_762x51_Mag {
		author="Akira";
		scope=2;
		scopeArsenal=2;
		ammo="Tenthed_B_127x40_NARQ_Ball";
		count=6;
		displayname="6Rnd 12.7x40mm NARQ Cylinder";
		displaynameshort="12.7x40mm NARQ";
		descriptionShort="6 Round Cylinder<br/>Caliber: 12.7x40mm<br/>Tranquilizer";
		initspeed=900;
		mass=4;
	};
	class Tenthed_6Rnd_127x40_Cyl_NARQ_Tracer : Tenthed_6Rnd_127x40_Cyl_NARQ {
		displayname="6Rnd 12.7x40mm NARQ Cylinder (Tracer)";
		displaynameshort="12.7x40mm NARQ Tracer";
		descriptionShort="6 Round Cylinder<br/>Caliber: 12.7x40mm<br/>Tranquilizer Tracers";
		tracersEvery=1;
	};
};
class cfgMagazineWells
{
	class PistolHeavy_01_45ACP{
		Tenthed_6Rnd_127x40[]=
		{
			"Tenthed_6Rnd_127x40_Cyl_NARQ",
			"Tenthed_6Rnd_127x40_Cyl_NARQ_Tracer"
		};
	};
};