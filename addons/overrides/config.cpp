class CfgPatches {
    class Tenthed_overrides {
        author = "Akira";
        name = "10th JTF: Overrides";
        requiredAddons[] = {
            "Tenthed_core",
            "GX_Blanco_Cartel"
        };
        weapons[] = {};
        units[] = {};
    };
};
class CfgWeapons
{
    class GX_BC_Carrier_GL_Black;
    class GX_BC_Carrier_GL_Black : GX_BC_Carrier_GL_Black {
        author="GanX";
        displayName="GX - BC Carrier GL Rig (Black)";
        picture="\A3\Characters_F_Mark\Data\UI\icon_carrier_gl_rig_mtp.paa";
        hiddenSelectionsTextures[]=
        {
            "\GX_BLANCO_CARTEL\Textures\Vests\GX_B_C_Carrier_GL_Rig_Black.paa"
        };
    };

    class GX_BC_Carrier_Special_Black;
    class GX_BC_Carrier_Special_Black : GX_BC_Carrier_Special_Black {
        author="GanX";
        displayName="GX - BC Carrier Special Rig (Black)";
        picture="\A3\Characters_F_Mark\Data\UI\icon_carrier_spec_rig_mtp.paa";
        hiddenSelectionsTextures[]=
        {
            "\GX_BLANCO_CARTEL\Textures\Vests\GX_B_C_Carrier_GL_Rig_Black.paa"
        };
        class ItemInfo: VestItem
        {
            uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
            containerClass = "Supply140";
            mass = 100;
            class HitpointsProtectionInfo
            {
                class Abdomen   { hitpointName = "HitAbdomen";   armor = 16; passThrough = 0.3; };
                class Arms      { hitpointName = "HitArms";      armor = 8;  passThrough = 0.5; };
                class Chest     { hitpointName = "HitChest";     armor = 60; passThrough = 0.6; };
                class Diaphragm { hitpointName = "HitDiaphragm"; armor = 60; passThrough = 0.6; };
                class Neck      { hitpointName = "HitNeck";      armor = 8;  passThrough = 0.5; };
                class Pelvis    { hitpointName = "HitPelvis";    armor = 16; passThrough = 0.3; };
            };
        };
    };
};