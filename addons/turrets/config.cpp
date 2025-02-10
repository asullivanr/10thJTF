class CfgPatches {
    class Tenthed_Turrets {
        author = "Akira";
        name = "10th JTF: Turrets";
        requiredAddons[] = {
            "Tenthed_core"
        };
        weapons[] = {
			"Tenthed_HMG_static",
			"Tenthed_mortar_82mm"
		};
		units[] = {
			"Tenthed_HMG_Turret",
			"Tenthed_HMG_Backpack",
			"Tenthed_Mortar_Turret",
			"Tenthed_Mortar_Backpack",
			"Tenthed_AU_44_Mortar"
		};
    };
};
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

class cfgWeapons {
	class HMG_static;
	class Tenthed_HMG_static : HMG_static {
		magazines[] =
		{
			"Tenthed_100Rnd_127x99_mag_Tracer_Yellow"
		};
	};

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

class cfgVehicles {
	class All;
	class Strategic;
	class Land;

	class Bag_Base;
	class Tenthed_Weapon_Bag_Base : Bag_Base {
		_generalMacro = "Tenthed_Weapon_Bag_Base";
		//picture = "\OPTRE_weapons\backpacks\icons\icon_b_anprc521_ca.paa";
		scope = 0;
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		//model = "\OPTRE_unsc_units\army\rucksack.p3d";
		//hiddenSelections[] = {
		//	"camo",
		//	"camo2",
		//	"B_Medic",
		//	"B_Radio"
		//};
		//hiddenSelectionsTextures[] = {
		//	"\z\10thMod\addons\turrets\data\TurretBackpack\soft_backpack_co.paa",
		//	""
		//};
		maximumLoad = 0;
		class assembleInfo {
			primary = 1;
			base = "";
			assembleTo = "";
			dissasembleTo[] = {};
			displayName = "";
		};
	};


