class CfgPatches {
    class Tenthed_Turrets {
        author = "Akira";
        name = "10th JTF: Turrets";
        requiredAddons[] = {
            "Tenthed_core",
        };
        weapons[] = {};
		units[] = {};
    };
};
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

class cfgWeapons {
	class mortar_82mm;
	class Tenthed_mortar_82mm : mortar_82mm {
		magazines[] =
		{
			"8Rnd_82mm_Mo_shells",
			"8Rnd_82mm_Mo_Flare_white",
			"8Rnd_82mm_Mo_Smoke_white",
			"8Rnd_82mm_Mo_guided",
			"8Rnd_82mm_Mo_LG"
		};
	};
};

// TODO: Remove OPTRE related sections/code and replace with marine focused

class cfgVehicles {
	class All;
	class Strategic;
	class Land;

	class Bag_Base;
	class Tenthed_Weapon_Bag_Base : Bag_Base {
		_generalMacro = "Tenthed_Weapon_Bag_Base";
		picture = "\OPTRE_weapons\backpacks\icons\icon_b_anprc521_ca.paa";
		scope = 0;
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		model = "\OPTRE_unsc_units\army\rucksack.p3d";
		hiddenSelections[] = {
			"camo",
			"camo2",
			"B_Medic",
			"B_Radio"
		};
		hiddenSelectionsTextures[] = {
			"\z\10thJTF\addons\turrets\data\TurretBackpack\soft_backpack_co.paa",
			""
		};
		maximumLoad = 0;
		class assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {};
			displayName = "";
		};
	};

	class LandVehicle;
	class StaticWeapon : LandVehicle {
		class Turrets {
			class MainTurret;
		};
	};
	class StaticMortar : StaticWeapon {
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				class ViewOptics;
			};
		};
	};
	class Tenthed_Mortar_01_base_F : StaticMortar {
		features = "Randomization: No						<br />Camo selections: 1 - the whole weapon with pod						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: Just the weapon						<br />Slingload: No						<br />Cargo proxy indexes: None";
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Tenthed_Mortar_01_base_F";
		scope = 0;
		displayname = "[10th] Mortar Base";
		class Library {
			libTextDesc = "$STR_A3_CfgVehicles_Mortar_01_Base_Library0";
		};
		transportSoldier = 0;
		cargoAction[] =
		{
			"Mortar_Gunner"
		};
		getInAction = "GetInMortar";
		getOutAction = "GetOutLow";
		unitInfoType = "RscUnitInfoMortar";
		side = 1;
		faction = "Tenthed_UnitFact_Main";
		editorCategory = "Tenthed_EditorCategory_Main";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Turrets";
		picture = "\A3\Static_f\Mortar_01\data\UI\Mortar_01_ca.paa";
		icon = "\A3\Static_f\Mortar_01\data\UI\map_Mortar_01_CA.paa";
		cost = 200000;
		accuracy = 0.25;
		EPEImpulseDamageCoef = 5;
		class Damage {
			tex[] = {};
			mat[] =
			{
				"A3\Static_f\Mortar_01\data\Mortar_01.rvmat",
				"A3\Static_f\Mortar_01\data\Mortar_01_damage.rvmat",
				"A3\Static_f\Mortar_01\data\Mortar_01_destruct.rvmat"
			};
		};
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				gunnerAction = "Mortar_Gunner";
				gunnergetInAction = "";
				gunnergetOutAction = "";
				weapons[] =
				{
					"Tenthed_mortar_82mm"
				};
				elevationMode = 1;
				initCamElev = 0;
				minCamElev = -35;
				maxCamElev = 35;
				initElev = 0;
				minTurn = -180;
				maxTurn = 180;
				initTurn = 0;
				cameraDir = "look";
				discreteDistance[] = { 100,200,300,400,500,700,1000,1600,2000,2400,2800 };
				discreteDistanceCameraPoint[] =
				{
					"eye"
				};
				discreteDistanceInitIndex = 5;
				turretInfoType = "RscWeaponRangeArtillery";
				gunnerForceOptics = 0;
				memoryPointGunnerOptics = "eye";
				gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
				disableSoundAttenuation = 1;
				class ViewOptics : ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.17399999;
					minFov = 0.0077777999;
					maxFov = 0.14;
					visionMode[] =
					{
						"Normal",
						"NVG"
					};
				};
				minelev = -30;
				maxelev = 13;
				magazines[] =
				{
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_shells",
					"8Rnd_82mm_Mo_Flare_white",
					"8Rnd_82mm_Mo_Smoke_white"
				};
				ejectDeadGunner = 1;
				usepip = 2;
			};
		};
		class EventHandlers {
			fired = "_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
		};
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		class DestructionEffects {
			class Smoke {
				simulation = "particles";
				type = "WeaponWreckSmoke";
				position = "destructionEffect";
				intensity = 1;
				interval = 1;
				lifeTime = 5;
			};
		};
		model = "\A3\static_f\Mortar_01\Mortar_01_F";
		artilleryScanner = 1;
		class assembleInfo {
			primary = 0;
			base = "";
			assembleTo = "";
			dissasembleTo[] = { "Tenthed_Mortar_Backpack" };
			displayName = "";
		};
		hiddenSelections[] =
		{
			"Camo"
		};
		hiddenSelectionsTextures[] =
		{
			"\A3\Static_f\Mortar_01\data\Mortar_01_CO.paa"
		};
	};
	class Tenthed_Mortar_Turret : Tenthed_Mortar_01_base_F {
		author = "$STR_A3_Bohemia_Interactive";
		displayname = "[10th] MK82 Mortar";
		class SimpleObject {
			eden = 1;
			animate[] =
			{

				{
					"mainturret",
					0
				},

				{
					"maingun",
					0
				},

				{
					"optics",
					0
				},

				{
					"optics_stabilization",
					0
				},

				{
					"legs_zeroing",
					0
				},

				{
					"uplegs_zeroing",
					0
				}
			};
			hide[] =
			{
				"light_back",
				"brzdove svetlo",
				"clan",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset = 0.75700003;
			verticalOffsetWorld = 0.035;
			init = "''";
		};
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\B_Mortar_01_F.jpg";
		_generalMacro = "Tenthed_Mortar_Turret";
		scope = 2;
		side = 1;
		availableForSupportTypes[] = {
			"Artillery"
		};
	};

	class Tenthed_Mortar_Backpack : Tenthed_Weapon_Bag_Base {
		_generalMacro = "Tenthed_Mortar_Backpack";
		displayName = "[10th] MK82 Backback";
		scope = 2;
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Small_oli.paa";
		class assembleInfo : assembleInfo {
			displayName = "Assemble [10th] MK82";
			assembleTo = "Tenthed_Mortar_Turret";
		};
	};
};