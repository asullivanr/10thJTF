class CfgPatches {
    class Tenthed_Turrets {
        author = "Akira";
        name = "10th JTF: Turrets";
        requiredAddons[] = {
            "Tenthed_core"
        };
        weapons[] = {};
		units[] = {
			"Tenthed_M252_Backpack",
			"Tenthed_M2HBM3_Backpack",
			"Tenthed_M41A4TOW_Backpack",
			"Tenthed_M252_Turret",
			"Tenthed_M2HBM3_Turret",
			"Tenthed_M41A4TOW_Turret"
		};
    };
};
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

class cfgWeapons {
	class HMG_static;
	class Tenthed_HMG_static : HMG_static {
		magazines[] = {
			"Tenthed_100Rnd_127x99_mag_Tracer_Yellow"
		};
	};

	class mortar_82mm;
	class Tenthed_mortar_82mm : mortar_82mm {
		magazines[] = {
			"8Rnd_82mm_Mo_shells",
			"8Rnd_82mm_Mo_Flare_white",
			"8Rnd_82mm_Mo_Smoke_white",
			"8Rnd_82mm_Mo_guided",
			"8Rnd_82mm_Mo_LG"
		};
	};
};

// class names
// Mortar: RHS_M252_USMC_WD - M252
// HMG: RHS_M2StaticMG_MiniTripod_USMC_WD - M2HB (M3)
// TOW: RHS_TOW_TriPod_USMC_WD - M41A4 TOW

class cfgVehicles {
	// Bag Base
	class Bag_Base;
	class Tenthed_Deploy_Bag_Base : Bag_Base {
		_generalMacro = "Tenthed_Weapon_Bag_Base";
		//picture = "\OPTRE_weapons\backpacks\icons\icon_b_anprc521_ca.paa";
		scope = 0;
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		//model = "\OPTRE_unsc_units\army\rucksack.p3d";
		maximumLoad = 0;
		class assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {};
			displayName = "";
		};
	};
	// Mortar Bag
	class Tenthed_M252_Backpack : Tenthed_Deploy_Bag_Base {
		_generalMacro = "Tenthed_M252_Backpack";
		displayName = "[10th] M252 Backback";
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Small_oli.paa";
		class assembleInfo : assembleInfo {
			displayName = "Assemble [10th] M252";
			assembleTo = "Tenthed_M252_Turret";
		};
	};
	// HMG Bag
	class Tenthed_M2HBM3_Backpack : Tenthed_Deploy_Bag_Base {
		_generalMacro = "Tenthed_M2HBM3_Backpack";
		displayName = "[10th] M2HB (M3) Backback";
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Small_oli.paa";
		class assembleInfo : assembleInfo {
			displayName = "Assemble [10th] M2HB (M3)";
			assembleTo = "Tenthed_M2HBM3_Turret";
		};
	};
	// TOW Bag
	class Tenthed_M41A4TOW_Backpack : Tenthed_Deploy_Bag_Base {
		_generalMacro = "Tenthed_M41A4TOW_Backpack";
		displayName = "[10th] M41A4 TOW Backback";
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Small_oli.paa";
		class assembleInfo : assembleInfo {
			displayName = "Assemble [10th] M41A4 TOW";
			assembleTo = "Tenthed_M41A4TOW_Turret";
		};
	};

// Mortar: RHS_M252_USMC_WD - M252
// HMG: RHS_M2StaticMG_MiniTripod_USMC_WD - M2HB (M3)
// TOW: RHS_TOW_TriPod_USMC_WD - M41A4 TOW

	// Mortar
	class RHS_M252_USMC_WD;
	class Tenthed_M252_Turret : RHS_M252_USMC_WD {
		displayName = "[10th] M252";
		_generalMacro = "Tenthed_M252_Turret";
		scope = 2;
		side = 1;
		faction = "Tenthed_UnitFact_Main";
		editorCategory = "Tenthed_EditorCategory_Main";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Turrets";
		//crew = "I_Soldier_F";
		class assembleInfo {
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = { "Tenthed_M252_Backpack" };
			displayName = "";
		};
		/* need to figure out if i can get away with just this, also need to get the class names for whichever ammo it uses
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				magazines[] =
				{
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_Flare_white",
					"8Rnd_82mm_Mo_Smoke_white"
				};
			};
		};
		*/

	};
	// HMG
	class RHS_M2StaticMG_MiniTripod_USMC_WD;
	class Tenthed_M2HBM3_Turret : RHS_M2StaticMG_MiniTripod_USMC_WD {
		displayName = "[10th] M2HB (M3)";
		_generalMacro = "Tenthed_M2HBM3_Turret";
		scope = 2;
		side = 1;
		faction = "Tenthed_UnitFact_Main";
		editorCategory = "Tenthed_EditorCategory_Main";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Turrets";
		//crew = "I_Soldier_F";
		class assembleInfo {
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = { "Tenthed_M2HBM3_Backpack" };
			displayName = "";
		};
	};
	// TOW
	class RHS_TOW_TriPod_USMC_WD;
	class Tenthed_M41A4TOW_Turret : RHS_TOW_TriPod_USMC_WD {
		displayName = "[10th] M41A4 TOW";
		_generalMacro = "Tenthed_M41A4TOW_Turret";
		scope = 2;
		side = 1;
		faction = "Tenthed_UnitFact_Main";
		editorCategory = "Tenthed_EditorCategory_Main";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Turrets";
		//crew = "I_Soldier_F";
		class assembleInfo {
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = { "Tenthed_M41A4TOW_Backpack" };
			displayName = "";
		};
	};
};