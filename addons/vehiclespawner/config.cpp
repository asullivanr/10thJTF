class CfgPatches {
    class Tenthed_vehiclespawner {
        author = "Akira";
        name = "10th JTF: vehicle spawner";
        units[] = {
            "Tenthed_Spawner_VehicleSpawner"
        };
        weapons[] = {};
        requiredAddons[] = {"A3_Modules_F","A3_Functions_F"};
    };
};
// https://community.bistudio.com/wiki/Modules
class CfgFunctions {
    class Tenthed_functions_spawning
    {
        tag = "Tenthed_Spawner";
        class Tenthed_Func_spawnVehicle
        {
            file="z\10thJTF\addons\vehiclespawner\functions";
            class spawnVehicle {};
        };
    };
};

class CfgVehicles {
	class Logic;
	class Module_F : Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;					// Default edit box (i.e. text input field)
			class Combo;				// Default combo box (i.e. drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};

		// Description base classes (for more information see below):
		class ModuleDescription
		{
            //class Anything;
			class AnyBrain;
		};
	};

    // 
    class Tenthed_Spawner_VehicleSpawner : Module_F {
        scope = 2;
        displayName = "Spawn Single Vehicle";
        category = "Tenthed_UnitFact_Main";

        function = "Tenthed_Spawner_fnc_spawnVehicle"; // called when module is placed
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;

        class Arguments {
            class vehicleClassName {
                displayName = "Vehicle Class Name";
                description = "Class name of the vehicle to spawn.";
                typeName = "STRING";
                defaultValue = "RHS_M2A2_BUSKI";
            };
            class vehicleDisplayName {
                displayName = "Vehicle Display Name";
                description = "Name shown in action menu.";
                typeName = "STRING";
                defaultValue = "M2A2ODS (BUSK I)";
            };
        };

        class ModuleDescription {
            description = "Spawns a vehicle when a player uses a console. Sync the spawn location(VR area yello) and a spawn console of some kind for module to function.";
        };
    };
};