	class Tenthed_LandVehicle : Land {
		class ViewPilot;
		class NewTurret;
	};
	class Tenthed_StaticWeapon : Tenthed_LandVehicle {
		epeImpulseDamageCoef = 8;
		editorSubcategory = "EdSubcat_Turrets";
		vehicleClass = "Static";
		driverOpticsModel = "\A3\weapons_f\reticle\optics_empty";
		selectionClan = "clan";
		selectionDashboard = "podsvit pristroju";
		selectionShowDamage = "poskozeni";
		selectionBackLights = "light_back";
		bounding = "usti hlavne";
		alphaTracks = 0.69999999;
		textureTrackWheel = 0;
		selectionLeftOffset = "";
		selectionRightOffset = "";
		memoryPointTrack1L = "";
		memoryPointTrack1R = "";
		memoryPointTrack2L = "";
		memoryPointTrack2R = "";
		tracksSpeed = 1;
		unitInfoType = "RscUnitInfoStatic";
		waterLeakiness = 100;
		selectionFireAnim = "";
		fireDustEffect = "FDustEffects";
		class DestructionEffects {};
		memoryPointMissile[] =
		{
			"spice rakety",
			"usti hlavne"
		};
		memoryPointMissileDir[] =
		{
			"konec rakety",
			"konec hlavne"
		};
		memoryPointCargoLight = "cargo light";
		driverCanSee = "1 + 2 + 4 + 8 + 32";
		gunnerCanSee = "1 + 2 + 4 + 8 + 32";
		commanderCanSee = "1 + 2 + 4 + 8 + 32";
		gunnerHasFlares = 0;
		class VehicleTransport {
			class Cargo {
				canBeTransported = 0;
			};
		};
		class Turrets {
			class MainTurret : NewTurret {
				selectionFireAnim = "";
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				gunnerReversedGetOut = 0;
				memoryPointGun = "usti hlavne";
				outGunnerMayFire = 1;
				optics = 1;
				minTurn = -40;
				maxTurn = 40;
				initTurn = 0;
				minElev = -7;
				maxElev = 70;
				initElev = 0;
				castGunnerShadow = 1;
				ejectDeadGunner = 0;
				canEject = 0;
				gunnerGetInAction = "";
				gunnerGetOutAction = "";
				gunnerForceOptics = 0;
				class ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					minFov = 0.25;
					maxFov = 1.25;
					initFov = 0.75;
					minMoveX = 0;
					maxMoveX = 0;
					minMoveY = 0;
					maxMoveY = 0;
					minMoveZ = 0;
					maxMoveZ = 0;
				};
				class HitPoints {
					class HitGun {
						armor = 0.30000001;
						material = -1;
						name = "action";
						visual = "autonomous_unhide";
						passThrough = 0;
						radius = 0.2;
					};
					class HitTurret : HitGun {
						armor = 0.30000001;
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
					};
				};
				class Components {
					class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
						class Components {
							class EmptyDisplay {
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay {
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoMiniMap";
							};
							class UAVDisplay {
								componentType = "UAVFeedDisplayComponent";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
						class Components {
							class EmptyDisplay {
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay {
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoMiniMap";
							};
							class UAVDisplay {
								componentType = "UAVFeedDisplayComponent";
							};
						};
					};
				};
			};
		};
		damperSize = 1.4;
		damperForce = 0.80000001;
		gearBox[] = { -1,0,1 };
		attenuationEffectType = "OpenCarAttenuation";
		soundEnviron[] =
		{
			"",
			1,
			0.69999999
		};
		soundEngine[] =
		{
			"",
			10,
			1
		};
		soundCrash[] =
		{
			"",
			0.56234133,
			1
		};
		soundGear[] =
		{
			"",
			0.00031622773,
			1
		};
		soundDammage[] =
		{
			"",
			0.0099999998,
			1
		};
		getInAction = "";
		getOutAction = "";
		cargoGetInAction[] = {};
		cargoGetOutAction[] = {};
		class Wounds {
			tex[] = {};
			mat[] = {};
		};
		getInRadius = 3.5;
		secondaryExplosion = -1;
		fuelExplosionPower = 0;
		fuelCapacity = 0;
		irScanRangeMin = 0;
		irScanRangeMax = 0;
		irScanToEyeFactor = 1;
		allowTabLock = 0;
		irTarget = 0;
		laserTarget = 0;
		armor = 24;
		armorStructural = 1;
		explosionShielding = 1;
		minTotalDamageThreshold = 0.0099999998;
		crewCrashProtection = 1;
		crewExplosionProtection = 0;
		class HitPoints {
			class HitEngine {
				armor = 0.80000001;
				material = -1;
				name = "motor";
				passThrough = 1;
			};
			class HitHull {
				armor = 1;
				material = -1;
				name = "telo";
				passThrough = 1;
			};
			class HitTurret {
				armor = 0.80000001;
				material = -1;
				name = "vez";
				passThrough = 1;
			};
			class HitGun {
				armor = 0.60000002;
				material = -1;
				name = "zbran";
				passThrough = 1;
			};
			class HitLTrack {
				armor = 0.60000002;
				material = -1;
				name = "pas_L";
				passThrough = 1;
			};
			class HitRTrack {
				armor = 0.60000002;
				material = -1;
				name = "pas_P";
				passThrough = 1;
			};
			class HitBody {
				armor = 1;
				material = -1;
				name = "NEzbytek";
				visual = "zbytek";
				passThrough = 1;
			};
		};
		extCameraPosition[] = { 0,1.5,-9 };
		class ViewPilot : ViewPilot {
			initAngleX = 7;
			minAngleX = -15;
			maxAngleX = 25;
			initAngleY = 0;
			minAngleY = -90;
			maxAngleY = 90;
		};
		cost = 10000;
		steerAheadSimul = 0.40000001;
		steerAheadPlan = 0.60000002;
		predictTurnSimul = 1.2;
		predictTurnPlan = 1.8;
		ejectDeadDriver = 1;
		ejectDeadCargo = 1;
		hasDriver = 0;
		nightVision = 0;
		driverAction = "ManActCargo";
		driverInAction = "ManActCargo";
		memoryPointsGetInCargo = "pos_cargo";
		memoryPointsGetInCargoDir = "pos_cargo_dir";
		simulation = "tankX";
		occludeSoundsWhenIn = 1;
		obstructSoundsWhenIn = 1;
		formationX = 20;
		formationZ = 30;
		precision = 1;
		brakeDistance = 0;
		turnCoef = 0;
		maxSpeed = 0;
		canFloat = 0;
		weapons[] =
		{
			"FakeWeapon"
		};
		magazines[] =
		{
			"FakeWeapon"
		};
		type = 1;
		threat[] = { 0.69999999,1,0.30000001 };
		camouflage = 1;
		audible = 1;
		sensitivityEar = 0.125;
		sensitivity = 1.75;
		hideProxyInCombat = 0;
		driverOpticsColor[] = { 0,0,0,1 };
		class CargoLight {
			color[] = { 0,0,0,0 };
			ambient[] = { 0.60000002,0,0.15000001,1 };
			brightness = 0.0070000002;
		};
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		class Reflectors {};
		class UserActions {
			class PressXToFlipTheThing {
				displayNameDefault = "$STR_A3_Tenthed_StaticWeapon_UserActions_PressXToFlipTheThing0";
				displayName = "$STR_A3_Tenthed_StaticWeapon_UserActions_PressXToFlipTheThing0";
				position = "";
				radius = 2.7;
				onlyForPlayer = 1;
				condition = "alive this AND (not canmove this) AND (count crew this == 0 || isAutonomous this) AND (simulationEnabled this) AND ((locked this) < 2)";
				statement = "[this] call bis_fnc_unflipVehicle";
			};
		};
		numberPhysicalWheels = 0;
	};
	class Tenthed_StaticMGWeapon : Tenthed_StaticWeapon {
		accuracy = 0.12;
		cost = 10000;
		threat[] = { 0.80000001,0.30000001,0.60000002 };
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				class ViewOptics;
				optics = 1;
			};
		};
		icon = "iconStaticMG";
	};
	class Tenthed_HMG_01_base_F : Tenthed_StaticMGWeapon {
		features = "Randomization: No						<br />Camo selections: 1 - the whole weapon with pod						<br />Script door sources: None						<br />Script animations: None						<br />Executed scripts: None						<br />Firing from vehicles: Just the weapon						<br />Slingload: No						<br />Cargo proxy indexes: None";
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Tenthed_HMG_01_base_F";
		scope = 0;
		displayName = "HMG_01_Base0";
		class Armory {
			description = "HMG_01_Base_Armory0";
		};
		model = "\A3\Static_F_Gamma\HMG_01\HMG_01_F.p3d";
		editorSubcategory = "EdSubcat_Turrets";
		picture = "\A3\Static_f_gamma\data\ui\gear_StaticTurret_MG_CA.paa";
		UiPicture = "\A3\Static_f_gamma\data\ui\gear_StaticTurret_MG_CA.paa";
		cost = 150000;
		getInAction = "";
		getOutAction = "";
		class Damage {
			tex[] = {};
			mat[] =
			{
				"A3\Static_F_Gamma\data\StaticTurret_01.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_02_destruct.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_03.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_03_damage.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_03_destruct.rvmat"
			};
		};
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				optics = 1;
				discreteDistance[] = { 100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000 };
				discreteDistanceInitIndex = 2;
				turretInfoType = "RscOptics_crows";
				gunnerOpticsModel = "\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
				minElev = -20;
				maxElev = 35;
				weapons[] =
				{
					"Tenthed_HMG_static"
				};
				magazines[] =
				{
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow"
				};
				gunnerAction = "gunner_static_low01";
				gunnergetInAction = "";
				gunnergetOutAction = "";
				displayName = "";
				disableSoundAttenuation = 1;
				class ViewOptics : ViewOptics {
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.117;
					minFov = 0.028999999;
					maxFov = 0.117;
					visionMode[] =
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[] = { 0,1 };
				};
				gunnerRightHandAnimName = "OtocHlaven_shake";
				gunnerLeftHandAnimName = "OtocHlaven_shake";
				ejectDeadGunner = 1;
			};
		};
		class AnimationSources {
			class autonomous_unhide {
				source = "user";
				animPeriod = 1e-006;
				initPhase = 0;
			};
			class muzzle_source {
				source = "reload";
				weapon = "Tenthed_HMG_static";
			};
			class muzzle_source_rot {
				source = "ammorandom";
				weapon = "Tenthed_HMG_static";
			};
			class ReloadAnim {
				source = "reload";
				weapon = "Tenthed_HMG_static";
			};
			class ReloadMagazine {
				source = "reloadmagazine";
				weapon = "Tenthed_HMG_static";
			};
			class Revolving {
				source = "revolving";
				weapon = "Tenthed_HMG_static";
			};
		};
		soundGetOut[] =
		{
			"A3\sounds_f\dummysound",
			0.00099999993,
			1,
			5
		};
		soundGetIn[] =
		{
			"A3\sounds_f\dummysound",
			0.00031622773,
			1,
			5
		};
	};

	class Tenthed_HMG_Turret : Tenthed_HMG_01_base_F {
		author = "$STR_A3_Bohemia_Interactive";
		displayName = "[10th] HMG";
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
					"mainturret_destructx",
					0
				},

				{
					"mainturret_destructy",
					0
				},

				{
					"mainturret_destructz",
					0
				},

				{
					"maingun_destructx",
					0
				},

				{
					"maingun_destructy",
					0
				},

				{
					"maingun_destructz",
					0
				},

				{
					"magazine_destruct",
					0
				},

				{
					"ammo_belt_destruct",
					0
				},

				{
					"bolt_destruct",
					0
				},

				{
					"charging_handle_destruct",
					0
				},

				{
					"damagehidevez_destruct",
					0
				},

				{
					"damagehidehlaven_destruct",
					0
				},

				{
					"damagehiderecoil_destruct",
					0
				},

				{
					"ammo_belt_rotation",
					0
				},

				{
					"barrel_recoil",
					0
				},

				{
					"bolt_recoil",
					0
				},

				{
					"turret_shake",
					0
				},

				{
					"turret_shake_backside",
					0
				},

				{
					"turret_shake_aside",
					0
				},

				{
					"bolt_reload_begin",
					0
				},

				{
					"bolt_reload_end",
					0
				},

				{
					"charging_handle_reload_begin",
					0
				},

				{
					"charging_handle_reload_end",
					0
				},

				{
					"magazine_hide",
					0
				},

				{
					"ammo_belt_hide",
					0
				},

				{
					"muzzleflash",
					0
				},

				{
					"zaslehrot",
					924
				},

				{
					"addautonomous_unhide",
					0
				},

				{
					"bullet001_reload_hide",
					1
				},

				{
					"bullet002_reload_hide",
					1
				},

				{
					"bullet003_reload_hide",
					1
				},

				{
					"bullet004_reload_hide",
					1
				},

				{
					"bullet005_reload_hide",
					1
				},

				{
					"bullet006_reload_hide",
					1
				},

				{
					"bullet007_reload_hide",
					1
				},

				{
					"bullet008_reload_hide",
					1
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
			verticalOffset = 1.206;
			verticalOffsetWorld = 0.074000001;
			init = "''";
		};
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\I_HMG_01_F.jpg";
		_generalMacro = "Tenthed_HMG_Turret";
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
			dissasembleTo[] = { "Tenthed_HMG_Backpack" };
			displayName = "";
		};
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				magazines[] =
				{
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow",
					"Tenthed_100Rnd_127x99_mag_Tracer_Yellow"
				};
			};
		};
	};
	class Tenthed_HMG_Backpack : Tenthed_Weapon_Bag_Base {
		_generalMacro = "Tenthed_HMG_Backpack";
		displayName = "[10th] HMG Backback";
		editorCategory = "Tenthed_EditorCategory_Items";
		editorSubcategory = "Tenthed_EditorSubcategory_Objects_Backpacks";
		scope = 2;
		picture = "\A3\Weapons_F\Ammoboxes\Bags\data\UI\icon_B_C_Small_oli.paa";
		class assembleInfo : assembleInfo {
			displayName = "Assemble [10th] HMG";
			assembleTo = "Tenthed_HMG_Turret";
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