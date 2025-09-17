class CfgPatches {
    class Tenthed_functions {
        author = "Akira";
        name = "10th JTF: Functions";
        requiredAddons[] = {
            "Tenthed_core",
            "cba_main"
        };
        weapons[] = {};
        units[] = {};
    };
};
class CfgSurfaces {
	class Default {
		AIAvoidStance = 2;
	};
};
class RscTitles {
    class Tenthed_RscServerFPS {
        idd = -1;
        duration = 1e10;
        movingEnable = 0;
        onLoad = "uiNamespace setVariable ['Tenthed_RscServerFPS_display', _this select 0]";
        onUnload = "uiNamespace setVariable ['Tenthed_RscServerFPS_display', displayNull]";
        fadein = 0;
        fadeout = 0;

        class controls {
            class ServerFPS_Text {
                idc = 1000;
                type = 13;
                style = 0;
                x = safeZoneX + 0.01;
                y = safeZoneY + 0.01;
                w = 0.25;
                h = 0.08;
                size = 0.035;
                colorBackground[] = {0,0,0,0.3};
                colorText[] = {1,1,1,1};
                font = "PuristaMedium";
                text = "";
            };
        };
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
        class serverFPS {
            file = "z\10thJTF\addons\functions\functions";
            class isAuthorizedPlayer {};
            class toggleServerFPS {};
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
class Extended_PostInit_EventHandlers {
    class Tenthed_ServerFPSDisplay {
        init = "call compile preprocessFileLineNumbers 'z\10thJTF\addons\functions\XEH_postInit.sqf'";
    };
};