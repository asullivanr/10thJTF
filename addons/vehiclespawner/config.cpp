class CfgPatches {
    class Tenthed_vehiclespawner {
        author = "Akira";
        name = "10th JTF: vehicle spawner";
        units[] = {
            "Tenthed_Spawner_SpawnVehicleObjective",
            "Tenthed_Spawner_SpawnVehicleSpawner"
        };
        weapons[] = {};
        requiredAddons[] = {"A3_Modules_F"};
    };
};
// https://community.bistudio.com/wiki/Modules
class CfgFunctions {
    class Tenthed_functions_spawning
    {
        tag = "Tenthed_Spawner";
        class Tenthed_Func_spawnVehicleObjective
        {
            file="z\10thJTF\addons\vehiclespawner\functions";
            class spawnVehicleObjective {};
        };
        class Tenthed_Func_setSpawnPosition
        {
            file="z\10thJTF\addons\vehiclespawner\functions";
            class setSpawnPosition {};
        };
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
    
    // Vehicle Spawn Objective Module
    class Tenthed_Spawner_SpawnVehicleObjective: Module_F {
        scope = 2;
        displayName = "Vehicle Spawn Object";
        category = "Tenthed_UnitFact_Main";  // Make sure this is a visible category
        function = "Tenthed_Spawner_fnc_spawnVehicleObjective";
        isGlobal = 1;
        //is3DEN = 1;  // Enable in 3DEN Editor
        curatorCanAttach = 0;
        /*
        class Arguments {
            class VehicleCategories {
                displayName = "Vehicle Categories";
                description = "Define vehicle categories and their vehicles (vehicle class and name).";
                typeName = "ARRAY";
                
                // Define the categories
                class values {
                    class MRAP {
                        value = "MRAP";  // A unique category identifier
                        displayName = "MRAP Vehicles";
                    };
                    
                    class Tank {
                        value = "Tank";  // A unique category identifier
                        displayName = "Tank Vehicles";
                    };
                    
                    class Offroad {
                        value = "Offroad";  // A unique category identifier
                        displayName = "Offroad Vehicles";
                    };
                };
            };
        };*/
    };

    // Vehicle Spawn Position Module
    class Tenthed_Spawner_SpawnVehicleSpawner: Module_F {
        scope = 2;
        displayName = "Vehicle Spawn Position";
        category = "Tenthed_UnitFact_Main";  // Make sure this is a visible category
        function = "Tenthed_Spawner_fnc_setSpawnPosition";
        isGlobal = 1;
        //is3DEN = 1;  // Enable in 3DEN Editor
        curatorCanAttach = 0;
        /*
        class Arguments {
            class SpawnPosition {
                displayName = "Spawn Position";
                description = "Define the spawn position for vehicles.";
                typeName = "OBJECT";
                class values {
                    class Default {
                        value = "";
                        default = 1;
                    };
                };
            };
        };*/

		class Attributes : AttributesBase
		{
			// Arguments shared by specific module type (have to be mentioned in order to be present):
			class Units : Units
			{
				property = "TAG_Module_Nuke_Units";
			};

			// Module-specific arguments:
			class Yield : Combo
			{
				property = "TAG_Module_Nuke_Yield";				// Unique property (use "<tag>_<moduleClass>_<attributeClass>" format to ensure that the name is unique)
				displayName = "Nuclear weapon yield";			// Argument label
				tooltip = "How strong will the explosion be";	// Tooltip description
				typeName = "NUMBER";							// Value type, can be "NUMBER", "STRING" or "BOOL"
				defaultValue = "50";							// Default attribute value. Warning: this is an expression, and its returned value will be used (50 in this case).

				// Listbox items
				class Values
				{
					class 50Mt	{ name = "50 megatons";	value = 50; };
					class 100Mt	{ name = "100 megatons"; value = 100; };
				};
			};

			class Name : Edit
			{
				displayName = "Name";
				tooltip = "Name of the nuclear device";
				property = "TAG_Module_Nuke_Name";
				// Default text for the input box:
				defaultValue = """Tsar Bomba"""; // Because this is an expression, one must have a string within a string to return a string
			};
            
			class ModuleDescription : ModuleDescription {}; // Module description should be shown last
		};

        // Module description (must inherit from base class, otherwise pre-defined entities won't be available)
        class ModuleDescription : ModuleDescription
        {
            description = "Simply passes the synced object back to its parent module.";	// Short description, will be formatted as structured text
            sync[] = { "LocationArea_F" };				// Array of synced entities (can contain base classes)

			class LocationArea_F
			{
				description[] = { // Multi-line descriptions are supported
					"First line",
					"Second line"
				};
				position = 1;	// Position is taken into effect
				direction = 1;	// Direction is taken into effect
				optional = 0;	// Synced entity is optional
				duplicate = 0;	// Multiple entities of this type can be synced
				//synced[] = { "BluforUnit", "AnyBrain" };	// Pre-defined entities like "AnyBrain" can be used (see the table below)
                synced[] = { "VR_Area_01_square_1x1_yellow_F" };
            };
        };
    };
};