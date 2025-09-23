class CfgPatches {
    class Tenthed_core {
        author = "Akira";
        name = "10th JTF: Core";
        requiredAddons[] = {};
        weapons[] = {};
        units[] = {};
    };
};
class RscPicture;
class RscControlsGroup;
class RscPictureKeepAspect;

class CfgMods {
	class tend_mod {
		dir="@10thJTF";
		name="Tenthed JTF";
		picture="A3\Ui_f\data\Logos\arma3_expansion_alpha_ca";
		hidePicture="true";
		hideName="true";
		actionName="Website";
		action="https://discord.gg/GERZ4Un";
		description="Join the 10th JTF: https://discord.gg/GERZ4Un";
	};
};

class RscControlsGroupNoHScrollbars;
class RscHTML;
class RscText;

class RscStandardDisplay;
/*
class RscDisplayMain: RscStandardDisplay {
    class controls {

        class ProjectOPFORLogo{}; // clear the project OPFOR homescreen

        class InfoMods: RscControlsGroupNoHScrollbars {
            class Controls;
        };

        class InfoNews: InfoMods {
            class Controls: Controls {
                class Background;
                class BackgroundIcon;
                class Icon;
                class News;
                class Notification;
                class Button;
            };
        };

        class Tenthed_news_apex: InfoNews {
            idc = 12199;
            y = "safeZoneY + safeZoneH - (4 * 2 + 1) * (pixelH * pixelGrid * 2) - 4 * (4 * pixelH)";

            class Controls: Controls {
                class Background: Background {};
                class BackgroundIcon: BackgroundIcon {};
                class Icon: Icon {
                    text = "\z\10thJTF\addons\core\data\logo.paa";
                };
                class Button: Button {
                    tooltip = "Join the 10th JTF";
                    url = "https://discord.gg/GERZ4Un";
                };
            };
        };
    };
};*/
class CfgFactionClasses {
    // Primary 10th JTF faction
    class Tenthed_UnitFact_Main {
        displayname = "[10th] JTF Faction";
        priority = 1;
        side = 1;
        icon = "\Tenthed_Core\data\logo.paa";
        flag = "\Tenthed_Core\data\logo.paa";
    };
};
class CfgEditorCategories {
    // Primary unit category used for units
    class Tenthed_EditorCategory_Main {
        displayName = "[10th] Units";
    };
    // Category used for Objects
    class Tenthed_EditorCategory_Objects {
        displayName = "[10th] Objects";
    };
    // Category used for Items
    class Tenthed_EditorCategory_Items {
        displayName = "[10th] Items";
    };
    // Category used for Items
    class Tenthed_EditorCategory_Modules {
        displayName = "[10th] Modules";
    };
};
class CfgEditorSubcategories {
    // Eden and Zeus Categories //
    class Tenthed_EditorSubcategory_Objects_Zeus {
        displayName = "Mission building";
    };

    // Prop Categories //
    class Tenthed_EditorSubcategory_Objects_Military {
        displayName = "Military";
    };
    class Tenthed_EditorSubcategory_Objects_Banners {
        displayName = "Banners";
    };
    // All supply props. Pods boxes or others
    class Tenthed_EditorSubcategory_Objects_Supplies {
        displayName = "Supplies";
    };

    // Item Categories //
    // All weapons
    class Tenthed_EditorSubcategory_Objects_Weapons {
        displayName = "Weapons";
    };
    // All backbacks
    class Tenthed_EditorSubcategory_Objects_Backpacks {
        displayName = "Backpacks";
    };

    // Vehicle Categories //
    // Generic uncategorized vehicles
    class Tenthed_EditorSubcategory_Objects_Vehicles {
        displayName = "Vehicles";
    };
    // Generic for turrets
    class Tenthed_EditorSubcategory_Objects_Turrets {
        displayName = "Turrets";
    };

    // Generic for Units
    class Tenthed_EditorSubcategory_Units_Men {
        displayName = "Men";
    };

};
class ACEX_Fortify_Presets {
    class Tenthed_Fortify01 {
        displayName = "10th JTF - Fortify";
        objects[] = {
            {"Land_BagFence_Round_F", 10},
            {"Land_BagFence_Long_F", 10},
            {"Land_BagFence_Short_F", 10},

            {"Land_Plank_01_4m_F", 10},
            {"Land_HBarrier_1_F", 30},
            {"Land_HBarrierWall4_F", 30},
            {"Land_HBarrierWall6_F", 30},
            {"Land_HBarrierWall_corner_F", 30},
            {"Land_HBarrierWall_corridor_F", 30},
            {"Land_HBarrierTower_F", 60}
        };
    };
};

class CfgWeapons {
    class Uniform_Base;
    class Uniform_Base {
        class ItemInfo {
            uniformType = "Neopren";
        };
    };
};