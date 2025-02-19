class CfgPatches {
	class Tenthed_AutoTurretBackpack {
        author = "Akira";
        name = "10th JTF: Auto Turret";
        requiredAddons[] = {
			"Tenthed_core",
			"Tenthed_turrets",
			"A3_Data_F",
			"A3Data",
			"A3_Weapons_F",
			"A3_Weapons_F_Mark",
			"cba_common",
			"cba_arrays",
			"cba_accessory",
			"cba_main",
			"cba_main_a3",
			"cba_modules"
        };
		units[] = {};
		weapons[] = {};
	};
};

class assembleInfo;
class Turrets;
class MainTurret;
class RCWSOptics;

class CfgVehicles {
	
	class B_HMG_01_F;
	class Weapon_Bag_Base;
	class Tenthed_Turret_Bag : Weapon_Bag_Base {
		//model="MA_Armor\data\Backpacks\ODST_Rucksack\ODST_Ruck.p3d";
		//picture="MA_Armor\data\Icons\ODST_Rucksack.paa";
		//hiddenSelections[]= {
		//	"camo1",
		//	"camo2",
		//	"Radio"
		//};
		//hiddenSelectionsTextures[]= {
		//	"MA_Armor\data\Backpacks\ODST_Rucksack\ODST_Ruck_co.paa",
		//	"MA_Armor\data\Backpacks\ODST_Rucksack\Attachments\Backpack_Radio_Green_co.paa"
		//};
		faction = "BLU_F";
		mass = 240;
		_generalMacro = "Tenthed_Turret_Bag";
		displayName = "[10th] The Bag";
		scope = 1;
		scopeArsenal = 1;
		class AssembleInfo : AssembleInfo {
			displayName = "Mk30 HMG .50";
			assembleTo = "Tenthed_HMG_02_F_Auto";
			base[] = {""};
		};
	};

	class Tenthed_HMG_02_F_Auto : B_HMG_01_F {
		displayName = "[10th] M2A HMG .50 Auto";
		
		sensitivity = 8;
		scopeCurator = 2;
		scope = 2;
		faction = "BLU_F"; // IND_F | BLU_F
		isUav = 1;
		crew = "B_UAV_AI"; // I_UAV_AI | B_UAV_AI
		typicalCargo[] = {};
		
		class AssembleInfo : AssembleInfo {
			displayName = "[10th] M2A HMG .50 Auto";
			assembleTo = "";
			primary = 0;
			base[] = {""};
			dissasembleTo[] = {"Tenthed_HMG_02_F_Bag_Auto"};
		};
	};
	
	class Tenthed_HMG_02_F_Bag_Auto : Tenthed_Turret_Bag {
		_generalMacro = "Tenthed_HMG_02_F_Bag_Auto";
		displayName = "[10th] M2A HMG .50 Auto";
		side = 2;
		scope = 2;
		scopeArsenal = 2;
		class AssembleInfo : AssembleInfo {
			primary = 1;
			displayName = "[10th] M2A HMG .50 Auto";
			assembleTo = "Tenthed_HMG_02_F_Auto";
			base[] = {""};
		};
	};
	
	
};
