class CfgPatches {
    class Tenthed_functions {
        author = "Akira";
        name = "10th JTF: Functions";
        requiredAddons[] = {
            "Tenthed_core"
        };
        weapons[] = {};
        units[] = {};
    };
};
class CfgFunctions {
    class Tenthed_functions {
    	//Prefix for functions ie Tenthed_fnc_# (_fnc_ is added automatically between tag and file name see below)
    	tag = "Tenthed";
      
        //Category
        class Tenthed_Server_Functions
        {
            file="z\10thJTF\addons\functions\functions";
            class Arsenal {};
            // [this, true] call Tenthed_fnc_Arsenal;
        };

        class Tenthed_Server_Functions_Teleport {
            file = "z\10thJTF\addons\functions\functions";
            class AddTeleportMenu {};
            class ModuleTeleport {};
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
    class Tenthed_Teleport : Module_F {
        scope = 2;
        displayName = "Teleport Location";
        category = "Tenthed_UnitFact_Main";

        function = "Tenthed_fnc_ModuleTeleport";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;

        class Arguments {
            class locationName {
                displayName = "Location Name";
                description = "Display name for the teleport destination.";
                typeName = "STRING";
                defaultValue = "Forward Base";
                property = "locationName";
            };
        };

        class ModuleDescription : ModuleDescription {
            description = "Sync one object as the teleport destination, and one as the terminal to interact with.";
            class AnyPerson {
                name = "Any Player";
                description = "Applies to any unit.";
                position = 1;
                direction = 1;
            };
        };
    };
};