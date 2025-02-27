#define MAG_XX(a,b) class _xx_##a { magazine = a; count = b; }
#define WEAP_XX(a,b) class _xx_##a { weapon = a; count = b; }
#define ITEM_XX(a,b) class _xx_##a { name = a; count = b; }

class CfgPatches {
    class Tenthed_Supplies {
        author = "Akira";
        name = "10th JTF: Supplies";
        requiredAddons[] = {};
        weapons[] = {};
        units[] = {
            "Tenthed_Resupply_Weapons",
            "Tenthed_Restricted_Arsenal"
        };
    };
};
class CfgVehicles {
    class EventHandlers;
    class I_E_CargoNet_01_ammo_F;

    class Tenthed_Resupply_Weapons : I_E_CargoNet_01_ammo_F {
        displayName = "[10th] Weapons Resupply";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        class EventHandlers {
            init = "(_this select 0) addAction ['Weapons Resupply', {}];";
        };
        class TransportMagazines {
            MAG_XX(hlc_200rnd_556x45_B_SAW, 50);
            MAG_XX(hlc_30rnd_556x45_EPR, 180);
            MAG_XX(1Rnd_Smoke_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeRed_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeGreen_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeYellow_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokePurple_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeBlue_Grenade_shell, 20);
            MAG_XX(1Rnd_SmokeOrange_Grenade_shell, 20);
            MAG_XX(ACE_HuntIR_M203, 50);
            MAG_XX(rhs_mag_M441_HE, 30);
            MAG_XX(rhs_mag_M433_HEDP, 30);
            MAG_XX(rhs_mag_M397_HET, 30);
            MAG_XX(rhs_mag_m576, 20);
            MAG_XX(rhs_mag_m4009, 20);
            MAG_XX(rhs_mag_M583A1_white, 20);
            MAG_XX(rhs_mag_m661_green, 20);
            MAG_XX(rhs_mag_m662_red, 20);
            MAG_XX(rhs_mag_M585_white_cluster, 20);
            MAG_XX(rhs_mag_M663_green_cluster, 20);
            MAG_XX(rhs_mag_M664_red_cluster, 20);
            MAG_XX(ACE_40mm_Flare_white, 20);
            MAG_XX(ACE_40mm_Flare_red, 20);
            MAG_XX(ACE_40mm_Flare_green, 20);
            MAG_XX(ACE_40mm_Flare_ir, 20);
            MAG_XX(PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade_40mm, 20);
            MAG_XX(PHEN_FSPLUS_ChemGrenade_RiotCSGasGrenade_40mm_3GL, 20);
            MAG_XX(BWA3_1Rnd_Flare_Illum, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_White, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_Green, 20);
            MAG_XX(BWA3_1Rnd_Flare_Singlestar_Red, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_White, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_Green, 20);
            MAG_XX(BWA3_1Rnd_Flare_Multistar_Red, 20);
            MAG_XX(rhsusf_20Rnd_762x51_m993_Mag, 70);
            MAG_XX(MRAWS_HEAT_F, 100);
            MAG_XX(rhs_fim92_mag, 100);
        };
        class TransportWeapons{
            WEAP_XX(hlc_rifle_M4_grip2, 30);
            WEAP_XX(hlc_m249_pip2_30Rnd, 15);
            WEAP_XX(rhs_weap_M320, 20);
            WEAP_XX(BWA3_P2A1, 30);
            WEAP_XX(rhs_weap_m14ebrri, 15);
            WEAP_XX(rhs_weap_maaws, 20);
            WEAP_XX(rhs_weap_M136, 40);
            WEAP_XX(rhs_weap_fim92, 20);
        };
        class TransportBackpacks { };
        class TransportItems { };
    };

    class Tenthed_Restricted_Arsenal : I_E_CargoNet_01_ammo_F {
        displayName = "[10th] Arsenal";
        editorCategory = "Tenthed_EditorCategory_Items";
        editorSubcategory = "Tenthed_EditorSubcategory_Objects_Supplies";
        //class EventHandlers {
        //    init = "[_this, true] execVM call Tenthed_fnc_Arsenal;";
        //};
        class EventHandlers {
            //init = "(_this select 0) addAction ['Open Arsenal', {hint 'This is your Arsenal!'}];";
            init = "(_this select 0) call Tenthed_fnc_Arsenal;";
        };
        class TransportMagazines { };
        class TransportWeapons { };
        class TransportBackpacks { };
        class TransportItems {
            ITEM_XX(ACE_Banana, 300);
        };
    };
};