class CfgPatches {
    class Tenthed_vehiclespawner {
        author = "Akira";
        name = "10th JTF: vehicle spawner";
        units[] = {
            "Tenthed_Spawner_VehicleSpawner",
            "Tenthed_Spawner_VehicleSpawnerArray"
        };
        weapons[] = {};
        requiredAddons[] = {"A3_Modules_F","A3_Functions_F"};
    };
};
// https://community.bistudio.com/wiki/Modules
class CfgFunctions {
    class Tenthed_functions_spawning {
        tag = "Tenthed_Spawner";
        class Tenthed_Func_spawnVehicle {
            file="z\10thJTF\addons\vehiclespawner\functions";
            class spawnVehicle {};
        };
        class Tenthed_Func_spawnVehicleArray {
            file="z\10thJTF\addons\vehiclespawner\functions";
            class spawnVehicleArray {};
        };
    };
};

class CfgVehicles {
	class Logic;
	class Module_F : Logic {
		class AttributesBase {
			class Default;
			class Edit;					// Default edit box (i.e. text input field)
			class Combo;				// Default combo box (i.e. drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};

		// Description base classes (for more information see below):
		class ModuleDescription {
            description = "Base module description.";
            class Anything;
			class AnyBrain;
		};
	};

    // 
    class Tenthed_Spawner_VehicleSpawner : Module_F {
        scope = 2;
        displayName = "Spawn Vehicle";
        category = "Tenthed_UnitFact_Main";

        function = "Tenthed_Spawner_fnc_spawnVehicle";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;

        class Arguments {
            class vehicleClassNames {
                displayName = "Vehicle Class Names";
                description = "Comma-separated class names of vehicles to spawn.";
                typeName = "STRING";
                defaultValue = "RHS_M2A2_BUSKI,rhsusf_m998_d_s_2dr_halftop";
            };
            class vehicleDisplayNames {
                displayName = "Vehicle Display Names";
                description = "Comma-separated display names matching class names.";
                typeName = "STRING";
                defaultValue = "M2A2ODS (BUSK I),M1123 (2D/Half/Snorkel)";
            };
        };
    };
    class Tenthed_Spawner_VehicleSpawnerArray : Module_F {
        scope = 2;
        displayName = "Spawn Vehicle Array";
        category = "Tenthed_UnitFact_Main";

        function = "Tenthed_Spawner_fnc_spawnVehicleArray";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;

        class Arguments {
            class vehicleEntries {
                displayName = "Vehicles";
                description = "List of vehicles in format: DisplayName|ClassName;DisplayName2|ClassName2";
                typeName = "STRING";
                defaultValue = "M2A2ODS (BUSK I)|RHS_M2A2_BUSKI;M1123 (2D/Half/Snorkel)|rhsusf_m998_d_s_2dr_halftop";
            };
        };
    };
};